LOCAL_PATH := $(call my-dir)
# Path to the root of UnNetHack relative to this file
ROOT_PATH := ../../..

include $(CLEAR_VARS)

LOCAL_MODULE := unnethack

# All paths are relative to LOCAL_PATH (which is this jni directory)
# We exclude generated files (tile.c, monstr.c, vis_tab.c) from this list
# and add them conditionally below.
LOCAL_SRC_FILES := \
    $(ROOT_PATH)/src/allmain.c \
    $(ROOT_PATH)/src/alloc.c \
    $(ROOT_PATH)/src/apply.c \
    $(ROOT_PATH)/src/artifact.c \
    $(ROOT_PATH)/src/attrib.c \
    $(ROOT_PATH)/src/ball.c \
    $(ROOT_PATH)/src/bones.c \
    $(ROOT_PATH)/src/botl.c \
    $(ROOT_PATH)/src/cmd.c \
    $(ROOT_PATH)/src/dbridge.c \
    $(ROOT_PATH)/src/decl.c \
    $(ROOT_PATH)/src/detect.c \
    $(ROOT_PATH)/src/dig.c \
    $(ROOT_PATH)/src/display.c \
    $(ROOT_PATH)/src/dlb.c \
    $(ROOT_PATH)/src/do.c \
    $(ROOT_PATH)/src/do_name.c \
    $(ROOT_PATH)/src/do_wear.c \
    $(ROOT_PATH)/src/dog.c \
    $(ROOT_PATH)/src/dogmove.c \
    $(ROOT_PATH)/src/dokick.c \
    $(ROOT_PATH)/src/dothrow.c \
    $(ROOT_PATH)/src/drawing.c \
    $(ROOT_PATH)/src/dungeon.c \
    $(ROOT_PATH)/src/eat.c \
    $(ROOT_PATH)/src/end.c \
    $(ROOT_PATH)/src/engrave.c \
    $(ROOT_PATH)/src/exper.c \
    $(ROOT_PATH)/src/explode.c \
    $(ROOT_PATH)/src/extralev.c \
    $(ROOT_PATH)/src/files.c \
    $(ROOT_PATH)/src/fountain.c \
    $(ROOT_PATH)/src/hack.c \
    $(ROOT_PATH)/src/hacklib.c \
    $(ROOT_PATH)/src/invent.c \
    $(ROOT_PATH)/src/light.c \
    $(ROOT_PATH)/src/lock.c \
    $(ROOT_PATH)/src/mail.c \
    $(ROOT_PATH)/src/makemon.c \
    $(ROOT_PATH)/src/mapglyph.c \
    $(ROOT_PATH)/src/mcastu.c \
    $(ROOT_PATH)/src/mhitm.c \
    $(ROOT_PATH)/src/mhitu.c \
    $(ROOT_PATH)/src/minion.c \
    $(ROOT_PATH)/src/mklev.c \
    $(ROOT_PATH)/src/mkmap.c \
    $(ROOT_PATH)/src/mkmaze.c \
    $(ROOT_PATH)/src/mksheol.c \
    $(ROOT_PATH)/src/mkobj.c \
    $(ROOT_PATH)/src/mkroom.c \
    $(ROOT_PATH)/src/mon.c \
    $(ROOT_PATH)/src/mondata.c \
    $(ROOT_PATH)/src/monmove.c \
    $(ROOT_PATH)/src/monst.c \
    $(ROOT_PATH)/src/mplayer.c \
    $(ROOT_PATH)/src/mthrowu.c \
    $(ROOT_PATH)/src/muse.c \
    $(ROOT_PATH)/src/music.c \
    $(ROOT_PATH)/src/o_init.c \
    $(ROOT_PATH)/src/objects.c \
    $(ROOT_PATH)/src/objnam.c \
    $(ROOT_PATH)/src/options.c \
    $(ROOT_PATH)/src/pager.c \
    $(ROOT_PATH)/src/pickup.c \
    $(ROOT_PATH)/src/pline.c \
    $(ROOT_PATH)/src/polyself.c \
    $(ROOT_PATH)/src/potion.c \
    $(ROOT_PATH)/src/pray.c \
    $(ROOT_PATH)/src/priest.c \
    $(ROOT_PATH)/src/quest.c \
    $(ROOT_PATH)/src/questpgr.c \
    $(ROOT_PATH)/src/read.c \
    $(ROOT_PATH)/src/rect.c \
    $(ROOT_PATH)/src/region.c \
    $(ROOT_PATH)/src/restore.c \
    $(ROOT_PATH)/src/rip.c \
    $(ROOT_PATH)/src/rnd.c \
    $(ROOT_PATH)/src/rnd_isaac.c \
    $(ROOT_PATH)/src/role.c \
    $(ROOT_PATH)/src/rumors.c \
    $(ROOT_PATH)/src/save.c \
    $(ROOT_PATH)/src/shk.c \
    $(ROOT_PATH)/src/shknam.c \
    $(ROOT_PATH)/src/sit.c \
    $(ROOT_PATH)/src/sounds.c \
    $(ROOT_PATH)/src/sp_lev.c \
    $(ROOT_PATH)/src/spell.c \
    $(ROOT_PATH)/src/steal.c \
    $(ROOT_PATH)/src/steed.c \
    $(ROOT_PATH)/src/teleport.c \
    $(ROOT_PATH)/src/timeout.c \
    $(ROOT_PATH)/src/topten.c \
    $(ROOT_PATH)/src/track.c \
    $(ROOT_PATH)/src/trap.c \
    $(ROOT_PATH)/src/u_init.c \
    $(ROOT_PATH)/src/uhitm.c \
    $(ROOT_PATH)/src/vault.c \
    $(ROOT_PATH)/src/version.c \
    $(ROOT_PATH)/src/vision.c \
    $(ROOT_PATH)/src/weapon.c \
    $(ROOT_PATH)/src/were.c \
    $(ROOT_PATH)/src/wield.c \
    $(ROOT_PATH)/src/windows.c \
    $(ROOT_PATH)/src/wizard.c \
    $(ROOT_PATH)/src/worm.c \
    $(ROOT_PATH)/src/worn.c \
    $(ROOT_PATH)/src/write.c \
    $(ROOT_PATH)/src/zap.c \
    $(ROOT_PATH)/src/dump.c \
    $(ROOT_PATH)/src/tutorial.c \
    $(ROOT_PATH)/src/livelog.c \
    $(ROOT_PATH)/src/unicode.c \
    $(ROOT_PATH)/sys/share/ioctl.c \
    $(ROOT_PATH)/sys/share/unixtty.c \
    $(ROOT_PATH)/sys/share/nhlan.c \
    $(ROOT_PATH)/sys/android/androidmain.c \
    $(ROOT_PATH)/sys/android/androidunix.c \
    $(ROOT_PATH)/sys/android/winandroid.c \
    $(ROOT_PATH)/win/tty/getline.c \
    $(ROOT_PATH)/win/tty/termcap.c \
    $(ROOT_PATH)/win/tty/topl.c \
    $(ROOT_PATH)/win/tty/wintty.c

# Add generated files only if they exist.
# These are normally created by util/makedefs.
ifneq ($(wildcard $(LOCAL_PATH)/$(ROOT_PATH)/src/tile.c),)
    LOCAL_SRC_FILES += $(ROOT_PATH)/src/tile.c
    LOCAL_CFLAGS += -DUSE_TILES
endif

ifneq ($(wildcard $(LOCAL_PATH)/$(ROOT_PATH)/src/monstr.c),)
    LOCAL_SRC_FILES += $(ROOT_PATH)/src/monstr.c
endif

ifneq ($(wildcard $(LOCAL_PATH)/$(ROOT_PATH)/src/vis_tab.c),)
    LOCAL_SRC_FILES += $(ROOT_PATH)/src/vis_tab.c
endif

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/$(ROOT_PATH)/include \
    $(LOCAL_PATH)/$(ROOT_PATH)/src \
    $(LOCAL_PATH)/$(ROOT_PATH)/sys/android

LOCAL_CFLAGS += -DANDROID -fsigned-char -O2 -Wno-format \
                -std=gnu89 \
                -Wno-error=implicit-function-declaration \
                -Wno-implicit-function-declaration \
                -Wno-deprecated-non-prototype

LOCAL_LDLIBS := -llog -lz

include $(BUILD_SHARED_LIBRARY)
