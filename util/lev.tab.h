/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LEV_TAB_H_INCLUDED
# define YY_YY_LEV_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    PERCENT = 261,                 /* PERCENT  */
    SPERCENT = 262,                /* SPERCENT  */
    MINUS_INTEGER = 263,           /* MINUS_INTEGER  */
    PLUS_INTEGER = 264,            /* PLUS_INTEGER  */
    MAZE_GRID_ID = 265,            /* MAZE_GRID_ID  */
    SOLID_FILL_ID = 266,           /* SOLID_FILL_ID  */
    MINES_ID = 267,                /* MINES_ID  */
    SHEOL_ID = 268,                /* SHEOL_ID  */
    ROGUELEV_ID = 269,             /* ROGUELEV_ID  */
    MESSAGE_ID = 270,              /* MESSAGE_ID  */
    LEVEL_ID = 271,                /* LEVEL_ID  */
    LEV_INIT_ID = 272,             /* LEV_INIT_ID  */
    GEOMETRY_ID = 273,             /* GEOMETRY_ID  */
    NOMAP_ID = 274,                /* NOMAP_ID  */
    OBJECT_ID = 275,               /* OBJECT_ID  */
    COBJECT_ID = 276,              /* COBJECT_ID  */
    MONSTER_ID = 277,              /* MONSTER_ID  */
    TRAP_ID = 278,                 /* TRAP_ID  */
    DOOR_ID = 279,                 /* DOOR_ID  */
    DRAWBRIDGE_ID = 280,           /* DRAWBRIDGE_ID  */
    object_ID = 281,               /* object_ID  */
    monster_ID = 282,              /* monster_ID  */
    terrain_ID = 283,              /* terrain_ID  */
    MAZEWALK_ID = 284,             /* MAZEWALK_ID  */
    WALLIFY_ID = 285,              /* WALLIFY_ID  */
    REGION_ID = 286,               /* REGION_ID  */
    FILLING = 287,                 /* FILLING  */
    IRREGULAR = 288,               /* IRREGULAR  */
    JOINED = 289,                  /* JOINED  */
    ALTAR_ID = 290,                /* ALTAR_ID  */
    LADDER_ID = 291,               /* LADDER_ID  */
    STAIR_ID = 292,                /* STAIR_ID  */
    NON_DIGGABLE_ID = 293,         /* NON_DIGGABLE_ID  */
    NON_PASSWALL_ID = 294,         /* NON_PASSWALL_ID  */
    ROOM_ID = 295,                 /* ROOM_ID  */
    PORTAL_ID = 296,               /* PORTAL_ID  */
    TELEPRT_ID = 297,              /* TELEPRT_ID  */
    BRANCH_ID = 298,               /* BRANCH_ID  */
    LEV = 299,                     /* LEV  */
    CHANCE_ID = 300,               /* CHANCE_ID  */
    MINERALIZE_ID = 301,           /* MINERALIZE_ID  */
    CORRIDOR_ID = 302,             /* CORRIDOR_ID  */
    GOLD_ID = 303,                 /* GOLD_ID  */
    ENGRAVING_ID = 304,            /* ENGRAVING_ID  */
    FOUNTAIN_ID = 305,             /* FOUNTAIN_ID  */
    POOL_ID = 306,                 /* POOL_ID  */
    SINK_ID = 307,                 /* SINK_ID  */
    NONE = 308,                    /* NONE  */
    RAND_CORRIDOR_ID = 309,        /* RAND_CORRIDOR_ID  */
    DOOR_STATE = 310,              /* DOOR_STATE  */
    LIGHT_STATE = 311,             /* LIGHT_STATE  */
    CURSE_TYPE = 312,              /* CURSE_TYPE  */
    ENGRAVING_TYPE = 313,          /* ENGRAVING_TYPE  */
    DIRECTION = 314,               /* DIRECTION  */
    RANDOM_TYPE = 315,             /* RANDOM_TYPE  */
    RANDOM_TYPE_BRACKET = 316,     /* RANDOM_TYPE_BRACKET  */
    A_REGISTER = 317,              /* A_REGISTER  */
    ALIGNMENT = 318,               /* ALIGNMENT  */
    LEFT_OR_RIGHT = 319,           /* LEFT_OR_RIGHT  */
    CENTER = 320,                  /* CENTER  */
    TOP_OR_BOT = 321,              /* TOP_OR_BOT  */
    ALTAR_TYPE = 322,              /* ALTAR_TYPE  */
    UP_OR_DOWN = 323,              /* UP_OR_DOWN  */
    SUBROOM_ID = 324,              /* SUBROOM_ID  */
    NAME_ID = 325,                 /* NAME_ID  */
    FLAGS_ID = 326,                /* FLAGS_ID  */
    FLAG_TYPE = 327,               /* FLAG_TYPE  */
    MON_ATTITUDE = 328,            /* MON_ATTITUDE  */
    MON_ALERTNESS = 329,           /* MON_ALERTNESS  */
    MON_APPEARANCE = 330,          /* MON_APPEARANCE  */
    ROOMDOOR_ID = 331,             /* ROOMDOOR_ID  */
    IF_ID = 332,                   /* IF_ID  */
    ELSE_ID = 333,                 /* ELSE_ID  */
    SPILL_ID = 334,                /* SPILL_ID  */
    TERRAIN_ID = 335,              /* TERRAIN_ID  */
    HORIZ_OR_VERT = 336,           /* HORIZ_OR_VERT  */
    REPLACE_TERRAIN_ID = 337,      /* REPLACE_TERRAIN_ID  */
    EXIT_ID = 338,                 /* EXIT_ID  */
    SHUFFLE_ID = 339,              /* SHUFFLE_ID  */
    QUANTITY_ID = 340,             /* QUANTITY_ID  */
    BURIED_ID = 341,               /* BURIED_ID  */
    LOOP_ID = 342,                 /* LOOP_ID  */
    FOR_ID = 343,                  /* FOR_ID  */
    TO_ID = 344,                   /* TO_ID  */
    SWITCH_ID = 345,               /* SWITCH_ID  */
    CASE_ID = 346,                 /* CASE_ID  */
    BREAK_ID = 347,                /* BREAK_ID  */
    DEFAULT_ID = 348,              /* DEFAULT_ID  */
    ERODED_ID = 349,               /* ERODED_ID  */
    TRAPPED_STATE = 350,           /* TRAPPED_STATE  */
    RECHARGED_ID = 351,            /* RECHARGED_ID  */
    INVIS_ID = 352,                /* INVIS_ID  */
    GREASED_ID = 353,              /* GREASED_ID  */
    FEMALE_ID = 354,               /* FEMALE_ID  */
    CANCELLED_ID = 355,            /* CANCELLED_ID  */
    REVIVED_ID = 356,              /* REVIVED_ID  */
    AVENGE_ID = 357,               /* AVENGE_ID  */
    FLEEING_ID = 358,              /* FLEEING_ID  */
    BLINDED_ID = 359,              /* BLINDED_ID  */
    PARALYZED_ID = 360,            /* PARALYZED_ID  */
    STUNNED_ID = 361,              /* STUNNED_ID  */
    CONFUSED_ID = 362,             /* CONFUSED_ID  */
    SEENTRAPS_ID = 363,            /* SEENTRAPS_ID  */
    ALL_ID = 364,                  /* ALL_ID  */
    MON_GENERATION_ID = 365,       /* MON_GENERATION_ID  */
    MONTYPE_ID = 366,              /* MONTYPE_ID  */
    GRAVE_ID = 367,                /* GRAVE_ID  */
    ERODEPROOF_ID = 368,           /* ERODEPROOF_ID  */
    FUNCTION_ID = 369,             /* FUNCTION_ID  */
    INCLUDE_ID = 370,              /* INCLUDE_ID  */
    SOUNDS_ID = 371,               /* SOUNDS_ID  */
    MSG_OUTPUT_TYPE = 372,         /* MSG_OUTPUT_TYPE  */
    WALLWALK_ID = 373,             /* WALLWALK_ID  */
    COMPARE_TYPE = 374,            /* COMPARE_TYPE  */
    VAULTGEN_ID = 375,             /* VAULTGEN_ID  */
    rect_ID = 376,                 /* rect_ID  */
    fillrect_ID = 377,             /* fillrect_ID  */
    line_ID = 378,                 /* line_ID  */
    randline_ID = 379,             /* randline_ID  */
    grow_ID = 380,                 /* grow_ID  */
    selection_ID = 381,            /* selection_ID  */
    flood_ID = 382,                /* flood_ID  */
    rndcoord_ID = 383,             /* rndcoord_ID  */
    circle_ID = 384,               /* circle_ID  */
    ellipse_ID = 385,              /* ellipse_ID  */
    filter_ID = 386,               /* filter_ID  */
    complement_ID = 387,           /* complement_ID  */
    gradient_ID = 388,             /* gradient_ID  */
    GRADIENT_TYPE = 389,           /* GRADIENT_TYPE  */
    LIMITED = 390,                 /* LIMITED  */
    HUMIDITY_TYPE = 391,           /* HUMIDITY_TYPE  */
    STRING = 392,                  /* STRING  */
    MAP_ID = 393,                  /* MAP_ID  */
    NQSTRING = 394,                /* NQSTRING  */
    VARSTRING = 395,               /* VARSTRING  */
    CFUNC = 396,                   /* CFUNC  */
    CFUNC_INT = 397,               /* CFUNC_INT  */
    CFUNC_STR = 398,               /* CFUNC_STR  */
    CFUNC_COORD = 399,             /* CFUNC_COORD  */
    CFUNC_REGION = 400,            /* CFUNC_REGION  */
    VARSTRING_INT = 401,           /* VARSTRING_INT  */
    VARSTRING_INT_ARRAY = 402,     /* VARSTRING_INT_ARRAY  */
    VARSTRING_STRING = 403,        /* VARSTRING_STRING  */
    VARSTRING_STRING_ARRAY = 404,  /* VARSTRING_STRING_ARRAY  */
    VARSTRING_VAR = 405,           /* VARSTRING_VAR  */
    VARSTRING_VAR_ARRAY = 406,     /* VARSTRING_VAR_ARRAY  */
    VARSTRING_COORD = 407,         /* VARSTRING_COORD  */
    VARSTRING_COORD_ARRAY = 408,   /* VARSTRING_COORD_ARRAY  */
    VARSTRING_REGION = 409,        /* VARSTRING_REGION  */
    VARSTRING_REGION_ARRAY = 410,  /* VARSTRING_REGION_ARRAY  */
    VARSTRING_MAPCHAR = 411,       /* VARSTRING_MAPCHAR  */
    VARSTRING_MAPCHAR_ARRAY = 412, /* VARSTRING_MAPCHAR_ARRAY  */
    VARSTRING_MONST = 413,         /* VARSTRING_MONST  */
    VARSTRING_MONST_ARRAY = 414,   /* VARSTRING_MONST_ARRAY  */
    VARSTRING_OBJ = 415,           /* VARSTRING_OBJ  */
    VARSTRING_OBJ_ARRAY = 416,     /* VARSTRING_OBJ_ARRAY  */
    VARSTRING_SEL = 417,           /* VARSTRING_SEL  */
    VARSTRING_SEL_ARRAY = 418,     /* VARSTRING_SEL_ARRAY  */
    METHOD_INT = 419,              /* METHOD_INT  */
    METHOD_INT_ARRAY = 420,        /* METHOD_INT_ARRAY  */
    METHOD_STRING = 421,           /* METHOD_STRING  */
    METHOD_STRING_ARRAY = 422,     /* METHOD_STRING_ARRAY  */
    METHOD_VAR = 423,              /* METHOD_VAR  */
    METHOD_VAR_ARRAY = 424,        /* METHOD_VAR_ARRAY  */
    METHOD_COORD = 425,            /* METHOD_COORD  */
    METHOD_COORD_ARRAY = 426,      /* METHOD_COORD_ARRAY  */
    METHOD_REGION = 427,           /* METHOD_REGION  */
    METHOD_REGION_ARRAY = 428,     /* METHOD_REGION_ARRAY  */
    METHOD_MAPCHAR = 429,          /* METHOD_MAPCHAR  */
    METHOD_MAPCHAR_ARRAY = 430,    /* METHOD_MAPCHAR_ARRAY  */
    METHOD_MONST = 431,            /* METHOD_MONST  */
    METHOD_MONST_ARRAY = 432,      /* METHOD_MONST_ARRAY  */
    METHOD_OBJ = 433,              /* METHOD_OBJ  */
    METHOD_OBJ_ARRAY = 434,        /* METHOD_OBJ_ARRAY  */
    METHOD_SEL = 435,              /* METHOD_SEL  */
    METHOD_SEL_ARRAY = 436,        /* METHOD_SEL_ARRAY  */
    DICE = 437                     /* DICE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define INTEGER 259
#define BOOLEAN 260
#define PERCENT 261
#define SPERCENT 262
#define MINUS_INTEGER 263
#define PLUS_INTEGER 264
#define MAZE_GRID_ID 265
#define SOLID_FILL_ID 266
#define MINES_ID 267
#define SHEOL_ID 268
#define ROGUELEV_ID 269
#define MESSAGE_ID 270
#define LEVEL_ID 271
#define LEV_INIT_ID 272
#define GEOMETRY_ID 273
#define NOMAP_ID 274
#define OBJECT_ID 275
#define COBJECT_ID 276
#define MONSTER_ID 277
#define TRAP_ID 278
#define DOOR_ID 279
#define DRAWBRIDGE_ID 280
#define object_ID 281
#define monster_ID 282
#define terrain_ID 283
#define MAZEWALK_ID 284
#define WALLIFY_ID 285
#define REGION_ID 286
#define FILLING 287
#define IRREGULAR 288
#define JOINED 289
#define ALTAR_ID 290
#define LADDER_ID 291
#define STAIR_ID 292
#define NON_DIGGABLE_ID 293
#define NON_PASSWALL_ID 294
#define ROOM_ID 295
#define PORTAL_ID 296
#define TELEPRT_ID 297
#define BRANCH_ID 298
#define LEV 299
#define CHANCE_ID 300
#define MINERALIZE_ID 301
#define CORRIDOR_ID 302
#define GOLD_ID 303
#define ENGRAVING_ID 304
#define FOUNTAIN_ID 305
#define POOL_ID 306
#define SINK_ID 307
#define NONE 308
#define RAND_CORRIDOR_ID 309
#define DOOR_STATE 310
#define LIGHT_STATE 311
#define CURSE_TYPE 312
#define ENGRAVING_TYPE 313
#define DIRECTION 314
#define RANDOM_TYPE 315
#define RANDOM_TYPE_BRACKET 316
#define A_REGISTER 317
#define ALIGNMENT 318
#define LEFT_OR_RIGHT 319
#define CENTER 320
#define TOP_OR_BOT 321
#define ALTAR_TYPE 322
#define UP_OR_DOWN 323
#define SUBROOM_ID 324
#define NAME_ID 325
#define FLAGS_ID 326
#define FLAG_TYPE 327
#define MON_ATTITUDE 328
#define MON_ALERTNESS 329
#define MON_APPEARANCE 330
#define ROOMDOOR_ID 331
#define IF_ID 332
#define ELSE_ID 333
#define SPILL_ID 334
#define TERRAIN_ID 335
#define HORIZ_OR_VERT 336
#define REPLACE_TERRAIN_ID 337
#define EXIT_ID 338
#define SHUFFLE_ID 339
#define QUANTITY_ID 340
#define BURIED_ID 341
#define LOOP_ID 342
#define FOR_ID 343
#define TO_ID 344
#define SWITCH_ID 345
#define CASE_ID 346
#define BREAK_ID 347
#define DEFAULT_ID 348
#define ERODED_ID 349
#define TRAPPED_STATE 350
#define RECHARGED_ID 351
#define INVIS_ID 352
#define GREASED_ID 353
#define FEMALE_ID 354
#define CANCELLED_ID 355
#define REVIVED_ID 356
#define AVENGE_ID 357
#define FLEEING_ID 358
#define BLINDED_ID 359
#define PARALYZED_ID 360
#define STUNNED_ID 361
#define CONFUSED_ID 362
#define SEENTRAPS_ID 363
#define ALL_ID 364
#define MON_GENERATION_ID 365
#define MONTYPE_ID 366
#define GRAVE_ID 367
#define ERODEPROOF_ID 368
#define FUNCTION_ID 369
#define INCLUDE_ID 370
#define SOUNDS_ID 371
#define MSG_OUTPUT_TYPE 372
#define WALLWALK_ID 373
#define COMPARE_TYPE 374
#define VAULTGEN_ID 375
#define rect_ID 376
#define fillrect_ID 377
#define line_ID 378
#define randline_ID 379
#define grow_ID 380
#define selection_ID 381
#define flood_ID 382
#define rndcoord_ID 383
#define circle_ID 384
#define ellipse_ID 385
#define filter_ID 386
#define complement_ID 387
#define gradient_ID 388
#define GRADIENT_TYPE 389
#define LIMITED 390
#define HUMIDITY_TYPE 391
#define STRING 392
#define MAP_ID 393
#define NQSTRING 394
#define VARSTRING 395
#define CFUNC 396
#define CFUNC_INT 397
#define CFUNC_STR 398
#define CFUNC_COORD 399
#define CFUNC_REGION 400
#define VARSTRING_INT 401
#define VARSTRING_INT_ARRAY 402
#define VARSTRING_STRING 403
#define VARSTRING_STRING_ARRAY 404
#define VARSTRING_VAR 405
#define VARSTRING_VAR_ARRAY 406
#define VARSTRING_COORD 407
#define VARSTRING_COORD_ARRAY 408
#define VARSTRING_REGION 409
#define VARSTRING_REGION_ARRAY 410
#define VARSTRING_MAPCHAR 411
#define VARSTRING_MAPCHAR_ARRAY 412
#define VARSTRING_MONST 413
#define VARSTRING_MONST_ARRAY 414
#define VARSTRING_OBJ 415
#define VARSTRING_OBJ_ARRAY 416
#define VARSTRING_SEL 417
#define VARSTRING_SEL_ARRAY 418
#define METHOD_INT 419
#define METHOD_INT_ARRAY 420
#define METHOD_STRING 421
#define METHOD_STRING_ARRAY 422
#define METHOD_VAR 423
#define METHOD_VAR_ARRAY 424
#define METHOD_COORD 425
#define METHOD_COORD_ARRAY 426
#define METHOD_REGION 427
#define METHOD_REGION_ARRAY 428
#define METHOD_MAPCHAR 429
#define METHOD_MAPCHAR_ARRAY 430
#define METHOD_MONST 431
#define METHOD_MONST_ARRAY 432
#define METHOD_OBJ 433
#define METHOD_OBJ_ARRAY 434
#define METHOD_SEL 435
#define METHOD_SEL_ARRAY 436
#define DICE 437

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 154 "lev_comp.y"

	long	i;
	char*	map;
	struct {
		long room;
		long wall;
		long door;
	} corpos;
    struct {
	long area;
	long x1;
	long y1;
	long x2;
	long y2;
    } lregn;
    struct {
	long x;
	long y;
    } crd;
    struct {
	long ter;
	long lit;
    } terr;
    struct {
	long height;
	long width;
    } sze;
    struct {
	long die;
	long num;
    } dice;
    struct {
	long cfunc;
	char *varstr;
    } meth;

#line 468 "lev.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LEV_TAB_H_INCLUDED  */
