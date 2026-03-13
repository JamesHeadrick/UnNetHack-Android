#!/usr/bin/env python3
"""
Generate src/tile.c for the UnNetHack Android build.

This reimplements the tilemap utility (win/share/tilemap.c) in Python,
using the correct constants for the current Android build.

Why this script exists:
  The C tilemap tool references PM_BABY_SILVER_DRAGON and PM_SILVER_DRAGON
  which no longer exist in pm.h (replaced by PM_BABY_GLOWING_DRAGON /
  PM_GLOWING_DRAGON), so it cannot be compiled against the current headers.
  This script hardcodes the correct constants.

Constants verified against (from main repo):
  include/pm.h      → NUMMONS=434
  include/onames.h  → NUM_OBJECTS=540, CORPSE=270, SCR_STINKING_CLOUD=358
  include/rm.h      → MAXPCHARS=98, MAXEXPCHARS=9, S_sw_tl=81, S_vwall=1, S_trwall=11
  include/hack.h    → EXPL_MAX=7
  include/display.h → NUM_ZAP=9
  include/decl.h    → WARNCOUNT=6
  include/config.h  → KOPS, STEED, TOURIST, BLACKMARKET, WEBB_DISINT all defined
  include/androidconf.h → MAIL undefined

Run from the repository root or util/ directory:
  python3 util/generate_tile_c.py

Output: src/tile.c  (and optionally sys/android/assets/tile_source.txt)
"""

import os
import sys

# ── Game constants ─────────────────────────────────────────────────────────────

NUMMONS     = 434   # include/pm.h (generated)
NUM_OBJECTS = 540   # include/onames.h (generated)
CORPSE      = 270   # include/onames.h
MAXPCHARS   = 98    # include/rm.h
MAXEXPCHARS = 9     # include/rm.h
EXPL_MAX    = 7     # include/hack.h
NUM_ZAP     = 9     # include/display.h
WARNCOUNT   = 6     # include/decl.h
S_sw_tl     = 81    # include/rm.h  (start of swallow tiles in CMAP)
S_vwall     = 1     # include/rm.h
S_trwall    = 11    # include/rm.h
# ── Monster PM indices (include/pm.h) ─────────────────────────────────────────

PM_HELL_HOUND          = 28
PM_SHOCKING_SPHERE     = 33
PM_BABY_GLOWING_DRAGON = 151   # replaced PM_BABY_SILVER_DRAGON in this fork
PM_GLOWING_DRAGON      = 161   # replaced PM_SILVER_DRAGON in this fork
PM_VAMPIRE_LORD        = 243
PM_CROESUS             = 310
PM_FAMINE              = 340
PM_SHAMAN_KARNOV       = 377   # was 378; shifted -1 by mail daemon exclusion
PM_TIAMAT              = 391   # was 392; shifted -1
PM_NEANDERTHAL         = 404   # was 405; shifted -1

# ── Object indices (include/onames.h) ─────────────────────────────────────────

REFLECTING_DRAGON_SCALE_MAIL = 84   # predecessor for shimmering scale mail conditional
REFLECTING_DRAGON_SCALES     = 95   # predecessor for shimmering scales conditional

SCR_STINKING_CLOUD     = 358   # include/onames.h
SCR_MAIL_PREDECESSOR   = SCR_STINKING_CLOUD + 21  # 379: scroll just before mail scroll's image slot
# (mail scroll was at old index 380 = SCR_STINKING_CLOUD+22; predecessor is 379)

# ── Glyph type tags (mirrors tilemap.c) ───────────────────────────────────────

MON_GLYPH = 1
OBJ_GLYPH = 2
OTH_GLYPH = 3

# ── Conditionals for the Android build ────────────────────────────────────────
#
# These are tiles present in the tileset image file but compiled out of the
# game binary.  The tilemap must skip a tile slot for each so that image tile
# indices stay aligned.
#
# Derived from win/share/tilemap.c conditionals[] for this fork's configuration:
#   Defined:   KOPS, STEED, TOURIST, BLACKMARKET, WEBB_DISINT
#   Undefined: CHARON (not yet supported)
#
# MAIL and the monster/object loop:
#   pm.h and onames.h were generated WITHOUT MAIL defined (-DANDROID), so:
#     - mail daemon is NOT counted in NUMMONS=434 (excluded from pm.h)
#     - mail scroll is NOT counted in NUM_OBJECTS=540 (excluded from onames.h)
#   BUT the tileset image still has slots for both — so they need conditional
#   entries to advance tilenum past those image slots:
#     MON conditional: mail daemon after PM_FAMINE=340
#     OBJ conditional: mail scroll after SCR_MAIL_PREDECESSOR=379
#
# Silver dragons were replaced by glowing dragons in this fork:
#   - PM_BABY_SILVER_DRAGON → PM_BABY_GLOWING_DRAGON=151 (compiled in)
#   - PM_SILVER_DRAGON      → PM_GLOWING_DRAGON=161      (compiled in)
#   But "baby shimmering dragon" and "shimmering dragon" are still DEFERRED
#   (#if 0) in monst.c, so they are NOT counted in NUMMONS and the tileset
#   still has reserved image slots for them (confirmed by user).
#
#   Similarly "shimmering dragon scale mail" and "shimmering dragon scales"
#   are DEFERRED (#if 0) in objects.c, NOT counted in NUM_OBJECTS.
#   Old stale tile.c had MAXOBJTILE=986 = 444+(540+2), confirming 2 OBJ conds.
#   Current: MAXOBJTILE = 445+(541+2) = 988.
#
# ALL MON entries must come before ALL OBJ entries, each group sorted by
# predecessor (ascending), to match tilemap.c's init_tilemap() loop logic.

CONDITIONALS = [
    # (sequence,  predecessor,                  name)
    # ── MON conditionals (10, sorted by predecessor) ──────────────────────────
    (MON_GLYPH, PM_HELL_HOUND,          "Cerberus"),               # #ifndef CHARON
    (MON_GLYPH, PM_SHOCKING_SPHERE,     "beholder"),               # #if 0 in monst.c
    (MON_GLYPH, PM_BABY_GLOWING_DRAGON, "baby shimmering dragon"), # #if 0 in monst.c
    (MON_GLYPH, PM_GLOWING_DRAGON,      "shimmering dragon"),      # #if 0 in monst.c
    (MON_GLYPH, PM_VAMPIRE_LORD,        "vampire mage"),           # #if 0 in monst.c
    (MON_GLYPH, PM_CROESUS,             "Charon"),                 # #ifndef CHARON
    (MON_GLYPH, PM_FAMINE,              "mail daemon"),            # #ifdef MAIL (excluded by -DANDROID)
    (MON_GLYPH, PM_SHAMAN_KARNOV,       "Earendil"),               # #if 0 in monst.c
    (MON_GLYPH, PM_SHAMAN_KARNOV,       "Elwing"),                 # #if 0 in monst.c
    (MON_GLYPH, PM_TIAMAT,              "Goblin King"),            # #if 0 in monst.c
    (MON_GLYPH, PM_NEANDERTHAL,         "High-elf"),               # #if 0 in monst.c
    # ── OBJ conditionals (3, sorted by predecessor) ───────────────────────────
    (OBJ_GLYPH, REFLECTING_DRAGON_SCALE_MAIL, "shimmering dragon scale mail"), # #if 0
    (OBJ_GLYPH, REFLECTING_DRAGON_SCALES,     "shimmering dragon scales"),     # #if 0
    (OBJ_GLYPH, SCR_MAIL_PREDECESSOR,         "mail scroll"),                  # #ifdef MAIL (excluded by -DANDROID)
]

# ── Glyph offset computation (mirrors include/display.h) ──────────────────────

NUM_INVIS_TILES   = 1

GLYPH_MON_OFF     = 0
GLYPH_PET_OFF     = NUMMONS     + GLYPH_MON_OFF
GLYPH_INVIS_OFF   = NUMMONS     + GLYPH_PET_OFF
GLYPH_DETECT_OFF  = 1           + GLYPH_INVIS_OFF
GLYPH_BODY_OFF    = NUMMONS     + GLYPH_DETECT_OFF
GLYPH_RIDDEN_OFF  = NUMMONS     + GLYPH_BODY_OFF
GLYPH_OBJ_OFF     = NUMMONS     + GLYPH_RIDDEN_OFF
GLYPH_CMAP_OFF    = NUM_OBJECTS + GLYPH_OBJ_OFF
GLYPH_EXPLODE_OFF = (MAXPCHARS - MAXEXPCHARS) + GLYPH_CMAP_OFF
GLYPH_ZAP_OFF     = (MAXEXPCHARS * EXPL_MAX)  + GLYPH_EXPLODE_OFF
GLYPH_SWALLOW_OFF = (NUM_ZAP << 2)            + GLYPH_ZAP_OFF
GLYPH_WARNING_OFF = (NUMMONS << 3)            + GLYPH_SWALLOW_OFF
MAX_GLYPH         = WARNCOUNT                 + GLYPH_WARNING_OFF
GLYPH_INVISIBLE   = GLYPH_INVIS_OFF


def init_tilemap():
    """Reimplement tilemap.c:init_tilemap()."""
    tilemap = [-1] * MAX_GLYPH

    # Compute corpsetile and swallowbase (base positions in the tile image)
    corpsetile  = NUMMONS + NUM_INVIS_TILES + CORPSE
    swallowbase = NUMMONS + NUM_INVIS_TILES + NUM_OBJECTS + S_sw_tl

    for seq, pred, _name in CONDITIONALS:
        if seq == MON_GLYPH:
            corpsetile  += 1
            swallowbase += 1
        elif seq == OBJ_GLYPH:
            if pred < CORPSE:
                corpsetile += 1
            swallowbase += 1
        elif seq == OTH_GLYPH:
            if pred < S_sw_tl:
                swallowbase += 1

    # ── Monster tiles ──────────────────────────────────────────────────────────
    condnum = 0
    tilenum = 0

    for i in range(NUMMONS):
        tilemap[GLYPH_MON_OFF    + i] = tilenum
        tilemap[GLYPH_PET_OFF    + i] = tilenum
        tilemap[GLYPH_DETECT_OFF + i] = tilenum
        tilemap[GLYPH_RIDDEN_OFF + i] = tilenum
        tilemap[GLYPH_BODY_OFF   + i] = corpsetile
        j = GLYPH_SWALLOW_OFF + 8 * i
        for k in range(8):
            tilemap[j + k] = swallowbase + k
        tilenum += 1
        while (condnum < len(CONDITIONALS) and
               CONDITIONALS[condnum][0] == MON_GLYPH and
               CONDITIONALS[condnum][1] == i):
            condnum += 1
            tilenum += 1

    tilemap[GLYPH_INVISIBLE] = tilenum
    tilenum += 1
    lastmontile = tilenum - 1

    # ── Object tiles ───────────────────────────────────────────────────────────
    for i in range(NUM_OBJECTS):
        tilemap[GLYPH_OBJ_OFF + i] = tilenum
        tilenum += 1
        while (condnum < len(CONDITIONALS) and
               CONDITIONALS[condnum][0] == OBJ_GLYPH and
               CONDITIONALS[condnum][1] == i):
            condnum += 1
            tilenum += 1

    lastobjtile = tilenum - 1

    # ── CMAP tiles (non-explosion) ─────────────────────────────────────────────
    for i in range(MAXPCHARS - MAXEXPCHARS):
        tilemap[GLYPH_CMAP_OFF + i] = tilenum
        tilenum += 1
        while (condnum < len(CONDITIONALS) and
               CONDITIONALS[condnum][0] == OTH_GLYPH and
               CONDITIONALS[condnum][1] == i):
            condnum += 1
            tilenum += 1

    # ── Explosion tiles ────────────────────────────────────────────────────────
    for i in range(MAXEXPCHARS * EXPL_MAX):
        tilemap[GLYPH_EXPLODE_OFF + i] = tilenum
        tilenum += 1
        while (condnum < len(CONDITIONALS) and
               CONDITIONALS[condnum][0] == OTH_GLYPH and
               CONDITIONALS[condnum][1] == (i + MAXPCHARS)):
            condnum += 1
            tilenum += 1

    # ── Zap tiles ──────────────────────────────────────────────────────────────
    for i in range(NUM_ZAP << 2):
        tilemap[GLYPH_ZAP_OFF + i] = tilenum
        tilenum += 1
        while (condnum < len(CONDITIONALS) and
               CONDITIONALS[condnum][0] == OTH_GLYPH and
               CONDITIONALS[condnum][1] == (i + MAXEXPCHARS)):
            condnum += 1
            tilenum += 1

    # ── Warning tiles ──────────────────────────────────────────────────────────
    for i in range(WARNCOUNT):
        tilemap[GLYPH_WARNING_OFF + i] = tilenum
        tilenum += 1

    lastothtile = tilenum - 1

    return tilemap, lastmontile, lastobjtile, lastothtile, corpsetile, swallowbase


def write_tile_c(path, tilemap, lastmontile, lastobjtile, lastothtile):
    """Write src/tile.c, replicating tilemap.c:main() + process_substitutions()."""

    # Substitution ranges: all 4 use the same glyph span (vwall..trwall)
    first_glyph = GLYPH_CMAP_OFF + S_vwall
    last_glyph  = GLYPH_CMAP_OFF + S_trwall

    substitutes = [
        (first_glyph, last_glyph, "In_mines(plev)"),
        (first_glyph, last_glyph, "In_hell(plev)"),
        (first_glyph, last_glyph, "Is_knox(plev)"),
        (first_glyph, last_glyph, "In_sokoban(plev)"),
    ]

    # std_tiles0: the default wall tiles for those glyphs
    std_tiles = [tilemap[k] for k in range(first_glyph, last_glyph + 1)]

    with open(path, "w", newline="\n") as f:

        # ── Header ─────────────────────────────────────────────────────────────
        f.write("/* This file is automatically generated.  Do not edit. */\n")
        f.write("\n#include \"hack.h\"\n\n")

        # ── glyph2tile array ───────────────────────────────────────────────────
        f.write("short glyph2tile[MAX_GLYPH] = {\n")
        for i in range(MAX_GLYPH):
            # Match original: '\n' when i%12==0, ' ' otherwise
            sep = '\n' if (i % 12 == 0) else ' '
            f.write(f"{tilemap[i]:2d},{sep}")
        # After the loop i == MAX_GLYPH; add '\n' before '}' if not already on new line
        if MAX_GLYPH % 12 != 0:
            f.write("\n")
        f.write("};\n")

        # ── substitute_tiles (from process_substitutions) ──────────────────────
        f.write("\n\n")
        std_str = ", ".join(str(v) for v in std_tiles)
        f.write(f"short std_tiles0[] = {{ {std_str} }};\n")

        # Prolog (K&R style to match original generator output)
        f.write("\n\n")
        f.write("void\n")
        f.write("substitute_tiles(plev)\n")
        f.write("d_level *plev;\n")
        f.write("{\n")
        f.write("\tint i;\n")
        f.write("\n")

        # Generate the if/else chain
        start = lastothtile + 1
        prev_j = -1
        for i, (fg, lg, test) in enumerate(substitutes):
            same_span = (i > 0 and
                         substitutes[i][0] == substitutes[prev_j][0] and
                         substitutes[i][1] == substitutes[prev_j][1])
            if not same_span:
                if i != 0:
                    # finish previous span with its else-restore block
                    f.write(f"\t}} else {{\n")
                    f.write(f"\t\tfor (i = {substitutes[prev_j][0]}; i <= {substitutes[prev_j][1]}; i++)\n")
                    f.write(f"\t\t\tglyph2tile[i] = std_tiles0[i - {substitutes[prev_j][0]}];\n")
                    f.write(f"\t}}\n\n")
                prev_j = i
                f.write(f"\tif ({test}) {{\n")
            else:
                f.write(f"\t}} else \tif ({test}) {{\n")

            f.write(f"\t\tfor (i = {fg}; i <= {lg}; i++)\n")
            f.write(f"\t\t\tglyph2tile[i] = {start} + i - {fg};\n")
            start += lg - fg + 1

        # Finish last span
        f.write(f"\t}} else {{\n")
        f.write(f"\t\tfor (i = {substitutes[prev_j][0]}; i <= {substitutes[prev_j][1]}; i++)\n")
        f.write(f"\t\t\tglyph2tile[i] = std_tiles0[i - {substitutes[prev_j][0]}];\n")
        f.write(f"\t}}\n\n")

        # Epilog
        f.write("}\n")

        f.write(f"\nint total_tiles_used = {start};\n")

        # ── MAXMONTILE / MAXOBJTILE / MAXOTHTILE ──────────────────────────────
        final_lastothtile = start - 1
        f.write(f"\n#define MAXMONTILE {lastmontile}\n")
        f.write(f"#define MAXOBJTILE {lastobjtile}\n")
        f.write(f"#define MAXOTHTILE {final_lastothtile}\n")

        f.write("\n/*tile.c*/\n")

    return start  # total_tiles_used


def find_repo_root(start_dir):
    """Walk up from start_dir to find the repository root (has src/ and include/)."""
    d = os.path.abspath(start_dir)
    for _ in range(6):
        if os.path.isdir(os.path.join(d, "src")) and os.path.isdir(os.path.join(d, "include")):
            return d
        d = os.path.dirname(d)
    return None


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    repo_root = find_repo_root(script_dir)
    if repo_root is None:
        print("ERROR: could not find repo root (looking for src/ and include/)", file=sys.stderr)
        sys.exit(1)

    tilemap, lastmontile, lastobjtile, lastothtile, corpsetile, swallowbase = init_tilemap()

    out_tile_c = os.path.join(repo_root, "src", "tile.c")
    total = write_tile_c(out_tile_c, tilemap, lastmontile, lastobjtile, lastothtile)

    print(f"Generated {out_tile_c}")
    print(f"  NUMMONS={NUMMONS}  NUM_OBJECTS={NUM_OBJECTS}")
    print(f"  GLYPH_CMAP_OFF={GLYPH_CMAP_OFF}  MAX_GLYPH={MAX_GLYPH}")
    print(f"  corpsetile={corpsetile}  swallowbase={swallowbase}")
    print(f"  MAXMONTILE={lastmontile}  MAXOBJTILE={lastobjtile}  MAXOTHTILE={total-1}")
    print(f"  total_tiles_used={total}")

    # Also update sys/android/assets/tile_source.txt (kept as a reference copy)
    asset = os.path.join(repo_root, "sys", "android", "assets", "tile_source.txt")
    if os.path.isfile(asset):
        import shutil
        shutil.copy2(out_tile_c, asset)
        print(f"Updated {asset}")


if __name__ == "__main__":
    main()
