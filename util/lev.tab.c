/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lev_comp.y"

/*	SCCS Id: @(#)lev_yacc.c	3.4	2000/01/17	*/
/*	Copyright (c) 1989 by Jean-Christophe Collet */
/* NetHack may be freely redistributed.  See license for details. */

/*
 * This file contains the Level Compiler code
 * It may handle special mazes & special room-levels
 */

/* In case we're using bison in AIX.  This definition must be
 * placed before any other C-language construct in the file
 * excluding comments and preprocessor directives (thanks IBM
 * for this wonderful feature...).
 *
 * Note: some cpps barf on this 'undefined control' (#pragma).
 * Addition of the leading space seems to prevent barfage for now,
 * and AIX will still see the directive.
 */
#ifdef _AIX
 #pragma alloca		/* keep leading space! */
#endif

#include "hack.h"
#include "sp_lev.h"

#define ERR		(-1)
/* many types of things are put in chars for transference to NetHack.
 * since some systems will use signed chars, limit everybody to the
 * same number for portability.
 */
#define MAX_OF_TYPE	128

#define MAX_NESTED_IFS	20
#define MAX_SWITCH_CASES 20

#define New(type)		\
	(type *) memset((genericptr_t)alloc(sizeof(type)), 0, sizeof(type))
#define NewTab(type, size)	(type **) alloc(sizeof(type *) * size)
#define Free(ptr)		free((genericptr_t)ptr)

extern void VDECL(lc_error, (const char *, ...));
extern void VDECL(lc_warning, (const char *, ...));
extern void FDECL(yyerror, (const char *));
extern void FDECL(yywarning, (const char *));
extern int NDECL(yylex);
int NDECL(yyparse);
 extern void FDECL(include_push, (const char *));
extern int NDECL(include_pop);

extern int FDECL(get_floor_type, (CHAR_P));
extern int FDECL(get_room_type, (char *));
extern int FDECL(get_trap_type, (char *));
extern int FDECL(get_monster_id, (char *,CHAR_P));
extern int FDECL(get_object_id, (char *,CHAR_P));
extern boolean FDECL(check_monster_char, (CHAR_P));
extern boolean FDECL(check_object_char, (CHAR_P));
extern char FDECL(what_map_char, (CHAR_P));
extern void FDECL(scan_map, (char *, sp_lev *));
extern void FDECL(add_opcode, (sp_lev *, int, genericptr_t));
extern genericptr_t FDECL(get_last_opcode_data1, (sp_lev *, int));
extern genericptr_t FDECL(get_last_opcode_data2, (sp_lev *, int,int));
extern boolean FDECL(check_subrooms, (sp_lev *));
extern boolean FDECL(write_level_file, (char *,sp_lev *));
extern struct opvar *FDECL(set_opvar_int, (struct opvar *, long));
extern void VDECL(add_opvars, (sp_lev *, const char *, ...));

extern struct lc_funcdefs *FDECL(funcdef_new,(long,char *));
extern void FDECL(funcdef_free_all,(struct lc_funcdefs *));
extern struct lc_funcdefs *FDECL(funcdef_defined,(struct lc_funcdefs *,char *, int));
extern char *FDECL(funcdef_paramtypes, (struct lc_funcdefs *));
extern char *FDECL(decode_parm_str, (char *));

extern struct lc_vardefs *FDECL(vardef_new,(long,char *));
extern void FDECL(vardef_free_all,(struct lc_vardefs *));
extern struct lc_vardefs *FDECL(vardef_defined,(struct lc_vardefs *,char *, int));

extern void NDECL(break_stmt_start);
extern void FDECL(break_stmt_end, (sp_lev *));
extern void FDECL(break_stmt_new, (sp_lev *, long));

extern void FDECL(splev_add_from, (sp_lev *, sp_lev *));

extern void FDECL(check_vardef_type, (struct lc_vardefs *, char *, long));
extern void FDECL(vardef_used, (struct lc_vardefs *, char *));
extern struct lc_vardefs *FDECL(add_vardef_type, (struct lc_vardefs *, char *, long));

extern int FDECL(reverse_jmp_opcode, (int));

extern int FDECL(is_core_func, (char *));
extern int FDECL(core_func_idx, (char *));
extern char FDECL(core_func_retval, (int));
extern const char *FDECL(core_func_params, (int));
extern const char *FDECL(core_func_name, (int));
extern int FDECL(handle_corefunc, (sp_lev *, char *, char *, char));

struct coord {
	long x;
	long y;
};

struct forloopdef {
    char *varname;
    long jmp_point;
};
static struct forloopdef forloop_list[MAX_NESTED_IFS];
static short n_forloops = 0;


sp_lev *splev = NULL;

static struct opvar *if_list[MAX_NESTED_IFS];

static short n_if_list = 0;

unsigned int max_x_map, max_y_map;
int obj_containment = 0;

int in_container_obj = 0;

/* integer value is possibly an inconstant value (eg. dice notation or a variable) */
int is_inconstant_number = 0;

int in_switch_statement = 0;
static struct opvar *switch_check_jump = NULL;
static struct opvar *switch_default_case = NULL;
static struct opvar *switch_case_list[MAX_SWITCH_CASES];
static long switch_case_value[MAX_SWITCH_CASES];
int n_switch_case_list = 0;

int allow_break_statements = 0;
struct lc_breakdef *break_list = NULL;

extern struct lc_vardefs *variable_definitions;


struct lc_vardefs *function_tmp_var_defs = NULL;
extern struct lc_funcdefs *function_definitions;
struct lc_funcdefs *curr_function = NULL;
struct lc_funcdefs_parm * curr_function_param = NULL;
int in_function_definition = 0;
sp_lev *function_splev_backup = NULL;

extern int fatal_error;
extern int got_errors;
extern int line_number;
extern const char *fname;
extern int is_rnd_vault;
extern int rnd_vault_freq;


#line 223 "lev.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "lev.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_PERCENT = 6,                    /* PERCENT  */
  YYSYMBOL_SPERCENT = 7,                   /* SPERCENT  */
  YYSYMBOL_MINUS_INTEGER = 8,              /* MINUS_INTEGER  */
  YYSYMBOL_PLUS_INTEGER = 9,               /* PLUS_INTEGER  */
  YYSYMBOL_MAZE_GRID_ID = 10,              /* MAZE_GRID_ID  */
  YYSYMBOL_SOLID_FILL_ID = 11,             /* SOLID_FILL_ID  */
  YYSYMBOL_MINES_ID = 12,                  /* MINES_ID  */
  YYSYMBOL_SHEOL_ID = 13,                  /* SHEOL_ID  */
  YYSYMBOL_ROGUELEV_ID = 14,               /* ROGUELEV_ID  */
  YYSYMBOL_MESSAGE_ID = 15,                /* MESSAGE_ID  */
  YYSYMBOL_LEVEL_ID = 16,                  /* LEVEL_ID  */
  YYSYMBOL_LEV_INIT_ID = 17,               /* LEV_INIT_ID  */
  YYSYMBOL_GEOMETRY_ID = 18,               /* GEOMETRY_ID  */
  YYSYMBOL_NOMAP_ID = 19,                  /* NOMAP_ID  */
  YYSYMBOL_OBJECT_ID = 20,                 /* OBJECT_ID  */
  YYSYMBOL_COBJECT_ID = 21,                /* COBJECT_ID  */
  YYSYMBOL_MONSTER_ID = 22,                /* MONSTER_ID  */
  YYSYMBOL_TRAP_ID = 23,                   /* TRAP_ID  */
  YYSYMBOL_DOOR_ID = 24,                   /* DOOR_ID  */
  YYSYMBOL_DRAWBRIDGE_ID = 25,             /* DRAWBRIDGE_ID  */
  YYSYMBOL_object_ID = 26,                 /* object_ID  */
  YYSYMBOL_monster_ID = 27,                /* monster_ID  */
  YYSYMBOL_terrain_ID = 28,                /* terrain_ID  */
  YYSYMBOL_MAZEWALK_ID = 29,               /* MAZEWALK_ID  */
  YYSYMBOL_WALLIFY_ID = 30,                /* WALLIFY_ID  */
  YYSYMBOL_REGION_ID = 31,                 /* REGION_ID  */
  YYSYMBOL_FILLING = 32,                   /* FILLING  */
  YYSYMBOL_IRREGULAR = 33,                 /* IRREGULAR  */
  YYSYMBOL_JOINED = 34,                    /* JOINED  */
  YYSYMBOL_ALTAR_ID = 35,                  /* ALTAR_ID  */
  YYSYMBOL_LADDER_ID = 36,                 /* LADDER_ID  */
  YYSYMBOL_STAIR_ID = 37,                  /* STAIR_ID  */
  YYSYMBOL_NON_DIGGABLE_ID = 38,           /* NON_DIGGABLE_ID  */
  YYSYMBOL_NON_PASSWALL_ID = 39,           /* NON_PASSWALL_ID  */
  YYSYMBOL_ROOM_ID = 40,                   /* ROOM_ID  */
  YYSYMBOL_PORTAL_ID = 41,                 /* PORTAL_ID  */
  YYSYMBOL_TELEPRT_ID = 42,                /* TELEPRT_ID  */
  YYSYMBOL_BRANCH_ID = 43,                 /* BRANCH_ID  */
  YYSYMBOL_LEV = 44,                       /* LEV  */
  YYSYMBOL_CHANCE_ID = 45,                 /* CHANCE_ID  */
  YYSYMBOL_MINERALIZE_ID = 46,             /* MINERALIZE_ID  */
  YYSYMBOL_CORRIDOR_ID = 47,               /* CORRIDOR_ID  */
  YYSYMBOL_GOLD_ID = 48,                   /* GOLD_ID  */
  YYSYMBOL_ENGRAVING_ID = 49,              /* ENGRAVING_ID  */
  YYSYMBOL_FOUNTAIN_ID = 50,               /* FOUNTAIN_ID  */
  YYSYMBOL_POOL_ID = 51,                   /* POOL_ID  */
  YYSYMBOL_SINK_ID = 52,                   /* SINK_ID  */
  YYSYMBOL_NONE = 53,                      /* NONE  */
  YYSYMBOL_RAND_CORRIDOR_ID = 54,          /* RAND_CORRIDOR_ID  */
  YYSYMBOL_DOOR_STATE = 55,                /* DOOR_STATE  */
  YYSYMBOL_LIGHT_STATE = 56,               /* LIGHT_STATE  */
  YYSYMBOL_CURSE_TYPE = 57,                /* CURSE_TYPE  */
  YYSYMBOL_ENGRAVING_TYPE = 58,            /* ENGRAVING_TYPE  */
  YYSYMBOL_DIRECTION = 59,                 /* DIRECTION  */
  YYSYMBOL_RANDOM_TYPE = 60,               /* RANDOM_TYPE  */
  YYSYMBOL_RANDOM_TYPE_BRACKET = 61,       /* RANDOM_TYPE_BRACKET  */
  YYSYMBOL_A_REGISTER = 62,                /* A_REGISTER  */
  YYSYMBOL_ALIGNMENT = 63,                 /* ALIGNMENT  */
  YYSYMBOL_LEFT_OR_RIGHT = 64,             /* LEFT_OR_RIGHT  */
  YYSYMBOL_CENTER = 65,                    /* CENTER  */
  YYSYMBOL_TOP_OR_BOT = 66,                /* TOP_OR_BOT  */
  YYSYMBOL_ALTAR_TYPE = 67,                /* ALTAR_TYPE  */
  YYSYMBOL_UP_OR_DOWN = 68,                /* UP_OR_DOWN  */
  YYSYMBOL_SUBROOM_ID = 69,                /* SUBROOM_ID  */
  YYSYMBOL_NAME_ID = 70,                   /* NAME_ID  */
  YYSYMBOL_FLAGS_ID = 71,                  /* FLAGS_ID  */
  YYSYMBOL_FLAG_TYPE = 72,                 /* FLAG_TYPE  */
  YYSYMBOL_MON_ATTITUDE = 73,              /* MON_ATTITUDE  */
  YYSYMBOL_MON_ALERTNESS = 74,             /* MON_ALERTNESS  */
  YYSYMBOL_MON_APPEARANCE = 75,            /* MON_APPEARANCE  */
  YYSYMBOL_ROOMDOOR_ID = 76,               /* ROOMDOOR_ID  */
  YYSYMBOL_IF_ID = 77,                     /* IF_ID  */
  YYSYMBOL_ELSE_ID = 78,                   /* ELSE_ID  */
  YYSYMBOL_SPILL_ID = 79,                  /* SPILL_ID  */
  YYSYMBOL_TERRAIN_ID = 80,                /* TERRAIN_ID  */
  YYSYMBOL_HORIZ_OR_VERT = 81,             /* HORIZ_OR_VERT  */
  YYSYMBOL_REPLACE_TERRAIN_ID = 82,        /* REPLACE_TERRAIN_ID  */
  YYSYMBOL_EXIT_ID = 83,                   /* EXIT_ID  */
  YYSYMBOL_SHUFFLE_ID = 84,                /* SHUFFLE_ID  */
  YYSYMBOL_QUANTITY_ID = 85,               /* QUANTITY_ID  */
  YYSYMBOL_BURIED_ID = 86,                 /* BURIED_ID  */
  YYSYMBOL_LOOP_ID = 87,                   /* LOOP_ID  */
  YYSYMBOL_FOR_ID = 88,                    /* FOR_ID  */
  YYSYMBOL_TO_ID = 89,                     /* TO_ID  */
  YYSYMBOL_SWITCH_ID = 90,                 /* SWITCH_ID  */
  YYSYMBOL_CASE_ID = 91,                   /* CASE_ID  */
  YYSYMBOL_BREAK_ID = 92,                  /* BREAK_ID  */
  YYSYMBOL_DEFAULT_ID = 93,                /* DEFAULT_ID  */
  YYSYMBOL_ERODED_ID = 94,                 /* ERODED_ID  */
  YYSYMBOL_TRAPPED_STATE = 95,             /* TRAPPED_STATE  */
  YYSYMBOL_RECHARGED_ID = 96,              /* RECHARGED_ID  */
  YYSYMBOL_INVIS_ID = 97,                  /* INVIS_ID  */
  YYSYMBOL_GREASED_ID = 98,                /* GREASED_ID  */
  YYSYMBOL_FEMALE_ID = 99,                 /* FEMALE_ID  */
  YYSYMBOL_CANCELLED_ID = 100,             /* CANCELLED_ID  */
  YYSYMBOL_REVIVED_ID = 101,               /* REVIVED_ID  */
  YYSYMBOL_AVENGE_ID = 102,                /* AVENGE_ID  */
  YYSYMBOL_FLEEING_ID = 103,               /* FLEEING_ID  */
  YYSYMBOL_BLINDED_ID = 104,               /* BLINDED_ID  */
  YYSYMBOL_PARALYZED_ID = 105,             /* PARALYZED_ID  */
  YYSYMBOL_STUNNED_ID = 106,               /* STUNNED_ID  */
  YYSYMBOL_CONFUSED_ID = 107,              /* CONFUSED_ID  */
  YYSYMBOL_SEENTRAPS_ID = 108,             /* SEENTRAPS_ID  */
  YYSYMBOL_ALL_ID = 109,                   /* ALL_ID  */
  YYSYMBOL_MON_GENERATION_ID = 110,        /* MON_GENERATION_ID  */
  YYSYMBOL_MONTYPE_ID = 111,               /* MONTYPE_ID  */
  YYSYMBOL_GRAVE_ID = 112,                 /* GRAVE_ID  */
  YYSYMBOL_ERODEPROOF_ID = 113,            /* ERODEPROOF_ID  */
  YYSYMBOL_FUNCTION_ID = 114,              /* FUNCTION_ID  */
  YYSYMBOL_INCLUDE_ID = 115,               /* INCLUDE_ID  */
  YYSYMBOL_SOUNDS_ID = 116,                /* SOUNDS_ID  */
  YYSYMBOL_MSG_OUTPUT_TYPE = 117,          /* MSG_OUTPUT_TYPE  */
  YYSYMBOL_WALLWALK_ID = 118,              /* WALLWALK_ID  */
  YYSYMBOL_COMPARE_TYPE = 119,             /* COMPARE_TYPE  */
  YYSYMBOL_VAULTGEN_ID = 120,              /* VAULTGEN_ID  */
  YYSYMBOL_rect_ID = 121,                  /* rect_ID  */
  YYSYMBOL_fillrect_ID = 122,              /* fillrect_ID  */
  YYSYMBOL_line_ID = 123,                  /* line_ID  */
  YYSYMBOL_randline_ID = 124,              /* randline_ID  */
  YYSYMBOL_grow_ID = 125,                  /* grow_ID  */
  YYSYMBOL_selection_ID = 126,             /* selection_ID  */
  YYSYMBOL_flood_ID = 127,                 /* flood_ID  */
  YYSYMBOL_rndcoord_ID = 128,              /* rndcoord_ID  */
  YYSYMBOL_circle_ID = 129,                /* circle_ID  */
  YYSYMBOL_ellipse_ID = 130,               /* ellipse_ID  */
  YYSYMBOL_filter_ID = 131,                /* filter_ID  */
  YYSYMBOL_complement_ID = 132,            /* complement_ID  */
  YYSYMBOL_gradient_ID = 133,              /* gradient_ID  */
  YYSYMBOL_GRADIENT_TYPE = 134,            /* GRADIENT_TYPE  */
  YYSYMBOL_LIMITED = 135,                  /* LIMITED  */
  YYSYMBOL_HUMIDITY_TYPE = 136,            /* HUMIDITY_TYPE  */
  YYSYMBOL_137_ = 137,                     /* ','  */
  YYSYMBOL_138_ = 138,                     /* ':'  */
  YYSYMBOL_139_ = 139,                     /* '('  */
  YYSYMBOL_140_ = 140,                     /* ')'  */
  YYSYMBOL_141_ = 141,                     /* '['  */
  YYSYMBOL_142_ = 142,                     /* ']'  */
  YYSYMBOL_143_ = 143,                     /* '{'  */
  YYSYMBOL_144_ = 144,                     /* '}'  */
  YYSYMBOL_STRING = 145,                   /* STRING  */
  YYSYMBOL_MAP_ID = 146,                   /* MAP_ID  */
  YYSYMBOL_NQSTRING = 147,                 /* NQSTRING  */
  YYSYMBOL_VARSTRING = 148,                /* VARSTRING  */
  YYSYMBOL_CFUNC = 149,                    /* CFUNC  */
  YYSYMBOL_CFUNC_INT = 150,                /* CFUNC_INT  */
  YYSYMBOL_CFUNC_STR = 151,                /* CFUNC_STR  */
  YYSYMBOL_CFUNC_COORD = 152,              /* CFUNC_COORD  */
  YYSYMBOL_CFUNC_REGION = 153,             /* CFUNC_REGION  */
  YYSYMBOL_VARSTRING_INT = 154,            /* VARSTRING_INT  */
  YYSYMBOL_VARSTRING_INT_ARRAY = 155,      /* VARSTRING_INT_ARRAY  */
  YYSYMBOL_VARSTRING_STRING = 156,         /* VARSTRING_STRING  */
  YYSYMBOL_VARSTRING_STRING_ARRAY = 157,   /* VARSTRING_STRING_ARRAY  */
  YYSYMBOL_VARSTRING_VAR = 158,            /* VARSTRING_VAR  */
  YYSYMBOL_VARSTRING_VAR_ARRAY = 159,      /* VARSTRING_VAR_ARRAY  */
  YYSYMBOL_VARSTRING_COORD = 160,          /* VARSTRING_COORD  */
  YYSYMBOL_VARSTRING_COORD_ARRAY = 161,    /* VARSTRING_COORD_ARRAY  */
  YYSYMBOL_VARSTRING_REGION = 162,         /* VARSTRING_REGION  */
  YYSYMBOL_VARSTRING_REGION_ARRAY = 163,   /* VARSTRING_REGION_ARRAY  */
  YYSYMBOL_VARSTRING_MAPCHAR = 164,        /* VARSTRING_MAPCHAR  */
  YYSYMBOL_VARSTRING_MAPCHAR_ARRAY = 165,  /* VARSTRING_MAPCHAR_ARRAY  */
  YYSYMBOL_VARSTRING_MONST = 166,          /* VARSTRING_MONST  */
  YYSYMBOL_VARSTRING_MONST_ARRAY = 167,    /* VARSTRING_MONST_ARRAY  */
  YYSYMBOL_VARSTRING_OBJ = 168,            /* VARSTRING_OBJ  */
  YYSYMBOL_VARSTRING_OBJ_ARRAY = 169,      /* VARSTRING_OBJ_ARRAY  */
  YYSYMBOL_VARSTRING_SEL = 170,            /* VARSTRING_SEL  */
  YYSYMBOL_VARSTRING_SEL_ARRAY = 171,      /* VARSTRING_SEL_ARRAY  */
  YYSYMBOL_METHOD_INT = 172,               /* METHOD_INT  */
  YYSYMBOL_METHOD_INT_ARRAY = 173,         /* METHOD_INT_ARRAY  */
  YYSYMBOL_METHOD_STRING = 174,            /* METHOD_STRING  */
  YYSYMBOL_METHOD_STRING_ARRAY = 175,      /* METHOD_STRING_ARRAY  */
  YYSYMBOL_METHOD_VAR = 176,               /* METHOD_VAR  */
  YYSYMBOL_METHOD_VAR_ARRAY = 177,         /* METHOD_VAR_ARRAY  */
  YYSYMBOL_METHOD_COORD = 178,             /* METHOD_COORD  */
  YYSYMBOL_METHOD_COORD_ARRAY = 179,       /* METHOD_COORD_ARRAY  */
  YYSYMBOL_METHOD_REGION = 180,            /* METHOD_REGION  */
  YYSYMBOL_METHOD_REGION_ARRAY = 181,      /* METHOD_REGION_ARRAY  */
  YYSYMBOL_METHOD_MAPCHAR = 182,           /* METHOD_MAPCHAR  */
  YYSYMBOL_METHOD_MAPCHAR_ARRAY = 183,     /* METHOD_MAPCHAR_ARRAY  */
  YYSYMBOL_METHOD_MONST = 184,             /* METHOD_MONST  */
  YYSYMBOL_METHOD_MONST_ARRAY = 185,       /* METHOD_MONST_ARRAY  */
  YYSYMBOL_METHOD_OBJ = 186,               /* METHOD_OBJ  */
  YYSYMBOL_METHOD_OBJ_ARRAY = 187,         /* METHOD_OBJ_ARRAY  */
  YYSYMBOL_METHOD_SEL = 188,               /* METHOD_SEL  */
  YYSYMBOL_METHOD_SEL_ARRAY = 189,         /* METHOD_SEL_ARRAY  */
  YYSYMBOL_DICE = 190,                     /* DICE  */
  YYSYMBOL_191_ = 191,                     /* '+'  */
  YYSYMBOL_192_ = 192,                     /* '-'  */
  YYSYMBOL_193_ = 193,                     /* '*'  */
  YYSYMBOL_194_ = 194,                     /* '/'  */
  YYSYMBOL_195_ = 195,                     /* '%'  */
  YYSYMBOL_196_ = 196,                     /* '='  */
  YYSYMBOL_197_ = 197,                     /* '.'  */
  YYSYMBOL_198_ = 198,                     /* '|'  */
  YYSYMBOL_199_ = 199,                     /* '&'  */
  YYSYMBOL_YYACCEPT = 200,                 /* $accept  */
  YYSYMBOL_file = 201,                     /* file  */
  YYSYMBOL_header_stmts = 202,             /* header_stmts  */
  YYSYMBOL_header_stmt = 203,              /* header_stmt  */
  YYSYMBOL_include_def = 204,              /* include_def  */
  YYSYMBOL_levels = 205,                   /* levels  */
  YYSYMBOL_level = 206,                    /* level  */
  YYSYMBOL_level_def = 207,                /* level_def  */
  YYSYMBOL_lev_init = 208,                 /* lev_init  */
  YYSYMBOL_opt_limited = 209,              /* opt_limited  */
  YYSYMBOL_opt_coord_or_var = 210,         /* opt_coord_or_var  */
  YYSYMBOL_opt_fillchar = 211,             /* opt_fillchar  */
  YYSYMBOL_walled = 212,                   /* walled  */
  YYSYMBOL_flags = 213,                    /* flags  */
  YYSYMBOL_flag_list = 214,                /* flag_list  */
  YYSYMBOL_levstatements = 215,            /* levstatements  */
  YYSYMBOL_stmt_block = 216,               /* stmt_block  */
  YYSYMBOL_levstatement = 217,             /* levstatement  */
  YYSYMBOL_any_var_array = 218,            /* any_var_array  */
  YYSYMBOL_any_var = 219,                  /* any_var  */
  YYSYMBOL_any_var_or_arr = 220,           /* any_var_or_arr  */
  YYSYMBOL_any_var_or_unk = 221,           /* any_var_or_unk  */
  YYSYMBOL_shuffle_detail = 222,           /* shuffle_detail  */
  YYSYMBOL_variable_define = 223,          /* variable_define  */
  YYSYMBOL_encodeobj_list = 224,           /* encodeobj_list  */
  YYSYMBOL_encodemonster_list = 225,       /* encodemonster_list  */
  YYSYMBOL_mapchar_list = 226,             /* mapchar_list  */
  YYSYMBOL_encoderegion_list = 227,        /* encoderegion_list  */
  YYSYMBOL_encodecoord_list = 228,         /* encodecoord_list  */
  YYSYMBOL_integer_list = 229,             /* integer_list  */
  YYSYMBOL_string_list = 230,              /* string_list  */
  YYSYMBOL_function_define = 231,          /* function_define  */
  YYSYMBOL_232_1 = 232,                    /* $@1  */
  YYSYMBOL_233_2 = 233,                    /* $@2  */
  YYSYMBOL_function_call = 234,            /* function_call  */
  YYSYMBOL_exitstatement = 235,            /* exitstatement  */
  YYSYMBOL_opt_percent = 236,              /* opt_percent  */
  YYSYMBOL_opt_spercent = 237,             /* opt_spercent  */
  YYSYMBOL_comparestmt = 238,              /* comparestmt  */
  YYSYMBOL_switchstatement = 239,          /* switchstatement  */
  YYSYMBOL_240_3 = 240,                    /* $@3  */
  YYSYMBOL_241_4 = 241,                    /* $@4  */
  YYSYMBOL_switchcases = 242,              /* switchcases  */
  YYSYMBOL_switchcase = 243,               /* switchcase  */
  YYSYMBOL_244_5 = 244,                    /* $@5  */
  YYSYMBOL_245_6 = 245,                    /* $@6  */
  YYSYMBOL_breakstatement = 246,           /* breakstatement  */
  YYSYMBOL_for_to_span = 247,              /* for_to_span  */
  YYSYMBOL_forstmt_start = 248,            /* forstmt_start  */
  YYSYMBOL_forstatement = 249,             /* forstatement  */
  YYSYMBOL_250_7 = 250,                    /* $@7  */
  YYSYMBOL_loopstatement = 251,            /* loopstatement  */
  YYSYMBOL_252_8 = 252,                    /* $@8  */
  YYSYMBOL_chancestatement = 253,          /* chancestatement  */
  YYSYMBOL_254_9 = 254,                    /* $@9  */
  YYSYMBOL_ifstatement = 255,              /* ifstatement  */
  YYSYMBOL_256_10 = 256,                   /* $@10  */
  YYSYMBOL_if_ending = 257,                /* if_ending  */
  YYSYMBOL_258_11 = 258,                   /* $@11  */
  YYSYMBOL_vaultgen_stmt = 259,            /* vaultgen_stmt  */
  YYSYMBOL_message = 260,                  /* message  */
  YYSYMBOL_wallwalk_detail = 261,          /* wallwalk_detail  */
  YYSYMBOL_random_corridors = 262,         /* random_corridors  */
  YYSYMBOL_corridor = 263,                 /* corridor  */
  YYSYMBOL_corr_spec = 264,                /* corr_spec  */
  YYSYMBOL_room_begin = 265,               /* room_begin  */
  YYSYMBOL_subroom_def = 266,              /* subroom_def  */
  YYSYMBOL_267_12 = 267,                   /* $@12  */
  YYSYMBOL_room_def = 268,                 /* room_def  */
  YYSYMBOL_269_13 = 269,                   /* $@13  */
  YYSYMBOL_roomfill = 270,                 /* roomfill  */
  YYSYMBOL_room_pos = 271,                 /* room_pos  */
  YYSYMBOL_subroom_pos = 272,              /* subroom_pos  */
  YYSYMBOL_room_align = 273,               /* room_align  */
  YYSYMBOL_room_size = 274,                /* room_size  */
  YYSYMBOL_door_detail = 275,              /* door_detail  */
  YYSYMBOL_secret = 276,                   /* secret  */
  YYSYMBOL_door_wall = 277,                /* door_wall  */
  YYSYMBOL_dir_list = 278,                 /* dir_list  */
  YYSYMBOL_door_pos = 279,                 /* door_pos  */
  YYSYMBOL_map_definition = 280,           /* map_definition  */
  YYSYMBOL_h_justif = 281,                 /* h_justif  */
  YYSYMBOL_v_justif = 282,                 /* v_justif  */
  YYSYMBOL_sounds_detail = 283,            /* sounds_detail  */
  YYSYMBOL_sounds_list = 284,              /* sounds_list  */
  YYSYMBOL_lvl_sound_part = 285,           /* lvl_sound_part  */
  YYSYMBOL_mon_generation = 286,           /* mon_generation  */
  YYSYMBOL_mon_gen_list = 287,             /* mon_gen_list  */
  YYSYMBOL_mon_gen_part = 288,             /* mon_gen_part  */
  YYSYMBOL_monster_detail = 289,           /* monster_detail  */
  YYSYMBOL_290_14 = 290,                   /* $@14  */
  YYSYMBOL_monster_desc = 291,             /* monster_desc  */
  YYSYMBOL_monster_infos = 292,            /* monster_infos  */
  YYSYMBOL_monster_info = 293,             /* monster_info  */
  YYSYMBOL_seen_trap_mask = 294,           /* seen_trap_mask  */
  YYSYMBOL_object_detail = 295,            /* object_detail  */
  YYSYMBOL_296_15 = 296,                   /* $@15  */
  YYSYMBOL_object_desc = 297,              /* object_desc  */
  YYSYMBOL_object_infos = 298,             /* object_infos  */
  YYSYMBOL_object_info = 299,              /* object_info  */
  YYSYMBOL_trap_detail = 300,              /* trap_detail  */
  YYSYMBOL_drawbridge_detail = 301,        /* drawbridge_detail  */
  YYSYMBOL_mazewalk_detail = 302,          /* mazewalk_detail  */
  YYSYMBOL_wallify_detail = 303,           /* wallify_detail  */
  YYSYMBOL_ladder_detail = 304,            /* ladder_detail  */
  YYSYMBOL_stair_detail = 305,             /* stair_detail  */
  YYSYMBOL_stair_region = 306,             /* stair_region  */
  YYSYMBOL_portal_region = 307,            /* portal_region  */
  YYSYMBOL_teleprt_region = 308,           /* teleprt_region  */
  YYSYMBOL_branch_region = 309,            /* branch_region  */
  YYSYMBOL_teleprt_detail = 310,           /* teleprt_detail  */
  YYSYMBOL_fountain_detail = 311,          /* fountain_detail  */
  YYSYMBOL_sink_detail = 312,              /* sink_detail  */
  YYSYMBOL_pool_detail = 313,              /* pool_detail  */
  YYSYMBOL_terrain_type = 314,             /* terrain_type  */
  YYSYMBOL_replace_terrain_detail = 315,   /* replace_terrain_detail  */
  YYSYMBOL_terrain_detail = 316,           /* terrain_detail  */
  YYSYMBOL_spill_detail = 317,             /* spill_detail  */
  YYSYMBOL_diggable_detail = 318,          /* diggable_detail  */
  YYSYMBOL_passwall_detail = 319,          /* passwall_detail  */
  YYSYMBOL_region_detail = 320,            /* region_detail  */
  YYSYMBOL_321_16 = 321,                   /* @16  */
  YYSYMBOL_region_detail_end = 322,        /* region_detail_end  */
  YYSYMBOL_altar_detail = 323,             /* altar_detail  */
  YYSYMBOL_grave_detail = 324,             /* grave_detail  */
  YYSYMBOL_gold_detail = 325,              /* gold_detail  */
  YYSYMBOL_engraving_detail = 326,         /* engraving_detail  */
  YYSYMBOL_mineralize = 327,               /* mineralize  */
  YYSYMBOL_trap_name = 328,                /* trap_name  */
  YYSYMBOL_room_type = 329,                /* room_type  */
  YYSYMBOL_optroomregionflags = 330,       /* optroomregionflags  */
  YYSYMBOL_roomregionflags = 331,          /* roomregionflags  */
  YYSYMBOL_roomregionflag = 332,           /* roomregionflag  */
  YYSYMBOL_door_state = 333,               /* door_state  */
  YYSYMBOL_light_state = 334,              /* light_state  */
  YYSYMBOL_alignment = 335,                /* alignment  */
  YYSYMBOL_alignment_prfx = 336,           /* alignment_prfx  */
  YYSYMBOL_altar_type = 337,               /* altar_type  */
  YYSYMBOL_a_register = 338,               /* a_register  */
  YYSYMBOL_monster = 339,                  /* monster  */
  YYSYMBOL_string_or_var = 340,            /* string_or_var  */
  YYSYMBOL_integer_or_var = 341,           /* integer_or_var  */
  YYSYMBOL_coord_or_var = 342,             /* coord_or_var  */
  YYSYMBOL_encodecoord = 343,              /* encodecoord  */
  YYSYMBOL_humidity_flags = 344,           /* humidity_flags  */
  YYSYMBOL_region_or_var = 345,            /* region_or_var  */
  YYSYMBOL_encoderegion = 346,             /* encoderegion  */
  YYSYMBOL_mapchar_or_var = 347,           /* mapchar_or_var  */
  YYSYMBOL_mapchar = 348,                  /* mapchar  */
  YYSYMBOL_monster_or_var = 349,           /* monster_or_var  */
  YYSYMBOL_encodemonster = 350,            /* encodemonster  */
  YYSYMBOL_object_or_var = 351,            /* object_or_var  */
  YYSYMBOL_xobject_or_var = 352,           /* xobject_or_var  */
  YYSYMBOL_encodexobj = 353,               /* encodexobj  */
  YYSYMBOL_encodeobj = 354,                /* encodeobj  */
  YYSYMBOL_string_expr = 355,              /* string_expr  */
  YYSYMBOL_math_expr_var = 356,            /* math_expr_var  */
  YYSYMBOL_func_param_type = 357,          /* func_param_type  */
  YYSYMBOL_func_param_part = 358,          /* func_param_part  */
  YYSYMBOL_func_param_list = 359,          /* func_param_list  */
  YYSYMBOL_func_params_list = 360,         /* func_params_list  */
  YYSYMBOL_func_call_param_part = 361,     /* func_call_param_part  */
  YYSYMBOL_func_call_param_list = 362,     /* func_call_param_list  */
  YYSYMBOL_func_call_params_list = 363,    /* func_call_params_list  */
  YYSYMBOL_corefunc_param_part = 364,      /* corefunc_param_part  */
  YYSYMBOL_corefunc_param_list = 365,      /* corefunc_param_list  */
  YYSYMBOL_corefunc_params_list = 366,     /* corefunc_params_list  */
  YYSYMBOL_corefunc_stmt = 367,            /* corefunc_stmt  */
  YYSYMBOL_corefunc_int = 368,             /* corefunc_int  */
  YYSYMBOL_corefunc_str = 369,             /* corefunc_str  */
  YYSYMBOL_corefunc_coord = 370,           /* corefunc_coord  */
  YYSYMBOL_corefunc_region = 371,          /* corefunc_region  */
  YYSYMBOL_ter_selection_x = 372,          /* ter_selection_x  */
  YYSYMBOL_ter_selection = 373,            /* ter_selection  */
  YYSYMBOL_dice = 374,                     /* dice  */
  YYSYMBOL_all_integers = 375,             /* all_integers  */
  YYSYMBOL_all_ints_push = 376,            /* all_ints_push  */
  YYSYMBOL_objectid = 377,                 /* objectid  */
  YYSYMBOL_monsterid = 378,                /* monsterid  */
  YYSYMBOL_terrainid = 379,                /* terrainid  */
  YYSYMBOL_engraving_type = 380,           /* engraving_type  */
  YYSYMBOL_lev_region = 381,               /* lev_region  */
  YYSYMBOL_region = 382                    /* region  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  200
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  183
/* YYNRULES -- Number of rules.  */
#define YYNRULES  460
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  976

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   437


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   195,   199,     2,
     139,   140,   193,   191,   137,   192,   197,   194,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   138,     2,
       2,   196,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   141,     2,   142,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,   198,   144,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   283,   283,   284,   287,   288,   291,   292,   296,   303,
     304,   307,   329,   355,   364,   373,   377,   381,   407,   410,
     417,   421,   428,   431,   438,   439,   443,   446,   454,   458,
     465,   468,   474,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   554,   555,   556,   559,   560,   563,   575,   581,   587,
     593,   599,   605,   611,   617,   623,   630,   637,   644,   651,
     658,   665,   674,   679,   686,   691,   698,   703,   710,   714,
     720,   725,   732,   736,   742,   746,   753,   775,   752,   789,
     834,   841,   844,   851,   854,   860,   866,   870,   879,   883,
     878,   940,   941,   945,   944,   957,   956,   971,   981,   982,
     985,  1018,  1017,  1043,  1042,  1072,  1071,  1102,  1101,  1127,
    1136,  1135,  1162,  1174,  1180,  1184,  1190,  1194,  1198,  1204,
    1211,  1220,  1228,  1239,  1238,  1254,  1253,  1270,  1273,  1279,
    1289,  1295,  1304,  1310,  1315,  1321,  1326,  1332,  1341,  1347,
    1348,  1351,  1352,  1355,  1359,  1365,  1366,  1369,  1375,  1381,
    1389,  1390,  1393,  1394,  1397,  1404,  1408,  1414,  1420,  1428,
    1432,  1438,  1444,  1453,  1458,  1457,  1471,  1478,  1484,  1492,
    1497,  1502,  1507,  1512,  1517,  1522,  1527,  1532,  1537,  1542,
    1547,  1552,  1557,  1562,  1567,  1574,  1581,  1585,  1598,  1605,
    1604,  1620,  1628,  1634,  1642,  1647,  1652,  1657,  1662,  1667,
    1672,  1677,  1682,  1687,  1698,  1703,  1708,  1713,  1718,  1725,
    1731,  1758,  1763,  1770,  1774,  1780,  1786,  1792,  1802,  1812,
    1827,  1837,  1840,  1846,  1852,  1858,  1864,  1869,  1876,  1882,
    1888,  1894,  1900,  1907,  1906,  1930,  1933,  1939,  1945,  1949,
    1954,  1961,  1967,  1974,  1978,  1984,  1992,  1995,  2005,  2009,
    2012,  2018,  2022,  2029,  2033,  2037,  2043,  2044,  2047,  2048,
    2051,  2052,  2053,  2059,  2060,  2061,  2067,  2068,  2071,  2080,
    2091,  2096,  2103,  2110,  2114,  2120,  2124,  2128,  2132,  2139,
    2148,  2154,  2158,  2164,  2168,  2176,  2180,  2187,  2196,  2205,
    2211,  2215,  2222,  2231,  2240,  2251,  2255,  2262,  2271,  2280,
    2289,  2298,  2304,  2308,  2315,  2324,  2328,  2335,  2345,  2354,
    2365,  2375,  2384,  2393,  2400,  2401,  2407,  2408,  2409,  2410,
    2411,  2417,  2425,  2433,  2434,  2435,  2436,  2437,  2438,  2441,
    2447,  2455,  2484,  2485,  2488,  2489,  2492,  2496,  2503,  2510,
    2521,  2524,  2532,  2536,  2540,  2544,  2548,  2552,  2559,  2566,
    2577,  2580,  2587,  2595,  2600,  2608,  2613,  2621,  2626,  2634,
    2639,  2647,  2651,  2655,  2659,  2663,  2668,  2672,  2676,  2680,
    2684,  2688,  2692,  2696,  2700,  2704,  2708,  2712,  2716,  2723,
    2729,  2733,  2739,  2745,  2746,  2747,  2750,  2754,  2758,  2762,
    2768,  2769,  2772,  2773,  2776,  2777,  2780,  2781,  2784,  2788,
    2806
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INTEGER",
  "BOOLEAN", "PERCENT", "SPERCENT", "MINUS_INTEGER", "PLUS_INTEGER",
  "MAZE_GRID_ID", "SOLID_FILL_ID", "MINES_ID", "SHEOL_ID", "ROGUELEV_ID",
  "MESSAGE_ID", "LEVEL_ID", "LEV_INIT_ID", "GEOMETRY_ID", "NOMAP_ID",
  "OBJECT_ID", "COBJECT_ID", "MONSTER_ID", "TRAP_ID", "DOOR_ID",
  "DRAWBRIDGE_ID", "object_ID", "monster_ID", "terrain_ID", "MAZEWALK_ID",
  "WALLIFY_ID", "REGION_ID", "FILLING", "IRREGULAR", "JOINED", "ALTAR_ID",
  "LADDER_ID", "STAIR_ID", "NON_DIGGABLE_ID", "NON_PASSWALL_ID", "ROOM_ID",
  "PORTAL_ID", "TELEPRT_ID", "BRANCH_ID", "LEV", "CHANCE_ID",
  "MINERALIZE_ID", "CORRIDOR_ID", "GOLD_ID", "ENGRAVING_ID", "FOUNTAIN_ID",
  "POOL_ID", "SINK_ID", "NONE", "RAND_CORRIDOR_ID", "DOOR_STATE",
  "LIGHT_STATE", "CURSE_TYPE", "ENGRAVING_TYPE", "DIRECTION",
  "RANDOM_TYPE", "RANDOM_TYPE_BRACKET", "A_REGISTER", "ALIGNMENT",
  "LEFT_OR_RIGHT", "CENTER", "TOP_OR_BOT", "ALTAR_TYPE", "UP_OR_DOWN",
  "SUBROOM_ID", "NAME_ID", "FLAGS_ID", "FLAG_TYPE", "MON_ATTITUDE",
  "MON_ALERTNESS", "MON_APPEARANCE", "ROOMDOOR_ID", "IF_ID", "ELSE_ID",
  "SPILL_ID", "TERRAIN_ID", "HORIZ_OR_VERT", "REPLACE_TERRAIN_ID",
  "EXIT_ID", "SHUFFLE_ID", "QUANTITY_ID", "BURIED_ID", "LOOP_ID", "FOR_ID",
  "TO_ID", "SWITCH_ID", "CASE_ID", "BREAK_ID", "DEFAULT_ID", "ERODED_ID",
  "TRAPPED_STATE", "RECHARGED_ID", "INVIS_ID", "GREASED_ID", "FEMALE_ID",
  "CANCELLED_ID", "REVIVED_ID", "AVENGE_ID", "FLEEING_ID", "BLINDED_ID",
  "PARALYZED_ID", "STUNNED_ID", "CONFUSED_ID", "SEENTRAPS_ID", "ALL_ID",
  "MON_GENERATION_ID", "MONTYPE_ID", "GRAVE_ID", "ERODEPROOF_ID",
  "FUNCTION_ID", "INCLUDE_ID", "SOUNDS_ID", "MSG_OUTPUT_TYPE",
  "WALLWALK_ID", "COMPARE_TYPE", "VAULTGEN_ID", "rect_ID", "fillrect_ID",
  "line_ID", "randline_ID", "grow_ID", "selection_ID", "flood_ID",
  "rndcoord_ID", "circle_ID", "ellipse_ID", "filter_ID", "complement_ID",
  "gradient_ID", "GRADIENT_TYPE", "LIMITED", "HUMIDITY_TYPE", "','", "':'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "STRING", "MAP_ID", "NQSTRING",
  "VARSTRING", "CFUNC", "CFUNC_INT", "CFUNC_STR", "CFUNC_COORD",
  "CFUNC_REGION", "VARSTRING_INT", "VARSTRING_INT_ARRAY",
  "VARSTRING_STRING", "VARSTRING_STRING_ARRAY", "VARSTRING_VAR",
  "VARSTRING_VAR_ARRAY", "VARSTRING_COORD", "VARSTRING_COORD_ARRAY",
  "VARSTRING_REGION", "VARSTRING_REGION_ARRAY", "VARSTRING_MAPCHAR",
  "VARSTRING_MAPCHAR_ARRAY", "VARSTRING_MONST", "VARSTRING_MONST_ARRAY",
  "VARSTRING_OBJ", "VARSTRING_OBJ_ARRAY", "VARSTRING_SEL",
  "VARSTRING_SEL_ARRAY", "METHOD_INT", "METHOD_INT_ARRAY", "METHOD_STRING",
  "METHOD_STRING_ARRAY", "METHOD_VAR", "METHOD_VAR_ARRAY", "METHOD_COORD",
  "METHOD_COORD_ARRAY", "METHOD_REGION", "METHOD_REGION_ARRAY",
  "METHOD_MAPCHAR", "METHOD_MAPCHAR_ARRAY", "METHOD_MONST",
  "METHOD_MONST_ARRAY", "METHOD_OBJ", "METHOD_OBJ_ARRAY", "METHOD_SEL",
  "METHOD_SEL_ARRAY", "DICE", "'+'", "'-'", "'*'", "'/'", "'%'", "'='",
  "'.'", "'|'", "'&'", "$accept", "file", "header_stmts", "header_stmt",
  "include_def", "levels", "level", "level_def", "lev_init", "opt_limited",
  "opt_coord_or_var", "opt_fillchar", "walled", "flags", "flag_list",
  "levstatements", "stmt_block", "levstatement", "any_var_array",
  "any_var", "any_var_or_arr", "any_var_or_unk", "shuffle_detail",
  "variable_define", "encodeobj_list", "encodemonster_list",
  "mapchar_list", "encoderegion_list", "encodecoord_list", "integer_list",
  "string_list", "function_define", "$@1", "$@2", "function_call",
  "exitstatement", "opt_percent", "opt_spercent", "comparestmt",
  "switchstatement", "$@3", "$@4", "switchcases", "switchcase", "$@5",
  "$@6", "breakstatement", "for_to_span", "forstmt_start", "forstatement",
  "$@7", "loopstatement", "$@8", "chancestatement", "$@9", "ifstatement",
  "$@10", "if_ending", "$@11", "vaultgen_stmt", "message",
  "wallwalk_detail", "random_corridors", "corridor", "corr_spec",
  "room_begin", "subroom_def", "$@12", "room_def", "$@13", "roomfill",
  "room_pos", "subroom_pos", "room_align", "room_size", "door_detail",
  "secret", "door_wall", "dir_list", "door_pos", "map_definition",
  "h_justif", "v_justif", "sounds_detail", "sounds_list", "lvl_sound_part",
  "mon_generation", "mon_gen_list", "mon_gen_part", "monster_detail",
  "$@14", "monster_desc", "monster_infos", "monster_info",
  "seen_trap_mask", "object_detail", "$@15", "object_desc", "object_infos",
  "object_info", "trap_detail", "drawbridge_detail", "mazewalk_detail",
  "wallify_detail", "ladder_detail", "stair_detail", "stair_region",
  "portal_region", "teleprt_region", "branch_region", "teleprt_detail",
  "fountain_detail", "sink_detail", "pool_detail", "terrain_type",
  "replace_terrain_detail", "terrain_detail", "spill_detail",
  "diggable_detail", "passwall_detail", "region_detail", "@16",
  "region_detail_end", "altar_detail", "grave_detail", "gold_detail",
  "engraving_detail", "mineralize", "trap_name", "room_type",
  "optroomregionflags", "roomregionflags", "roomregionflag", "door_state",
  "light_state", "alignment", "alignment_prfx", "altar_type", "a_register",
  "monster", "string_or_var", "integer_or_var", "coord_or_var",
  "encodecoord", "humidity_flags", "region_or_var", "encoderegion",
  "mapchar_or_var", "mapchar", "monster_or_var", "encodemonster",
  "object_or_var", "xobject_or_var", "encodexobj", "encodeobj",
  "string_expr", "math_expr_var", "func_param_type", "func_param_part",
  "func_param_list", "func_params_list", "func_call_param_part",
  "func_call_param_list", "func_call_params_list", "corefunc_param_part",
  "corefunc_param_list", "corefunc_params_list", "corefunc_stmt",
  "corefunc_int", "corefunc_str", "corefunc_coord", "corefunc_region",
  "ter_selection_x", "ter_selection", "dice", "all_integers",
  "all_ints_push", "objectid", "monsterid", "terrainid", "engraving_type",
  "lev_region", "region", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-766)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-225)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   -64,   -58,   140,   154,   147,  -766,  -766,    42,  -766,
    -766,    38,  -766,   154,   116,  -766,  -766,    46,  -766,    79,
     832,   801,  -766,   149,  -766,    89,    97,   137,  -766,   152,
     170,   191,   216,   224,   239,   242,   245,   247,   250,   263,
     267,   273,   281,   287,   290,   302,   304,   318,   324,   333,
     334,   337,   340,   349,   355,   358,   365,    13,   367,   368,
     370,  -766,   371,   211,   775,  -766,  -766,   383,   384,   398,
     399,   404,   101,   271,  -766,   373,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,   832,  -766,  -766,   178,
    -766,  -766,  -766,  -766,  -766,   406,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,   418,  -766,   387,   417,   421,  -766,   359,   293,   374,
     261,   261,   103,   -31,     7,   386,   386,   893,   414,   386,
     386,   284,   414,   414,   -27,   -16,   -16,   -16,   101,   431,
     101,   386,   893,   893,   893,   339,   -27,    37,  -766,   386,
     893,   414,   651,   101,  -766,  -766,   364,   425,   572,   386,
     101,   386,   576,  -766,   214,   442,  -766,   441,  -766,  -766,
     413,  -766,  -766,    56,   329,  -766,   298,  -766,   443,   115,
     801,  -766,   149,  -766,   449,  -766,   451,  -766,   396,  -766,
     457,   472,   473,  -766,  -766,  -766,   475,  -766,  -766,   476,
     610,   478,  -766,   483,   493,   502,  -766,  -766,  -766,  -766,
     646,  -766,  -766,   514,  -766,  -766,  -766,  -766,  -766,  -766,
     660,  -766,  -766,   526,   527,   536,  -766,  -766,  -766,   538,
    -766,  -766,   539,   541,   542,   414,   414,   386,   386,   544,
     386,   545,   547,   548,   893,   549,   634,  -766,  -766,   481,
    -766,   677,   550,  -766,   552,   553,  -766,  -766,   560,   564,
     568,   687,   595,   602,  -766,  -766,  -766,  -766,  -766,   603,
     737,   740,   615,   616,   617,   623,   453,   765,   633,   202,
     635,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,   637,
    -766,  -766,   638,   443,   639,   640,   641,  -766,   629,   101,
     101,   642,   648,   650,   652,  -766,   653,   405,   329,   101,
     101,  -766,   101,   101,   101,   101,   101,   396,   453,  -766,
     654,   656,  -766,  -766,  -766,  -766,    18,  -766,   647,  -766,
    -766,  -766,  -766,   396,   453,   661,  -766,   657,   667,   669,
    -766,  -766,   671,   237,    43,  -766,  -766,   396,   453,   673,
     675,   679,   832,   832,  -766,  -766,  -766,  -766,  -766,   443,
    -766,   329,   101,   359,   787,    27,   812,   684,   681,   893,
     691,   329,   101,   235,   819,   683,   693,   101,   694,   443,
     695,   101,   443,   386,   386,   893,   774,   776,  -766,  -766,
     644,   645,   766,  -766,   386,   386,   504,  -766,   700,   699,
     893,   704,   329,   101,    66,   303,   780,   838,   706,   791,
     -16,   -11,  -766,   707,   723,   -16,   -16,   -16,   101,   727,
     108,   386,    78,    -9,     7,   788,  -766,    40,    40,    40,
    -766,   272,   734,   726,   -10,   738,    40,  -766,  -766,   745,
     427,   459,   238,   238,  -766,  -766,  -766,    56,  -766,   755,
     763,   101,   329,  -766,   757,    35,   893,   -78,   -66,   -36,
      34,  -766,  -766,   396,   453,    91,   236,   124,  -766,   759,
    -766,   764,   524,  -766,  -766,  -766,   903,  -766,   770,   475,
    -766,   773,   906,   777,   530,  -766,  -766,   502,  -766,  -766,
     783,   535,    64,  -766,   785,   543,  -766,  -766,  -766,  -766,
     784,   795,   386,   386,   736,   803,   798,   810,   814,  -766,
     837,   581,  -766,   834,   839,  -766,   840,   841,  -766,  -766,
     921,   842,   554,  -766,  -766,   846,  -766,   843,  -766,   848,
    -766,  -766,   867,  1001,  -766,   869,  -766,  1003,   871,    66,
    1005,   873,   874,  -766,   875,   954,  -766,  -766,  -766,  -766,
    -766,   882,  -766,  1025,   894,   896,   952,  1031,   898,  -766,
     899,   443,  -766,   844,   101,  -766,   101,  -766,   900,  -766,
     396,   925,  -766,   907,   909,  -766,  -766,  -766,  -766,   902,
    1039,   589,  -766,  -766,  -766,  -766,   -74,  -766,   -24,  -766,
     101,  -766,   359,  -766,   104,  -766,    35,  -766,    28,  -766,
    -766,  -766,  -766,   911,  1046,  -766,  -766,   910,  -766,  -766,
     905,   912,  -766,  -766,  -766,  -766,  -766,  -766,  -766,   917,
     918,  -766,   919,  -766,   920,  -766,  -766,   922,  -766,  -766,
    -766,  -766,  -766,   934,  -766,   924,     7,  1054,  -766,   938,
    1017,   893,  -766,   101,   101,   893,   940,   101,   893,   893,
     939,   942,  -766,  -766,   -27,  1076,   142,  1077,   -38,  1014,
     946,    -8,  -766,   947,   941,  1019,  -766,   101,   948,   359,
     951,    -7,   256,   443,  1030,    40,  -766,  -766,   453,   949,
     953,   726,   956,   738,    93,  -766,   955,    49,  -766,  -766,
    -766,   453,   396,    82,  -766,    94,  -766,   100,  -766,    66,
     957,  -766,  -766,  -766,   359,   101,   101,   101,   103,  -766,
     965,  -766,   959,   101,  -766,   958,   336,   357,   960,    66,
     608,   961,   962,   101,  1087,   966,   963,  -766,  -766,  -766,
     967,  1093,  -766,  1095,  -766,   258,   969,  -766,  -766,   970,
      53,   396,  1104,  -766,  1105,   966,  -766,   974,  -766,  -766,
     975,   976,   244,    24,  -766,   359,  -766,  -766,   977,  -766,
     104,  -766,    35,  -766,    28,  -766,   978,  1110,   396,  -766,
    -766,  -766,  -766,   232,  -766,  -766,  -766,   359,  -766,  -766,
    -766,  -766,  -766,   979,   981,   982,  -766,  -766,   985,  -766,
    -766,  -766,   396,  1121,  -766,   453,  -766,  1094,  -766,   101,
    -766,   987,  -766,  -766,  -766,   466,   988,   507,  -766,  -766,
    1124,   992,   990,   994,    -7,   101,  -766,  -766,   993,   995,
     997,  -766,    53,   101,  1125,    73,   998,   996,   244,  -766,
     999,  1002,   -86,  1130,  -766,  -766,  -766,  -766,  -766,  1004,
    1078,   396,   101,   101,   101,   -70,  -766,  1006,   380,  -766,
     101,  1139,  -766,  -766,  -766,  -766,  1007,   443,  1008,  1143,
    -766,   235,   966,  -766,  -766,  -766,  1144,   443,  -766,   453,
    -766,  1011,  -766,  -766,  -766,  -766,  -766,  -766,  1145,  -766,
    -766,  -766,  -766,  -766,   964,  -766,  -766,  1119,  -766,   220,
    1012,   507,  -766,  -766,  1149,  1015,  1016,  -766,  1018,  -766,
    -766,   832,  1020,   -70,  1021,  1024,  1023,  -766,  -766,  1026,
    -766,  -766,   443,  -766,   832,  -766,    66,  -766,  -766,  -766,
    1027,  -766,  -766,  -766,  1028,   386,    50,  1032,  -766,  -766,
     959,   386,  1033,  -766,  -766,  -766
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     0,     0,     0,     2,     4,     7,     6,     0,     8,
       1,     0,     3,     9,    26,     5,   136,     0,    10,     0,
      30,   394,    12,     0,   145,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,   140,     0,     0,     0,   148,   157,     0,     0,     0,
       0,     0,     0,     0,   103,     0,    92,    83,    93,    84,
      94,    85,    95,    86,    96,    87,    97,    88,    98,    89,
      99,    90,   100,    91,    34,    11,    30,   101,   102,     0,
      42,    41,    58,    59,    56,     0,    51,    57,   161,    52,
      53,    55,    54,    61,    33,    45,    70,    40,    73,    72,
      44,    63,    38,    37,    65,    66,    81,    46,    64,    82,
      62,    78,    79,    69,    80,    39,    49,    74,    68,    76,
      75,    77,    43,    67,    71,    35,    36,    50,    47,    48,
      60,     0,   392,   395,     0,    29,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   376,     0,   413,   381,     0,   380,   442,
       0,   379,   377,   400,   410,    31,     0,   165,     0,     0,
       0,   137,     0,   330,   415,   331,     0,   374,   173,   333,
       0,     0,     0,    15,    16,   341,     0,   210,   211,     0,
       0,   417,   338,     0,     0,   187,   335,   336,   371,   373,
       0,   370,   363,     0,   248,   252,   362,   249,   359,   361,
       0,   358,   356,     0,   223,     0,   355,   306,   305,     0,
     316,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   421,   440,
     274,     0,   419,   346,     0,     0,   345,   349,     0,     0,
       0,     0,     0,     0,   458,   291,   292,   308,   307,     0,
     141,     0,     0,     0,     0,     0,   334,     0,     0,     0,
       0,   283,   285,   284,   445,   443,   444,   178,   177,     0,
     199,   200,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,   300,     0,     0,   172,     0,     0,   410,     0,
       0,   147,     0,     0,     0,     0,     0,   397,   396,   398,
     401,     0,   451,   453,   450,   452,     0,   366,     0,   405,
     406,   404,   365,   403,   402,   408,   411,     0,     0,     0,
     454,   455,     0,     0,     0,   113,   114,   109,   107,     0,
       0,     0,     0,    30,   162,   389,   390,   391,   393,     0,
      28,   410,     0,     0,     0,     0,     0,   343,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   422,   423,
       0,     0,     0,   431,     0,     0,     0,   437,     0,     0,
       0,     0,   410,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   168,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,   378,   388,     0,
       0,     0,   383,   384,   385,   386,   387,     0,   139,     0,
     376,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,   130,   128,   134,   132,     0,     0,     0,   166,     0,
     138,     0,     0,   375,    14,   286,     0,    13,     0,     0,
     342,     0,     0,     0,     0,   213,   212,   187,   188,   209,
       0,     0,     0,   250,     0,     0,   225,   227,   269,   198,
       0,   271,     0,     0,   203,     0,     0,     0,     0,   353,
       0,     0,   351,     0,     0,   350,     0,     0,   439,   441,
       0,     0,     0,   318,   319,     0,   322,     0,   320,     0,
     321,   275,     0,     0,   276,     0,   190,     0,     0,     0,
       0,     0,   281,   280,     0,     0,   179,   180,   301,   456,
     457,     0,   192,     0,     0,     0,     0,     0,     0,   289,
       0,     0,   159,     0,     0,   149,     0,   218,   219,   299,
     298,     0,   214,   215,   143,   414,   382,   146,   399,     0,
       0,     0,   409,   369,   407,   108,     0,   117,     0,   116,
       0,   115,     0,   121,     0,   112,     0,   111,     0,   110,
      32,   416,   332,     0,     0,   344,   337,     0,   418,   339,
       0,     0,   364,   448,   446,   447,   263,   260,   254,     0,
       0,   259,     0,   264,     0,   266,   267,     0,   262,   253,
     268,   449,   256,     0,   357,   226,     0,     0,   424,     0,
       0,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   347,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   158,   160,     0,
       0,     0,     0,     0,     0,   174,     0,     0,   367,   129,
     131,   133,   135,     0,   122,     0,   124,     0,   126,     0,
       0,   340,   208,   372,     0,     0,     0,     0,     0,   360,
       0,   270,    22,     0,   204,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   327,   326,   297,
       0,     0,   277,     0,   194,     0,     0,   278,   282,     0,
       0,   302,     0,   196,     0,   309,   202,     0,   201,   171,
       0,     0,   151,     0,   220,     0,   216,   144,   143,   368,
       0,   120,     0,   119,     0,   118,     0,     0,   257,   258,
     261,   265,   255,     0,   323,   230,   231,     0,   235,   234,
     236,   237,   238,     0,     0,     0,   242,   243,     0,   228,
     232,   324,   229,     0,   272,   425,   427,     0,   432,     0,
     428,     0,   352,   430,   429,     0,     0,     0,   293,   328,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   151,   329,
       0,     0,     0,     0,   175,   123,   125,   127,   287,     0,
       0,   233,     0,     0,     0,     0,    23,     0,     0,   354,
       0,     0,   313,   314,   315,   310,   311,   295,     0,     0,
     189,     0,   309,   303,   181,   191,     0,     0,   197,   290,
     288,     0,   155,   150,   152,   222,   221,   217,     0,   325,
     239,   240,   241,   246,   245,   244,   433,     0,   434,   384,
       0,     0,   296,   294,     0,     0,     0,   185,     0,   184,
     153,    30,     0,     0,     0,     0,     0,   348,   312,     0,
     460,   193,     0,   195,    30,   156,     0,   247,   435,    19,
       0,   459,   186,   154,     0,     0,     0,    20,    24,    25,
      22,     0,     0,    17,    21,   436
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -766,  -766,  1155,  -766,  -766,  1141,  -766,  -766,  -766,  -766,
    -766,   197,  -766,  -766,   950,   -96,  -329,   778,   983,  1107,
      -6,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,   139,  -766,  -766,  -766,  -766,  -766,   376,  1111,  -766,
    -766,  -766,   308,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,   717,  1000,  -766,  -766,  -766,  -766,
     655,  -766,  -766,  -766,   325,  -766,  -766,  -766,  -632,   316,
    -766,   408,   279,  -766,   458,  -766,  -766,   463,  -766,  -766,
    -766,  -766,  -766,  -766,   246,  -766,  -766,  1029,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,   491,
    -765,   257,  -766,  -456,  -574,  -766,  -766,  -766,   437,  -766,
     789,  -184,  -125,  -378,   672,   327,  -374,  -444,  -621,  -495,
    -488,   688,  -766,  -766,  -616,  -155,   -71,  -766,   980,  -766,
    -766,   708,  -766,  -766,  -766,   702,  -313,  -766,  -766,  -766,
    -766,  -766,   913,   -98,   664,  -457,  -766,   986,   989,  -766,
    -766,  -163,  -766
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,     5,     6,    12,    13,    14,    94,   946,
     972,   834,   970,    20,   156,    95,   394,    96,    97,    98,
      99,   196,   100,   101,   733,   735,   737,   497,   498,   499,
     500,   102,    21,   399,   103,   104,   453,   725,   105,   106,
     197,   719,   867,   868,   954,   941,   107,   604,   108,   109,
     218,   110,   601,   111,   392,   112,   333,   466,   596,   113,
     114,   115,   116,   117,   318,   309,   118,   907,   119,   952,
     415,   578,   594,   776,   785,   120,   332,   787,   545,   858,
     121,   244,   527,   122,   612,   613,   123,   607,   608,   124,
     422,   264,   675,   829,   925,   125,   419,   254,   418,   669,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     706,   136,   137,   138,   517,   139,   140,   141,   142,   143,
     144,   897,   933,   145,   146,   147,   148,   149,   269,   310,
     848,   895,   896,   272,   565,   569,   830,   769,   570,   871,
     227,   315,   288,   246,   408,   370,   296,   554,   555,   265,
     266,   255,   371,   372,   256,   373,   316,   397,   152,   153,
     154,   359,   360,   361,   375,   376,   377,   150,   211,   229,
     247,   297,   289,   439,   212,   328,   672,   378,   379,   391,
     591,   303,   304
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     215,   210,   228,   587,   465,   702,   501,   624,   595,   338,
     502,   637,   312,   313,   314,   151,   343,   738,   734,    24,
     861,   489,   490,   598,   599,   600,   346,   869,   300,   267,
     515,   549,   614,   307,   245,   479,   235,   236,   258,   923,
     273,   274,   330,   549,   298,   299,   302,   203,   754,   576,
     609,   592,   774,   783,   917,   968,   320,   856,   357,   626,
     203,   387,   270,   639,   334,   291,   627,   271,   653,   290,
     510,   628,   654,   655,   342,   924,   344,   324,   629,   292,
     788,   325,   326,     8,   321,   322,   323,     9,   511,   369,
     533,   385,   335,   536,   248,   259,   549,   331,   523,   771,
     797,   630,   741,   235,   236,   203,   258,   248,   631,   319,
     969,   403,   324,   857,   268,   240,   325,   326,   308,   656,
     657,   658,   563,   311,   235,   236,   564,   549,   577,   561,
     593,   775,   784,   347,   659,   223,   589,   937,   590,     7,
      10,   224,   358,   374,     7,   388,   225,   226,   736,   660,
     661,   249,   430,   431,    72,   433,   472,   204,   662,   663,
     664,   665,   666,   259,   249,   806,   516,   597,   205,   870,
      11,   632,   206,   207,   260,   667,    17,   668,   633,   597,
     261,    16,   383,   877,   875,   841,   764,    19,   223,   741,
     208,    22,   239,   205,   224,   204,   292,   206,   207,   225,
     226,   223,   767,   240,   552,   553,   205,   224,   209,   768,
     206,   207,   225,   226,   151,   208,   241,    23,   203,   800,
     751,   155,   346,   369,   242,   243,   801,   157,   208,   503,
     250,   802,   597,   209,   634,   158,   251,   804,   803,   258,
     204,   490,   260,   250,   805,   346,   209,   317,   261,   251,
     730,   205,   729,   812,   209,   206,   207,   552,   553,   252,
     253,     1,     2,   597,   248,   395,   396,   638,   471,   262,
     263,   791,   716,   208,   584,   159,   369,   374,   480,   481,
     798,   482,   483,   484,   485,   486,   369,   575,   552,   553,
     160,   209,   581,   582,   583,   347,   259,   509,   537,   538,
     525,   526,   203,   230,   231,   232,   233,   234,   161,   547,
     548,   521,   347,   504,   876,   544,   786,   369,   362,   610,
     363,   249,   237,   238,   364,   365,   380,   539,   300,   162,
     374,   512,   357,   203,   546,   865,   588,   866,   556,   461,
     374,   524,   559,   324,   235,   236,   531,   325,   326,   362,
     535,   363,   193,   204,   163,   364,   365,   945,   235,   236,
     -18,   602,   164,   566,   205,   567,   568,   369,   206,   207,
     880,   374,   562,   695,   216,   260,   204,   165,   381,   636,
     166,   261,   964,   167,   789,   168,   208,   205,   169,   235,
     236,   206,   207,   352,   353,   354,   355,   356,   625,   327,
     250,   170,   262,   263,   209,   171,   251,   670,   911,   208,
     213,   172,   239,   354,   355,   356,   358,   678,   679,   173,
     621,   374,   720,   301,   382,   174,   239,   209,   175,   252,
     253,   354,   355,   356,   235,   236,   241,   383,   237,   238,
     176,   384,   177,   223,   242,   243,   235,   236,   205,   224,
     241,   292,   206,   207,   225,   226,   178,   239,   242,   243,
     293,   294,   179,   352,   353,   354,   355,   356,   366,   603,
     208,   180,   181,   837,   223,   182,   838,   732,   183,   205,
     224,   241,   292,   206,   207,   225,   226,   184,   209,   242,
     243,   293,   294,   185,   839,   295,   186,   367,   368,   305,
     306,   208,   239,   187,   223,   189,   190,   549,   191,   192,
     224,   550,   214,   240,   239,   225,   226,   927,   336,   209,
     928,   198,   199,   779,   220,   240,   241,   352,   353,   354,
     355,   356,   350,   718,   242,   243,   200,   201,   241,   892,
     893,   894,   202,   386,   217,   478,   242,   243,   352,   353,
     354,   355,   356,   291,   781,   351,   219,   221,   222,   731,
     339,   809,   810,   811,   235,   236,   340,   292,   932,   616,
     317,   352,   353,   354,   355,   356,   293,   294,   939,   341,
     345,   348,   349,   755,   686,   410,   393,   758,   401,   808,
     761,   762,   402,   403,   404,   832,   352,   353,   354,   355,
     356,   617,   428,   429,   352,   353,   354,   355,   356,   405,
     406,   407,   756,   757,   410,   409,   760,   411,   352,   353,
     354,   355,   356,   962,   412,   275,   276,   277,   278,   279,
     413,   280,   239,   281,   282,   283,   284,   285,   410,   414,
     872,   235,   236,   551,   352,   353,   354,   355,   356,   416,
     352,   353,   354,   355,   356,   417,   241,   352,   890,   354,
     355,   356,   881,   420,   242,   243,   642,   421,   552,   553,
    -224,   903,   649,   423,   287,   424,   425,   652,   426,   427,
     440,   441,   835,   432,   434,   674,   435,   436,   438,   442,
     444,   448,   845,   443,   235,   236,   693,   445,   920,   921,
     922,   446,   275,   276,   277,   278,   279,   447,   280,   239,
     281,   282,   283,   284,   285,   352,   353,   354,   355,   356,
     286,   352,   353,   354,   355,   356,   352,   353,   354,   355,
     356,   728,   449,   241,   352,   353,   354,   355,   356,   450,
     451,   242,   243,   452,   454,   352,   353,   354,   355,   356,
     842,   287,   455,   456,   457,   275,   276,   277,   278,   279,
     458,   280,   239,   281,   282,   283,   284,   285,   888,   459,
     460,   470,   462,   286,   463,   464,   467,   468,   469,   473,
     352,   353,   354,   355,   356,   474,   241,   475,   491,   476,
     514,   487,   909,   477,   242,   243,   488,   493,   492,   352,
     353,   354,   355,   356,   287,   494,    77,   495,    79,   496,
      81,   505,    83,   506,    85,   518,    87,   507,    89,   929,
      91,   519,    93,   520,   528,   544,   235,   236,   522,   529,
     530,   532,   534,   540,   557,   541,   542,   543,    24,   558,
     967,   560,   572,   573,   579,   955,   974,    25,   571,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   963,   574,
     580,    35,    36,    37,   585,   606,  -170,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   605,   611,    47,    48,
      49,    50,    51,    52,    53,   615,    54,   275,   276,   277,
     278,   279,   619,   280,   239,   281,   282,   283,   284,   285,
     620,    55,   623,   640,   641,   286,   643,   644,    56,    57,
     647,    58,    59,   646,    60,    61,    62,   648,   241,    63,
      64,   676,    65,   194,    66,   691,   242,   243,   651,    76,
     673,    78,   677,    80,   680,    82,   287,    84,   682,    86,
     681,    88,    67,    90,    68,    92,     1,   683,    69,    74,
      70,   684,    71,   235,   236,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    72,   685,   687,   688,   689,   690,    73,
      74,    75,   692,   694,   695,   696,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   697,   698,   699,   700,   701,   703,
     704,   705,   707,   708,   275,   276,   277,   278,   279,   709,
     280,   239,   281,   282,   283,   284,   285,   813,   814,   710,
     713,   711,   286,   712,   686,   714,   715,   721,   815,   816,
     817,   717,   722,   727,   723,   241,   724,   726,   739,   740,
     741,   742,   743,   242,   243,   744,   745,   746,   747,   752,
     748,   750,   818,   287,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   749,   753,   544,   759,   763,   764,
     766,   770,   772,   773,   771,   780,   777,   778,   782,   790,
     793,   846,   792,   795,   807,   799,   833,   851,   836,   852,
     840,   843,   844,   847,   850,   849,   854,   855,   859,   860,
     223,   862,   863,   864,   873,   879,   224,   882,   878,   883,
     884,   225,   226,   885,   886,   891,   887,   889,   898,   899,
     900,   901,   910,   904,   906,   905,   912,   797,   919,   915,
     913,   918,   916,   930,   931,   934,   926,   935,   938,   940,
     942,   944,   947,   949,    18,   950,   951,   956,   953,   959,
      15,   958,   943,   960,   965,   966,   961,   973,   188,   971,
     508,   195,   400,   975,   874,   337,   914,   586,   908,   902,
     936,   796,   650,   853,   794,   765,   329,   831,   948,   957,
     257,   645,   513,   635,   622,   618,   671,   437,     0,     0,
     398,     0,   389,     0,     0,   390
};

static const yytype_int16 yycheck[] =
{
      96,    72,   157,   460,   333,   579,   384,   495,   464,   193,
     384,   506,   175,   176,   177,    21,   200,   638,   634,     6,
     785,     3,     4,   467,   468,   469,     8,     3,    44,    60,
       3,     3,   476,    60,   159,   348,    60,    61,     3,   109,
     165,   166,     5,     3,   169,   170,   171,     4,   680,    60,
      60,    60,    60,    60,   140,     5,   181,     4,   213,   137,
       4,   216,    55,   507,   189,   139,   144,    60,     4,   167,
     399,   137,     8,     9,   199,   145,   201,     4,   144,   153,
     712,     8,     9,   147,   182,   183,   184,   145,   401,   214,
     419,   216,   190,   422,     3,    60,     3,    60,   411,   137,
       7,   137,   140,    60,    61,     4,     3,     3,   144,   180,
      60,   197,     4,    60,   145,   139,     8,     9,   145,    55,
      56,    57,    56,   139,    60,    61,    60,     3,   139,   442,
     139,   139,   139,   204,    70,   145,    58,   902,    60,     0,
       0,   151,   213,   214,     5,   216,   156,   157,   636,    85,
      86,    60,   277,   278,   141,   280,   340,   139,    94,    95,
      96,    97,    98,    60,    60,   739,   139,   139,   150,   145,
      16,   137,   154,   155,   139,   111,   138,   113,   144,   139,
     145,   139,   139,   804,   800,   759,   137,    71,   145,   140,
     172,   145,   128,   150,   151,   139,   153,   154,   155,   156,
     157,   145,    60,   139,   164,   165,   150,   151,   190,    67,
     154,   155,   156,   157,   220,   172,   152,   138,     4,   137,
     676,    72,     8,   348,   160,   161,   144,   138,   172,   384,
     139,   137,   139,   190,   143,   138,   145,   137,   144,     3,
     139,     4,   139,   139,   144,     8,   190,   139,   145,   145,
     628,   150,   626,   748,   190,   154,   155,   164,   165,   168,
     169,   114,   115,   139,     3,   150,   151,   143,   339,   166,
     167,   715,   601,   172,   458,   138,   401,   348,   349,   350,
     724,   352,   353,   354,   355,   356,   411,   450,   164,   165,
     138,   190,   455,   456,   457,   366,    60,   393,   423,   424,
      65,    66,     4,    10,    11,    12,    13,    14,   138,   434,
     435,   409,   383,   384,   802,    59,    60,   442,    20,   474,
      22,    60,    64,    65,    26,    27,    28,   425,    44,   138,
     401,   402,   487,     4,   432,    91,   461,    93,   436,   137,
     411,   412,   440,     4,    60,    61,   417,     8,     9,    20,
     421,    22,   141,   139,   138,    26,    27,   137,    60,    61,
     140,    89,   138,    60,   150,    62,    63,   492,   154,   155,
     138,   442,   443,   141,   196,   139,   139,   138,    80,   143,
     138,   145,   956,   138,   713,   138,   172,   150,   138,    60,
      61,   154,   155,   191,   192,   193,   194,   195,   496,    60,
     139,   138,   166,   167,   190,   138,   145,   532,   865,   172,
     139,   138,   128,   193,   194,   195,   487,   542,   543,   138,
     491,   492,   606,   139,   126,   138,   128,   190,   138,   168,
     169,   193,   194,   195,    60,    61,   152,   139,    64,    65,
     138,   143,   138,   145,   160,   161,    60,    61,   150,   151,
     152,   153,   154,   155,   156,   157,   138,   128,   160,   161,
     162,   163,   138,   191,   192,   193,   194,   195,   139,   197,
     172,   138,   138,   137,   145,   138,   140,   632,   138,   150,
     151,   152,   153,   154,   155,   156,   157,   138,   190,   160,
     161,   162,   163,   138,   137,   168,   138,   168,   169,   172,
     173,   172,   128,   138,   145,   138,   138,     3,   138,   138,
     151,     7,   139,   139,   128,   156,   157,   137,   191,   190,
     140,   138,   138,   707,   137,   139,   152,   191,   192,   193,
     194,   195,   119,   604,   160,   161,   138,   138,   152,    32,
      33,    34,   138,   216,   138,   140,   160,   161,   191,   192,
     193,   194,   195,   139,   709,   142,   138,   140,   137,   630,
     196,   745,   746,   747,    60,    61,   141,   153,   897,   142,
     139,   191,   192,   193,   194,   195,   162,   163,   907,     7,
       4,   139,   141,   681,     3,     4,   143,   685,   139,   744,
     688,   689,   141,   197,   137,   750,   191,   192,   193,   194,
     195,   142,   275,   276,   191,   192,   193,   194,   195,   137,
     137,   136,   683,   684,     4,   139,   687,   139,   191,   192,
     193,   194,   195,   952,   141,   121,   122,   123,   124,   125,
     137,   127,   128,   129,   130,   131,   132,   133,     4,   137,
     795,    60,    61,   139,   191,   192,   193,   194,   195,     3,
     191,   192,   193,   194,   195,   141,   152,   191,   192,   193,
     194,   195,   817,     3,   160,   161,   142,   141,   164,   165,
     143,   855,   142,   137,   170,   137,   137,   142,   137,   137,
     199,     4,   753,   139,   139,   142,   139,   139,   139,   139,
     137,     4,   763,   141,    60,    61,   142,   137,   882,   883,
     884,   137,   121,   122,   123,   124,   125,   139,   127,   128,
     129,   130,   131,   132,   133,   191,   192,   193,   194,   195,
     139,   191,   192,   193,   194,   195,   191,   192,   193,   194,
     195,   142,   137,   152,   191,   192,   193,   194,   195,   137,
     137,   160,   161,     6,     4,   191,   192,   193,   194,   195,
     142,   170,   137,   137,   137,   121,   122,   123,   124,   125,
     137,   127,   128,   129,   130,   131,   132,   133,   839,     4,
     137,   142,   137,   139,   137,   137,   137,   137,   137,   137,
     191,   192,   193,   194,   195,   137,   152,   137,   141,   137,
       3,   137,   863,   140,   160,   161,   140,   140,   137,   191,
     192,   193,   194,   195,   170,   138,   155,   138,   157,   138,
     159,   138,   161,   138,   163,     3,   165,   138,   167,   890,
     169,   137,   171,   142,     5,    59,    60,    61,   137,   146,
     137,   137,   137,    59,   134,    59,   192,   192,     6,   140,
     965,   137,     4,   137,   137,   941,   971,    15,    68,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   954,    68,
     137,    29,    30,    31,   137,   139,    78,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   142,   139,    46,    47,
      48,    49,    50,    51,    52,   140,    54,   121,   122,   123,
     124,   125,   137,   127,   128,   129,   130,   131,   132,   133,
     137,    69,   145,   144,   140,   139,     3,   137,    76,    77,
       4,    79,    80,   140,    82,    83,    84,   140,   152,    87,
      88,   137,    90,   148,    92,     4,   160,   161,   145,   154,
     145,   156,   137,   158,   198,   160,   170,   162,   140,   164,
     137,   166,   110,   168,   112,   170,   114,   137,   116,   148,
     118,   137,   120,    60,    61,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   141,   137,   141,   137,   137,   137,   147,
     148,   149,   140,   137,   141,   137,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   137,     4,   137,     4,   137,     4,
     137,   137,   137,    59,   121,   122,   123,   124,   125,   137,
     127,   128,   129,   130,   131,   132,   133,    62,    63,     4,
      78,   137,   139,   137,     3,   137,   137,   137,    73,    74,
      75,   197,   117,     4,   137,   152,   137,   145,   137,     3,
     140,   146,   140,   160,   161,   138,   138,   138,   138,     5,
     138,   137,    97,   170,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   140,   137,    59,   137,   139,   137,
       4,     4,    68,   137,   137,   137,   145,    68,   137,    59,
     137,     4,   143,   137,   137,   140,   137,     4,   140,     4,
     140,   140,   140,   137,   137,   142,   137,   137,     4,     4,
     145,   137,   137,   137,   137,     5,   151,   138,   140,   138,
     138,   156,   157,   138,     3,   137,    32,   140,     4,   137,
     140,   137,     7,   140,   137,   140,   138,     7,    60,   140,
     144,   137,   140,     4,   137,   137,   140,     4,     4,   138,
       5,    32,   140,     4,    13,   140,   140,   137,   140,   135,
       5,   140,   198,   140,   137,   137,   140,   970,    57,   137,
     392,    64,   222,   140,   798,   192,   868,   460,   862,   854,
     901,   723,   527,   775,   721,   694,   186,   750,   931,   943,
     161,   519,   403,   505,   492,   487,   532,   284,    -1,    -1,
     220,    -1,   216,    -1,    -1,   216
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   114,   115,   201,   202,   203,   204,   231,   147,   145,
       0,    16,   205,   206,   207,   202,   139,   138,   205,    71,
     213,   232,   145,   138,     6,    15,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    29,    30,    31,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    46,    47,    48,
      49,    50,    51,    52,    54,    69,    76,    77,    79,    80,
      82,    83,    84,    87,    88,    90,    92,   110,   112,   116,
     118,   120,   141,   147,   148,   149,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   208,   215,   217,   218,   219,   220,
     222,   223,   231,   234,   235,   238,   239,   246,   248,   249,
     251,   253,   255,   259,   260,   261,   262,   263,   266,   268,
     275,   280,   283,   286,   289,   295,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   311,   312,   313,   315,
     316,   317,   318,   319,   320,   323,   324,   325,   326,   327,
     367,   220,   358,   359,   360,    72,   214,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   238,   138,
     138,   138,   138,   141,   148,   219,   221,   240,   138,   138,
     138,   138,   138,     4,   139,   150,   154,   155,   172,   190,
     356,   368,   374,   139,   139,   215,   196,   138,   250,   138,
     137,   140,   137,   145,   151,   156,   157,   340,   355,   369,
      10,    11,    12,    13,    14,    60,    61,    64,    65,   128,
     139,   152,   160,   161,   281,   342,   343,   370,     3,    60,
     139,   145,   168,   169,   297,   351,   354,   297,     3,    60,
     139,   145,   166,   167,   291,   349,   350,    60,   145,   328,
      55,    60,   333,   342,   342,   121,   122,   123,   124,   125,
     127,   129,   130,   131,   132,   133,   139,   170,   342,   372,
     373,   139,   153,   162,   163,   345,   346,   371,   342,   342,
      44,   139,   342,   381,   382,   345,   345,    60,   145,   265,
     329,   139,   381,   381,   381,   341,   356,   139,   264,   356,
     342,   373,   373,   373,     4,     8,     9,    60,   375,   265,
       5,    60,   276,   256,   342,   373,   345,   218,   341,   196,
     141,     7,   342,   341,   342,     4,     8,   356,   139,   141,
     119,   142,   191,   192,   193,   194,   195,   355,   356,   361,
     362,   363,    20,    22,    26,    27,   139,   168,   169,   342,
     345,   352,   353,   355,   356,   364,   365,   366,   377,   378,
      28,    80,   126,   139,   143,   342,   345,   355,   356,   377,
     378,   379,   254,   143,   216,   150,   151,   357,   358,   233,
     214,   139,   141,   197,   137,   137,   137,   136,   344,   139,
       4,   139,   141,   137,   137,   270,     3,   141,   298,   296,
       3,   141,   290,   137,   137,   137,   137,   137,   345,   345,
     342,   342,   139,   342,   139,   139,   139,   372,   139,   373,
     199,     4,   139,   141,   137,   137,   137,   139,     4,   137,
     137,   137,     6,   236,     4,   137,   137,   137,   137,     4,
     137,   137,   137,   137,   137,   216,   257,   137,   137,   137,
     142,   356,   341,   137,   137,   137,   137,   140,   140,   366,
     356,   356,   356,   356,   356,   356,   356,   137,   140,     3,
       4,   141,   137,   140,   138,   138,   138,   227,   228,   229,
     230,   343,   346,   355,   356,   138,   138,   138,   217,   215,
     216,   366,   356,   340,     3,     3,   139,   314,     3,   137,
     142,   373,   137,   366,   356,    65,    66,   282,     5,   146,
     137,   356,   137,   216,   137,   356,   216,   342,   342,   373,
      59,    59,   192,   192,    59,   278,   373,   342,   342,     3,
       7,   139,   164,   165,   347,   348,   373,   134,   140,   373,
     137,   366,   356,    56,    60,   334,    60,    62,    63,   335,
     338,    68,     4,   137,    68,   381,    60,   139,   271,   137,
     137,   381,   381,   381,   341,   137,   264,   375,   342,    58,
      60,   380,    60,   139,   272,   333,   258,   139,   347,   347,
     347,   252,    89,   197,   247,   142,   139,   287,   288,    60,
     355,   139,   284,   285,   347,   140,   142,   142,   361,   137,
     137,   356,   365,   145,   350,   373,   137,   144,   137,   144,
     137,   144,   137,   144,   143,   351,   143,   349,   143,   347,
     144,   140,   142,     3,   137,   344,   140,     4,   140,   142,
     270,   145,   142,     4,     8,     9,    55,    56,    57,    70,
      85,    86,    94,    95,    96,    97,    98,   111,   113,   299,
     342,   374,   376,   145,   142,   292,   137,   137,   342,   342,
     198,   137,   140,   137,   137,   137,     3,   141,   137,   137,
     137,     4,   140,   142,   137,   141,   137,   137,     4,   137,
       4,   137,   334,     4,   137,   137,   310,   137,    59,   137,
       4,   137,   137,    78,   137,   137,   216,   197,   356,   241,
     341,   137,   117,   137,   137,   237,   145,     4,   142,   346,
     343,   356,   355,   224,   354,   225,   350,   226,   348,   137,
       3,   140,   146,   140,   138,   138,   138,   138,   138,   140,
     137,   333,     5,   137,   278,   373,   356,   356,   373,   137,
     356,   373,   373,   139,   137,   329,     4,    60,    67,   337,
       4,   137,    68,   137,    60,   139,   273,   145,    68,   341,
     137,   355,   137,    60,   139,   274,    60,   277,   278,   216,
      59,   347,   143,   137,   287,   137,   284,     7,   347,   140,
     137,   144,   137,   144,   137,   144,   334,   137,   355,   341,
     341,   341,   349,    62,    63,    73,    74,    75,    97,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   293,
     336,   338,   355,   137,   211,   356,   140,   137,   140,   137,
     140,   334,   142,   140,   140,   356,     4,   137,   330,   142,
     137,     4,     4,   281,   137,   137,     4,    60,   279,     4,
       4,   330,   137,   137,   137,    91,    93,   242,   243,     3,
     145,   339,   355,   137,   237,   354,   350,   348,   140,     5,
     138,   355,   138,   138,   138,   138,     3,    32,   356,   140,
     192,   137,    32,    33,    34,   331,   332,   321,     4,   137,
     140,   137,   274,   341,   140,   140,   137,   267,   279,   356,
       7,   375,   138,   144,   242,   140,   140,   140,   137,    60,
     341,   341,   341,   109,   145,   294,   140,   137,   140,   356,
       4,   137,   216,   322,   137,     4,   282,   330,     4,   216,
     138,   245,     5,   198,    32,   137,   209,   140,   331,     4,
     140,   140,   269,   140,   244,   215,   137,   294,   140,   135,
     140,   140,   216,   215,   334,   137,   137,   342,     5,    60,
     212,   137,   210,   211,   342,   140
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   200,   201,   201,   202,   202,   203,   203,   204,   205,
     205,   206,   207,   208,   208,   208,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   220,   220,   220,   221,   221,   222,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   232,   233,   231,   234,
     235,   236,   236,   237,   237,   238,   238,   238,   240,   241,
     239,   242,   242,   244,   243,   245,   243,   246,   247,   247,
     248,   250,   249,   252,   251,   254,   253,   256,   255,   257,
     258,   257,   259,   260,   261,   261,   262,   262,   262,   263,
     263,   264,   265,   267,   266,   269,   268,   270,   270,   271,
     271,   272,   272,   273,   273,   274,   274,   275,   275,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   280,
     281,   281,   282,   282,   283,   284,   284,   285,   286,   287,
     287,   288,   288,   289,   290,   289,   291,   292,   292,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   294,   295,   296,
     295,   297,   298,   298,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   300,
     301,   302,   302,   303,   303,   304,   305,   306,   307,   308,
     309,   310,   310,   311,   312,   313,   314,   314,   315,   316,
     317,   318,   319,   321,   320,   322,   322,   323,   324,   324,
     324,   325,   326,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   332,   332,   332,   333,   333,   334,   334,
     335,   335,   335,   336,   336,   336,   337,   337,   338,   339,
     340,   340,   340,   340,   341,   342,   342,   342,   342,   342,
     343,   343,   343,   344,   344,   345,   345,   345,   346,   346,
     347,   347,   347,   348,   348,   349,   349,   349,   350,   350,
     350,   350,   351,   351,   351,   352,   352,   352,   353,   353,
     354,   354,   354,   354,   355,   355,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   357,
     357,   358,   359,   359,   360,   360,   361,   361,   362,   362,
     363,   363,   364,   364,   364,   364,   364,   364,   365,   365,
     366,   366,   367,   368,   368,   369,   369,   370,   370,   371,
     371,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     373,   373,   374,   375,   375,   375,   376,   376,   376,   376,
     377,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     382
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     3,     5,     5,     3,     3,    16,     0,     2,
       0,     2,     0,     2,     1,     1,     0,     3,     3,     1,
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     5,     3,
       5,     5,     5,     3,     3,     5,     5,     5,     7,     7,
       7,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     0,     0,     8,     4,
       1,     0,     1,     0,     2,     1,     5,     3,     0,     0,
       9,     0,     2,     0,     5,     0,     4,     1,     2,     1,
       6,     0,     3,     0,     6,     0,     4,     0,     4,     1,
       0,     4,     3,     3,     6,     8,     1,     3,     3,     5,
       5,     7,     4,     0,    10,     0,    12,     0,     2,     5,
       1,     5,     1,     5,     1,     5,     1,     9,     5,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     7,     5,
       1,     1,     1,     1,     5,     1,     3,     5,     5,     1,
       3,     5,     5,     3,     0,     5,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     3,     1,     1,     3,     3,     0,
       5,     2,     0,     3,     1,     3,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     5,
       7,     5,     8,     1,     3,     5,     5,     7,     7,     6,
       5,     0,     2,     3,     3,     3,     1,     5,     9,     5,
       9,     3,     3,     0,    10,     0,     1,     7,     5,     5,
       3,     5,     7,     9,     1,     1,     1,     1,     1,     0,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     1,
       1,     1,     4,     1,     1,     1,     1,     4,     1,     4,
       5,     1,     3,     1,     3,     1,     1,     4,     9,     1,
       1,     1,     4,     1,     5,     1,     1,     4,     1,     1,
       5,     1,     1,     1,     4,     1,     1,     4,     5,     3,
       1,     1,     5,     1,     1,     3,     1,     1,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     0,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       0,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     2,     4,     6,     4,     6,     6,     6,
       6,     2,     6,     8,     8,    10,    14,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    10,
       9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* include_def: INCLUDE_ID STRING  */
#line 297 "lev_comp.y"
                  {
		      include_push( (yyvsp[0].map) );
		      Free((yyvsp[0].map));
		  }
#line 2387 "lev.tab.c"
    break;

  case 11: /* level: level_def flags levstatements  */
#line 308 "lev_comp.y"
                  {
			if (fatal_error > 0) {
				(void) fprintf(stderr,
				"%s: %d errors detected for level \"%s\". No output created!\n",
					       fname, fatal_error, (yyvsp[-2].map));
				fatal_error = 0;
				got_errors++;
			} else if (!got_errors) {
				if (!write_level_file((yyvsp[-2].map), splev)) {
				    lc_error("Can't write output file for '%s'!", (yyvsp[-2].map));
				    exit(EXIT_FAILURE);
				}
			}
			Free((yyvsp[-2].map));
			Free(splev);
			splev = NULL;
			vardef_free_all(variable_definitions);
			variable_definitions = NULL;
		  }
#line 2411 "lev.tab.c"
    break;

  case 12: /* level_def: LEVEL_ID ':' STRING  */
#line 330 "lev_comp.y"
                  {
		      struct lc_funcdefs *f;
			if (index((yyvsp[0].map), '.'))
			    lc_error("Invalid dot ('.') in level name '%s'.", (yyvsp[0].map));
			if ((int) strlen((yyvsp[0].map)) > 14)
			    lc_error("Level names limited to 14 characters ('%s').", (yyvsp[0].map));
			f = function_definitions;
			while (f) {
			    f->n_called = 0;
			    f = f->next;
			}
			splev = (sp_lev *)alloc(sizeof(sp_lev));
			splev->n_opcodes = 0;
			splev->opcodes = NULL;

			vardef_free_all(variable_definitions);
			variable_definitions = NULL;

			rnd_vault_freq = 1;
			is_rnd_vault = 0;

			(yyval.map) = (yyvsp[0].map);
		  }
#line 2439 "lev.tab.c"
    break;

  case 13: /* lev_init: LEV_INIT_ID ':' SOLID_FILL_ID ',' terrain_type  */
#line 356 "lev_comp.y"
                  {
		      long filling = (yyvsp[0].terr).ter;
		      if (filling == INVALID_TYPE || filling >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");
		      add_opvars(splev, "iiiiiiiio", LVLINIT_SOLIDFILL,filling,0,(long)(yyvsp[0].terr).lit, 0,0,0,0, SPO_INITLEVEL);
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  }
#line 2452 "lev.tab.c"
    break;

  case 14: /* lev_init: LEV_INIT_ID ':' MAZE_GRID_ID ',' CHAR  */
#line 365 "lev_comp.y"
                  {
		      long filling = what_map_char((char) (yyvsp[0].i));
		      if (filling == INVALID_TYPE || filling >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");
		      add_opvars(splev, "iiiiiiiio", LVLINIT_MAZEGRID,filling,0,0, 0,0,0,0, SPO_INITLEVEL);
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  }
#line 2465 "lev.tab.c"
    break;

  case 15: /* lev_init: LEV_INIT_ID ':' SHEOL_ID  */
#line 374 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiiiio", LVLINIT_SHEOL,0,0,0,0,0,0,0, SPO_INITLEVEL);
		  }
#line 2473 "lev.tab.c"
    break;

  case 16: /* lev_init: LEV_INIT_ID ':' ROGUELEV_ID  */
#line 378 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiiiio", LVLINIT_ROGUE,0,0,0,0,0,0,0, SPO_INITLEVEL);
		  }
#line 2481 "lev.tab.c"
    break;

  case 17: /* lev_init: LEV_INIT_ID ':' MINES_ID ',' CHAR ',' CHAR ',' BOOLEAN ',' BOOLEAN ',' light_state ',' walled opt_fillchar  */
#line 382 "lev_comp.y"
                  {
		      long fg = what_map_char((char) (yyvsp[-11].i));
		      long bg = what_map_char((char) (yyvsp[-9].i));
		      long smoothed = (yyvsp[-7].i);
		      long joined = (yyvsp[-5].i);
		      long lit = (yyvsp[-3].i);
		      long walled = (yyvsp[-1].i);
		      long filling = (yyvsp[0].i);
		      if (fg == INVALID_TYPE || fg >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid foreground type.");
		      if (bg == INVALID_TYPE || bg >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid background type.");
		      if (joined && fg != CORR && fg != ROOM)
			  lc_error("INIT_MAP: Invalid foreground type for joined map.");

		      if (filling == INVALID_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");

		      add_opvars(splev, "iiiiiiiio", LVLINIT_MINES,filling,walled,lit, joined,smoothed,bg,fg, SPO_INITLEVEL);
			max_x_map = COLNO-1;
			max_y_map = ROWNO;
		  }
#line 2508 "lev.tab.c"
    break;

  case 18: /* opt_limited: %empty  */
#line 407 "lev_comp.y"
                  {
		      (yyval.i) = 0;
		  }
#line 2516 "lev.tab.c"
    break;

  case 19: /* opt_limited: ',' LIMITED  */
#line 411 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 2524 "lev.tab.c"
    break;

  case 20: /* opt_coord_or_var: %empty  */
#line 417 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_COPY);
		      (yyval.i) = 0;
		  }
#line 2533 "lev.tab.c"
    break;

  case 21: /* opt_coord_or_var: ',' coord_or_var  */
#line 422 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 2541 "lev.tab.c"
    break;

  case 22: /* opt_fillchar: %empty  */
#line 428 "lev_comp.y"
                  {
		      (yyval.i) = -1;
		  }
#line 2549 "lev.tab.c"
    break;

  case 23: /* opt_fillchar: ',' CHAR  */
#line 432 "lev_comp.y"
                  {
		      (yyval.i) = what_map_char((char) (yyvsp[0].i));
		  }
#line 2557 "lev.tab.c"
    break;

  case 26: /* flags: %empty  */
#line 443 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 0, SPO_LEVEL_FLAGS);
		  }
#line 2565 "lev.tab.c"
    break;

  case 27: /* flags: FLAGS_ID ':' flag_list  */
#line 447 "lev_comp.y"
                  {
		      if ((yyvsp[0].i) & FLAG_RNDVAULT)
			  is_rnd_vault = 1;
		      add_opvars(splev, "io", (yyvsp[0].i), SPO_LEVEL_FLAGS);
		  }
#line 2575 "lev.tab.c"
    break;

  case 28: /* flag_list: FLAG_TYPE ',' flag_list  */
#line 455 "lev_comp.y"
                  {
		      (yyval.i) = ((yyvsp[-2].i) | (yyvsp[0].i));
		  }
#line 2583 "lev.tab.c"
    break;

  case 29: /* flag_list: FLAG_TYPE  */
#line 459 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 2591 "lev.tab.c"
    break;

  case 30: /* levstatements: %empty  */
#line 465 "lev_comp.y"
                  {
		      (yyval.i) = 0;
		  }
#line 2599 "lev.tab.c"
    break;

  case 31: /* levstatements: levstatement levstatements  */
#line 469 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[0].i);
		  }
#line 2607 "lev.tab.c"
    break;

  case 32: /* stmt_block: '{' levstatements '}'  */
#line 475 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[-1].i);
		  }
#line 2615 "lev.tab.c"
    break;

  case 106: /* shuffle_detail: SHUFFLE_ID ':' any_var_array  */
#line 564 "lev_comp.y"
                  {
		      struct lc_vardefs *vd;
		      if ((vd = vardef_defined(variable_definitions, (yyvsp[0].map), 1))) {
			  if (!(vd->var_type & SPOVAR_ARRAY))
			      lc_error("Trying to shuffle non-array variable '%s'", (yyvsp[0].map));
		      } else lc_error("Trying to shuffle undefined variable '%s'", (yyvsp[0].map));
		      add_opvars(splev, "so", (yyvsp[0].map), SPO_SHUFFLE_ARRAY);
		      Free((yyvsp[0].map));
		  }
#line 2629 "lev.tab.c"
    break;

  case 107: /* variable_define: any_var_or_arr '=' math_expr_var  */
#line 576 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-2].map), SPOVAR_INT);
		      add_opvars(splev, "iso", 0, (yyvsp[-2].map), SPO_VAR_INIT);
		      Free((yyvsp[-2].map));
		  }
#line 2639 "lev.tab.c"
    break;

  case 108: /* variable_define: any_var_or_arr '=' selection_ID ':' ter_selection  */
#line 582 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_SEL);
		      add_opvars(splev, "iso", 0, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2649 "lev.tab.c"
    break;

  case 109: /* variable_define: any_var_or_arr '=' string_expr  */
#line 588 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-2].map), SPOVAR_STRING);
		      add_opvars(splev, "iso", 0, (yyvsp[-2].map), SPO_VAR_INIT);
		      Free((yyvsp[-2].map));
		  }
#line 2659 "lev.tab.c"
    break;

  case 110: /* variable_define: any_var_or_arr '=' terrainid ':' mapchar_or_var  */
#line 594 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_MAPCHAR);
		      add_opvars(splev, "iso", 0, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2669 "lev.tab.c"
    break;

  case 111: /* variable_define: any_var_or_arr '=' monsterid ':' monster_or_var  */
#line 600 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_MONST);
		      add_opvars(splev, "iso", 0, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2679 "lev.tab.c"
    break;

  case 112: /* variable_define: any_var_or_arr '=' objectid ':' object_or_var  */
#line 606 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_OBJ);
		      add_opvars(splev, "iso", 0, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2689 "lev.tab.c"
    break;

  case 113: /* variable_define: any_var_or_arr '=' coord_or_var  */
#line 612 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-2].map), SPOVAR_COORD);
		      add_opvars(splev, "iso", 0, (yyvsp[-2].map), SPO_VAR_INIT);
		      Free((yyvsp[-2].map));
		  }
#line 2699 "lev.tab.c"
    break;

  case 114: /* variable_define: any_var_or_arr '=' region_or_var  */
#line 618 "lev_comp.y"
                  {
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-2].map), SPOVAR_REGION);
		      add_opvars(splev, "iso", 0, (yyvsp[-2].map), SPO_VAR_INIT);
		      Free((yyvsp[-2].map));
		  }
#line 2709 "lev.tab.c"
    break;

  case 115: /* variable_define: any_var_or_arr '=' '{' integer_list '}'  */
#line 624 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_INT|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2720 "lev.tab.c"
    break;

  case 116: /* variable_define: any_var_or_arr '=' '{' encodecoord_list '}'  */
#line 631 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_COORD|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2731 "lev.tab.c"
    break;

  case 117: /* variable_define: any_var_or_arr '=' '{' encoderegion_list '}'  */
#line 638 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_REGION|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2742 "lev.tab.c"
    break;

  case 118: /* variable_define: any_var_or_arr '=' terrainid ':' '{' mapchar_list '}'  */
#line 645 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-6].map), SPOVAR_MAPCHAR|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-6].map), SPO_VAR_INIT);
		      Free((yyvsp[-6].map));
		  }
#line 2753 "lev.tab.c"
    break;

  case 119: /* variable_define: any_var_or_arr '=' monsterid ':' '{' encodemonster_list '}'  */
#line 652 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-6].map), SPOVAR_MONST|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-6].map), SPO_VAR_INIT);
		      Free((yyvsp[-6].map));
		  }
#line 2764 "lev.tab.c"
    break;

  case 120: /* variable_define: any_var_or_arr '=' objectid ':' '{' encodeobj_list '}'  */
#line 659 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-6].map), SPOVAR_OBJ|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-6].map), SPO_VAR_INIT);
		      Free((yyvsp[-6].map));
		  }
#line 2775 "lev.tab.c"
    break;

  case 121: /* variable_define: any_var_or_arr '=' '{' string_list '}'  */
#line 666 "lev_comp.y"
                  {
		      long n_items = (yyvsp[-1].i);
		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_STRING|SPOVAR_ARRAY);
		      add_opvars(splev, "iso", n_items, (yyvsp[-4].map), SPO_VAR_INIT);
		      Free((yyvsp[-4].map));
		  }
#line 2786 "lev.tab.c"
    break;

  case 122: /* encodeobj_list: encodeobj  */
#line 675 "lev_comp.y"
                  {
		      add_opvars(splev, "O", (yyvsp[0].i));
		      (yyval.i) = 1;
		  }
#line 2795 "lev.tab.c"
    break;

  case 123: /* encodeobj_list: encodeobj_list ',' encodeobj  */
#line 680 "lev_comp.y"
                  {
		      add_opvars(splev, "O", (yyvsp[0].i));
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2804 "lev.tab.c"
    break;

  case 124: /* encodemonster_list: encodemonster  */
#line 687 "lev_comp.y"
                  {
		      add_opvars(splev, "M", (yyvsp[0].i));
		      (yyval.i) = 1;
		  }
#line 2813 "lev.tab.c"
    break;

  case 125: /* encodemonster_list: encodemonster_list ',' encodemonster  */
#line 692 "lev_comp.y"
                  {
		      add_opvars(splev, "M", (yyvsp[0].i));
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2822 "lev.tab.c"
    break;

  case 126: /* mapchar_list: mapchar  */
#line 699 "lev_comp.y"
                  {
		      add_opvars(splev, "m", (yyvsp[0].i));
		      (yyval.i) = 1;
		  }
#line 2831 "lev.tab.c"
    break;

  case 127: /* mapchar_list: mapchar_list ',' mapchar  */
#line 704 "lev_comp.y"
                  {
		      add_opvars(splev, "m", (yyvsp[0].i));
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2840 "lev.tab.c"
    break;

  case 128: /* encoderegion_list: encoderegion  */
#line 711 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 2848 "lev.tab.c"
    break;

  case 129: /* encoderegion_list: encoderegion_list ',' encoderegion  */
#line 715 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2856 "lev.tab.c"
    break;

  case 130: /* encodecoord_list: encodecoord  */
#line 721 "lev_comp.y"
                  {
		      add_opvars(splev, "c", (yyvsp[0].i));
		      (yyval.i) = 1;
		  }
#line 2865 "lev.tab.c"
    break;

  case 131: /* encodecoord_list: encodecoord_list ',' encodecoord  */
#line 726 "lev_comp.y"
                  {
		      add_opvars(splev, "c", (yyvsp[0].i));
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2874 "lev.tab.c"
    break;

  case 132: /* integer_list: math_expr_var  */
#line 733 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 2882 "lev.tab.c"
    break;

  case 133: /* integer_list: integer_list ',' math_expr_var  */
#line 737 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2890 "lev.tab.c"
    break;

  case 134: /* string_list: string_expr  */
#line 743 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 2898 "lev.tab.c"
    break;

  case 135: /* string_list: string_list ',' string_expr  */
#line 747 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[-2].i);
		  }
#line 2906 "lev.tab.c"
    break;

  case 136: /* $@1: %empty  */
#line 753 "lev_comp.y"
                  {
		      struct lc_funcdefs *funcdef;

		      if (in_function_definition)
			  lc_error("Recursively defined functions not allowed (function %s).", (yyvsp[-1].map));

		      in_function_definition++;

		      if (funcdef_defined(function_definitions, (yyvsp[-1].map), 1))
			  lc_error("Function '%s' already defined once.", (yyvsp[-1].map));

		      funcdef = funcdef_new(-1, (yyvsp[-1].map));
		      funcdef->next = function_definitions;
		      function_definitions = funcdef;
		      function_splev_backup = splev;
		      splev = &(funcdef->code);
		      Free((yyvsp[-1].map));
		      curr_function = funcdef;
		      function_tmp_var_defs = variable_definitions;
		      variable_definitions = NULL;
		  }
#line 2932 "lev.tab.c"
    break;

  case 137: /* $@2: %empty  */
#line 775 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 2940 "lev.tab.c"
    break;

  case 138: /* function_define: FUNCTION_ID NQSTRING '(' $@1 func_params_list ')' $@2 stmt_block  */
#line 779 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 0, SPO_RETURN);
		      splev = function_splev_backup;
		      in_function_definition--;
		      curr_function = NULL;
		      vardef_free_all(variable_definitions);
		      variable_definitions = function_tmp_var_defs;
		  }
#line 2953 "lev.tab.c"
    break;

  case 139: /* function_call: NQSTRING '(' func_call_params_list ')'  */
#line 790 "lev_comp.y"
                  {
		      struct lc_funcdefs *tmpfunc;
		      tmpfunc = funcdef_defined(function_definitions, (yyvsp[-3].map), 1);
		      if (tmpfunc) {
			  long l;
			  long nparams = strlen( (yyvsp[-1].map) );
			  char *fparamstr = funcdef_paramtypes(tmpfunc);
			  if (strcmp((yyvsp[-1].map), fparamstr)) {
			      char *tmps = strdup(decode_parm_str(fparamstr));
			      lc_error("Function '%s' requires params '%s', got '%s' instead.", (yyvsp[-3].map), tmps, decode_parm_str((yyvsp[-1].map)));
			      Free(tmps);
			  }
			  Free(fparamstr);
			  Free((yyvsp[-1].map));
			  if (!(tmpfunc->n_called)) {
			      /* we haven't called the function yet, so insert it in the code */
			      struct opvar *jmp = New(struct opvar);
			      set_opvar_int(jmp, splev->n_opcodes+1);
			      add_opcode(splev, SPO_PUSH, jmp);
			      add_opcode(splev, SPO_JMP, NULL); /* we must jump past it first, then CALL it, due to RETURN. */

			      tmpfunc->addr = splev->n_opcodes;

			      { /* init function parameter variables */
				  struct lc_funcdefs_parm *tfp = tmpfunc->params;
				  while (tfp) {
				      add_opvars(splev, "iso", 0, tfp->name, SPO_VAR_INIT);
				      tfp = tfp->next;
				  }
			      }

			      splev_add_from(splev, &(tmpfunc->code));
			      set_opvar_int(jmp, splev->n_opcodes - jmp->vardata.l);
			  }
			  l = tmpfunc->addr - splev->n_opcodes - 2;
			  add_opvars(splev, "iio", nparams, l, SPO_CALL);
			  tmpfunc->n_called++;
		      } else {
			  lc_error("Function '%s' not defined.", (yyvsp[-3].map));
		      }
		      Free((yyvsp[-3].map));
		  }
#line 3000 "lev.tab.c"
    break;

  case 140: /* exitstatement: EXIT_ID  */
#line 835 "lev_comp.y"
                  {
		      add_opcode(splev, SPO_EXIT, NULL);
		  }
#line 3008 "lev.tab.c"
    break;

  case 141: /* opt_percent: %empty  */
#line 841 "lev_comp.y"
                  {
		      (yyval.i) = 100;
		  }
#line 3016 "lev.tab.c"
    break;

  case 142: /* opt_percent: PERCENT  */
#line 845 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 3024 "lev.tab.c"
    break;

  case 143: /* opt_spercent: %empty  */
#line 851 "lev_comp.y"
                  {
		      (yyval.i) = 100;
		  }
#line 3032 "lev.tab.c"
    break;

  case 144: /* opt_spercent: ',' SPERCENT  */
#line 855 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 3040 "lev.tab.c"
    break;

  case 145: /* comparestmt: PERCENT  */
#line 861 "lev_comp.y"
                  {
		      /* val > rn2(100) */
		      add_opvars(splev, "iio", (long)(yyvsp[0].i), 100, SPO_RN2);
		      (yyval.i) = SPO_JG;
                  }
#line 3050 "lev.tab.c"
    break;

  case 146: /* comparestmt: '[' math_expr_var COMPARE_TYPE math_expr_var ']'  */
#line 867 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[-2].i);
                  }
#line 3058 "lev.tab.c"
    break;

  case 147: /* comparestmt: '[' math_expr_var ']'  */
#line 871 "lev_comp.y"
                  {
		      /* boolean, explicit foo != 0 */
		      add_opvars(splev, "i", 0);
		      (yyval.i) = SPO_JNE;
                  }
#line 3068 "lev.tab.c"
    break;

  case 148: /* $@3: %empty  */
#line 879 "lev_comp.y"
                  {
		      is_inconstant_number = 0;
		  }
#line 3076 "lev.tab.c"
    break;

  case 149: /* $@4: %empty  */
#line 883 "lev_comp.y"
                  {
		      struct opvar *chkjmp;
		      if (in_switch_statement > 0)
			  lc_error("Cannot nest switch-statements.");

		      in_switch_statement++;

		      n_switch_case_list = 0;
		      switch_default_case = NULL;

		      if (!is_inconstant_number)
			  add_opvars(splev, "o", SPO_RN2);
		      is_inconstant_number = 0;

		      chkjmp = New(struct opvar);
		      set_opvar_int(chkjmp, splev->n_opcodes+1);
		      switch_check_jump = chkjmp;
		      add_opcode(splev, SPO_PUSH, chkjmp);
		      add_opcode(splev, SPO_JMP, NULL);
		      break_stmt_start();
		  }
#line 3102 "lev.tab.c"
    break;

  case 150: /* switchstatement: SWITCH_ID $@3 '[' integer_or_var ']' $@4 '{' switchcases '}'  */
#line 905 "lev_comp.y"
                  {
		      struct opvar *endjump = New(struct opvar);
		      int i;

		      set_opvar_int(endjump, splev->n_opcodes+1);

		      add_opcode(splev, SPO_PUSH, endjump);
		      add_opcode(splev, SPO_JMP, NULL);

		      set_opvar_int(switch_check_jump, splev->n_opcodes - switch_check_jump->vardata.l);

		      for (i = 0; i < n_switch_case_list; i++) {
			  add_opvars(splev, "oio", SPO_COPY, switch_case_value[i], SPO_CMP);
			  set_opvar_int(switch_case_list[i], switch_case_list[i]->vardata.l - splev->n_opcodes-1);
			  add_opcode(splev, SPO_PUSH, switch_case_list[i]);
			  add_opcode(splev, SPO_JE, NULL);
		      }

		      if (switch_default_case) {
			  set_opvar_int(switch_default_case, switch_default_case->vardata.l - splev->n_opcodes-1);
			  add_opcode(splev, SPO_PUSH, switch_default_case);
			  add_opcode(splev, SPO_JMP, NULL);
		      }

		      set_opvar_int(endjump, splev->n_opcodes - endjump->vardata.l);

		      break_stmt_end(splev);

		      add_opcode(splev, SPO_POP, NULL); /* get rid of the value in stack */
		      in_switch_statement--;


		  }
#line 3140 "lev.tab.c"
    break;

  case 153: /* $@5: %empty  */
#line 945 "lev_comp.y"
                  {
		      if (n_switch_case_list < MAX_SWITCH_CASES) {
			  struct opvar *tmppush = New(struct opvar);
			  set_opvar_int(tmppush, splev->n_opcodes);
			  switch_case_value[n_switch_case_list] = (yyvsp[-1].i);
			  switch_case_list[n_switch_case_list++] = tmppush;
		      } else lc_error("Too many cases in a switch.");
		  }
#line 3153 "lev.tab.c"
    break;

  case 154: /* switchcase: CASE_ID all_integers ':' $@5 levstatements  */
#line 954 "lev_comp.y"
                  {
		  }
#line 3160 "lev.tab.c"
    break;

  case 155: /* $@6: %empty  */
#line 957 "lev_comp.y"
                  {
		      struct opvar *tmppush = New(struct opvar);

		      if (switch_default_case)
			  lc_error("Switch default case already used.");

		      set_opvar_int(tmppush, splev->n_opcodes);
		      switch_default_case = tmppush;
		  }
#line 3174 "lev.tab.c"
    break;

  case 156: /* switchcase: DEFAULT_ID ':' $@6 levstatements  */
#line 967 "lev_comp.y"
                  {
		  }
#line 3181 "lev.tab.c"
    break;

  case 157: /* breakstatement: BREAK_ID  */
#line 972 "lev_comp.y"
                  {
		      if (!allow_break_statements)
			  lc_error("Cannot use BREAK outside a statement block.");
		      else {
			  break_stmt_new(splev, splev->n_opcodes);
		      }
		  }
#line 3193 "lev.tab.c"
    break;

  case 160: /* forstmt_start: FOR_ID any_var_or_unk '=' math_expr_var for_to_span math_expr_var  */
#line 986 "lev_comp.y"
                  {
		      char buf[256], buf2[256];

		      if (n_forloops >= MAX_NESTED_IFS) {
			  lc_error("FOR: Too deeply nested loops.");
			  n_forloops = MAX_NESTED_IFS - 1;
		      }

		      /* first, define a variable for the for-loop end value */
		      snprintf(buf, 255, "%s end", (yyvsp[-4].map));
		      /* the value of which is already in stack (the 2nd math_expr) */
		      add_opvars(splev, "iso", 0, buf, SPO_VAR_INIT);

		      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-4].map), SPOVAR_INT);
		      /* define the for-loop variable. value is in stack (1st math_expr) */
		      add_opvars(splev, "iso", 0, (yyvsp[-4].map), SPO_VAR_INIT);

		      /* calculate value for the loop "step" variable */
		      snprintf(buf2, 255, "%s step", (yyvsp[-4].map));
		      add_opvars(splev, "vvo", buf, (yyvsp[-4].map), SPO_MATH_SUB); /* end - start */
		      add_opvars(splev, "o", SPO_MATH_SIGN); /* sign of that */
		      add_opvars(splev, "iso", 0, buf2, SPO_VAR_INIT); /* save the sign into the step var */

		      forloop_list[n_forloops].varname = strdup((yyvsp[-4].map));
		      forloop_list[n_forloops].jmp_point = splev->n_opcodes;

		      n_forloops++;
		      Free((yyvsp[-4].map));
		  }
#line 3227 "lev.tab.c"
    break;

  case 161: /* $@7: %empty  */
#line 1018 "lev_comp.y"
                  {
		      /* nothing */
		      break_stmt_start();
		  }
#line 3236 "lev.tab.c"
    break;

  case 162: /* forstatement: forstmt_start $@7 stmt_block  */
#line 1023 "lev_comp.y"
                  {
		      char buf[256], buf2[256];
		      n_forloops--;
		      snprintf(buf, 255, "%s step", forloop_list[n_forloops].varname);
		      snprintf(buf2, 255, "%s end", forloop_list[n_forloops].varname);
		      /* compare for-loop var to end value */
		      add_opvars(splev, "vvo", forloop_list[n_forloops].varname, buf2, SPO_CMP);
		      /* var + step */
		      add_opvars(splev, "vvo", buf,
				 forloop_list[n_forloops].varname, SPO_MATH_ADD);
		      /* for-loop var = (for-loop var + step) */
		      add_opvars(splev, "iso", 0, forloop_list[n_forloops].varname, SPO_VAR_INIT);
		      /* jump back if compared values were not equal */
		      add_opvars(splev, "io", forloop_list[n_forloops].jmp_point - splev->n_opcodes - 1, SPO_JNE);
		      Free(forloop_list[n_forloops].varname);
		      break_stmt_end(splev);
		  }
#line 3258 "lev.tab.c"
    break;

  case 163: /* $@8: %empty  */
#line 1043 "lev_comp.y"
                  {
		      struct opvar *tmppush = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("LOOP: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }
		      set_opvar_int(tmppush, splev->n_opcodes);
		      if_list[n_if_list++] = tmppush;

		      add_opvars(splev, "o", SPO_DEC);
		      break_stmt_start();
		  }
#line 3276 "lev.tab.c"
    break;

  case 164: /* loopstatement: LOOP_ID '[' integer_or_var ']' $@8 stmt_block  */
#line 1057 "lev_comp.y"
                  {
		      struct opvar *tmppush;

		      add_opvars(splev, "oio", SPO_COPY, 0, SPO_CMP);

		      tmppush = (struct opvar *) if_list[--n_if_list];
		      set_opvar_int(tmppush, tmppush->vardata.l - splev->n_opcodes-1);
		      add_opcode(splev, SPO_PUSH, tmppush);
		      add_opcode(splev, SPO_JG, NULL);
		      add_opcode(splev, SPO_POP, NULL); /* get rid of the count value in stack */
		      break_stmt_end(splev);
		  }
#line 3293 "lev.tab.c"
    break;

  case 165: /* $@9: %empty  */
#line 1072 "lev_comp.y"
                  {
		      struct opvar *tmppush2 = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("IF: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }

		      add_opcode(splev, SPO_CMP, NULL);

		      set_opvar_int(tmppush2, splev->n_opcodes+1);

		      if_list[n_if_list++] = tmppush2;

		      add_opcode(splev, SPO_PUSH, tmppush2);

		      add_opcode(splev, reverse_jmp_opcode( (yyvsp[-1].i) ), NULL);

		  }
#line 3317 "lev.tab.c"
    break;

  case 166: /* chancestatement: comparestmt ':' $@9 levstatement  */
#line 1092 "lev_comp.y"
                  {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;
			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush, splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?!  No start address?");
		  }
#line 3329 "lev.tab.c"
    break;

  case 167: /* $@10: %empty  */
#line 1102 "lev_comp.y"
                  {
		      struct opvar *tmppush2 = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("IF: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }

		      add_opcode(splev, SPO_CMP, NULL);

		      set_opvar_int(tmppush2, splev->n_opcodes+1);

		      if_list[n_if_list++] = tmppush2;

		      add_opcode(splev, SPO_PUSH, tmppush2);

		      add_opcode(splev, reverse_jmp_opcode( (yyvsp[0].i) ), NULL);

		  }
#line 3353 "lev.tab.c"
    break;

  case 168: /* ifstatement: IF_ID comparestmt $@10 if_ending  */
#line 1122 "lev_comp.y"
                  {
		     /* do nothing */
		  }
#line 3361 "lev.tab.c"
    break;

  case 169: /* if_ending: stmt_block  */
#line 1128 "lev_comp.y"
                  {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;
			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush, splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?!  No start address?");
		  }
#line 3373 "lev.tab.c"
    break;

  case 170: /* $@11: %empty  */
#line 1136 "lev_comp.y"
                  {
		      if (n_if_list > 0) {
			  struct opvar *tmppush = New(struct opvar);
			  struct opvar *tmppush2;

			  set_opvar_int(tmppush, splev->n_opcodes+1);
			  add_opcode(splev, SPO_PUSH, tmppush);

			  add_opcode(splev, SPO_JMP, NULL);

			  tmppush2 = (struct opvar *) if_list[--n_if_list];

			  set_opvar_int(tmppush2, splev->n_opcodes - tmppush2->vardata.l);
			  if_list[n_if_list++] = tmppush;
		      } else lc_error("IF: Huh?!  No else-part address?");
		  }
#line 3394 "lev.tab.c"
    break;

  case 171: /* if_ending: stmt_block $@11 ELSE_ID stmt_block  */
#line 1153 "lev_comp.y"
                  {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;
			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush, splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?! No end address?");
		  }
#line 3406 "lev.tab.c"
    break;

  case 172: /* vaultgen_stmt: VAULTGEN_ID ':' INTEGER  */
#line 1163 "lev_comp.y"
                  {
		      if (is_rnd_vault) {
			  if ((yyvsp[0].i) > 0)
			      rnd_vault_freq = (yyvsp[0].i);
			  else
			      lc_error("Invalid VAULTGEN frequency");
		      } else
			  lc_error("VAULTGEN without rndvault FLAG.");
		  }
#line 3420 "lev.tab.c"
    break;

  case 173: /* message: MESSAGE_ID ':' string_expr  */
#line 1175 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_MESSAGE);
		  }
#line 3428 "lev.tab.c"
    break;

  case 174: /* wallwalk_detail: WALLWALK_ID ':' coord_or_var ',' mapchar_or_var opt_spercent  */
#line 1181 "lev_comp.y"
                  {
		      add_opvars(splev, "mio", SP_MAPCHAR_PACK(ROOM,-2), (yyvsp[0].i), SPO_WALLWALK);
		  }
#line 3436 "lev.tab.c"
    break;

  case 175: /* wallwalk_detail: WALLWALK_ID ':' coord_or_var ',' mapchar_or_var ',' mapchar_or_var opt_spercent  */
#line 1185 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (yyvsp[0].i), SPO_WALLWALK);
		  }
#line 3444 "lev.tab.c"
    break;

  case 176: /* random_corridors: RAND_CORRIDOR_ID  */
#line 1191 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiio", -1,  0, -1, -1, -1, -1, SPO_CORRIDOR);
		  }
#line 3452 "lev.tab.c"
    break;

  case 177: /* random_corridors: RAND_CORRIDOR_ID ':' all_integers  */
#line 1195 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiio", -1, (yyvsp[0].i), -1, -1, -1, -1, SPO_CORRIDOR);
		  }
#line 3460 "lev.tab.c"
    break;

  case 178: /* random_corridors: RAND_CORRIDOR_ID ':' RANDOM_TYPE  */
#line 1199 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiio", -1, -1, -1, -1, -1, -1, SPO_CORRIDOR);
		  }
#line 3468 "lev.tab.c"
    break;

  case 179: /* corridor: CORRIDOR_ID ':' corr_spec ',' corr_spec  */
#line 1205 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiio",
				 (yyvsp[-2].corpos).room, (yyvsp[-2].corpos).door, (yyvsp[-2].corpos).wall,
				 (yyvsp[0].corpos).room, (yyvsp[0].corpos).door, (yyvsp[0].corpos).wall,
				 SPO_CORRIDOR);
		  }
#line 3479 "lev.tab.c"
    break;

  case 180: /* corridor: CORRIDOR_ID ':' corr_spec ',' all_integers  */
#line 1212 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiiiio",
				 (yyvsp[-2].corpos).room, (yyvsp[-2].corpos).door, (yyvsp[-2].corpos).wall,
				 -1, -1, (long)(yyvsp[0].i),
				 SPO_CORRIDOR);
		  }
#line 3490 "lev.tab.c"
    break;

  case 181: /* corr_spec: '(' INTEGER ',' DIRECTION ',' door_pos ')'  */
#line 1221 "lev_comp.y"
                  {
			(yyval.corpos).room = (yyvsp[-5].i);
			(yyval.corpos).wall = (yyvsp[-3].i);
			(yyval.corpos).door = (yyvsp[-1].i);
		  }
#line 3500 "lev.tab.c"
    break;

  case 182: /* room_begin: room_type opt_percent ',' light_state  */
#line 1229 "lev_comp.y"
                  {
		      if (((yyvsp[-2].i) < 100) && ((yyvsp[-3].i) == OROOM))
			  lc_error("Only typed rooms can have a chance.");
		      else {
			  add_opvars(splev, "iii", (long)(yyvsp[-3].i), (long)(yyvsp[-2].i), (long)(yyvsp[0].i));
		      }
                  }
#line 3512 "lev.tab.c"
    break;

  case 183: /* $@12: %empty  */
#line 1239 "lev_comp.y"
                  {
		      long flags = (yyvsp[0].i);
		      if (flags == -1) flags = (1 << 0);
		      add_opvars(splev, "iiiiiiio", flags, ERR, ERR,
				 (yyvsp[-3].crd).x, (yyvsp[-3].crd).y, (yyvsp[-1].sze).width, (yyvsp[-1].sze).height, SPO_SUBROOM);
		      break_stmt_start();
		  }
#line 3524 "lev.tab.c"
    break;

  case 184: /* subroom_def: SUBROOM_ID ':' room_begin ',' subroom_pos ',' room_size optroomregionflags $@12 stmt_block  */
#line 1247 "lev_comp.y"
                  {
		      break_stmt_end(splev);
		      add_opcode(splev, SPO_ENDROOM, NULL);
		  }
#line 3533 "lev.tab.c"
    break;

  case 185: /* $@13: %empty  */
#line 1254 "lev_comp.y"
                  {
		      long flags = (yyvsp[-2].i);
		      if (flags == -1) flags = (1 << 0);
		      add_opvars(splev, "iiiiiiio", flags,
				 (yyvsp[-3].crd).x, (yyvsp[-3].crd).y, (yyvsp[-5].crd).x, (yyvsp[-5].crd).y,
				 (yyvsp[-1].sze).width, (yyvsp[-1].sze).height, SPO_ROOM);
		      break_stmt_start();
		  }
#line 3546 "lev.tab.c"
    break;

  case 186: /* room_def: ROOM_ID ':' room_begin ',' room_pos ',' room_align ',' room_size optroomregionflags $@13 stmt_block  */
#line 1263 "lev_comp.y"
                  {
		      break_stmt_end(splev);
		      add_opcode(splev, SPO_ENDROOM, NULL);
		  }
#line 3555 "lev.tab.c"
    break;

  case 187: /* roomfill: %empty  */
#line 1270 "lev_comp.y"
                  {
			(yyval.i) = 1;
		  }
#line 3563 "lev.tab.c"
    break;

  case 188: /* roomfill: ',' BOOLEAN  */
#line 1274 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3571 "lev.tab.c"
    break;

  case 189: /* room_pos: '(' INTEGER ',' INTEGER ')'  */
#line 1280 "lev_comp.y"
                  {
			if ( (yyvsp[-3].i) < 1 || (yyvsp[-3].i) > 5 ||
			    (yyvsp[-1].i) < 1 || (yyvsp[-1].i) > 5 ) {
			    lc_error("Room positions should be between 1-5: (%li,%li)!", (yyvsp[-3].i), (yyvsp[-1].i));
			} else {
			    (yyval.crd).x = (yyvsp[-3].i);
			    (yyval.crd).y = (yyvsp[-1].i);
			}
		  }
#line 3585 "lev.tab.c"
    break;

  case 190: /* room_pos: RANDOM_TYPE  */
#line 1290 "lev_comp.y"
                  {
			(yyval.crd).x = (yyval.crd).y = ERR;
		  }
#line 3593 "lev.tab.c"
    break;

  case 191: /* subroom_pos: '(' INTEGER ',' INTEGER ')'  */
#line 1296 "lev_comp.y"
                  {
			if ( (yyvsp[-3].i) < 0 || (yyvsp[-1].i) < 0) {
			    lc_error("Invalid subroom position (%li,%li)!", (yyvsp[-3].i), (yyvsp[-1].i));
			} else {
			    (yyval.crd).x = (yyvsp[-3].i);
			    (yyval.crd).y = (yyvsp[-1].i);
			}
		  }
#line 3606 "lev.tab.c"
    break;

  case 192: /* subroom_pos: RANDOM_TYPE  */
#line 1305 "lev_comp.y"
                  {
			(yyval.crd).x = (yyval.crd).y = ERR;
		  }
#line 3614 "lev.tab.c"
    break;

  case 193: /* room_align: '(' h_justif ',' v_justif ')'  */
#line 1311 "lev_comp.y"
                  {
		      (yyval.crd).x = (yyvsp[-3].i);
		      (yyval.crd).y = (yyvsp[-1].i);
		  }
#line 3623 "lev.tab.c"
    break;

  case 194: /* room_align: RANDOM_TYPE  */
#line 1316 "lev_comp.y"
                  {
		      (yyval.crd).x = (yyval.crd).y = ERR;
		  }
#line 3631 "lev.tab.c"
    break;

  case 195: /* room_size: '(' INTEGER ',' INTEGER ')'  */
#line 1322 "lev_comp.y"
                  {
			(yyval.sze).width = (yyvsp[-3].i);
			(yyval.sze).height = (yyvsp[-1].i);
		  }
#line 3640 "lev.tab.c"
    break;

  case 196: /* room_size: RANDOM_TYPE  */
#line 1327 "lev_comp.y"
                  {
			(yyval.sze).height = (yyval.sze).width = ERR;
		  }
#line 3648 "lev.tab.c"
    break;

  case 197: /* door_detail: ROOMDOOR_ID ':' secret ',' door_state ',' door_wall ',' door_pos  */
#line 1333 "lev_comp.y"
                  {
			/* ERR means random here */
			if ((yyvsp[-2].i) == ERR && (yyvsp[0].i) != ERR) {
			    lc_error("If the door wall is random, so must be its pos!");
			} else {
			    add_opvars(splev, "iiiio", (long)(yyvsp[0].i), (long)(yyvsp[-4].i), (long)(yyvsp[-6].i), (long)(yyvsp[-2].i), SPO_ROOM_DOOR);
			}
		  }
#line 3661 "lev.tab.c"
    break;

  case 198: /* door_detail: DOOR_ID ':' door_state ',' ter_selection  */
#line 1342 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (long)(yyvsp[-2].i), SPO_DOOR);
		  }
#line 3669 "lev.tab.c"
    break;

  case 203: /* dir_list: DIRECTION  */
#line 1356 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 3677 "lev.tab.c"
    break;

  case 204: /* dir_list: DIRECTION '|' dir_list  */
#line 1360 "lev_comp.y"
                  {
		      (yyval.i) = ((yyvsp[-2].i) | (yyvsp[0].i));
		  }
#line 3685 "lev.tab.c"
    break;

  case 207: /* map_definition: NOMAP_ID  */
#line 1370 "lev_comp.y"
                  {
		      add_opvars(splev, "ciisiio", 0, 0, 1, (char *)0, 0, 0, SPO_MAP);
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  }
#line 3695 "lev.tab.c"
    break;

  case 208: /* map_definition: GEOMETRY_ID ':' h_justif ',' v_justif roomfill MAP_ID  */
#line 1376 "lev_comp.y"
                  {
		      add_opvars(splev, "cii", SP_COORD_PACK(((yyvsp[-4].i)),((yyvsp[-2].i))), 1, (long)(yyvsp[-1].i));
		      scan_map((yyvsp[0].map), splev);
		      Free((yyvsp[0].map));
		  }
#line 3705 "lev.tab.c"
    break;

  case 209: /* map_definition: GEOMETRY_ID ':' coord_or_var roomfill MAP_ID  */
#line 1382 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 2, (long)(yyvsp[-1].i));
		      scan_map((yyvsp[0].map), splev);
		      Free((yyvsp[0].map));
		  }
#line 3715 "lev.tab.c"
    break;

  case 214: /* sounds_detail: SOUNDS_ID ':' integer_or_var ',' sounds_list  */
#line 1398 "lev_comp.y"
                  {
		      long n_sounds = (yyvsp[0].i);
		      add_opvars(splev, "io", n_sounds, SPO_LEVEL_SOUNDS);
		  }
#line 3724 "lev.tab.c"
    break;

  case 215: /* sounds_list: lvl_sound_part  */
#line 1405 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 3732 "lev.tab.c"
    break;

  case 216: /* sounds_list: lvl_sound_part ',' sounds_list  */
#line 1409 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[0].i);
		  }
#line 3740 "lev.tab.c"
    break;

  case 217: /* lvl_sound_part: '(' MSG_OUTPUT_TYPE ',' string_expr ')'  */
#line 1415 "lev_comp.y"
                  {
		      add_opvars(splev, "i", (long)(yyvsp[-3].i));
		  }
#line 3748 "lev.tab.c"
    break;

  case 218: /* mon_generation: MON_GENERATION_ID ':' SPERCENT ',' mon_gen_list  */
#line 1421 "lev_comp.y"
                  {
		      long total_mons = (yyvsp[0].i);
		      if (total_mons < 1) lc_error("Monster generation: zero monsters defined?");
		      add_opvars(splev, "iio", (yyvsp[-2].i), total_mons, SPO_MON_GENERATION);
		  }
#line 3758 "lev.tab.c"
    break;

  case 219: /* mon_gen_list: mon_gen_part  */
#line 1429 "lev_comp.y"
                  {
		      (yyval.i) = 1;
		  }
#line 3766 "lev.tab.c"
    break;

  case 220: /* mon_gen_list: mon_gen_part ',' mon_gen_list  */
#line 1433 "lev_comp.y"
                  {
		      (yyval.i) = 1 + (yyvsp[0].i);
		  }
#line 3774 "lev.tab.c"
    break;

  case 221: /* mon_gen_part: '(' integer_or_var ',' monster ')'  */
#line 1439 "lev_comp.y"
                  {
		      long token = (yyvsp[-1].i);
		      if (token == ERR) lc_error("Monster generation: Invalid monster symbol");
		      add_opvars(splev, "ii", token, 1);
		  }
#line 3784 "lev.tab.c"
    break;

  case 222: /* mon_gen_part: '(' integer_or_var ',' STRING ')'  */
#line 1445 "lev_comp.y"
                  {
		      long token;
		      token = get_monster_id((yyvsp[-1].map), (char)0);
		      if (token == ERR) lc_error("Monster generation: Invalid monster name");
		      add_opvars(splev, "ii", token, 0);
		  }
#line 3795 "lev.tab.c"
    break;

  case 223: /* monster_detail: MONSTER_ID ':' monster_desc  */
#line 1454 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 0, SPO_MONSTER);
		  }
#line 3803 "lev.tab.c"
    break;

  case 224: /* $@14: %empty  */
#line 1458 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 1, SPO_MONSTER);
		      in_container_obj++;
		      break_stmt_start();
		  }
#line 3813 "lev.tab.c"
    break;

  case 225: /* monster_detail: MONSTER_ID ':' monster_desc $@14 stmt_block  */
#line 1464 "lev_comp.y"
                 {
		     break_stmt_end(splev);
		     in_container_obj--;
		     add_opvars(splev, "o", SPO_END_MONINVENT);
		 }
#line 3823 "lev.tab.c"
    break;

  case 226: /* monster_desc: monster_or_var ',' coord_or_var monster_infos  */
#line 1472 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 3831 "lev.tab.c"
    break;

  case 227: /* monster_infos: %empty  */
#line 1478 "lev_comp.y"
                  {
		      struct opvar *stopit = New(struct opvar);
		      set_opvar_int(stopit, SP_M_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x0000;
		  }
#line 3842 "lev.tab.c"
    break;

  case 228: /* monster_infos: monster_infos ',' monster_info  */
#line 1485 "lev_comp.y"
                  {
		      if (( (yyvsp[-2].i) & (yyvsp[0].i) ))
			  lc_error("MONSTER extra info defined twice.");
		      (yyval.i) = ( (yyvsp[-2].i) | (yyvsp[0].i) );
		  }
#line 3852 "lev.tab.c"
    break;

  case 229: /* monster_info: string_expr  */
#line 1493 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_M_V_NAME);
		      (yyval.i) = 0x0001;
		  }
#line 3861 "lev.tab.c"
    break;

  case 230: /* monster_info: MON_ATTITUDE  */
#line 1498 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_M_V_PEACEFUL);
		      (yyval.i) = 0x0002;
		  }
#line 3870 "lev.tab.c"
    break;

  case 231: /* monster_info: MON_ALERTNESS  */
#line 1503 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_M_V_ASLEEP);
		      (yyval.i) = 0x0004;
		  }
#line 3879 "lev.tab.c"
    break;

  case 232: /* monster_info: alignment_prfx  */
#line 1508 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_M_V_ALIGN);
		      (yyval.i) = 0x0008;
		  }
#line 3888 "lev.tab.c"
    break;

  case 233: /* monster_info: MON_APPEARANCE string_expr  */
#line 1513 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[-1].i), SP_M_V_APPEAR);
		      (yyval.i) = 0x0010;
		  }
#line 3897 "lev.tab.c"
    break;

  case 234: /* monster_info: FEMALE_ID  */
#line 1518 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_FEMALE);
		      (yyval.i) = 0x0020;
		  }
#line 3906 "lev.tab.c"
    break;

  case 235: /* monster_info: INVIS_ID  */
#line 1523 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_INVIS);
		      (yyval.i) = 0x0040;
		  }
#line 3915 "lev.tab.c"
    break;

  case 236: /* monster_info: CANCELLED_ID  */
#line 1528 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_CANCELLED);
		      (yyval.i) = 0x0080;
		  }
#line 3924 "lev.tab.c"
    break;

  case 237: /* monster_info: REVIVED_ID  */
#line 1533 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_REVIVED);
		      (yyval.i) = 0x0100;
		  }
#line 3933 "lev.tab.c"
    break;

  case 238: /* monster_info: AVENGE_ID  */
#line 1538 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_AVENGE);
		      (yyval.i) = 0x0200;
		  }
#line 3942 "lev.tab.c"
    break;

  case 239: /* monster_info: FLEEING_ID ':' integer_or_var  */
#line 1543 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_M_V_FLEEING);
		      (yyval.i) = 0x0400;
		  }
#line 3951 "lev.tab.c"
    break;

  case 240: /* monster_info: BLINDED_ID ':' integer_or_var  */
#line 1548 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_M_V_BLINDED);
		      (yyval.i) = 0x0800;
		  }
#line 3960 "lev.tab.c"
    break;

  case 241: /* monster_info: PARALYZED_ID ':' integer_or_var  */
#line 1553 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_M_V_PARALYZED);
		      (yyval.i) = 0x1000;
		  }
#line 3969 "lev.tab.c"
    break;

  case 242: /* monster_info: STUNNED_ID  */
#line 1558 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_STUNNED);
		      (yyval.i) = 0x2000;
		  }
#line 3978 "lev.tab.c"
    break;

  case 243: /* monster_info: CONFUSED_ID  */
#line 1563 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_M_V_CONFUSED);
		      (yyval.i) = 0x4000;
		  }
#line 3987 "lev.tab.c"
    break;

  case 244: /* monster_info: SEENTRAPS_ID ':' seen_trap_mask  */
#line 1568 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_M_V_SEENTRAPS);
		      (yyval.i) = 0x8000;
		  }
#line 3996 "lev.tab.c"
    break;

  case 245: /* seen_trap_mask: STRING  */
#line 1575 "lev_comp.y"
                  {
		      int token = get_trap_type((yyvsp[0].map));
		      if (token == ERR || token == 0)
			  lc_error("Unknown trap type '%s'!", (yyvsp[0].map));
		      (yyval.i) = (1L << (token - 1));
		  }
#line 4007 "lev.tab.c"
    break;

  case 246: /* seen_trap_mask: ALL_ID  */
#line 1582 "lev_comp.y"
                  {
		      (yyval.i) = (long) ~0;
		  }
#line 4015 "lev.tab.c"
    break;

  case 247: /* seen_trap_mask: STRING '|' seen_trap_mask  */
#line 1586 "lev_comp.y"
                  {
		      int token = get_trap_type((yyvsp[-2].map));
		      if (token == ERR || token == 0)
			  lc_error("Unknown trap type '%s'!", (yyvsp[-2].map));

		      if ((1L << (token - 1)) & (yyvsp[0].i))
			  lc_error("Monster seen_traps, trap '%s' listed twice.", (yyvsp[-2].map));

		      (yyval.i) = ((1L << (token - 1)) | (yyvsp[0].i));
		  }
#line 4030 "lev.tab.c"
    break;

  case 248: /* object_detail: OBJECT_ID ':' object_desc  */
#line 1599 "lev_comp.y"
                  {
		      long cnt = 0;
		      if (in_container_obj) cnt |= SP_OBJ_CONTENT;
		      add_opvars(splev, "io", cnt, SPO_OBJECT);
		  }
#line 4040 "lev.tab.c"
    break;

  case 249: /* $@15: %empty  */
#line 1605 "lev_comp.y"
                  {
		      long cnt = SP_OBJ_CONTAINER;
		      if (in_container_obj) cnt |= SP_OBJ_CONTENT;
		      add_opvars(splev, "io", cnt, SPO_OBJECT);
		      in_container_obj++;
		      break_stmt_start();
		  }
#line 4052 "lev.tab.c"
    break;

  case 250: /* object_detail: COBJECT_ID ':' object_desc $@15 stmt_block  */
#line 1613 "lev_comp.y"
                 {
		     break_stmt_end(splev);
		     in_container_obj--;
		     add_opcode(splev, SPO_POP_CONTAINER, NULL);
		 }
#line 4062 "lev.tab.c"
    break;

  case 251: /* object_desc: object_or_var object_infos  */
#line 1621 "lev_comp.y"
                  {
		      if (( (yyvsp[0].i) & 0x4000) && in_container_obj) lc_error("Object cannot have a coord when contained.");
		      else if (!( (yyvsp[0].i) & 0x4000) && !in_container_obj) lc_error("Object needs a coord when not contained.");
		  }
#line 4071 "lev.tab.c"
    break;

  case 252: /* object_infos: %empty  */
#line 1628 "lev_comp.y"
                  {
		      struct opvar *stopit = New(struct opvar);
		      set_opvar_int(stopit, SP_O_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x00;
		  }
#line 4082 "lev.tab.c"
    break;

  case 253: /* object_infos: object_infos ',' object_info  */
#line 1635 "lev_comp.y"
                  {
		      if (( (yyvsp[-2].i) & (yyvsp[0].i) ))
			  lc_error("OBJECT extra info defined twice.");
		      (yyval.i) = ( (yyvsp[-2].i) | (yyvsp[0].i) );
		  }
#line 4092 "lev.tab.c"
    break;

  case 254: /* object_info: CURSE_TYPE  */
#line 1643 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_O_V_CURSE);
		      (yyval.i) = 0x0001;
		  }
#line 4101 "lev.tab.c"
    break;

  case 255: /* object_info: MONTYPE_ID ':' monster_or_var  */
#line 1648 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_CORPSENM);
		      (yyval.i) = 0x0002;
		  }
#line 4110 "lev.tab.c"
    break;

  case 256: /* object_info: all_ints_push  */
#line 1653 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_SPE);
		      (yyval.i) = 0x0004;
		  }
#line 4119 "lev.tab.c"
    break;

  case 257: /* object_info: NAME_ID ':' string_expr  */
#line 1658 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_NAME);
		      (yyval.i) = 0x0008;
		  }
#line 4128 "lev.tab.c"
    break;

  case 258: /* object_info: QUANTITY_ID ':' integer_or_var  */
#line 1663 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_QUAN);
		      (yyval.i) = 0x0010;
		  }
#line 4137 "lev.tab.c"
    break;

  case 259: /* object_info: BURIED_ID  */
#line 1668 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_O_V_BURIED);
		      (yyval.i) = 0x0020;
		  }
#line 4146 "lev.tab.c"
    break;

  case 260: /* object_info: LIGHT_STATE  */
#line 1673 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (long)(yyvsp[0].i), SP_O_V_LIT);
		      (yyval.i) = 0x0040;
		  }
#line 4155 "lev.tab.c"
    break;

  case 261: /* object_info: ERODED_ID ':' integer_or_var  */
#line 1678 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_ERODED);
		      (yyval.i) = 0x0080;
		  }
#line 4164 "lev.tab.c"
    break;

  case 262: /* object_info: ERODEPROOF_ID  */
#line 1683 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", -1, SP_O_V_ERODED);
		      (yyval.i) = 0x0080;
		  }
#line 4173 "lev.tab.c"
    break;

  case 263: /* object_info: DOOR_STATE  */
#line 1688 "lev_comp.y"
                  {
		      if ((yyvsp[0].i) == D_LOCKED) {
			  add_opvars(splev, "ii", 1, SP_O_V_LOCKED);
			  (yyval.i) = 0x0100;
		      } else if ((yyvsp[0].i) == D_BROKEN) {
			  add_opvars(splev, "ii", 1, SP_O_V_BROKEN);
			  (yyval.i) = 0x0200;
		      } else
			  lc_error("OBJECT state can only be locked or broken.");
		  }
#line 4188 "lev.tab.c"
    break;

  case 264: /* object_info: TRAPPED_STATE  */
#line 1699 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", (yyvsp[0].i), SP_O_V_TRAPPED);
		      (yyval.i) = 0x0400;
		  }
#line 4197 "lev.tab.c"
    break;

  case 265: /* object_info: RECHARGED_ID ':' integer_or_var  */
#line 1704 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_RECHARGED);
		      (yyval.i) = 0x0800;
		  }
#line 4206 "lev.tab.c"
    break;

  case 266: /* object_info: INVIS_ID  */
#line 1709 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_O_V_INVIS);
		      (yyval.i) = 0x1000;
		  }
#line 4215 "lev.tab.c"
    break;

  case 267: /* object_info: GREASED_ID  */
#line 1714 "lev_comp.y"
                  {
		      add_opvars(splev, "ii", 1, SP_O_V_GREASED);
		      (yyval.i) = 0x2000;
		  }
#line 4224 "lev.tab.c"
    break;

  case 268: /* object_info: coord_or_var  */
#line 1719 "lev_comp.y"
                  {
		      add_opvars(splev, "i", SP_O_V_COORD);
		      (yyval.i) = 0x4000;
		  }
#line 4233 "lev.tab.c"
    break;

  case 269: /* trap_detail: TRAP_ID ':' trap_name ',' coord_or_var  */
#line 1726 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (long)(yyvsp[-2].i), SPO_TRAP);
		  }
#line 4241 "lev.tab.c"
    break;

  case 270: /* drawbridge_detail: DRAWBRIDGE_ID ':' coord_or_var ',' DIRECTION ',' door_state  */
#line 1732 "lev_comp.y"
                   {
		       long d, state = 0;
		       /* convert dir from a DIRECTION to a DB_DIR */
		       d = (yyvsp[-2].i);
		       switch(d) {
		       case W_NORTH: d = DB_NORTH; break;
		       case W_SOUTH: d = DB_SOUTH; break;
		       case W_EAST:  d = DB_EAST;  break;
		       case W_WEST:  d = DB_WEST;  break;
		       default:
			   lc_error("Invalid drawbridge direction.");
			   break;
		       }

		       if ( (yyvsp[0].i) == D_ISOPEN )
			   state = 1;
		       else if ( (yyvsp[0].i) == D_CLOSED )
			   state = 0;
		       else if ( (yyvsp[0].i) == -1 )
			   state = -1;
		       else
			   lc_error("A drawbridge can only be open, closed or random!");
		       add_opvars(splev, "iio", state, d, SPO_DRAWBRIDGE);
		   }
#line 4270 "lev.tab.c"
    break;

  case 271: /* mazewalk_detail: MAZEWALK_ID ':' coord_or_var ',' DIRECTION  */
#line 1759 "lev_comp.y"
                  {
		      add_opvars(splev, "iiio",
				 (long)(yyvsp[0].i), 1, 0, SPO_MAZEWALK);
		  }
#line 4279 "lev.tab.c"
    break;

  case 272: /* mazewalk_detail: MAZEWALK_ID ':' coord_or_var ',' DIRECTION ',' BOOLEAN opt_fillchar  */
#line 1764 "lev_comp.y"
                  {
		      add_opvars(splev, "iiio",
				 (long)(yyvsp[-3].i), (long)(yyvsp[-1].i), (long)(yyvsp[0].i), SPO_MAZEWALK);
		  }
#line 4288 "lev.tab.c"
    break;

  case 273: /* wallify_detail: WALLIFY_ID  */
#line 1771 "lev_comp.y"
                  {
		      add_opvars(splev, "rio", SP_REGION_PACK(-1,-1,-1,-1), 0, SPO_WALLIFY);
		  }
#line 4296 "lev.tab.c"
    break;

  case 274: /* wallify_detail: WALLIFY_ID ':' ter_selection  */
#line 1775 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 1, SPO_WALLIFY);
		  }
#line 4304 "lev.tab.c"
    break;

  case 275: /* ladder_detail: LADDER_ID ':' coord_or_var ',' UP_OR_DOWN  */
#line 1781 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (long)(yyvsp[0].i), SPO_LADDER);
		  }
#line 4312 "lev.tab.c"
    break;

  case 276: /* stair_detail: STAIR_ID ':' coord_or_var ',' UP_OR_DOWN  */
#line 1787 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (long)(yyvsp[0].i), SPO_STAIR);
		  }
#line 4320 "lev.tab.c"
    break;

  case 277: /* stair_region: STAIR_ID ':' lev_region ',' lev_region ',' UP_OR_DOWN  */
#line 1793 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiii iiiii iiso",
				 (yyvsp[-4].lregn).x1, (yyvsp[-4].lregn).y1, (yyvsp[-4].lregn).x2, (yyvsp[-4].lregn).y2, (yyvsp[-4].lregn).area,
				 (yyvsp[-2].lregn).x1, (yyvsp[-2].lregn).y1, (yyvsp[-2].lregn).x2, (yyvsp[-2].lregn).y2, (yyvsp[-2].lregn).area,
				 (long)(((yyvsp[0].i)) ? LR_UPSTAIR : LR_DOWNSTAIR),
				 0, (char *)0, SPO_LEVREGION);
		  }
#line 4332 "lev.tab.c"
    break;

  case 278: /* portal_region: PORTAL_ID ':' lev_region ',' lev_region ',' STRING  */
#line 1803 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiii iiiii iiso",
				 (yyvsp[-4].lregn).x1, (yyvsp[-4].lregn).y1, (yyvsp[-4].lregn).x2, (yyvsp[-4].lregn).y2, (yyvsp[-4].lregn).area,
				 (yyvsp[-2].lregn).x1, (yyvsp[-2].lregn).y1, (yyvsp[-2].lregn).x2, (yyvsp[-2].lregn).y2, (yyvsp[-2].lregn).area,
				 LR_PORTAL, 0, (yyvsp[0].map), SPO_LEVREGION);
		      Free((yyvsp[0].map));
		  }
#line 4344 "lev.tab.c"
    break;

  case 279: /* teleprt_region: TELEPRT_ID ':' lev_region ',' lev_region teleprt_detail  */
#line 1813 "lev_comp.y"
                  {
		      long rtype = 0;
		      switch((yyvsp[0].i)) {
		      case -1: rtype = LR_TELE; break;
		      case  0: rtype = LR_DOWNTELE; break;
		      case  1: rtype = LR_UPTELE; break;
		      }
		      add_opvars(splev, "iiiii iiiii iiso",
				 (yyvsp[-3].lregn).x1, (yyvsp[-3].lregn).y1, (yyvsp[-3].lregn).x2, (yyvsp[-3].lregn).y2, (yyvsp[-3].lregn).area,
				 (yyvsp[-1].lregn).x1, (yyvsp[-1].lregn).y1, (yyvsp[-1].lregn).x2, (yyvsp[-1].lregn).y2, (yyvsp[-1].lregn).area,
				 rtype, 0, (char *)0, SPO_LEVREGION);
		  }
#line 4361 "lev.tab.c"
    break;

  case 280: /* branch_region: BRANCH_ID ':' lev_region ',' lev_region  */
#line 1828 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiii iiiii iiso",
				 (yyvsp[-2].lregn).x1, (yyvsp[-2].lregn).y1, (yyvsp[-2].lregn).x2, (yyvsp[-2].lregn).y2, (yyvsp[-2].lregn).area,
				 (yyvsp[0].lregn).x1, (yyvsp[0].lregn).y1, (yyvsp[0].lregn).x2, (yyvsp[0].lregn).y2, (yyvsp[0].lregn).area,
				 (long)LR_BRANCH, 0, (char *)0, SPO_LEVREGION);
		  }
#line 4372 "lev.tab.c"
    break;

  case 281: /* teleprt_detail: %empty  */
#line 1837 "lev_comp.y"
                  {
			(yyval.i) = -1;
		  }
#line 4380 "lev.tab.c"
    break;

  case 282: /* teleprt_detail: ',' UP_OR_DOWN  */
#line 1841 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 4388 "lev.tab.c"
    break;

  case 283: /* fountain_detail: FOUNTAIN_ID ':' ter_selection  */
#line 1847 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_FOUNTAIN);
		  }
#line 4396 "lev.tab.c"
    break;

  case 284: /* sink_detail: SINK_ID ':' ter_selection  */
#line 1853 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SINK);
		  }
#line 4404 "lev.tab.c"
    break;

  case 285: /* pool_detail: POOL_ID ':' ter_selection  */
#line 1859 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_POOL);
		  }
#line 4412 "lev.tab.c"
    break;

  case 286: /* terrain_type: CHAR  */
#line 1865 "lev_comp.y"
                  {
		      (yyval.terr).lit = -2;
		      (yyval.terr).ter = what_map_char((char) (yyvsp[0].i));
		  }
#line 4421 "lev.tab.c"
    break;

  case 287: /* terrain_type: '(' CHAR ',' light_state ')'  */
#line 1870 "lev_comp.y"
                  {
		      (yyval.terr).lit = (yyvsp[-1].i);
		      (yyval.terr).ter = what_map_char((char) (yyvsp[-3].i));
		  }
#line 4430 "lev.tab.c"
    break;

  case 288: /* replace_terrain_detail: REPLACE_TERRAIN_ID ':' region_or_var ',' mapchar_or_var ',' mapchar_or_var ',' SPERCENT  */
#line 1877 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (yyvsp[0].i), SPO_REPLACETERRAIN);
		  }
#line 4438 "lev.tab.c"
    break;

  case 289: /* terrain_detail: TERRAIN_ID ':' ter_selection ',' mapchar_or_var  */
#line 1883 "lev_comp.y"
                 {
		     add_opvars(splev, "o", SPO_TERRAIN);
		 }
#line 4446 "lev.tab.c"
    break;

  case 290: /* spill_detail: SPILL_ID ':' coord_or_var ',' mapchar_or_var ',' DIRECTION ',' math_expr_var  */
#line 1889 "lev_comp.y"
                {
		    add_opvars(splev, "io", (long)(yyvsp[-2].i), SPO_SPILL);
		}
#line 4454 "lev.tab.c"
    break;

  case 291: /* diggable_detail: NON_DIGGABLE_ID ':' region_or_var  */
#line 1895 "lev_comp.y"
                  {
		     add_opvars(splev, "o", SPO_NON_DIGGABLE);
		  }
#line 4462 "lev.tab.c"
    break;

  case 292: /* passwall_detail: NON_PASSWALL_ID ':' region_or_var  */
#line 1901 "lev_comp.y"
                  {
		     add_opvars(splev, "o", SPO_NON_PASSWALL);
		  }
#line 4470 "lev.tab.c"
    break;

  case 293: /* @16: %empty  */
#line 1907 "lev_comp.y"
                  {
		      long irr;
		      long rt = (yyvsp[-1].i);
		      long flags = (yyvsp[0].i);
		      if (flags == -1) flags = (1 << 0);
		      if (!(( flags ) & 1)) rt += MAXRTYPE+1;
		      irr = ((( flags ) & 2) != 0);
		      add_opvars(splev, "iiio",
				 (long)(yyvsp[-3].i), rt, flags, SPO_REGION);
		      (yyval.i) = (irr || (flags & 1) || rt != OROOM);
		      break_stmt_start();
		  }
#line 4487 "lev.tab.c"
    break;

  case 294: /* region_detail: REGION_ID ':' region_or_var ',' light_state ',' room_type optroomregionflags @16 region_detail_end  */
#line 1920 "lev_comp.y"
                  {
		      break_stmt_end(splev);
		      if ( (yyvsp[-1].i) ) {
			  add_opcode(splev, SPO_ENDROOM, NULL);
		      } else if ( (yyvsp[0].i) )
			  lc_error("Cannot use lev statements in non-permanent REGION");
		  }
#line 4499 "lev.tab.c"
    break;

  case 295: /* region_detail_end: %empty  */
#line 1930 "lev_comp.y"
                  {
		      (yyval.i) = 0;
		  }
#line 4507 "lev.tab.c"
    break;

  case 296: /* region_detail_end: stmt_block  */
#line 1934 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 4515 "lev.tab.c"
    break;

  case 297: /* altar_detail: ALTAR_ID ':' coord_or_var ',' alignment ',' altar_type  */
#line 1940 "lev_comp.y"
                  {
		      add_opvars(splev, "iio", (long)(yyvsp[0].i), (long)(yyvsp[-2].i), SPO_ALTAR);
		  }
#line 4523 "lev.tab.c"
    break;

  case 298: /* grave_detail: GRAVE_ID ':' coord_or_var ',' string_expr  */
#line 1946 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 2, SPO_GRAVE);
		  }
#line 4531 "lev.tab.c"
    break;

  case 299: /* grave_detail: GRAVE_ID ':' coord_or_var ',' RANDOM_TYPE  */
#line 1950 "lev_comp.y"
                  {
		      add_opvars(splev, "sio",
				 (char *)0, 1, SPO_GRAVE);
		  }
#line 4540 "lev.tab.c"
    break;

  case 300: /* grave_detail: GRAVE_ID ':' coord_or_var  */
#line 1955 "lev_comp.y"
                  {
		      add_opvars(splev, "sio",
				 (char *)0, 0, SPO_GRAVE);
		  }
#line 4549 "lev.tab.c"
    break;

  case 301: /* gold_detail: GOLD_ID ':' math_expr_var ',' coord_or_var  */
#line 1962 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_GOLD);
		  }
#line 4557 "lev.tab.c"
    break;

  case 302: /* engraving_detail: ENGRAVING_ID ':' coord_or_var ',' engraving_type ',' string_expr  */
#line 1968 "lev_comp.y"
                  {
		      add_opvars(splev, "io",
				 (long)(yyvsp[-2].i), SPO_ENGRAVING);
		  }
#line 4566 "lev.tab.c"
    break;

  case 303: /* mineralize: MINERALIZE_ID ':' integer_or_var ',' integer_or_var ',' integer_or_var ',' integer_or_var  */
#line 1975 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_MINERALIZE);
		  }
#line 4574 "lev.tab.c"
    break;

  case 304: /* mineralize: MINERALIZE_ID  */
#line 1979 "lev_comp.y"
                  {
		      add_opvars(splev, "iiiio", -1L, -1L, -1L, -1L, SPO_MINERALIZE);
		  }
#line 4582 "lev.tab.c"
    break;

  case 305: /* trap_name: STRING  */
#line 1985 "lev_comp.y"
                  {
			int token = get_trap_type((yyvsp[0].map));
			if (token == ERR)
			    lc_error("Unknown trap type '%s'!", (yyvsp[0].map));
			(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 4594 "lev.tab.c"
    break;

  case 307: /* room_type: STRING  */
#line 1996 "lev_comp.y"
                  {
			int token = get_room_type((yyvsp[0].map));
			if (token == ERR) {
			    lc_warning("Unknown room type \"%s\"!  Making ordinary room...", (yyvsp[0].map));
				(yyval.i) = OROOM;
			} else
				(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 4608 "lev.tab.c"
    break;

  case 309: /* optroomregionflags: %empty  */
#line 2009 "lev_comp.y"
                  {
			(yyval.i) = -1;
		  }
#line 4616 "lev.tab.c"
    break;

  case 310: /* optroomregionflags: ',' roomregionflags  */
#line 2013 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 4624 "lev.tab.c"
    break;

  case 311: /* roomregionflags: roomregionflag  */
#line 2019 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 4632 "lev.tab.c"
    break;

  case 312: /* roomregionflags: roomregionflag ',' roomregionflags  */
#line 2023 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[-2].i) | (yyvsp[0].i);
		  }
#line 4640 "lev.tab.c"
    break;

  case 313: /* roomregionflag: FILLING  */
#line 2030 "lev_comp.y"
                  {
		      (yyval.i) = ((yyvsp[0].i) << 0);
		  }
#line 4648 "lev.tab.c"
    break;

  case 314: /* roomregionflag: IRREGULAR  */
#line 2034 "lev_comp.y"
                  {
		      (yyval.i) = ((yyvsp[0].i) << 1);
		  }
#line 4656 "lev.tab.c"
    break;

  case 315: /* roomregionflag: JOINED  */
#line 2038 "lev_comp.y"
                  {
		      (yyval.i) = ((yyvsp[0].i) << 2);
		  }
#line 4664 "lev.tab.c"
    break;

  case 322: /* alignment: RANDOM_TYPE  */
#line 2054 "lev_comp.y"
                  {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 4672 "lev.tab.c"
    break;

  case 325: /* alignment_prfx: A_REGISTER ':' RANDOM_TYPE  */
#line 2062 "lev_comp.y"
                  {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 4680 "lev.tab.c"
    break;

  case 328: /* a_register: A_REGISTER '[' INTEGER ']'  */
#line 2072 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) >= 3 )
				lc_error("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 4691 "lev.tab.c"
    break;

  case 329: /* monster: CHAR  */
#line 2081 "lev_comp.y"
                  {
			if (check_monster_char((char) (yyvsp[0].i)))
				(yyval.i) = (yyvsp[0].i) ;
			else {
			    lc_error("Unknown monster class '%c'!", (yyvsp[0].i));
			    (yyval.i) = ERR;
			}
		  }
#line 4704 "lev.tab.c"
    break;

  case 330: /* string_or_var: STRING  */
#line 2092 "lev_comp.y"
                  {
		      add_opvars(splev, "s", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4713 "lev.tab.c"
    break;

  case 331: /* string_or_var: VARSTRING_STRING  */
#line 2097 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_STRING);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4724 "lev.tab.c"
    break;

  case 332: /* string_or_var: VARSTRING_STRING_ARRAY '[' math_expr_var ']'  */
#line 2104 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_STRING|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 4735 "lev.tab.c"
    break;

  case 333: /* string_or_var: corefunc_str  */
#line 2110 "lev_comp.y"
                                        { }
#line 4741 "lev.tab.c"
    break;

  case 334: /* integer_or_var: math_expr_var  */
#line 2115 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 4749 "lev.tab.c"
    break;

  case 335: /* coord_or_var: encodecoord  */
#line 2121 "lev_comp.y"
                  {
		      add_opvars(splev, "c", (yyvsp[0].i));
		  }
#line 4757 "lev.tab.c"
    break;

  case 336: /* coord_or_var: corefunc_coord  */
#line 2125 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 4765 "lev.tab.c"
    break;

  case 337: /* coord_or_var: rndcoord_ID '(' ter_selection ')'  */
#line 2129 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_RNDCOORD);
		  }
#line 4773 "lev.tab.c"
    break;

  case 338: /* coord_or_var: VARSTRING_COORD  */
#line 2133 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_COORD);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4784 "lev.tab.c"
    break;

  case 339: /* coord_or_var: VARSTRING_COORD_ARRAY '[' math_expr_var ']'  */
#line 2140 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_COORD|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 4795 "lev.tab.c"
    break;

  case 340: /* encodecoord: '(' INTEGER ',' INTEGER ')'  */
#line 2149 "lev_comp.y"
                  {
		      if ((yyvsp[-3].i) < 0 || (yyvsp[-1].i) < 0 || (yyvsp[-3].i) >= COLNO || (yyvsp[-1].i) >= ROWNO)
			  lc_error("Coordinates (%li,%li) out of map range!", (yyvsp[-3].i), (yyvsp[-1].i));
		      (yyval.i) = SP_COORD_PACK((yyvsp[-3].i), (yyvsp[-1].i));
		  }
#line 4805 "lev.tab.c"
    break;

  case 341: /* encodecoord: RANDOM_TYPE  */
#line 2155 "lev_comp.y"
                  {
		      (yyval.i) = SP_COORD_PACK_RANDOM(0);
		  }
#line 4813 "lev.tab.c"
    break;

  case 342: /* encodecoord: RANDOM_TYPE_BRACKET humidity_flags ']'  */
#line 2159 "lev_comp.y"
                  {
		      (yyval.i) = SP_COORD_PACK_RANDOM( (yyvsp[-1].i) );
		  }
#line 4821 "lev.tab.c"
    break;

  case 343: /* humidity_flags: HUMIDITY_TYPE  */
#line 2165 "lev_comp.y"
                  {
		      (yyval.i) = (yyvsp[0].i);
		  }
#line 4829 "lev.tab.c"
    break;

  case 344: /* humidity_flags: HUMIDITY_TYPE ',' humidity_flags  */
#line 2169 "lev_comp.y"
                  {
		      if (((yyvsp[-2].i) & (yyvsp[0].i)))
			  lc_warning("Humidity flag used twice.");
		      (yyval.i) = ((yyvsp[-2].i) | (yyvsp[0].i));
		  }
#line 4839 "lev.tab.c"
    break;

  case 345: /* region_or_var: encoderegion  */
#line 2177 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 4847 "lev.tab.c"
    break;

  case 346: /* region_or_var: VARSTRING_REGION  */
#line 2181 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_REGION);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4858 "lev.tab.c"
    break;

  case 347: /* region_or_var: VARSTRING_REGION_ARRAY '[' math_expr_var ']'  */
#line 2188 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_REGION|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 4869 "lev.tab.c"
    break;

  case 348: /* encoderegion: '(' INTEGER ',' INTEGER ',' INTEGER ',' INTEGER ')'  */
#line 2197 "lev_comp.y"
                  {
		      long r = SP_REGION_PACK((yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
		      if ( (yyvsp[-7].i) > (yyvsp[-3].i) || (yyvsp[-5].i) > (yyvsp[-1].i) )
			  lc_error("Region start > end: (%li,%li,%li,%li)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));

		      add_opvars(splev, "r", r);
		      (yyval.i) = r;
		  }
#line 4882 "lev.tab.c"
    break;

  case 349: /* encoderegion: corefunc_region  */
#line 2206 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 4890 "lev.tab.c"
    break;

  case 350: /* mapchar_or_var: mapchar  */
#line 2212 "lev_comp.y"
                  {
		      add_opvars(splev, "m", (yyvsp[0].i));
		  }
#line 4898 "lev.tab.c"
    break;

  case 351: /* mapchar_or_var: VARSTRING_MAPCHAR  */
#line 2216 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_MAPCHAR);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4909 "lev.tab.c"
    break;

  case 352: /* mapchar_or_var: VARSTRING_MAPCHAR_ARRAY '[' math_expr_var ']'  */
#line 2223 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_MAPCHAR|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 4920 "lev.tab.c"
    break;

  case 353: /* mapchar: CHAR  */
#line 2232 "lev_comp.y"
                  {
		      if (what_map_char((char) (yyvsp[0].i)) != INVALID_TYPE)
			  (yyval.i) = SP_MAPCHAR_PACK(what_map_char((char) (yyvsp[0].i)), -2);
		      else {
			  lc_error("Unknown map char type '%c'!", (yyvsp[0].i));
			  (yyval.i) = SP_MAPCHAR_PACK(STONE, -2);
		      }
		  }
#line 4933 "lev.tab.c"
    break;

  case 354: /* mapchar: '(' CHAR ',' light_state ')'  */
#line 2241 "lev_comp.y"
                  {
		      if (what_map_char((char) (yyvsp[-3].i)) != INVALID_TYPE)
			  (yyval.i) = SP_MAPCHAR_PACK(what_map_char((char) (yyvsp[-3].i)), (yyvsp[-1].i));
		      else {
			  lc_error("Unknown map char type '%c'!", (yyvsp[-3].i));
			  (yyval.i) = SP_MAPCHAR_PACK(STONE, (yyvsp[-1].i));
		      }
		  }
#line 4946 "lev.tab.c"
    break;

  case 355: /* monster_or_var: encodemonster  */
#line 2252 "lev_comp.y"
                  {
		      add_opvars(splev, "M", (yyvsp[0].i));
		  }
#line 4954 "lev.tab.c"
    break;

  case 356: /* monster_or_var: VARSTRING_MONST  */
#line 2256 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_MONST);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 4965 "lev.tab.c"
    break;

  case 357: /* monster_or_var: VARSTRING_MONST_ARRAY '[' math_expr_var ']'  */
#line 2263 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_MONST|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 4976 "lev.tab.c"
    break;

  case 358: /* encodemonster: STRING  */
#line 2272 "lev_comp.y"
                  {
		      long m = get_monster_id((yyvsp[0].map), (char)0);
		      if (m == ERR) {
			  lc_error("Unknown monster \"%s\"!", (yyvsp[0].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_MONST_PACK(m, def_monsyms[(int)mons[m].mlet]);
		  }
#line 4989 "lev.tab.c"
    break;

  case 359: /* encodemonster: CHAR  */
#line 2281 "lev_comp.y"
                  {
			if (check_monster_char((char) (yyvsp[0].i)))
			    (yyval.i) = SP_MONST_PACK(-1, (yyvsp[0].i));
			else {
			    lc_error("Unknown monster class '%c'!", (yyvsp[0].i));
			    (yyval.i) = -1;
			}
		  }
#line 5002 "lev.tab.c"
    break;

  case 360: /* encodemonster: '(' CHAR ',' STRING ')'  */
#line 2290 "lev_comp.y"
                  {
		      long m = get_monster_id((yyvsp[-1].map), (char) (yyvsp[-3].i));
		      if (m == ERR) {
			  lc_error("Unknown monster ('%c', \"%s\")!", (yyvsp[-3].i), (yyvsp[-1].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_MONST_PACK(m, (yyvsp[-3].i));
		  }
#line 5015 "lev.tab.c"
    break;

  case 361: /* encodemonster: RANDOM_TYPE  */
#line 2299 "lev_comp.y"
                  {
		      (yyval.i) = -1;
		  }
#line 5023 "lev.tab.c"
    break;

  case 362: /* object_or_var: encodeobj  */
#line 2305 "lev_comp.y"
                  {
		      add_opvars(splev, "O", (yyvsp[0].i));
		  }
#line 5031 "lev.tab.c"
    break;

  case 363: /* object_or_var: VARSTRING_OBJ  */
#line 2309 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_OBJ);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 5042 "lev.tab.c"
    break;

  case 364: /* object_or_var: VARSTRING_OBJ_ARRAY '[' math_expr_var ']'  */
#line 2316 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_OBJ|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 5053 "lev.tab.c"
    break;

  case 365: /* xobject_or_var: encodexobj  */
#line 2325 "lev_comp.y"
                  {
		      add_opvars(splev, "O", (yyvsp[0].i));
		  }
#line 5061 "lev.tab.c"
    break;

  case 366: /* xobject_or_var: VARSTRING_OBJ  */
#line 2329 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_OBJ);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 5072 "lev.tab.c"
    break;

  case 367: /* xobject_or_var: VARSTRING_OBJ_ARRAY '[' math_expr_var ']'  */
#line 2336 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_OBJ|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		  }
#line 5083 "lev.tab.c"
    break;

  case 368: /* encodexobj: '(' CHAR ',' STRING ')'  */
#line 2346 "lev_comp.y"
                  {
		      long m = get_object_id((yyvsp[-1].map), (char) (yyvsp[-3].i));
		      if (m == ERR) {
			  lc_error("Unknown object ('%c', \"%s\")!", (yyvsp[-3].i), (yyvsp[-1].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_OBJ_PACK(m, (yyvsp[-3].i));
		  }
#line 5096 "lev.tab.c"
    break;

  case 369: /* encodexobj: objectid ':' STRING  */
#line 2355 "lev_comp.y"
                  {
		      long m = get_object_id((yyvsp[0].map), (char)0);
		      if (m == ERR) {
			  lc_error("Unknown object \"%s\"!", (yyvsp[0].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_OBJ_PACK(m, 1); /* obj class != 0 to force generation of a specific item */
		  }
#line 5109 "lev.tab.c"
    break;

  case 370: /* encodeobj: STRING  */
#line 2366 "lev_comp.y"
                  {
		      long m = get_object_id((yyvsp[0].map), (char)0);
		      if (m == ERR) {
			  lc_error("Unknown object \"%s\"!", (yyvsp[0].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_OBJ_PACK(m, 1); /* obj class != 0 to force generation of a specific item */

		  }
#line 5123 "lev.tab.c"
    break;

  case 371: /* encodeobj: CHAR  */
#line 2376 "lev_comp.y"
                  {
			if (check_object_char((char) (yyvsp[0].i)))
			    (yyval.i) = SP_OBJ_PACK(-1, (yyvsp[0].i));
			else {
			    lc_error("Unknown object class '%c'!", (yyvsp[0].i));
			    (yyval.i) = -1;
			}
		  }
#line 5136 "lev.tab.c"
    break;

  case 372: /* encodeobj: '(' CHAR ',' STRING ')'  */
#line 2385 "lev_comp.y"
                  {
		      long m = get_object_id((yyvsp[-1].map), (char) (yyvsp[-3].i));
		      if (m == ERR) {
			  lc_error("Unknown object ('%c', \"%s\")!", (yyvsp[-3].i), (yyvsp[-1].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_OBJ_PACK(m, (yyvsp[-3].i));
		  }
#line 5149 "lev.tab.c"
    break;

  case 373: /* encodeobj: RANDOM_TYPE  */
#line 2394 "lev_comp.y"
                  {
		      (yyval.i) = -1;
		  }
#line 5157 "lev.tab.c"
    break;

  case 374: /* string_expr: string_or_var  */
#line 2400 "lev_comp.y"
                                                { }
#line 5163 "lev.tab.c"
    break;

  case 375: /* string_expr: string_expr '.' string_or_var  */
#line 2402 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_MATH_ADD);
		  }
#line 5171 "lev.tab.c"
    break;

  case 376: /* math_expr_var: INTEGER  */
#line 2407 "lev_comp.y"
                                                { add_opvars(splev, "i", (yyvsp[0].i) ); }
#line 5177 "lev.tab.c"
    break;

  case 377: /* math_expr_var: dice  */
#line 2408 "lev_comp.y"
                                                { is_inconstant_number = 1; }
#line 5183 "lev.tab.c"
    break;

  case 378: /* math_expr_var: '(' MINUS_INTEGER ')'  */
#line 2409 "lev_comp.y"
                                                { add_opvars(splev, "i", (yyvsp[-1].i) ); }
#line 5189 "lev.tab.c"
    break;

  case 379: /* math_expr_var: corefunc_int  */
#line 2410 "lev_comp.y"
                                                { is_inconstant_number = 1; }
#line 5195 "lev.tab.c"
    break;

  case 380: /* math_expr_var: METHOD_INT  */
#line 2412 "lev_comp.y"
                  {
		      add_opvars(splev, "v", (yyvsp[0].meth).varstr);
		      add_opvars(splev, "io", (yyvsp[0].meth).cfunc, SPO_COREFUNC);
		      is_inconstant_number = 1;
		  }
#line 5205 "lev.tab.c"
    break;

  case 381: /* math_expr_var: VARSTRING_INT  */
#line 2418 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_INT);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		      is_inconstant_number = 1;
		  }
#line 5217 "lev.tab.c"
    break;

  case 382: /* math_expr_var: VARSTRING_INT_ARRAY '[' math_expr_var ']'  */
#line 2426 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[-3].map), SPOVAR_INT|SPOVAR_ARRAY);
		      vardef_used(variable_definitions, (yyvsp[-3].map));
		      add_opvars(splev, "v", (yyvsp[-3].map));
		      Free((yyvsp[-3].map));
		      is_inconstant_number = 1;
		  }
#line 5229 "lev.tab.c"
    break;

  case 383: /* math_expr_var: math_expr_var '+' math_expr_var  */
#line 2433 "lev_comp.y"
                                                        { add_opvars(splev, "o", SPO_MATH_ADD); }
#line 5235 "lev.tab.c"
    break;

  case 384: /* math_expr_var: math_expr_var '-' math_expr_var  */
#line 2434 "lev_comp.y"
                                                        { add_opvars(splev, "o", SPO_MATH_SUB); }
#line 5241 "lev.tab.c"
    break;

  case 385: /* math_expr_var: math_expr_var '*' math_expr_var  */
#line 2435 "lev_comp.y"
                                                        { add_opvars(splev, "o", SPO_MATH_MUL); }
#line 5247 "lev.tab.c"
    break;

  case 386: /* math_expr_var: math_expr_var '/' math_expr_var  */
#line 2436 "lev_comp.y"
                                                        { add_opvars(splev, "o", SPO_MATH_DIV); }
#line 5253 "lev.tab.c"
    break;

  case 387: /* math_expr_var: math_expr_var '%' math_expr_var  */
#line 2437 "lev_comp.y"
                                                        { add_opvars(splev, "o", SPO_MATH_MOD); }
#line 5259 "lev.tab.c"
    break;

  case 388: /* math_expr_var: '(' math_expr_var ')'  */
#line 2438 "lev_comp.y"
                                                    { }
#line 5265 "lev.tab.c"
    break;

  case 389: /* func_param_type: CFUNC_INT  */
#line 2442 "lev_comp.y"
                          {
			      if (!strcmp("int", (yyvsp[0].map)) || !strcmp("integer", (yyvsp[0].map))) {
				  (yyval.i) = (int)'i';
			      } else lc_error("Unknown function parameter type '%s'", (yyvsp[0].map));
			  }
#line 5275 "lev.tab.c"
    break;

  case 390: /* func_param_type: CFUNC_STR  */
#line 2448 "lev_comp.y"
                          {
			      if (!strcmp("str", (yyvsp[0].map)) || !strcmp("string", (yyvsp[0].map))) {
				  (yyval.i) = (int)'s';
			      } else lc_error("Unknown function parameter type '%s'", (yyvsp[0].map));
			  }
#line 5285 "lev.tab.c"
    break;

  case 391: /* func_param_part: any_var_or_arr ':' func_param_type  */
#line 2456 "lev_comp.y"
                          {
			      struct lc_funcdefs_parm *tmp = New(struct lc_funcdefs_parm);

			      if (!curr_function)
				  lc_error("Function parameters outside function definition.");
			      else if (!tmp)
				  lc_error("Could not alloc function params.");
			      else {
				  tmp->name = strdup((yyvsp[-2].map));
				  tmp->parmtype = (char) (yyvsp[0].i);
				  tmp->next = curr_function->params;
				  curr_function->params = tmp;
				  curr_function->n_params++;
				  {
				      long vt;
				      switch (tmp->parmtype) {
				      case 'i': vt = SPOVAR_INT; break;
				      case 's': vt = SPOVAR_STRING; break;
				      default: lc_error("Unknown func param conversion."); break;
				      }
				      variable_definitions = add_vardef_type(variable_definitions, (yyvsp[-2].map), vt);
				  }
			      }
			      Free((yyvsp[-2].map));
			  }
#line 5315 "lev.tab.c"
    break;

  case 396: /* func_call_param_part: math_expr_var  */
#line 2493 "lev_comp.y"
                          {
			      (yyval.i) = (int)'i';
			  }
#line 5323 "lev.tab.c"
    break;

  case 397: /* func_call_param_part: string_expr  */
#line 2497 "lev_comp.y"
                          {
			      (yyval.i) = (int)'s';
			  }
#line 5331 "lev.tab.c"
    break;

  case 398: /* func_call_param_list: func_call_param_part  */
#line 2504 "lev_comp.y"
                          {
			      char tmpbuf[2];
			      tmpbuf[0] = (char) (yyvsp[0].i);
			      tmpbuf[1] = '\0';
			      (yyval.map) = strdup(tmpbuf);
			  }
#line 5342 "lev.tab.c"
    break;

  case 399: /* func_call_param_list: func_call_param_list ',' func_call_param_part  */
#line 2511 "lev_comp.y"
                          {
			      long len = strlen( (yyvsp[-2].map) );
			      char *tmp = (char *)alloc(len + 2);
			      sprintf(tmp, "%c%s", (char) (yyvsp[0].i), (yyvsp[-2].map) );
			      Free( (yyvsp[-2].map) );
			      (yyval.map) = tmp;
			  }
#line 5354 "lev.tab.c"
    break;

  case 400: /* func_call_params_list: %empty  */
#line 2521 "lev_comp.y"
                          {
			      (yyval.map) = strdup("");
			  }
#line 5362 "lev.tab.c"
    break;

  case 401: /* func_call_params_list: func_call_param_list  */
#line 2525 "lev_comp.y"
                          {
			      char *tmp = strdup( (yyvsp[0].map) );
			      Free( (yyvsp[0].map) );
			      (yyval.map) = tmp;
			  }
#line 5372 "lev.tab.c"
    break;

  case 402: /* corefunc_param_part: math_expr_var  */
#line 2533 "lev_comp.y"
                          {
			      (yyval.i) = (int)'i';
			  }
#line 5380 "lev.tab.c"
    break;

  case 403: /* corefunc_param_part: string_expr  */
#line 2537 "lev_comp.y"
                          {
			      (yyval.i) = (int)'s';
			  }
#line 5388 "lev.tab.c"
    break;

  case 404: /* corefunc_param_part: xobject_or_var  */
#line 2541 "lev_comp.y"
                          {
			      (yyval.i) = (int)'O';
			  }
#line 5396 "lev.tab.c"
    break;

  case 405: /* corefunc_param_part: coord_or_var  */
#line 2545 "lev_comp.y"
                          {
			      (yyval.i) = (int)'c';
			  }
#line 5404 "lev.tab.c"
    break;

  case 406: /* corefunc_param_part: region_or_var  */
#line 2549 "lev_comp.y"
                          {
			      (yyval.i) = (int)'r';
			  }
#line 5412 "lev.tab.c"
    break;

  case 407: /* corefunc_param_part: monsterid ':' encodemonster  */
#line 2553 "lev_comp.y"
                          {
			      add_opvars(splev, "M", (yyvsp[0].i));
			      (yyval.i) = (int)'M';
			  }
#line 5421 "lev.tab.c"
    break;

  case 408: /* corefunc_param_list: corefunc_param_part  */
#line 2560 "lev_comp.y"
                          {
			      char tmpbuf[2];
			      tmpbuf[0] = (char) (yyvsp[0].i);
			      tmpbuf[1] = '\0';
			      (yyval.map) = strdup(tmpbuf);
			  }
#line 5432 "lev.tab.c"
    break;

  case 409: /* corefunc_param_list: corefunc_param_part ',' corefunc_param_list  */
#line 2567 "lev_comp.y"
                          {
			      long len = strlen( (yyvsp[0].map) );
			      char *tmp = (char *)alloc(len + 2);
			      sprintf(tmp, "%c%s", (char) (yyvsp[-2].i), (yyvsp[0].map) );
			      Free( (yyvsp[0].map) );
			      (yyval.map) = tmp;
			  }
#line 5444 "lev.tab.c"
    break;

  case 410: /* corefunc_params_list: %empty  */
#line 2577 "lev_comp.y"
                          {
			      (yyval.map) = strdup(" ");
			  }
#line 5452 "lev.tab.c"
    break;

  case 411: /* corefunc_params_list: corefunc_param_list  */
#line 2581 "lev_comp.y"
                          {
			      (yyval.map) = strdup((yyvsp[0].map));
			      Free((yyvsp[0].map));
			  }
#line 5461 "lev.tab.c"
    break;

  case 412: /* corefunc_stmt: CFUNC '(' corefunc_params_list ')'  */
#line 2588 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[-3].map), (yyvsp[-1].map), 'i');
		      Free((yyvsp[-3].map));
		      Free((yyvsp[-1].map));
		  }
#line 5471 "lev.tab.c"
    break;

  case 413: /* corefunc_int: CFUNC_INT  */
#line 2596 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[0].map), "", 'i');
		      Free((yyvsp[0].map));
		  }
#line 5480 "lev.tab.c"
    break;

  case 414: /* corefunc_int: CFUNC_INT '(' corefunc_params_list ')'  */
#line 2601 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[-3].map), (yyvsp[-1].map), 'i');
		      Free((yyvsp[-3].map));
		      Free((yyvsp[-1].map));
		  }
#line 5490 "lev.tab.c"
    break;

  case 415: /* corefunc_str: CFUNC_STR  */
#line 2609 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[0].map), "", 's');
		      Free((yyvsp[0].map));
		  }
#line 5499 "lev.tab.c"
    break;

  case 416: /* corefunc_str: CFUNC_STR '(' corefunc_params_list ')'  */
#line 2614 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[-3].map), (yyvsp[-1].map), 's');
		      Free((yyvsp[-3].map));
		      Free((yyvsp[-1].map));
		  }
#line 5509 "lev.tab.c"
    break;

  case 417: /* corefunc_coord: CFUNC_COORD  */
#line 2622 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[0].map), "", 'c');
		      Free((yyvsp[0].map));
		  }
#line 5518 "lev.tab.c"
    break;

  case 418: /* corefunc_coord: CFUNC_COORD '(' corefunc_params_list ')'  */
#line 2627 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[-3].map), (yyvsp[-1].map), 'c');
		      Free((yyvsp[-3].map));
		      Free((yyvsp[-1].map));
		  }
#line 5528 "lev.tab.c"
    break;

  case 419: /* corefunc_region: CFUNC_REGION  */
#line 2635 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[0].map), "", 'r');
		      Free((yyvsp[0].map));
		  }
#line 5537 "lev.tab.c"
    break;

  case 420: /* corefunc_region: CFUNC_REGION '(' corefunc_params_list ')'  */
#line 2640 "lev_comp.y"
                  {
		      handle_corefunc(splev, (yyvsp[-3].map), (yyvsp[-1].map), 'r');
		      Free((yyvsp[-3].map));
		      Free((yyvsp[-1].map));
		  }
#line 5547 "lev.tab.c"
    break;

  case 421: /* ter_selection_x: coord_or_var  */
#line 2648 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_POINT);
		  }
#line 5555 "lev.tab.c"
    break;

  case 422: /* ter_selection_x: rect_ID region_or_var  */
#line 2652 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_RECT);
		  }
#line 5563 "lev.tab.c"
    break;

  case 423: /* ter_selection_x: fillrect_ID region_or_var  */
#line 2656 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_FILLRECT);
		  }
#line 5571 "lev.tab.c"
    break;

  case 424: /* ter_selection_x: line_ID coord_or_var '-' coord_or_var  */
#line 2660 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_LINE);
		  }
#line 5579 "lev.tab.c"
    break;

  case 425: /* ter_selection_x: randline_ID coord_or_var '-' coord_or_var ',' math_expr_var  */
#line 2664 "lev_comp.y"
                  {
		      /* randline (x1,y1),(x2,y2), roughness */
		      add_opvars(splev, "o", SPO_SEL_RNDLINE);
		  }
#line 5588 "lev.tab.c"
    break;

  case 426: /* ter_selection_x: grow_ID '(' ter_selection ')'  */
#line 2669 "lev_comp.y"
                  {
		      add_opvars(splev, "io", W_ANY, SPO_SEL_GROW);
		  }
#line 5596 "lev.tab.c"
    break;

  case 427: /* ter_selection_x: grow_ID '(' dir_list ',' ter_selection ')'  */
#line 2673 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (yyvsp[-3].i), SPO_SEL_GROW);
		  }
#line 5604 "lev.tab.c"
    break;

  case 428: /* ter_selection_x: filter_ID '(' SPERCENT ',' ter_selection ')'  */
#line 2677 "lev_comp.y"
                  {
		      add_opvars(splev, "iio", (yyvsp[-3].i), SPOFILTER_PERCENT, SPO_SEL_FILTER);
		  }
#line 5612 "lev.tab.c"
    break;

  case 429: /* ter_selection_x: filter_ID '(' ter_selection ',' ter_selection ')'  */
#line 2681 "lev_comp.y"
                  {
		      add_opvars(splev, "io", SPOFILTER_SELECTION, SPO_SEL_FILTER);
		  }
#line 5620 "lev.tab.c"
    break;

  case 430: /* ter_selection_x: filter_ID '(' mapchar_or_var ',' ter_selection ')'  */
#line 2685 "lev_comp.y"
                  {
		      add_opvars(splev, "io", SPOFILTER_MAPCHAR, SPO_SEL_FILTER);
		  }
#line 5628 "lev.tab.c"
    break;

  case 431: /* ter_selection_x: flood_ID coord_or_var  */
#line 2689 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_FLOOD);
		  }
#line 5636 "lev.tab.c"
    break;

  case 432: /* ter_selection_x: circle_ID '(' coord_or_var ',' math_expr_var ')'  */
#line 2693 "lev_comp.y"
                  {
		      add_opvars(splev, "oio", SPO_COPY, 1, SPO_SEL_ELLIPSE);
		  }
#line 5644 "lev.tab.c"
    break;

  case 433: /* ter_selection_x: circle_ID '(' coord_or_var ',' math_expr_var ',' FILLING ')'  */
#line 2697 "lev_comp.y"
                  {
		      add_opvars(splev, "oio", SPO_COPY, (yyvsp[-1].i), SPO_SEL_ELLIPSE);
		  }
#line 5652 "lev.tab.c"
    break;

  case 434: /* ter_selection_x: ellipse_ID '(' coord_or_var ',' math_expr_var ',' math_expr_var ')'  */
#line 2701 "lev_comp.y"
                  {
		      add_opvars(splev, "io", 1, SPO_SEL_ELLIPSE);
		  }
#line 5660 "lev.tab.c"
    break;

  case 435: /* ter_selection_x: ellipse_ID '(' coord_or_var ',' math_expr_var ',' math_expr_var ',' FILLING ')'  */
#line 2705 "lev_comp.y"
                  {
		      add_opvars(splev, "io", (yyvsp[-1].i), SPO_SEL_ELLIPSE);
		  }
#line 5668 "lev.tab.c"
    break;

  case 436: /* ter_selection_x: gradient_ID '(' GRADIENT_TYPE ',' '(' math_expr_var '-' math_expr_var opt_limited ')' ',' coord_or_var opt_coord_or_var ')'  */
#line 2709 "lev_comp.y"
                  {
		      add_opvars(splev, "iio", (yyvsp[-5].i), (yyvsp[-11].i), SPO_SEL_GRADIENT);
		  }
#line 5676 "lev.tab.c"
    break;

  case 437: /* ter_selection_x: complement_ID ter_selection_x  */
#line 2713 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_COMPLEMENT);
		  }
#line 5684 "lev.tab.c"
    break;

  case 438: /* ter_selection_x: VARSTRING_SEL  */
#line 2717 "lev_comp.y"
                  {
		      check_vardef_type(variable_definitions, (yyvsp[0].map), SPOVAR_SEL);
		      vardef_used(variable_definitions, (yyvsp[0].map));
		      add_opvars(splev, "v", (yyvsp[0].map));
		      Free((yyvsp[0].map));
		  }
#line 5695 "lev.tab.c"
    break;

  case 439: /* ter_selection_x: '(' ter_selection ')'  */
#line 2724 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 5703 "lev.tab.c"
    break;

  case 440: /* ter_selection: ter_selection_x  */
#line 2730 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 5711 "lev.tab.c"
    break;

  case 441: /* ter_selection: ter_selection_x '&' ter_selection  */
#line 2734 "lev_comp.y"
                  {
		      add_opvars(splev, "o", SPO_SEL_ADD);
		  }
#line 5719 "lev.tab.c"
    break;

  case 442: /* dice: DICE  */
#line 2740 "lev_comp.y"
                  {
		      add_opvars(splev, "iio", (yyvsp[0].dice).num, (yyvsp[0].dice).die, SPO_DICE);
		  }
#line 5727 "lev.tab.c"
    break;

  case 446: /* all_ints_push: MINUS_INTEGER  */
#line 2751 "lev_comp.y"
                  {
		      add_opvars(splev, "i", (yyvsp[0].i) );
		  }
#line 5735 "lev.tab.c"
    break;

  case 447: /* all_ints_push: PLUS_INTEGER  */
#line 2755 "lev_comp.y"
                  {
		      add_opvars(splev, "i", (yyvsp[0].i) );
		  }
#line 5743 "lev.tab.c"
    break;

  case 448: /* all_ints_push: INTEGER  */
#line 2759 "lev_comp.y"
                  {
		      add_opvars(splev, "i", (yyvsp[0].i) );
		  }
#line 5751 "lev.tab.c"
    break;

  case 449: /* all_ints_push: dice  */
#line 2763 "lev_comp.y"
                  {
		      /* nothing */
		  }
#line 5759 "lev.tab.c"
    break;

  case 458: /* lev_region: region  */
#line 2785 "lev_comp.y"
                  {
			(yyval.lregn) = (yyvsp[0].lregn);
		  }
#line 5767 "lev.tab.c"
    break;

  case 459: /* lev_region: LEV '(' INTEGER ',' INTEGER ',' INTEGER ',' INTEGER ')'  */
#line 2789 "lev_comp.y"
                  {
			if ((yyvsp[-7].i) <= 0 || (yyvsp[-7].i) >= COLNO)
			    lc_error("Region (%li,%li,%li,%li) out of level range (x1)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) >= ROWNO)
			    lc_error("Region (%li,%li,%li,%li) out of level range (y1)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-3].i) <= 0 || (yyvsp[-3].i) >= COLNO)
			    lc_error("Region (%li,%li,%li,%li) out of level range (x2)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) >= ROWNO)
			    lc_error("Region (%li,%li,%li,%li) out of level range (y2)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			(yyval.lregn).x1 = (yyvsp[-7].i);
			(yyval.lregn).y1 = (yyvsp[-5].i);
			(yyval.lregn).x2 = (yyvsp[-3].i);
			(yyval.lregn).y2 = (yyvsp[-1].i);
			(yyval.lregn).area = 1;
		  }
#line 5787 "lev.tab.c"
    break;

  case 460: /* region: '(' INTEGER ',' INTEGER ',' INTEGER ',' INTEGER ')'  */
#line 2807 "lev_comp.y"
                  {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[-7].i) < 0 || (yyvsp[-7].i) > (int)max_x_map)
			    lc_error("Region (%li,%li,%li,%li) out of map range (x1)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) > (int)max_y_map)
			    lc_error("Region (%li,%li,%li,%li) out of map range (y1)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-3].i) < 0 || (yyvsp[-3].i) > (int)max_x_map)
			    lc_error("Region (%li,%li,%li,%li) out of map range (x2)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) > (int)max_y_map)
			    lc_error("Region (%li,%li,%li,%li) out of map range (y2)!", (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i));
			(yyval.lregn).area = 0;
			(yyval.lregn).x1 = (yyvsp[-7].i);
			(yyval.lregn).y1 = (yyvsp[-5].i);
			(yyval.lregn).x2 = (yyvsp[-3].i);
			(yyval.lregn).y2 = (yyvsp[-1].i);
		  }
#line 5809 "lev.tab.c"
    break;


#line 5813 "lev.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2827 "lev_comp.y"


/*lev_comp.y*/
