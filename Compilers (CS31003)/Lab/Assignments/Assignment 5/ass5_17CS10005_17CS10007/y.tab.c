/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "ass5_17CS10007_17CS10005.y" /* yacc.c:339  */

#include "ass5_17CS10007_17CS10005_translator.h"
SymTab* globalTab;    
SymTab* currentTab;
quad qArray[256];
int noTemp=0;		  
int nextinstr=0;
string dataType;
int dataSize=0;
void yyerror(char *s);

#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    _BOOL = 292,
    _COMPLEX = 293,
    _IMAGINARY = 294,
    INT_CONST = 295,
    FRACTION_CONST = 296,
    FLOAT_CONST = 297,
    CHAR_CONST = 298,
    STRING_LITERAL = 299,
    IDENTIFIER = 300,
    L_PARAN = 301,
    R_PARAN = 302,
    L_SQRB = 303,
    R_SQRB = 304,
    DOT = 305,
    ARROW_ASSIGN = 306,
    INCREMENT = 307,
    DECREMENT = 308,
    L_BRACES = 309,
    R_BRACES = 310,
    COMMA = 311,
    BIT_AND = 312,
    ADD = 313,
    MINUS = 314,
    MUL = 315,
    DIVIDE = 316,
    REMAINDER = 317,
    NEGATE = 318,
    NOT = 319,
    SPACE = 320,
    L_SHIFT = 321,
    R_SHIFT = 322,
    LESS_THAN = 323,
    GREATER_THAN = 324,
    LESS_THAN_EQUAL = 325,
    GREATER_THAN_EQUAL = 326,
    IS_EQUAL = 327,
    NOT_EQUAL = 328,
    BIT_OR = 329,
    BIT_XOR = 330,
    BOOL_OR = 331,
    BOOL_AND = 332,
    QM = 333,
    COLON = 334,
    ASSIGN = 335,
    ADD_ASSIGN = 336,
    MINUS_ASSIGN = 337,
    MUL_ASSIGN = 338,
    DIVIDE_ASSIGN = 339,
    REM_ASSIGN = 340,
    L_SHIFT_ASSIGN = 341,
    R_SHIFT_ASSIGN = 342,
    BIT_AND_ASSIGN = 343,
    BIT_OR_ASSIGN = 344,
    BIT_XOR_ASSIGN = 345,
    ELLIPSES = 346,
    SEMICOLON = 347,
    HASH = 348
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define _BOOL 292
#define _COMPLEX 293
#define _IMAGINARY 294
#define INT_CONST 295
#define FRACTION_CONST 296
#define FLOAT_CONST 297
#define CHAR_CONST 298
#define STRING_LITERAL 299
#define IDENTIFIER 300
#define L_PARAN 301
#define R_PARAN 302
#define L_SQRB 303
#define R_SQRB 304
#define DOT 305
#define ARROW_ASSIGN 306
#define INCREMENT 307
#define DECREMENT 308
#define L_BRACES 309
#define R_BRACES 310
#define COMMA 311
#define BIT_AND 312
#define ADD 313
#define MINUS 314
#define MUL 315
#define DIVIDE 316
#define REMAINDER 317
#define NEGATE 318
#define NOT 319
#define SPACE 320
#define L_SHIFT 321
#define R_SHIFT 322
#define LESS_THAN 323
#define GREATER_THAN 324
#define LESS_THAN_EQUAL 325
#define GREATER_THAN_EQUAL 326
#define IS_EQUAL 327
#define NOT_EQUAL 328
#define BIT_OR 329
#define BIT_XOR 330
#define BOOL_OR 331
#define BOOL_AND 332
#define QM 333
#define COLON 334
#define ASSIGN 335
#define ADD_ASSIGN 336
#define MINUS_ASSIGN 337
#define MUL_ASSIGN 338
#define DIVIDE_ASSIGN 339
#define REM_ASSIGN 340
#define L_SHIFT_ASSIGN 341
#define R_SHIFT_ASSIGN 342
#define BIT_AND_ASSIGN 343
#define BIT_OR_ASSIGN 344
#define BIT_XOR_ASSIGN 345
#define ELLIPSES 346
#define SEMICOLON 347
#define HASH 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "ass5_17CS10007_17CS10005.y" /* yacc.c:355  */

	int intval;
	double real;
	char *str;
	OpcodeType op;
	SymNode *symnode;  
	SymTab* symtab;
	List* list;
	IdList* idlist;
	ParamList* paramlist;

#line 316 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 333 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   110,   121,   132,   143,   152,   161,   165,
     167,   183,   189,   208,   208,   210,   220,   230,   231,   236,
     241,   248,   250,   256,   262,   339,   339,   343,   344,   345,
     346,   347,   348,   352,   354,   363,   365,   389,   413,   427,
     429,   453,   478,   480,   492,   506,   508,   518,   528,   538,
     550,   552,   562,   574,   576,   591,   593,   608,   610,   625,
     627,   638,   640,   651,   653,   671,   673,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   696,   696,
     700,   702,   702,   702,   702,   706,   712,   718,   719,   724,
     726,   732,   737,   738,   739,   740,   741,   742,   745,   748,
     749,   752,   753,   764,   765,   766,   767,   768,   769,   770,
     771,   774,   774,   777,   777,   777,   780,   781,   782,   783,
     786,   786,   789,   789,   792,   793,   794,   795,   796,   800,
     806,   807,   809,   818,   825,   826,   827,   828,   830,   845,
     846,   847,   848,   849,   851,   859,   867,   876,   878,   893,
     893,   896,   896,   899,   900,   903,   905,   913,   921,   932,
     936,   937,   938,   942,   943,   944,   945,   948,   952,   952,
     956,   956,   959,   960,   961,   965,   966,   970,   971,   975,
     976,   980,   981,   984,   987,   993,   994,   999,  1004,  1013,
    1021,  1028,  1033,  1044,  1051,  1062,  1063,  1064,  1065,  1070,
    1071,  1072,  1073,  1074,  1077,  1078,  1079,  1080,  1081,  1082,
    1085,  1085,  1088,  1088,  1091,  1092,  1099,  1100,  1104,  1111
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL",
  "_COMPLEX", "_IMAGINARY", "INT_CONST", "FRACTION_CONST", "FLOAT_CONST",
  "CHAR_CONST", "STRING_LITERAL", "IDENTIFIER", "L_PARAN", "R_PARAN",
  "L_SQRB", "R_SQRB", "DOT", "ARROW_ASSIGN", "INCREMENT", "DECREMENT",
  "L_BRACES", "R_BRACES", "COMMA", "BIT_AND", "ADD", "MINUS", "MUL",
  "DIVIDE", "REMAINDER", "NEGATE", "NOT", "SPACE", "L_SHIFT", "R_SHIFT",
  "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL",
  "IS_EQUAL", "NOT_EQUAL", "BIT_OR", "BIT_XOR", "BOOL_OR", "BOOL_AND",
  "QM", "COLON", "ASSIGN", "ADD_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN",
  "DIVIDE_ASSIGN", "REM_ASSIGN", "L_SHIFT_ASSIGN", "R_SHIFT_ASSIGN",
  "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "BIT_XOR_ASSIGN", "ELLIPSES",
  "SEMICOLON", "HASH", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "BOOL_AND_expression", "BOOL_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "storage_class_specifier",
  "type_specifier", "function_specifier", "init_declarator_list",
  "init_declarator", "declaration_specifiers", "declaration",
  "type_qualifier", "specifier_qualifier_list", "enumerator",
  "enumerator_list", "enum_specifier", "pointer", "direct_declarator",
  "declarator", "type_qualifier_list", "parameter_type_list",
  "parameter_declaration", "parameter_list", "identifier_list",
  "type_name", "initializer", "initializer_list", "designation",
  "designator_list", "designator", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "M", "N", "expression_opt1", "expression_opt2",
  "selection_statement", "iteration_statement", "jump_statement",
  "statement", "external_declaration", "translation_unit",
  "declaration_list", "function_definition", "X", "Y", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF -290

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-290)))

#define YYTABLE_NINF -185

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1187,  -290,  -290,  -290,  -290,    30,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  1187,  1187,  1187,   -28,   -84,  1187,  -290,  -290,
     849,  -290,   -12,     0,  -290,  -290,  -290,  -290,   -28,    81,
     -34,  -290,   176,    69,   488,  -290,  -290,  -290,  -290,     0,
     -24,  -290,   135,    35,  -290,  -290,    81,   -28,    69,  -290,
     656,   331,   937,   -28,  -290,  -290,   769,  -290,   168,  1074,
    -290,    64,  -290,  -290,  -290,  -290,    -3,   806,  1101,   710,
    -290,  -290,  -290,  -290,  -290,  -290,   614,  -290,  1128,  1128,
    -290,  -290,  -290,    49,  -290,  -290,  -290,   125,   118,  1074,
    -290,   121,   169,   163,   145,   161,    61,    89,    70,    97,
      36,  -290,   138,   683,    92,  1074,   134,   131,  -290,   185,
     195,   203,     8,   207,  -290,   178,  -290,  -290,  -290,  -290,
     -23,  -290,  -290,   200,  -290,  -290,  1187,  -290,  -290,  -290,
    -290,   909,  -290,  -290,  -290,  -290,  -290,  -290,    66,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,   -28,   211,  -290,   205,
      93,   614,  -290,   210,   710,    99,  1221,  1221,  -290,   215,
     614,  -290,  -290,  -290,   965,  1074,   219,   220,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  1074,  -290,  1074,  1074,  1074,  1074,  1074,  1074,  1074,
    1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  -290,
    -290,  -290,  -290,  1074,  -290,   217,   218,  -290,   189,  -290,
     388,   388,   559,   179,  1074,  -290,   -19,  1074,   224,   388,
    1074,  -290,  -290,   388,  -290,  1074,   227,  -290,   180,   937,
      14,  -290,  -290,  -290,  -290,  -290,   450,  -290,   228,   231,
    -290,   226,  -290,  -290,  -290,   992,   232,  -290,   100,  -290,
     109,  -290,  -290,  -290,  -290,  -290,  -290,   121,   121,   169,
     169,   163,   163,   163,   163,   145,   145,   161,    61,    89,
    1074,  1074,  1074,   233,  -290,  -290,   388,  -290,  -290,   225,
     491,   188,  -290,   225,   237,  -290,   105,  1074,  -290,  -290,
    -290,   238,  -290,  -290,   851,  -290,  -290,  -290,  -290,  -290,
    -290,   235,  -290,   909,  -290,   235,  -290,  1074,  -290,    70,
      97,   225,  -290,  -290,   250,  1020,   -13,  -290,  -290,   388,
     246,  -290,  -290,  -290,   937,   183,  -290,   216,   248,   388,
     113,  1047,  1074,   388,  -290,  -290,  -290,  -290,   880,  -290,
    1074,  -290,   388,   388,   116,   206,   287,   388,  -290,  1074,
     253,  -290,  -290,   388,  -290,   289,  -290,  -290,   212,  -290,
    1074,  -290,  -290,  -290,   388,   255,  -290,  -290,   388,  -290
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    86,   113,    91,     0,    81,    90,    98,    88,
      89,    84,   114,    87,    92,    82,    93,    85,   115,    94,
      95,    96,   103,   105,   109,   111,     0,   107,    97,   212,
       0,   210,   128,     0,   104,   106,   110,   133,     0,   129,
     112,    99,     0,   147,   101,   219,   108,     1,   213,     0,
     120,   122,     0,     0,   149,   132,   130,     0,   148,   218,
       0,   183,     0,   111,   214,   219,     0,   211,     0,     0,
     125,     0,   134,   150,   131,   100,   101,     0,     0,     0,
       3,     5,     4,     6,     7,     2,     0,   136,     0,     0,
      31,    27,    28,    29,    30,    32,     9,    21,    33,     0,
      35,    39,    42,    45,    50,    53,    55,    57,    59,    61,
      63,    65,     0,     0,     0,     0,     0,     0,   183,     0,
       0,     0,     0,     0,   183,     2,   176,    29,   182,    78,
       0,   204,   205,   183,   177,   206,     0,   207,   208,   209,
     180,     0,   160,   102,   217,   215,   219,   124,     0,    33,
      80,   121,   127,   123,   157,   146,   153,     0,   155,   151,
       0,     0,    25,     0,     0,     0,   116,   118,   159,     0,
       0,    22,    23,   143,     0,     0,     0,     0,    15,    16,
      67,    68,    69,    70,    71,    72,    73,    74,    76,    75,
      77,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     183,   183,   138,     0,   137,    29,     0,   201,     0,   200,
       0,     0,   185,     0,   187,   203,     0,     0,     0,     0,
       0,   181,   175,   183,   179,     0,     0,   164,     0,     0,
       0,   168,   216,   126,   154,   144,     0,   145,     0,     0,
     140,     0,     8,   117,   119,     0,     0,    11,     0,    19,
       0,    13,    14,    66,    36,    37,    38,    40,    41,    43,
      44,    46,    47,    48,    49,    51,    52,    54,    56,    58,
       0,     0,     0,     0,   142,   135,     0,   174,   183,   186,
       0,     0,   199,   188,     0,   202,     0,   187,   172,    79,
     178,     0,   171,   161,     0,   163,   167,   169,   152,   156,
     158,    26,   139,     0,    34,     0,    12,     0,    10,    60,
      62,   184,   141,   173,     0,     0,     0,   183,   183,     0,
       0,   170,   162,   166,     0,     0,    20,     0,     0,     0,
       0,     0,   187,     0,   191,   183,   165,    17,     0,   183,
     187,   198,     0,     0,     0,     0,   190,     0,    18,     0,
       0,   197,   196,     0,   183,     0,   192,    64,     0,   195,
     185,   183,   193,   184,     0,     0,   189,   183,     0,   194
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -290,  -290,  -290,  -290,   -69,  -290,   -87,    46,    47,    -7,
      43,   102,    96,    98,    29,    31,  -290,   -68,   -21,  -290,
     -65,  -112,  -290,   -81,  -290,  -290,   257,     4,   -37,   -16,
      85,   -58,   261,  -290,    37,   273,   -14,    -5,  -290,    71,
    -290,  -290,   -48,   -60,     3,  -289,  -290,    78,  -290,   -30,
    -290,    86,  -290,  -108,  -278,   -47,  -259,  -290,  -290,  -290,
     -32,   292,  -290,  -290,  -290,  -290,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    96,    97,   258,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   129,   191,
     130,   151,    22,    23,    24,    40,    41,    63,    26,    27,
     168,    51,    52,    28,    42,    43,    76,    56,   157,   158,
     159,   160,   169,   237,   238,   239,   240,   241,   131,   132,
     133,   134,   135,   136,   337,   291,   294,   137,   138,   139,
     140,    29,    30,    66,    31,    77,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,   150,   143,   218,    25,   166,   144,    64,    45,   162,
     221,    44,   192,   153,    65,   334,   228,    37,    38,   171,
     172,   165,    57,    54,    53,   233,    34,    35,    36,   145,
     149,    46,    39,   230,    25,    78,   146,   230,   330,   112,
      73,   142,    49,   230,    54,    50,   149,   150,    80,    81,
      82,    83,    84,    85,    86,   113,    69,   226,   163,   334,
      88,    89,   235,    54,   236,    90,    91,    92,   127,   231,
     167,    94,    95,   295,   164,    32,    55,    62,   365,   341,
     166,   156,    72,   355,    33,   166,   166,   242,     3,   166,
     153,   360,   216,    74,   306,   375,   165,    73,   173,   234,
     225,   280,   281,   282,    12,   165,   264,   265,   266,    50,
     260,    50,   210,   249,   211,    59,    18,    60,   206,   152,
     142,   243,   256,   301,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     247,    39,   244,   251,   208,   167,   252,   316,    73,   248,
     167,   167,   329,   259,   167,   230,   317,   289,   318,   293,
     352,   230,   296,   363,   207,   230,   149,   150,   314,   230,
     263,   174,   230,   175,   209,   176,   177,   178,   179,   305,
     324,   193,   194,   195,   217,   290,   149,   212,   287,   288,
      70,    71,   283,   271,   272,   273,   274,   298,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   299,
     220,   149,   149,   200,   201,   202,   203,   321,   142,   342,
     343,    37,    38,   147,   148,   326,   219,   196,   197,   198,
     199,   222,   293,   204,   205,   303,   304,   357,   347,   348,
     223,   359,   267,   268,   333,   269,   270,   275,   276,   224,
     156,   253,   254,   227,   323,   232,   370,   229,   245,   250,
     340,   246,   255,   374,   261,   262,   284,   285,   286,   378,
     297,   292,   302,   310,   346,   312,   354,   293,   311,   315,
     327,   230,   322,   142,   328,   293,   338,   331,   333,   313,
     149,   367,   142,   345,   350,   349,   336,   344,   364,  -184,
     368,   371,   377,   278,   372,   289,   279,   351,   277,   319,
      68,   356,   320,   142,    75,    58,   335,   309,   307,   300,
     361,   362,    48,   373,     0,   366,     0,   142,     0,     0,
       0,   369,     0,     0,     0,   114,   115,     0,     0,   116,
     117,   118,   376,     0,     0,     0,   379,   119,   120,   121,
       0,     0,     0,     0,     0,   122,     0,     0,    78,     0,
       0,   123,     0,     0,     0,     0,     0,   124,     0,     0,
       0,    80,    81,    82,    83,    84,   125,    86,     0,     0,
       0,     0,     0,    88,    89,    61,   126,     0,    90,    91,
      92,   127,   114,   115,    94,    95,   116,   117,   118,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
       0,     0,   122,     0,     0,    78,     0,     0,   123,     0,
       0,     0,     0,   128,   124,     0,     0,     0,    80,    81,
      82,    83,    84,   125,    86,     0,     0,     0,     0,     0,
      88,    89,    61,     0,     0,    90,    91,    92,   127,     0,
       0,    94,    95,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
     128,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       0,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,    78,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,   308,    61,    88,    89,     0,     0,     0,    90,    91,
      92,   127,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     2,     3,     0,    62,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,   325,    13,    14,    78,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,    90,    91,    92,   127,
       2,     3,    94,    95,     0,     4,     0,     5,     0,     7,
       0,     0,     0,     0,     9,    10,     0,    12,     0,    13,
      14,    78,     0,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     3,     0,     0,    88,    89,     0,     0,
       0,    90,    91,    92,   127,     0,     0,    94,    95,    12,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       3,    18,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,    87,    12,     0,    88,    89,
      78,   213,     0,    90,    91,    92,    93,     3,    18,    94,
      95,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,   214,    12,     0,    88,    89,    78,     0,     0,
      90,    91,    92,   215,     0,    18,    94,    95,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,    88,    89,     0,     0,     0,    90,    91,    92,
     127,     0,     1,    94,    95,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,    61,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,     0,     0,     0,    47,
       0,   154,     1,   155,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,    78,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     0,   235,
       0,   236,     0,    88,    89,   141,   332,    78,    90,    91,
      92,   127,     0,     0,    94,    95,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,   235,     0,
     236,     0,    88,    89,   141,   358,    78,    90,    91,    92,
     127,     0,     0,    94,    95,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,   235,     0,   236,
       0,    88,    89,   141,    78,     0,    90,    91,    92,   127,
       0,     0,    94,    95,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,    88,
      89,   141,    78,     0,    90,    91,    92,   127,     0,     0,
      94,    95,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,   257,     0,     0,     0,     0,    88,    89,    78,
       0,     0,    90,    91,    92,   127,     0,     0,    94,    95,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,    88,    89,   313,    78,     0,    90,
      91,    92,   127,     0,     0,    94,    95,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,   339,     0,     0,
       0,     0,    88,    89,    78,     0,     0,    90,    91,    92,
     127,     0,     0,    94,    95,     0,     0,    80,    81,    82,
      83,    84,    85,    86,   353,     0,     0,     0,     0,    88,
      89,    78,     0,     0,    90,    91,    92,   127,     0,     0,
      94,    95,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    88,    89,    78,     0,
       0,    90,    91,    92,   127,     0,     0,    94,    95,     0,
       0,    80,    81,    82,    83,    84,    85,   161,     0,     0,
       0,     0,     0,    88,    89,    78,     0,     0,    90,    91,
      92,   127,     0,     0,    94,    95,     0,     0,    80,    81,
      82,    83,    84,    85,   170,     0,     0,     0,     0,     0,
      88,    89,     0,     0,     0,    90,    91,    92,   127,     0,
       1,    94,    95,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
      69,    69,    62,   115,     0,    86,    65,    44,    92,    78,
     118,    25,    99,    71,    44,   304,   124,    45,    46,    88,
      89,    86,    56,    39,    38,   133,    22,    23,    24,    66,
      99,    27,    60,    56,    30,    27,    66,    56,   297,    60,
      56,    62,    54,    56,    60,    45,   115,   115,    40,    41,
      42,    43,    44,    45,    46,    60,    80,   122,    79,   348,
      52,    53,    48,    79,    50,    57,    58,    59,    60,    92,
      86,    63,    64,    92,    79,    45,    39,    80,   356,    92,
     161,    77,    47,   342,    54,   166,   167,   146,     7,   170,
     148,   350,   113,    56,    80,   373,   161,   113,    49,   136,
      92,   209,   210,   211,    23,   170,   193,   194,   195,    45,
     175,    45,    76,   161,    78,    46,    35,    48,    57,    55,
     141,    55,   170,   235,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      47,    60,   156,   164,    74,   161,    47,    47,   164,    56,
     166,   167,    47,   174,   170,    56,    56,   222,    49,   224,
      47,    56,   227,    47,    75,    56,   235,   235,   255,    56,
     191,    46,    56,    48,    77,    50,    51,    52,    53,   239,
     288,    60,    61,    62,    92,   222,   255,    49,   220,   221,
      55,    56,   213,   200,   201,   202,   203,   229,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   230,
      79,   280,   281,    68,    69,    70,    71,   282,   239,   327,
     328,    45,    46,    55,    56,   290,    92,    58,    59,    66,
      67,    46,   297,    72,    73,    55,    56,   345,    55,    56,
      45,   349,   196,   197,   304,   198,   199,   204,   205,    46,
     246,   166,   167,    46,   286,    55,   364,    79,    47,    49,
     325,    56,    47,   371,    45,    45,    49,    49,    79,   377,
      46,    92,    45,    45,   334,    49,   341,   342,    47,    47,
      92,    56,    49,   304,    47,   350,    36,    49,   348,    54,
     359,   359,   313,    47,    46,    79,   317,   329,    92,    12,
      47,    12,    47,   207,    92,   370,   208,   339,   206,   280,
      49,   343,   281,   334,    57,    42,   313,   246,   240,   233,
     352,   353,    30,   370,    -1,   357,    -1,   348,    -1,    -1,
      -1,   363,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,
       9,    10,   374,    -1,    -1,    -1,   378,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,     4,     5,    63,    64,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    92,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    63,    64,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      92,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
      -1,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    27,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    91,    54,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,    -1,    80,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    92,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,    60,
       6,     7,    63,    64,    -1,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    -1,    23,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,     7,    -1,    -1,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    63,    64,    23,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
       7,    35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    49,    23,    -1,    52,    53,
      27,    28,    -1,    57,    58,    59,    60,     7,    35,    63,
      64,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    23,    -1,    52,    53,    27,    -1,    -1,
      57,    58,    59,    60,    -1,    35,    63,    64,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,     3,    63,    64,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    54,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,    -1,    -1,    -1,     0,
      -1,    45,     3,    47,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    27,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    50,    -1,    52,    53,    54,    55,    27,    57,    58,
      59,    60,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      50,    -1,    52,    53,    54,    55,    27,    57,    58,    59,
      60,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    50,
      -1,    52,    53,    54,    27,    -1,    57,    58,    59,    60,
      -1,    -1,    63,    64,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    27,    -1,    57,    58,    59,    60,    -1,    -1,
      63,    64,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    27,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    63,    64,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    27,    -1,    57,
      58,    59,    60,    -1,    -1,    63,    64,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    27,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    63,    64,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    27,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      63,    64,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    53,    27,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    63,    64,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,    27,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    63,    64,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
       3,    63,    64,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   116,   117,   118,   121,   122,   123,   127,   155,
     156,   158,    45,    54,   121,   121,   121,    45,    46,    60,
     119,   120,   128,   129,   130,    92,   121,     0,   155,    54,
      45,   125,   126,   130,   123,   128,   131,    56,   129,    46,
      48,    54,    80,   121,   122,   143,   157,   160,   126,    80,
      55,    56,    47,   123,   128,   120,   130,   159,    27,    28,
      40,    41,    42,    43,    44,    45,    46,    49,    52,    53,
      57,    58,    59,    60,    63,    64,    95,    96,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   131,     4,     5,     8,     9,    10,    16,
      17,    18,    24,    30,    36,    45,    55,    60,    92,   112,
     114,   142,   143,   144,   145,   146,   147,   151,   152,   153,
     154,    54,   112,   137,   160,   122,   143,    55,    56,    98,
     111,   115,    55,   125,    45,    47,   121,   132,   133,   134,
     135,    46,    98,   112,   131,   114,   117,   123,   124,   136,
      46,    98,    98,    49,    46,    48,    50,    51,    52,    53,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   113,   100,    60,    61,    62,    58,    59,    66,    67,
      68,    69,    70,    71,    72,    73,    57,    75,    74,    77,
      76,    78,    49,    28,    49,    60,   112,    92,   115,    92,
      79,   147,    46,    45,    46,    92,   114,    46,   147,    79,
      56,    92,    55,   147,   122,    48,    50,   137,   138,   139,
     140,   141,   160,    55,   130,    47,    56,    47,    56,   136,
      49,   112,    47,   124,   124,    47,   136,    47,    97,   112,
     114,    45,    45,   112,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   104,   105,   106,   107,
     147,   147,   147,   112,    49,    49,    79,   154,   154,   114,
     122,   149,    92,   114,   150,    92,   114,    46,   154,   112,
     145,   115,    45,    55,    56,   137,    80,   141,    91,   133,
      45,    47,    49,    54,   100,    47,    47,    56,    49,   108,
     109,   114,    49,   154,   147,    92,   114,    92,    47,    47,
     150,    49,    55,   137,   139,   138,   112,   148,    36,    47,
     114,    92,   147,   147,   154,    47,   137,    55,    56,    79,
      46,   154,    47,    47,   114,   150,   154,   147,    55,   147,
     150,   154,   154,    47,    92,   148,   154,   111,    47,   154,
     147,    12,    92,   149,   147,   148,   154,    47,   147,   154
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   102,   103,   103,   103,   104,   104,   104,   104,   104,
     105,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   123,   123,   123,   124,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     137,   137,   137,   138,   138,   138,   138,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   148,   149,   149,   150,   150,   151,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     1,     4,     1,     8,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     1,     3,     5,     4,     6,     5,     2,     1,
       2,     3,     2,     1,     3,     5,     3,     4,     4,     6,
       5,     6,     5,     4,     5,     5,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     3,     1,
       1,     3,     4,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     3,     4,     3,     3,     2,     1,     3,     2,
       1,     2,     1,     0,     0,     0,     1,     0,     1,    10,
       6,     5,     7,     9,    13,     8,     7,     7,     6,     3,
       2,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     2,     5,     4,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 109 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=lookup(currentTab,(yyvsp[0].symnode)->name);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 	
	(yyval.symnode)=gentemp(currentTab);
  	(yyval.symnode)->value.flag=1;
  	(yyval.symnode)->value.ival=(yyvsp[0].intval);
  	update(currentTab,(yyval.symnode),"int");
  	char temp[20];
  	sprintf(temp,"%d",(yyval.symnode)->value.ival);
  	emit((yyval.symnode)->name,COPY,temp);
}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	(yyval.symnode)=gentemp(currentTab);
  	(yyval.symnode)->value.flag=2;
  	(yyval.symnode)->value.dval=(yyvsp[0].real);
  	update(currentTab,(yyval.symnode),"double");
  	char temp[12];
  	sprintf(temp,"%lf",(yyval.symnode)->value.dval);
  	emit((yyval.symnode)->name,COPY,temp);
}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	(yyval.symnode)=gentemp(currentTab);
  	(yyval.symnode)->value.flag=2;
  	(yyval.symnode)->value.dval=(yyvsp[0].real);
  	update(currentTab,(yyval.symnode),"double");
  	char temp[12];
  	sprintf(temp,"%lf",(yyval.symnode)->value.dval);
  	emit((yyval.symnode)->name,COPY,temp);
}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	(yyval.symnode)=gentemp(currentTab);
  	(yyval.symnode)->value.flag=3;
  	(yyval.symnode)->value.str=string((yyvsp[0].str));
  	update(currentTab,(yyval.symnode),"char");
  	emit((yyval.symnode)->name,COPY,(yyval.symnode)->value.str);
}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	(yyval.symnode)=gentemp(currentTab);
  	(yyval.symnode)->value.flag=3;
  	(yyval.symnode)->value.str=(yyvsp[0].str);
  	update(currentTab,(yyval.symnode),"char");
  	emit((yyval.symnode)->name,COPY,(yyval.symnode)->value.str);
}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 161 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { (yyval.symnode)=(yyvsp[-1].symnode);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 165 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 168 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	SymNode* temp=gentemp(currentTab);
	update(currentTab,temp,"int");
	char arg2[20];
	sprintf(arg2,"%d",(yyvsp[-3].symnode)->size / (yyvsp[-3].symnode)->arglist->index);
	sprintf(arg2,"%d",(yyvsp[-3].symnode)->size / (yyvsp[-3].symnode)->arglist->index);
	emit(temp->name,MULT,(yyvsp[-1].symnode)->name,arg2);
	(yyval.symnode)=gentemp(currentTab);
	emit((yyval.symnode)->name,ARRAY,(yyvsp[-3].symnode)->name,temp->name);
	(yyval.symnode)->value=(yyvsp[-3].symnode)->value;
	(yyval.symnode)->size=(yyvsp[-3].symnode)->size / (yyvsp[-3].symnode)->arglist->index;
	(yyval.symnode)->type=(yyvsp[-3].symnode)->type;
	(yyval.symnode)->arglist=(yyvsp[-3].symnode)->arglist->next;
}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab); 
	emit((yyval.symnode)->name,FUNC,(yyvsp[-2].symnode)->name,"0");
}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 190 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	ParamList* temp=(yyvsp[-1].paramlist);
	int length=0;
	while(temp!=NULL){
		emit(temp->name,PARAM);
		temp=temp->next;
		length++;
	}
	char strg[20];
	sprintf(strg,"%d",length);
	if((yyvsp[-3].symnode)->type=="void")
		emit("",FUNC,(yyvsp[-3].symnode)->name,strg);
	else{
		(yyval.symnode)=gentemp(currentTab);
		emit((yyval.symnode)->name,FUNC,(yyvsp[-3].symnode)->name,strg);  
	}	
}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 208 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 208 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
    emit((yyval.symnode)->name,COPY,(yyvsp[-1].symnode)->name);
    (yyval.symnode)->value.ival=(yyvsp[-1].symnode)->value.ival;
    (yyval.symnode)->value.flag=1;
    update(currentTab,(yyval.symnode),(yyvsp[-1].symnode)->type);
    emit((yyvsp[-1].symnode)->name,PLUS,(yyvsp[-1].symnode)->name,"1");
}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
    emit((yyval.symnode)->name,COPY,(yyvsp[-1].symnode)->name);
    (yyval.symnode)->value.ival=(yyvsp[-1].symnode)->value.ival;
    (yyval.symnode)->value.flag=1;
    update(currentTab,(yyval.symnode),(yyvsp[-1].symnode)->type);
    emit((yyvsp[-1].symnode)->name,SUB,(yyvsp[-1].symnode)->name,"1");
}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 230 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 237 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.paramlist)=makelist((yyvsp[0].symnode)->name,(yyvsp[0].symnode)->type);
}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.paramlist)=merge((yyvsp[-2].paramlist),makelist((yyvsp[0].symnode)->name,(yyvsp[0].symnode)->type));
}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 251 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	emit((yyvsp[0].symnode)->name,PLUS,(yyvsp[0].symnode)->name,"1");
    (yyval.symnode)=(yyvsp[0].symnode);
}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 257 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	emit((yyvsp[0].symnode)->name,SUB,(yyvsp[0].symnode)->name,"1");
    (yyval.symnode)=(yyvsp[0].symnode);
}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 263 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	switch((yyvsp[-1].op)){
		case(PLUS):
			(yyval.symnode)=gentemp(currentTab);
			emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
			update(currentTab,(yyval.symnode),(yyvsp[0].symnode)->type);
			(yyval.symnode)->value.flag=(yyvsp[0].symnode)->value.flag;
			//$$->value=$2->value;
			break;
		
		case(SUB):
			(yyval.symnode)=gentemp(currentTab);
			emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
			update(currentTab,(yyval.symnode),(yyvsp[0].symnode)->type);
			(yyval.symnode)->value.flag=(yyvsp[0].symnode)->value.flag;
			break;
		
		case(MULT):
			(yyval.symnode)=gentemp(currentTab);
			emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
			(yyval.symnode)->arglist=(yyvsp[0].symnode)->arglist->next;
			if((yyvsp[0].symnode)->type=="int"){
				update(currentTab,(yyval.symnode),"int");
				(yyval.symnode)->value.flag=1;
			}
			else if((yyvsp[0].symnode)->type=="double"){
				update(currentTab,(yyval.symnode),"double");
				(yyval.symnode)->value.flag=2;
			}
			else if((yyvsp[0].symnode)->type=="char"){
				update(currentTab,(yyval.symnode),"char");
				(yyval.symnode)->value.flag=3;
			}
			break;

		case(NEG):
			if((yyvsp[0].symnode)->value.flag==1){
				(yyval.symnode)=gentemp(currentTab);
				update(currentTab,(yyval.symnode),(yyvsp[0].symnode)->type);
				(yyval.symnode)->value.flag=(yyvsp[0].symnode)->value.flag;
				emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
			}
			else
				cout<<"Invalid operand type"<<endl;
			break;
		
		case(BITAND):
			(yyval.symnode)=gentemp(currentTab);
			emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
			(yyval.symnode)->arglist=makelist(0);
			(yyval.symnode)->arglist->next=(yyvsp[0].symnode)->arglist;
			(yyval.symnode)->value.flag=5;
			if((yyvsp[0].symnode)->type=="int"){
				update(currentTab,(yyval.symnode),"int");
			}
			else if((yyvsp[0].symnode)->type=="double"){
				update(currentTab,(yyval.symnode),"double");
			}
			else if((yyvsp[0].symnode)->type=="char"){
				update(currentTab,(yyval.symnode),"char");
			}
			break;
		
		case(NT):
			if((yyvsp[0].symnode)->value.flag==1){
				(yyval.symnode)=gentemp(currentTab);
				emit((yyval.symnode)->name,(yyvsp[-1].op),(yyvsp[0].symnode)->name);
				update(currentTab,(yyval.symnode),(yyvsp[0].symnode)->type);
				(yyval.symnode)->value.flag=(yyvsp[0].symnode)->value.flag;
			}
			else
				cout<<"Invalid operand type"<<endl;
			break;
	}
}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 339 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 339 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 343 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=PLUS;}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 344 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=SUB;}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 345 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=MULT;}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 346 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=NEG;}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 347 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=BITAND;}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 348 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=NT;}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 352 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 355 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab); 
	(yyval.symnode)=(yyvsp[0].symnode); (yyval.symnode)->type=(yyvsp[-2].str); 
	typecheck((yyval.symnode),(yyvsp[0].symnode));
}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 366 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
	if((yyvsp[-2].symnode)->type==(yyvsp[0].symnode)->type){
		if((yyvsp[-2].symnode)->type=="int"){
    		(yyval.symnode)->value.flag=1;
    		update(currentTab,(yyval.symnode),"int");
    	}
    	else if((yyvsp[-2].symnode)->type=="double"){
    		(yyval.symnode)->value.flag=2;
    		update(currentTab,(yyval.symnode),"double");
    	}
    }
    else if((yyvsp[-2].symnode)->type=="int" && (yyvsp[0].symnode)->type=="double"){
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
    else{
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
    emit((yyval.symnode)->name,MULT,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 390 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
	if((yyvsp[-2].symnode)->type==(yyvsp[0].symnode)->type){
		if((yyvsp[-2].symnode)->type=="int"){
    		(yyval.symnode)->value.flag=1;
    		update(currentTab,(yyval.symnode),"int");
    	}
    	else if((yyvsp[-2].symnode)->type=="double"){
    		(yyval.symnode)->value.flag=2;
    		update(currentTab,(yyval.symnode),"double");
    	}
    }
    else if((yyvsp[-2].symnode)->type=="int" && (yyvsp[0].symnode)->type=="double"){
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
    else{
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
	emit((yyval.symnode)->name,DIV,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 414 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,REM,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 427 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 430 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
	if((yyvsp[-2].symnode)->type==(yyvsp[0].symnode)->type){
		if((yyvsp[-2].symnode)->type=="int"){
    		(yyval.symnode)->value.flag=1;
    		update(currentTab,(yyval.symnode),"int");
    	}
    	else if((yyvsp[-2].symnode)->type=="double"){
    		(yyval.symnode)->value.flag=2;
    		update(currentTab,(yyval.symnode),"double");
    	}
    }
    else if((yyvsp[-2].symnode)->type=="int" && (yyvsp[0].symnode)->type=="double"){
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
    else{
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
	emit((yyval.symnode)->name,PLUS,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 454 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
	if((yyvsp[-2].symnode)->type==(yyvsp[0].symnode)->type){
		if((yyvsp[-2].symnode)->type=="int"){
    		(yyval.symnode)->value.flag=1;
    		update(currentTab,(yyval.symnode),"int");
    	}
    	else if((yyvsp[-2].symnode)->type=="double"){
    		(yyval.symnode)->value.flag=2;
    		update(currentTab,(yyval.symnode),"double");
    	}
    }
    else if((yyvsp[-2].symnode)->type=="int" && (yyvsp[0].symnode)->type=="double"){
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
    else{
    	(yyval.symnode)->value.flag=2;
    	update(currentTab,(yyval.symnode),"double");
    }
	emit((yyval.symnode)->name,SUB,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 478 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 481 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,LEFTSHIFT,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 493 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,RIGHTSHIFT,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 506 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 509 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",LESSTHAN,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 519 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",GREATERTHAN,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 529 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",LESSTHANEQUAL,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 539 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",GREATERTHANEQUAL,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 550 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 553 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",ISEQUAL,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 563 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	(yyval.symnode)->truelist=makelist(nextinstr);
	(yyval.symnode)->falselist=makelist(nextinstr+1);
	emit("",NOTEQUAL,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
	emit("",_GOTO);
}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 574 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 577 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.ival=(yyvsp[-2].symnode)->value.ival & (yyvsp[0].symnode)->value.ival;
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,BITAND,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 594 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.ival=(yyvsp[-2].symnode)->value.ival ^ (yyvsp[0].symnode)->value.ival;
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,XOR,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 608 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 611 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].symnode)->type=="int"){
    	(yyval.symnode)=gentemp(currentTab);
    	(yyval.symnode)->value.ival=(yyvsp[-2].symnode)->value.ival | (yyvsp[0].symnode)->value.ival;
    	(yyval.symnode)->value.flag=1;
    	update(currentTab,(yyval.symnode),(yyvsp[-2].symnode)->type);
    	emit((yyval.symnode)->name,BITOR,(yyvsp[-2].symnode)->name,(yyvsp[0].symnode)->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 625 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 628 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	backpatch((yyvsp[-3].symnode)->truelist,(yyvsp[-1].intval));
	(yyval.symnode)->truelist=(yyvsp[0].symnode)->truelist;
	(yyval.symnode)->falselist=merge((yyvsp[-3].symnode)->falselist,(yyvsp[0].symnode)->falselist);
}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 638 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 641 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->type="bool";
	backpatch((yyvsp[-3].symnode)->falselist,(yyvsp[-1].intval));
	(yyval.symnode)->truelist=merge((yyvsp[-3].symnode)->truelist,(yyvsp[0].symnode)->truelist);
	(yyval.symnode)->falselist=(yyvsp[0].symnode)->falselist;
}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 651 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 654 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=gentemp(currentTab);
	update(currentTab,(yyval.symnode),(yyvsp[-4].symnode)->type);
	emit((yyval.symnode)->name,COPY,(yyvsp[0].symnode)->name);  
	List* I=makelist(nextinstr);
	emit("",_GOTO);
	backpatch((yyvsp[-3].list),nextinstr);
	emit((yyval.symnode)->name,COPY,(yyvsp[-4].symnode)->name);
	I=merge(I,makelist(nextinstr));
	convInt2Bool((yyvsp[-7].symnode));                
	backpatch((yyvsp[-7].symnode)->truelist,(yyvsp[-5].intval));
	backpatch((yyvsp[-7].symnode)->falselist,(yyvsp[-1].intval));
	backpatch(I,nextinstr);
}
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 671 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 674 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {  
	typecheck((yyvsp[-2].symnode),(yyvsp[0].symnode));
	emit((yyvsp[-2].symnode)->name,COPY,(yyvsp[0].symnode)->name);
}
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 681 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGNMENT;}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 682 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 683 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 684 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 685 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 686 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 687 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 688 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 689 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 690 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 691 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 696 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 696 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 700 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 702 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 702 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 702 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 702 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 707 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	dataType="void"; 
	dataSize=0;
}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 713 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	dataType="char"; 
	dataSize=1;
}
#line 2779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 718 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 720 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	dataType="int"; 
	dataSize=4;
}
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 724 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 727 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	dataType="double"; 
	dataSize=8;
}
#line 2809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 733 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	dataType="double"; 
	dataSize=8;
}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 737 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 738 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 739 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 740 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 741 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 742 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 745 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 748 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 749 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=merge((yyvsp[-2].idlist),(yyvsp[0].idlist));}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 752 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 754 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	IdList* idtemp=(yyvsp[-2].idlist);
	while(idtemp->next != NULL)
		idtemp=idtemp->next; 					
	idtemp->id->value=(yyvsp[0].idlist)->id->value;
	emit(idtemp->id->name,COPY,(yyvsp[0].idlist)->id->name);
	(yyval.idlist)=(yyvsp[-2].idlist);
}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 764 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 765 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 766 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 767 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 768 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 769 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 770 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 771 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 774 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 774 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 777 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 777 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 777 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 780 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { (yyval.str)=(yyvsp[0].str); }
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 781 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 782 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 783 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 786 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 786 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 789 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 789 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 792 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 793 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 794 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 795 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 796 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 801 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { 
	dataSize=4;
	(yyval.list)=new List;
	(yyval.list)->index=0;
}
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 806 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 807 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 810 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyvsp[0].list)->next=new List;
	(yyvsp[0].list)->next->index=0;
	(yyval.list)=(yyvsp[0].list);
}
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 819 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyvsp[0].symnode)=lookup(currentTab,(yyvsp[0].symnode)->name);
	(yyvsp[0].symnode)->type=dataType;
	(yyvsp[0].symnode)->size=dataSize;
	(yyval.idlist)=makelist((yyvsp[0].symnode));
}
#line 3090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 825 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[-1].idlist);}
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 826 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 827 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 828 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 831 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	List* node=new List;
	(yyvsp[-3].idlist)->id->size = (yyvsp[-3].idlist)->id->size * (yyvsp[-1].symnode)->value.ival;
	node->index=(yyvsp[-1].symnode)->value.ival;
	if((yyvsp[-3].idlist)->id->arglist==NULL)
		(yyvsp[-3].idlist)->id->arglist=node;
	else{
		List* temp=(yyvsp[-3].idlist)->id->arglist;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	(yyval.idlist)=(yyvsp[-3].idlist);
}
#line 3133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 845 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 846 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 847 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 848 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 849 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 852 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	SymNode* ST=lookup(globalTab,(yyvsp[-4].idlist)->id->name);
	ST->next=(yyvsp[-2].symtab);
	(yyvsp[-4].idlist)->id->size=0;
	(yyval.idlist)=(yyvsp[-4].idlist);
}
#line 3174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 860 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	SymNode* ST=lookup(globalTab,(yyvsp[-4].idlist)->id->name);
	ST->next=(yyvsp[-2].symtab);
	(yyvsp[-4].idlist)->id->size=0;
	(yyval.idlist)=(yyvsp[-4].idlist);
}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 868 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	SymNode* ST=lookup(globalTab,(yyvsp[-3].idlist)->id->name);
	ST->next=(yyvsp[-1].symtab);
	(yyvsp[-3].idlist)->id->size=0;
	(yyval.idlist)=(yyvsp[-3].idlist);
}
#line 3196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 876 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 879 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	if((yyvsp[-1].list)!=NULL){
		(yyvsp[0].idlist)->id->size=dataSize;
		List* temp=(yyvsp[0].idlist)->id->arglist;
		(yyvsp[0].idlist)->id->arglist=(yyvsp[-1].list);
		List* t=(yyvsp[0].idlist)->id->arglist;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
	(yyval.idlist)=(yyvsp[0].idlist);
}
#line 3219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 893 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 893 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 896 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 896 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 899 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 900 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 903 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 906 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	merge((yyvsp[-2].idlist),(yyvsp[0].idlist));
	(yyval.idlist)=(yyvsp[-2].idlist);
}
#line 3270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 914 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyvsp[0].symnode)=lookup(currentTab,(yyvsp[0].symnode)->name);
	(yyvsp[0].symnode)->type=dataType;
	(yyvsp[0].symnode)->size=dataSize;
	(yyval.idlist)=makelist((yyvsp[0].symnode));
}
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 922 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyvsp[0].symnode)=lookup(currentTab,(yyvsp[0].symnode)->name);
	(yyvsp[0].symnode)->type=dataType;
	(yyvsp[0].symnode)->size=dataSize;
	merge((yyvsp[-2].idlist),makelist((yyvsp[0].symnode)));
	(yyval.idlist)=(yyvsp[-2].idlist);
}
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 932 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { (yyval.str)=(yyvsp[0].str); }
#line 3299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 936 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=makelist((yyvsp[0].symnode));}
#line 3305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 937 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 938 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 942 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 943 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 944 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 945 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 948 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 952 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 952 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 956 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 956 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 959 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 960 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 961 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 965 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[-1].list);}
#line 3395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 966 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=NULL;}
#line 3401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 970 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { (yyval.list)=(yyvsp[0].list);}
#line 3407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 971 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    { (yyval.list)=(yyvsp[0].list);}
#line 3413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 975 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=makelist((yyvsp[-1].intval));}
#line 3419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 976 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 980 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=NULL;}
#line 3431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 981 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=NULL;}
#line 3437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 984 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.intval)=nextinstr;}
#line 3443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 987 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.list)=makelist(nextinstr);
	emit("",_GOTO);
}
#line 3452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 993 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=new SymNode;}
#line 3458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 994 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.symnode)=(yyvsp[0].symnode);}
#line 3464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 999 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symnode)=new SymNode;
	(yyval.symnode)->truelist=makelist(nextinstr);
	emit("",_GOTO);
}
#line 3474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1005 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].symnode)->type!="bool")
		convInt2Bool((yyvsp[0].symnode));
	(yyval.symnode)=(yyvsp[0].symnode);
}
#line 3484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1014 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	backpatch((yyvsp[-7].symnode)->truelist,(yyvsp[-5].intval));
	backpatch((yyvsp[-7].symnode)->falselist,(yyvsp[-1].intval));
	(yyval.list)=merge(merge((yyvsp[-4].list),(yyvsp[-3].list)),(yyvsp[0].list));
	backpatch((yyvsp[-3].list),nextinstr);  
}
#line 3495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1022 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	backpatch((yyvsp[-3].symnode)->truelist,(yyvsp[-1].intval));
	(yyval.list)=merge((yyvsp[-3].symnode)->falselist,(yyvsp[0].list));
	backpatch((yyvsp[-3].symnode)->falselist,nextinstr);     
}
#line 3505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1028 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1034 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	backpatch((yyvsp[0].list),(yyvsp[-5].intval));
	backpatch((yyvsp[-3].symnode)->truelist,(yyvsp[-1].intval));
	(yyval.list)=(yyvsp[-3].symnode)->falselist;
	char str[20];
	sprintf(str,"%d",(yyvsp[-5].intval));
	emit(str,_GOTO);
	backpatch((yyvsp[-3].symnode)->falselist,nextinstr); 
}
#line 3525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1045 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	backpatch((yyvsp[-2].symnode)->truelist,(yyvsp[-7].intval));
	backpatch((yyvsp[-2].symnode)->falselist,nextinstr);
	(yyval.list)=(yyvsp[-2].symnode)->falselist;
}
#line 3535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1052 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	backpatch((yyvsp[-7].symnode)->truelist,(yyvsp[-1].intval));
	backpatch((yyvsp[-3].list),(yyvsp[-8].intval));
	backpatch((yyvsp[0].list),(yyvsp[-5].intval));
	char str[20];
	sprintf(str,"%d",(yyvsp[-5].intval));
	emit(str,_GOTO);
	(yyval.list)=(yyvsp[-7].symnode)->falselist;
	backpatch((yyvsp[-7].symnode)->falselist,nextinstr); 
}
#line 3550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1062 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1063 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1064 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1065 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1070 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1071 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1072 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1073 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {emit((yyvsp[-1].symnode)->name,_RETURN);}
#line 3598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1074 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {emit("",_RETURN);}
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1077 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1078 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1079 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1080 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1081 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1082 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 3640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1085 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1085 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1088 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1088 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {}
#line 3664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1091 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[0].idlist);}
#line 3670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1093 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	merge((yyvsp[-1].idlist),(yyvsp[0].idlist)); 
	(yyval.idlist)=(yyvsp[-1].idlist);
}
#line 3679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1099 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[-3].idlist);}
#line 3685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1100 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {(yyval.idlist)=(yyvsp[-2].idlist);}
#line 3691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1104 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {
	(yyval.symtab)=newTable();
	currentTab=(yyval.symtab);
	dataSize=0;
}
#line 3701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1111 "ass5_17CS10007_17CS10005.y" /* yacc.c:1646  */
    {currentTab=globalTab;}
#line 3707 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3711 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1114 "ass5_17CS10007_17CS10005.y" /* yacc.c:1906  */


void yyerror(char *s) {
printf("%s",s);
}
