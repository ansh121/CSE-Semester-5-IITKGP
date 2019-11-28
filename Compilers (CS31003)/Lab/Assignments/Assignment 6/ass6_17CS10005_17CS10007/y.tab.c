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
#line 7 "ass6_17CS10005_17CS10007.y" /* yacc.c:339  */
 /* C Declarations and Definitions */
	#include <string>
	#include <iostream>
	#include <fstream>
	using namespace std;
	extern int yylex();
	void yyerror(string s);
	extern int yyparse();


	#include "ass6_17CS10005_17CS10007_translator.h"

	Quad_Array Quad_arr;
	symbol_table GTable;
	symbol_table *symbol = &GTable;
	symbol_table *current_symbol = &GTable;
	type_inf *global_type;
	int global_width;
	vector<string> string_list;
	int literals_count;

#line 88 "y.tab.c" /* yacc.c:339  */

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
    DIV_ASSIGN = 258,
    ELLIPSIS = 259,
    EQ_OP = 260,
    LEFT_SHIFT = 261,
    AND_ASSIGN = 262,
    AND_OP = 263,
    SUB_ASSIGN = 264,
    DECREMENT_OP = 265,
    RIGHT_SHIFT = 266,
    MUL_ASSIGN = 267,
    GREATER_EQ_OP = 268,
    LESS_EQ_OP = 269,
    POINTER_OP = 270,
    INCREMENT_OP = 271,
    LEFT_ASSIGN = 272,
    RIGHT_ASSIGN = 273,
    XOR_ASSIGN = 274,
    NOT_EQ_OP = 275,
    OR_OP = 276,
    OR_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    DOUBLE_ = 280,
    DEFAULT_ = 281,
    BREAK_ = 282,
    BOOL_ = 283,
    STRUCT_ = 284,
    SIGNED_ = 285,
    EXTERN_ = 286,
    ELSE_ = 287,
    CONTINUE_ = 288,
    SHORT_ = 289,
    SWITCH_ = 290,
    TYPEDEF_ = 291,
    AUTO_ = 292,
    RETURN_ = 293,
    WHILE_ = 294,
    GOTO_ = 295,
    UNION_ = 296,
    INLINE_ = 297,
    ENUM_ = 298,
    CHAR_ = 299,
    CONST_ = 300,
    DO_ = 301,
    REGISTER_ = 302,
    RESTRICTED_ = 303,
    CASE_ = 304,
    IF_ = 305,
    SIZEOF_ = 306,
    FLOAT_ = 307,
    LONG_ = 308,
    IMAGINARY_ = 309,
    STATIC_ = 310,
    FOR_ = 311,
    UNSIGNED_ = 312,
    VOLATILE_ = 313,
    COMPLEX_ = 314,
    VOID_ = 315,
    INT_ = 316,
    IDENTIFIER = 317,
    STRING_LITERAL = 318,
    INT_CONSTANT = 319,
    FLOAT_CONSTANT = 320,
    CHAR_CONSTANT = 321
  };
#endif
/* Tokens.  */
#define DIV_ASSIGN 258
#define ELLIPSIS 259
#define EQ_OP 260
#define LEFT_SHIFT 261
#define AND_ASSIGN 262
#define AND_OP 263
#define SUB_ASSIGN 264
#define DECREMENT_OP 265
#define RIGHT_SHIFT 266
#define MUL_ASSIGN 267
#define GREATER_EQ_OP 268
#define LESS_EQ_OP 269
#define POINTER_OP 270
#define INCREMENT_OP 271
#define LEFT_ASSIGN 272
#define RIGHT_ASSIGN 273
#define XOR_ASSIGN 274
#define NOT_EQ_OP 275
#define OR_OP 276
#define OR_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define DOUBLE_ 280
#define DEFAULT_ 281
#define BREAK_ 282
#define BOOL_ 283
#define STRUCT_ 284
#define SIGNED_ 285
#define EXTERN_ 286
#define ELSE_ 287
#define CONTINUE_ 288
#define SHORT_ 289
#define SWITCH_ 290
#define TYPEDEF_ 291
#define AUTO_ 292
#define RETURN_ 293
#define WHILE_ 294
#define GOTO_ 295
#define UNION_ 296
#define INLINE_ 297
#define ENUM_ 298
#define CHAR_ 299
#define CONST_ 300
#define DO_ 301
#define REGISTER_ 302
#define RESTRICTED_ 303
#define CASE_ 304
#define IF_ 305
#define SIZEOF_ 306
#define FLOAT_ 307
#define LONG_ 308
#define IMAGINARY_ 309
#define STATIC_ 310
#define FOR_ 311
#define UNSIGNED_ 312
#define VOLATILE_ 313
#define COMPLEX_ 314
#define VOID_ 315
#define INT_ 316
#define IDENTIFIER 317
#define STRING_LITERAL 318
#define INT_CONSTANT 319
#define FLOAT_CONSTANT 320
#define CHAR_CONSTANT 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "ass6_17CS10005_17CS10007.y" /* yacc.c:355  */

  int intval;
  float floatval;
  char charval;
  string *str;
  expression_attribute *expr_attribute;
  declaration *declaration_list;
  init_declration_list *init_dec_list;
  type_inf *type_;
  function_definition *function_def;
  function_list *func_list;

#line 273 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 290 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  370

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    82,    75,     2,
      67,    68,    79,    76,    74,    77,    71,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    90,
      83,    89,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    86,    73,    78,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   180,   188,   195,   208,   218,   232,   245,
     251,   255,   256,   257,   279,   295,   315,   316,   317,   318,
     341,   349,   361,   385,   386,   409,   441,   442,   446,   450,
     454,   458,   462,   466,   473,   474,   478,   479,   581,   680,
     784,   785,   886,   990,   991,  1045,  1104,  1105,  1135,  1165,
    1195,  1227,  1228,  1258,  1291,  1292,  1324,  1328,  1359,  1360,
    1392,  1393,  1432,  1433,  1473,  1475,  1517,  1518,  1543,  1544,
    1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,  1556,
    1560,  1563,  1570,  1571,  1681,  1684,  1687,  1691,  1694,  1697,
    1700,  1703,  1710,  1715,  1724,  1729,  1736,  1737,  1738,  1739,
    1743,  1748,  1754,  1756,  1764,  1766,  1768,  1774,  1776,  1778,
    1780,  1782,  1784,  1788,  1792,  1795,  1797,  1801,  1802,  1803,
    1804,  1805,  1808,  1809,  1812,  1813,  1816,  1819,  1820,  1821,
    1824,  1826,  1832,  1843,  1848,  1852,  1859,  1862,  1865,  1868,
    1924,  1932,  1936,  1939,  1943,  1947,  1956,  1960,  1971,  1977,
    1981,  1987,  1989,  1994,  2000,  2006,  2014,  2024,  2046,  2053,
    2057,  2064,  2072,  2076,  2080,  2087,  2091,  2095,  2098,  2105,
    2112,  2116,  2122,  2126,  2136,  2140,  2144,  2148,  2152,  2156,
    2162,  2166,  2170,  2177,  2181,  2189,  2195,  2204,  2209,  2215,
    2220,  2227,  2243,  2260,  2266,  2280,  2289,  2306,  2312,  2316,
    2319,  2323,  2327,  2331,  2342,  2373,  2377,  2384,  2388,  2395,
    2399,  2454,  2458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIV_ASSIGN", "ELLIPSIS", "EQ_OP",
  "LEFT_SHIFT", "AND_ASSIGN", "AND_OP", "SUB_ASSIGN", "DECREMENT_OP",
  "RIGHT_SHIFT", "MUL_ASSIGN", "GREATER_EQ_OP", "LESS_EQ_OP", "POINTER_OP",
  "INCREMENT_OP", "LEFT_ASSIGN", "RIGHT_ASSIGN", "XOR_ASSIGN", "NOT_EQ_OP",
  "OR_OP", "OR_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "DOUBLE_", "DEFAULT_",
  "BREAK_", "BOOL_", "STRUCT_", "SIGNED_", "EXTERN_", "ELSE_", "CONTINUE_",
  "SHORT_", "SWITCH_", "TYPEDEF_", "AUTO_", "RETURN_", "WHILE_", "GOTO_",
  "UNION_", "INLINE_", "ENUM_", "CHAR_", "CONST_", "DO_", "REGISTER_",
  "RESTRICTED_", "CASE_", "IF_", "SIZEOF_", "FLOAT_", "LONG_",
  "IMAGINARY_", "STATIC_", "FOR_", "UNSIGNED_", "VOLATILE_", "COMPLEX_",
  "VOID_", "INT_", "IDENTIFIER", "STRING_LITERAL", "INT_CONSTANT",
  "FLOAT_CONSTANT", "CHAR_CONSTANT", "'('", "')'", "'['", "']'", "'.'",
  "'{'", "'}'", "','", "'&'", "'+'", "'-'", "'~'", "'*'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept",
  "M", "N", "primary_exp", "postfix_exp", "argument_exp_list", "unary_exp",
  "unary_op", "cast_exp", "multiplicative_exp", "additive_exp",
  "shift_exp", "relational_exp", "equality_exp", "and_exp",
  "exclusive_or_exp", "inclusive_or_exp", "logical_and_exp",
  "logical_or_exp", "conditional_exp", "assignment_exp", "assignment_op",
  "exp", "constant_exp", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list", "enum_specifier",
  "enumerator_list", "enumerator", "enumeration_constant",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "assignment_exp_opt", "type_qualifier_list_opt",
  "pointer", "type_qualifier_list", "parameter_type_list_opt",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "expression_opt", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,    40,    41,    91,
      93,    46,   123,   125,    44,    38,    43,    45,   126,    42,
      33,    47,    37,    60,    62,    94,   124,    63,    58,    61,
      59
};
# endif

#define YYPACT_NINF -270

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-270)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1016,  -270,  -270,  -270,  -270,  -270,  -270,  -270,    43,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,   -10,  1016,  1016,  -270,  1016,  1016,   867,
    -270,  -270,   -31,   -38,  -270,   -11,    16,  -270,   -40,  -270,
     828,   -27,     9,  -270,  -270,  -270,  -270,  -270,  -270,   -38,
    -270,   143,  -270,     8,    51,  -270,  -270,    16,   -11,  -270,
     289,   637,  -270,   -10,  -270,   941,   978,   125,   -27,   148,
    -270,   -26,   695,  -270,  -270,  -270,  -270,    28,   734,   734,
      35,    78,    86,   121,   425,  -270,   122,  -270,   695,   124,
     753,   138,   112,  -270,  -270,  -270,  -270,   541,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,    92,    36,   695,
    -270,   133,   142,   145,    64,    68,   151,   128,   147,   220,
     -12,  -270,  -270,   -28,  -270,  -270,  -270,  -270,   162,  -270,
    -270,  -270,  -270,  -270,  -270,   618,  -270,  -270,  -270,  -270,
    -270,   -11,   173,  -270,   171,  -270,    30,   117,   772,   134,
    -270,    21,  -270,  -270,  -270,  -270,  -270,   541,  -270,  -270,
     405,  -270,  -270,   695,  -270,    -8,   186,   164,   405,   167,
     695,   541,  -270,   483,   405,    52,  1053,  -270,  1053,   191,
    -270,   198,  -270,   657,   695,   200,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,   695,  -270,   695,
     695,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   695,   695,   695,   695,   257,     5,   695,  -270,  -270,
     347,   695,   205,  -270,   150,   637,    83,  -270,  -270,  -270,
     904,  -270,   209,   695,   117,   204,  -270,   206,   695,  -270,
     207,  -270,   103,  -270,   695,  -270,  -270,   405,   210,   211,
     210,   695,   188,  -270,  -270,  -270,  -270,   676,  -270,  -270,
     119,  -270,    90,  -270,  -270,  -270,  -270,  -270,   133,   133,
     142,   142,   145,   145,   145,   145,    64,    64,    68,   151,
     128,  -270,  -270,  -270,  -270,  -270,   219,  -270,  -270,   560,
    -270,  -270,  -270,  -270,  -270,  -270,   221,  -270,  -270,   222,
     224,   405,   210,   254,  -270,   226,   224,   213,  -270,   618,
    -270,  -270,   695,  -270,   695,   695,   695,  -270,  -270,  -270,
     637,  -270,  -270,  -270,   229,   233,  -270,   695,   695,   158,
    -270,   147,  -270,   210,  -270,  -270,   695,   405,   236,  -270,
    -270,   599,  -270,   257,   218,   405,   127,  -270,   405,   217,
    -270,  -270,  -270,   223,   269,  -270,  -270,   695,  -270,  -270,
     695,  -270,   405,  -270,  -270,   240,  -270,  -270,   405,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   106,   109,   107,    96,   102,    98,   130,     0,   101,
     127,    99,   128,   105,   104,   111,    97,   108,   129,   110,
     100,   103,   208,     0,    84,    86,   112,    88,    90,     0,
     205,   207,   121,     0,   133,     0,   145,    82,     0,    92,
      94,   132,     0,    85,    87,    89,    91,     1,   206,     0,
     126,     0,   122,   124,     0,   149,   147,   146,     0,    83,
       0,     0,   211,     0,   210,     0,   152,   144,   131,     0,
     117,     0,     0,   134,   150,   148,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     2,     0,     0,
       0,     0,     4,     6,     7,     8,     5,     0,   183,    28,
      29,    30,    31,    32,    33,   189,    10,    23,    34,     0,
      36,    40,    43,    46,    51,    54,    56,    58,    60,    62,
      64,    66,    79,     0,   187,   188,   174,   175,     2,   185,
     176,   177,   178,   179,     4,     0,   162,    95,   212,   209,
     159,   158,     0,   151,   153,   155,     0,   144,   142,   143,
     118,     0,   119,   123,    34,    81,   125,     0,    22,    24,
       0,   202,   201,     0,   203,     0,     0,     0,     0,     0,
       0,     0,    26,   199,     0,     0,   113,   161,   115,     0,
      19,     0,    13,     0,     0,     0,    70,    76,    73,    69,
      74,    75,    77,    78,    71,    72,    68,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   184,
       0,     0,     0,   165,     0,     0,     0,   170,   157,   139,
       0,   140,     0,     0,   143,    32,   141,     0,     0,   120,
       0,   182,     0,   204,     0,   200,     2,     0,     3,     0,
     198,   199,     0,   180,     9,   114,   116,     0,    12,    11,
       0,    20,     0,    16,    67,    38,    37,    39,    42,    41,
      44,    45,    50,    49,    47,    48,    52,    53,    55,    57,
      59,     2,     2,     2,    80,   186,     0,   173,   163,     0,
     166,   169,   171,   154,   156,   160,     0,   138,   135,     0,
       0,     0,     3,     0,   181,     0,    27,     0,     2,     0,
      35,    14,     0,    15,     0,     0,     0,   172,   164,   167,
       0,   136,   137,   193,     0,     0,     2,   199,   199,     0,
      21,     3,     3,     3,   168,     2,     0,     0,     0,     3,
      17,     0,    61,    63,     0,     0,     0,     3,     0,     0,
      18,     2,   194,     0,   191,   197,     2,     0,   195,     2,
     199,    65,     0,     3,     3,     0,   192,     2,     0,   196
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,   -79,   -95,  -270,  -270,  -270,   -72,  -270,   -88,    37,
      44,     2,    53,    97,    98,    96,     7,    10,  -270,   -71,
     -39,  -270,   -70,   -76,   -30,     4,  -270,   272,  -270,   -92,
     -21,  -270,   309,   -60,  -270,    49,  -270,   -20,   317,  -270,
     241,   -13,   -48,  -270,  -270,  -270,   130,  -270,   -90,   -59,
      61,  -269,  -270,   157,   -50,  -270,    -2,  -270,   156,  -270,
    -270,  -270,  -238,  -270,  -270,   342,  -270,  -270
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   166,   215,   106,   107,   260,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   197,   123,   156,    22,    63,    38,    39,    24,    25,
     177,    26,    51,    52,    53,    27,    28,    77,    41,   237,
     148,    42,    57,   142,   143,   144,   145,   146,   179,   223,
     224,   225,   226,   227,   125,   126,   127,   128,   129,   130,
     131,   132,   252,   133,    29,    30,    31,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     154,   155,   137,    40,    23,   176,   158,   159,   168,    -3,
      62,   153,   169,   307,   165,    54,   154,   155,   172,   149,
     320,   198,   136,    56,    50,   216,   282,   175,    43,    44,
     124,    45,    46,    23,    58,   138,    50,   154,    64,   186,
      66,    49,    67,   187,    75,   188,   217,   152,   189,   220,
      59,    34,    34,   190,   191,   192,    35,    35,   193,   194,
     195,    10,   218,   139,    12,   176,   217,   240,    36,    36,
     141,    34,   320,   210,    18,    -3,    35,   206,   207,   176,
      37,   249,   243,    50,   176,    55,   176,   175,   211,   338,
     339,   153,   283,   242,   239,    36,   136,    72,   231,   234,
     248,   175,   180,   250,   232,    32,    74,   181,   182,   236,
     241,   265,   266,   267,   262,    33,    55,    61,   246,    73,
     254,   228,   363,   160,   253,   196,   217,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   251,   261,   286,   178,   208,   209,   154,
     155,   204,   221,   305,   222,   255,   205,   256,   264,   183,
     313,   184,    10,   185,   217,    12,   290,   303,   161,   310,
      10,   301,   291,    12,   302,    18,   162,   217,   284,    10,
     147,   250,    12,    18,   167,   154,   136,   311,   163,   238,
     124,   170,    18,   312,   296,   353,    55,   304,    74,   299,
     174,   217,   314,   315,   316,   173,   178,   324,   272,   273,
     274,   275,   199,   213,   200,   201,    70,    71,   202,   203,
     178,   150,   151,   288,   289,   178,   212,   178,    -3,   328,
     319,   340,   341,   214,   141,   219,   342,   343,   344,   268,
     269,   229,   154,   154,   349,   230,   333,   337,   270,   271,
     136,   323,   354,   244,   245,   247,   345,   250,   250,   257,
     258,   334,   263,   276,   277,   281,   346,   287,   365,   366,
     136,   295,   357,   330,   297,   300,   298,   360,   308,   306,
     362,   136,   319,    74,   217,   154,   361,   347,   368,   317,
     250,   321,   322,   325,   326,   352,   309,   335,   355,    78,
     336,   359,   136,   327,   348,    79,   351,   356,   367,   278,
     280,   279,   364,   358,     1,    80,    81,     2,   369,     3,
       4,   331,    82,     5,    83,   332,     6,    84,    85,    86,
      76,     7,     8,     9,    10,    87,    11,    12,    88,    89,
      90,    13,    14,    15,    16,    91,    17,    18,    19,    20,
      21,    92,    93,    94,    95,    96,    97,    78,    69,    68,
     294,    60,    98,    79,    99,   100,   101,   102,   103,   104,
     329,    48,     1,    80,    81,     2,   285,     3,     4,   105,
      82,     5,    83,   292,     6,    84,    85,    86,   233,     7,
       8,     9,    10,    87,    11,    12,    88,    89,    90,    13,
      14,    15,    16,    91,    17,    18,    19,    20,    21,    92,
      93,    94,    95,    96,    97,    78,     0,     0,     0,    60,
       0,    79,    99,   100,   101,   102,   103,   104,     0,     0,
       0,    80,    81,     0,     0,    78,     0,   105,    82,     0,
      83,    79,     0,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,     0,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,     0,     0,     0,    90,    60,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   134,    93,    94,
      95,    96,    97,    78,     0,   105,     0,     0,     0,    79,
      99,   100,   101,   102,   103,   104,     0,     0,     1,     0,
       0,     2,     0,     3,     4,   164,     0,     5,     0,     0,
       6,     0,     0,     0,     0,     7,     8,     9,    10,     0,
      11,    12,     0,     0,    90,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,   134,    93,    94,    95,    96,
      97,    78,     0,     0,     0,     0,     0,    79,    99,   100,
     101,   102,   103,   104,     0,     0,     1,     0,     0,     2,
      78,     3,     0,     0,     0,     5,    79,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,     0,    12,
       0,     0,    90,    13,    14,    15,     0,     0,    17,    18,
      19,    20,    21,   134,    93,    94,    95,    96,    97,    78,
       0,    90,     0,     0,     0,    79,    99,   100,   101,   102,
     103,   104,   134,    93,    94,    95,    96,    97,    78,   221,
       0,   222,   135,   318,    79,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      90,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,   134,    93,    94,    95,    96,    97,    78,   221,    90,
     222,   135,   350,    79,    99,   100,   101,   102,   103,   104,
     134,    93,    94,    95,    96,    97,    78,   221,    90,   222,
     135,     0,    79,    99,   100,   101,   102,   103,   104,   134,
      93,    94,    95,    96,    97,    78,     0,     0,    90,   135,
       0,    79,    99,   100,   101,   102,   103,   104,     0,   134,
      93,    94,    95,    96,    97,   259,     0,    90,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   134,    93,
      94,    95,    96,    97,    78,     0,    90,     0,   309,     0,
      79,    99,   100,   101,   102,   103,   104,   134,    93,    94,
      95,    96,    97,    78,     0,     0,     0,     0,     0,    79,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    90,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,   134,    93,    94,    95,
      96,   157,     0,     0,    90,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   134,    93,    94,    95,    96,
     171,     0,     0,    90,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   134,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   235,   104,     1,     0,     0,     2,     0,     3,     4,
       0,     0,     5,     0,     0,     6,     0,    47,     0,     0,
       7,     8,     9,    10,     0,    11,    12,     0,     0,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
       0,     0,     1,     0,     0,     2,     0,     3,     4,     0,
      60,     5,     0,     0,     6,     0,     0,     0,   293,     7,
       8,     9,    10,     0,    11,    12,     0,    61,     0,    13,
      14,    15,    16,     0,    17,    18,    19,    20,    21,     1,
       0,     0,     2,     0,     3,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     9,    10,
       0,    11,    12,     0,     0,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,     1,     0,     0,     2,
       0,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     0,     0,     7,     8,     9,    10,     0,    11,    12,
       0,     0,     0,    13,    14,    15,    16,     0,    17,    18,
      19,    20,    21,     1,     0,     0,     2,     0,     3,     4,
       0,     0,     5,    60,     0,     6,     0,     0,     0,     0,
       7,     8,     9,    10,     0,    11,    12,     0,     0,     0,
      13,    14,    15,    16,     0,    17,    18,    19,    20,    21,
     140,     1,     0,     0,     2,     0,     3,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     0,     0,     7,     8,
       9,    10,     0,    11,    12,     0,     0,     0,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,     1,     0,
       0,     2,     0,     3,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,     0,
       0,    12,     0,     0,     0,    13,    14,    15,     0,     0,
      17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      72,    72,    61,    23,     0,    97,    78,    79,    87,    21,
      40,    71,    88,   251,    84,    35,    88,    88,    90,    67,
     289,   109,    61,    36,    62,   120,    21,    97,    24,    25,
      60,    27,    28,    29,    74,    65,    62,   109,    40,     3,
      67,    72,    69,     7,    57,     9,    74,    73,    12,   128,
      90,    62,    62,    17,    18,    19,    67,    67,    22,    23,
      24,    45,    90,    65,    48,   157,    74,   157,    79,    79,
      66,    62,   341,     5,    58,    87,    67,    13,    14,   171,
      90,   171,    90,    62,   176,    36,   178,   157,    20,   327,
     328,   151,    87,   163,    73,    79,   135,    89,    68,   147,
     170,   171,    10,   173,    74,    62,    57,    15,    16,   148,
     160,   199,   200,   201,   184,    72,    67,    89,   168,    68,
      68,   141,   360,    88,   174,    89,    74,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   173,   183,   221,    97,    83,    84,   221,
     221,     6,    69,   248,    71,   176,    11,   178,   197,    67,
      70,    69,    45,    71,    74,    48,   225,   246,    90,   257,
      45,    68,    89,    48,   244,    58,    90,    74,   217,    45,
      55,   251,    48,    58,    62,   257,   225,    68,    67,    55,
     220,    67,    58,    74,   233,    68,   147,   247,   149,   238,
      88,    74,   281,   282,   283,    67,   157,   302,   206,   207,
     208,   209,    79,    85,    81,    82,    73,    74,    76,    77,
     171,    73,    74,    73,    74,   176,    75,   178,     8,   308,
     289,    73,    74,    86,   230,    73,   331,   332,   333,   202,
     203,    68,   314,   315,   339,    74,   316,   326,   204,   205,
     289,   301,   347,    67,    90,    88,   335,   327,   328,    68,
      62,   320,    62,   210,   211,     8,   336,    62,   363,   364,
     309,    62,   351,   312,    70,    68,    70,   356,    90,    68,
     359,   320,   341,   234,    74,   357,   357,   337,   367,    70,
     360,    70,    70,    39,    68,   345,    72,    68,   348,    10,
      67,    32,   341,    90,    68,    16,    88,    90,    68,   212,
     214,   213,   362,    90,    25,    26,    27,    28,   368,    30,
      31,   314,    33,    34,    35,   315,    37,    38,    39,    40,
      58,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    10,    49,    42,
     230,    72,    73,    16,    75,    76,    77,    78,    79,    80,
     309,    29,    25,    26,    27,    28,   220,    30,    31,    90,
      33,    34,    35,   226,    37,    38,    39,    40,   147,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    10,    -1,    -1,    -1,    72,
      -1,    16,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    26,    27,    -1,    -1,    10,    -1,    90,    33,    -1,
      35,    16,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    51,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    -1,    62,    63,    64,
      65,    66,    67,    10,    -1,    90,    -1,    -1,    -1,    16,
      75,    76,    77,    78,    79,    80,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    90,    -1,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      47,    48,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    10,    -1,    -1,    -1,    -1,    -1,    16,    75,    76,
      77,    78,    79,    80,    -1,    -1,    25,    -1,    -1,    28,
      10,    30,    -1,    -1,    -1,    34,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    10,
      -1,    51,    -1,    -1,    -1,    16,    75,    76,    77,    78,
      79,    80,    62,    63,    64,    65,    66,    67,    10,    69,
      -1,    71,    72,    73,    16,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      51,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    10,    69,    51,
      71,    72,    73,    16,    75,    76,    77,    78,    79,    80,
      62,    63,    64,    65,    66,    67,    10,    69,    51,    71,
      72,    -1,    16,    75,    76,    77,    78,    79,    80,    62,
      63,    64,    65,    66,    67,    10,    -1,    -1,    51,    72,
      -1,    16,    75,    76,    77,    78,    79,    80,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    51,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    62,    63,
      64,    65,    66,    67,    10,    -1,    51,    -1,    72,    -1,
      16,    75,    76,    77,    78,    79,    80,    62,    63,    64,
      65,    66,    67,    10,    -1,    -1,    -1,    -1,    -1,    16,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    51,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    -1,    -1,    51,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    62,    63,    64,    65,    66,
      67,    -1,    -1,    51,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    25,    -1,    -1,    28,    -1,    30,    31,
      -1,    -1,    34,    -1,    -1,    37,    -1,     0,    -1,    -1,
      42,    43,    44,    45,    -1,    47,    48,    -1,    -1,    -1,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    -1,
      72,    34,    -1,    -1,    37,    -1,    -1,    -1,     4,    42,
      43,    44,    45,    -1,    47,    48,    -1,    89,    -1,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    25,
      -1,    -1,    28,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    47,    48,    -1,    -1,    -1,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    25,    -1,    -1,    28,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    -1,    47,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    25,    -1,    -1,    28,    -1,    30,    31,
      -1,    -1,    34,    72,    -1,    37,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    47,    48,    -1,    -1,    -1,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    25,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    47,    48,    -1,    -1,    -1,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    25,    -1,
      -1,    28,    -1,    30,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    59,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    28,    30,    31,    34,    37,    42,    43,    44,
      45,    47,    48,    52,    53,    54,    55,    57,    58,    59,
      60,    61,   115,   116,   119,   120,   122,   126,   127,   155,
     156,   157,    62,    72,    62,    67,    79,    90,   117,   118,
     128,   129,   132,   116,   116,   116,   116,     0,   156,    72,
      62,   123,   124,   125,   128,   126,   132,   133,    74,    90,
      72,    89,   115,   116,   147,   158,    67,    69,   129,   123,
      73,    74,    89,    68,   126,   132,   118,   128,    10,    16,
      26,    27,    33,    35,    38,    39,    40,    46,    49,    50,
      51,    56,    62,    63,    64,    65,    66,    67,    73,    75,
      76,    77,    78,    79,    80,    90,    94,    95,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   113,   115,   145,   146,   147,   148,   149,
     150,   151,   152,   154,    62,    72,   111,   140,   115,   147,
      62,   116,   134,   135,   136,   137,   138,    55,   131,   133,
      73,    74,    73,   124,    97,   110,   114,    67,    97,    97,
      88,    90,    90,    67,    90,   113,    92,    62,    92,   114,
      67,    67,    97,    67,    88,   113,   120,   121,   126,   139,
      10,    15,    16,    67,    69,    71,     3,     7,     9,    12,
      17,    18,    19,    22,    23,    24,    89,   112,    99,    79,
      81,    82,    76,    77,     6,    11,    13,    14,    83,    84,
       5,    20,    75,    85,    86,    93,    93,    74,    90,    73,
      92,    69,    71,   140,   141,   142,   143,   144,   128,    68,
      74,    68,    74,   131,   133,    79,   111,   130,    55,    73,
     139,   145,   113,    90,    67,    90,   145,    88,   113,   139,
     113,   115,   153,   145,    68,   121,   121,    68,    62,    68,
      96,   111,   113,    62,   111,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   103,   103,   104,   105,
     106,     8,    21,    87,   111,   149,   114,    62,    73,    74,
     140,    89,   144,     4,   137,    62,   111,    70,    70,   111,
      68,    68,   113,    92,   145,    93,    68,   153,    90,    72,
      99,    68,    74,    70,    92,    92,    92,    70,    73,   140,
     142,    70,    70,   145,    93,    39,    68,    90,    92,   141,
     111,   107,   108,   113,   140,    68,    67,    92,   153,   153,
      73,    74,    93,    93,    93,    92,   113,   145,    68,    93,
      73,    88,   145,    68,    93,   145,    90,    92,    90,    32,
      92,   110,    92,   153,   145,    93,    93,    68,    92,   145
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   126,   126,   126,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   140,   140,   140,   141,   141,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   145,   145,   145,   145,
     146,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   151,   152,   152,   152,   152,   153,   153,
     154,   154,   154,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     2,     4,     4,     3,     6,     7,     2,
       1,     3,     2,     1,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     1,     6,     1,     9,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     5,     6,     6,     5,     4,
       4,     1,     0,     1,     0,     1,     2,     2,     3,     1,
       2,     1,     0,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     3,     4,     1,     2,     3,     4,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     3,     1,     1,     1,
       2,     8,    12,     5,     8,     9,    14,     8,     1,     0,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     1,     2
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
#line 172 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->instr = Quad_arr.index;
    }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 180 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->nextlist = makelist(Quad_arr.index);
        Quad_arr.emit(GOTO,"","","");
    }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 189 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        string t = (*((yyvsp[0].str))); 
        symtab *h = current_symbol->lookup(t);
        (yyval.expr_attribute)->loc = t;
    }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 196 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type.type_name = "char";
        opcodeType op = COPY;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,(yyval.expr_attribute)->loc, (yyvsp[0].charval));
        init_value *init = new init_value;
        init->char_val = (yyvsp[0].charval);
        current_symbol->lookup((yyval.expr_attribute)->loc)->init_val = init;
        (yyval.expr_attribute)->is_pointer_type = 0;
    }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        string s = ".LC";
        string temp = to_string(literals_count);
        s = s + temp;
        (yyval.expr_attribute)->loc = s;
        literals_count++;
        string_list.push_back(*(yyvsp[0].str));
    }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 219 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type.type_name = "int";
        opcodeType op = COPY;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,(yyval.expr_attribute)->loc, (yyvsp[0].intval));
        init_value *init = new init_value;
        init->int_val = (yyvsp[0].intval);                     
        current_symbol->lookup((yyval.expr_attribute)->loc)->init_val = init;
        (yyval.expr_attribute)->is_pointer_type = 0;

    }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 233 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type.type_name = "double";
        opcodeType op = COPY;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,(yyval.expr_attribute)->loc, (yyvsp[0].floatval));
        init_value *init = new init_value;
        init->double_val = (yyvsp[0].floatval);
        current_symbol->lookup((yyval.expr_attribute)->loc)->init_val = init;
        (yyval.expr_attribute)->is_pointer_type = 0;
    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 246 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = (yyvsp[-1].expr_attribute);
    }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 252 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = (yyvsp[0].expr_attribute);
    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 255 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 256 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 258 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    
        (yyval.expr_attribute) = new expression_attribute;

        string s = (yyvsp[-1].expr_attribute)->loc;
        symtab * f = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc);
        (yyval.expr_attribute)->loc = current_symbol->gentemp(f->type);
        if(f->type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(f->type);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attribute)->loc, *((yyvsp[-1].expr_attribute)->inner));
            Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, temp, "");
            Quad_arr.emit(PLUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-1].expr_attribute)->loc, temp, *((yyvsp[-1].expr_attribute)->inner));
        }
        else
        {
            Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, (yyvsp[-1].expr_attribute)->loc, "");
            Quad_arr.emit(PLUS, (yyvsp[-1].expr_attribute)->loc, (yyvsp[-1].expr_attribute)->loc, "1");  
        }   
    }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 280 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        string f = (yyvsp[-3].expr_attribute)->loc;
        symbol_table *fsym = GTable.lookup(f)->nested_table;
        function_list *flist = ((yyvsp[-1].func_list));
        list<function_definition*>::iterator it;
        int c = 0;
        for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++)
        {
            function_definition *f = *it;
            c++;
            Quad_arr.emit(PARAM, f->param_name,"","");
        }
        string s = to_string(c);
            Quad_arr.emit(CALL,f,s,"");
    }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 296 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf t = current_symbol->lookup((yyvsp[-3].expr_attribute)->loc)->type;
        string s;
        type_inf t1;
        t1.type_name = "int";
    	int idx;
    	string s1;
    	idx = t.idx;
    	s = current_symbol->gentemp(t1);
            Quad_arr.emit(COPY, s, 0);
            (yyvsp[-3].expr_attribute) -> inner = new string(s); 
    	s = *((yyvsp[-3].expr_attribute)->inner);
    	s1 = to_string(idx);
 
        Quad_arr.emit(MULT, s, s, s1);
        Quad_arr.emit(PLUS, s, s, (yyvsp[-1].expr_attribute)->loc);
        Quad_arr.emit(MULT, s, s, string("4"));
        (yyval.expr_attribute) = (yyvsp[-3].expr_attribute);
    }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 315 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 316 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 317 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 319 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        symtab * f = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc);
        (yyval.expr_attribute)->loc = current_symbol->gentemp(f->type);
        if(f->type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(f->type);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attribute)->loc, *((yyvsp[-1].expr_attribute)->inner));
            Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, temp, "");
            Quad_arr.emit(MINUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-1].expr_attribute)->loc, temp, *((yyvsp[-1].expr_attribute)->inner));
        }
        else
        {
            Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, (yyvsp[-1].expr_attribute)->loc, "");
            Quad_arr.emit(MINUS, (yyvsp[-1].expr_attribute)->loc, (yyvsp[-1].expr_attribute)->loc, "1");    
        }
    }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 342 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        function_definition *f = new function_definition;
        f->param_name = (yyvsp[0].expr_attribute)->loc;
        (yyval.func_list) = new function_list;
        f->type = &(current_symbol->lookup(f->param_name)->type);
        (yyval.func_list)->func_def_list.push_back(f);
    }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 350 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        function_definition *f = new function_definition;
        f->param_name = (yyvsp[0].expr_attribute)->loc;
        (yyval.func_list) = new function_list;
        f->type = &(current_symbol->lookup(f->param_name)->type);
	(yyval.func_list) = (yyvsp[-2].func_list);
        (yyval.func_list)->func_def_list.push_back(f);
    }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 362 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        opcodeType op;
        op = MINUS;
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        if(type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(type);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            Quad_arr.emit(MINUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, (yyvsp[0].expr_attribute)->loc, temp, *((yyvsp[0].expr_attribute)->inner));
        }
        else
            Quad_arr.emit(op, (yyval.expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc, "1");

        type = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        
        op = COPY;
        Quad_arr.emit(op, (yyvsp[0].expr_attribute)->loc, (yyval.expr_attribute)->loc, "");        
    }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 385 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 387 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        opcodeType op;
        op = PLUS;
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;
        if(type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(type);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            Quad_arr.emit(PLUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, (yyvsp[0].expr_attribute)->loc, temp, *((yyvsp[0].expr_attribute)->inner));
        }
        else
            Quad_arr.emit(op, (yyval.expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc, "1");

        type = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        
        op = COPY;
        Quad_arr.emit(op, (yyvsp[0].expr_attribute)->loc, (yyval.expr_attribute)->loc, "");
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 410 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf type;
        type.type_name = string("int");
        if((yyvsp[-1].charval) == '-')
        {
            (yyval.expr_attribute) = new expression_attribute; 
            (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
            Quad_arr.emit(UNARY_MINUS,(yyval.expr_attribute)->loc,(yyvsp[0].expr_attribute)->loc,"");
        }
        else if((yyvsp[-1].charval) == '&')
        {
            (yyval.expr_attribute) = new expression_attribute;
	    type.pointer_type = "ptr";
	    type.pointer_count = 1;
	    type.size = 8;
            (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
            Quad_arr.emit(REFERENCE,(yyval.expr_attribute)->loc,(yyvsp[0].expr_attribute)->loc,"");
        }
        else if((yyvsp[-1].charval) == '*')
        {
            (yyval.expr_attribute) = new expression_attribute; 
            (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
            Quad_arr.emit(DEREFERENCE,(yyval.expr_attribute)->loc,(yyvsp[0].expr_attribute)->loc,"");
        }
        else
        {
            (yyval.expr_attribute) = (yyvsp[0].expr_attribute);
        }
        
    }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 441 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 442 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 447 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '&';
    }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 451 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '+';
    }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 455 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '-';
    }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 459 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '~';
    }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 463 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '*';
    }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 467 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.charval) = '!';
    }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 473 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 474 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 478 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 480 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {

     (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(DIVIDE, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);


    }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 582 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;


        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        Quad_arr.emit(MULT, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);

    }
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 681 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {

        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(MODULO, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);

    }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 784 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {(yyval.expr_attribute) = (yyvsp[0].expr_attribute);}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 786 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {

        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(MINUS, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);

    }
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 887 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {

        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[-2].expr_attribute));
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            type.type_name = sym_type1.type_name;
            
        }
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(PLUS, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);

    }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 990 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 992 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        int flag = 0;
        if(sym_type1.type_name.compare("int") == 0)
        {

        }
        else
        {
            if(sym_type1.type_name.compare("double") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Dbl_to_Int(e,(yyvsp[0].expr_attribute));
            }
            else if(sym_type1.type_name.compare("char") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
            }
        }
        sym_type1.type_name = "int";
        (yyval.expr_attribute)->loc = current_symbol->gentemp(sym_type1);
        Quad_arr.emit(SHIFT_LEFT, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
    }
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1046 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        int flag = 0;
        if(sym_type1.type_name.compare("int") == 0)
        {

        }
        else
        {
            if(sym_type1.type_name.compare("double") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Dbl_to_Int(e,(yyvsp[0].expr_attribute));
                //type.type_name = sym_type1.type_name;
            }
            else if(sym_type1.type_name.compare("char") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Char_to_Int(e,(yyvsp[0].expr_attribute));
                //type.type_name = sym_type1.type_name;
            }
        }
        sym_type1.type_name = "int";
        (yyval.expr_attribute)->loc = current_symbol->gentemp(sym_type1);
        Quad_arr.emit(SHIFT_RIGHT, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
    }
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1104 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1106 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_LESS, "", (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 2931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1136 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_GREATER, "", (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 2965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1166 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_LESS_EQUAL, "", (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1196 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_GREATER_EQUAL, "", (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 3033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1227 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1229 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_IS_EQUAL,"",(yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 3073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1259 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type.type_name = "bool";
        (yyval.expr_attribute)->loc = current_symbol->gentemp((yyval.expr_attribute)->type);
        (yyval.expr_attribute)->truelist = makelist(Quad_arr.index);
        (yyval.expr_attribute)->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_NOT_EQUAL,"",(yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
        Quad_arr.emit(GOTO,"","","");
    }
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1291 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1293 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        symtab *f = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc);//check
        type_inf t;
        t = f->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(t);
        Quad_arr.emit(LOGICAL_AND, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
    }
#line 3146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1325 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("exclusive_or_exp -> and_exp\n");
    }
#line 3154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1329 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        symtab *f = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc);//check
        type_inf t;
        t = f->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(t);
        Quad_arr.emit(XOR, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
    }
#line 3187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1359 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1361 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
            (yyvsp[-2].expr_attribute)->loc = temp;
            (yyvsp[-2].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        symtab *f = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc);//check
        type_inf t;
        t = f->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(t);
        Quad_arr.emit(OR, (yyval.expr_attribute)->loc, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc);
    }
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1392 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1394 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup((yyvsp[-5].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attribute)->loc, *((yyvsp[-1].expr_attribute)->inner));
            (yyvsp[-1].expr_attribute)->loc = temp;
            (yyvsp[-1].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-5].expr_attribute)->loc, *((yyvsp[-5].expr_attribute)->inner));
            (yyvsp[-5].expr_attribute)->loc = temp;
            (yyvsp[-5].expr_attribute)->type.array_type = ""; //check
        }
        
        type_inf type;
        type.type_name = "bool";
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type = type;

        Quad_arr.backpatch((yyvsp[-4].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-5].expr_attribute));

        Quad_arr.backpatch((yyvsp[0].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-1].expr_attribute));

        Quad_arr.backpatch((yyvsp[-5].expr_attribute)->truelist, (yyvsp[-2].expr_attribute)->instr);
        (yyval.expr_attribute)->truelist = (yyvsp[-1].expr_attribute)->truelist;
        (yyval.expr_attribute)->falselist = merge((yyvsp[-5].expr_attribute)->falselist, (yyvsp[-1].expr_attribute)->falselist);
    }
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1432 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1434 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup((yyvsp[-5].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attribute)->loc, *((yyvsp[-1].expr_attribute)->inner));
            (yyvsp[-1].expr_attribute)->loc = temp;
            (yyvsp[-1].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-5].expr_attribute)->loc, *((yyvsp[-5].expr_attribute)->inner));
            (yyvsp[-5].expr_attribute)->loc = temp;
            (yyvsp[-5].expr_attribute)->type.array_type = ""; //check
        }
        
        type_inf type;
        type.type_name = "bool";
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->type = type;
        
        Quad_arr.backpatch((yyvsp[-4].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-5].expr_attribute));

        Quad_arr.backpatch((yyvsp[0].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-1].expr_attribute));

        Quad_arr.backpatch((yyvsp[-5].expr_attribute)->falselist, (yyvsp[-2].expr_attribute)->instr);
        (yyval.expr_attribute)->truelist = merge((yyvsp[-5].expr_attribute)->truelist, (yyvsp[-1].expr_attribute)->truelist);
        (yyval.expr_attribute)->falselist = (yyvsp[-1].expr_attribute)->falselist;
        
    }
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1474 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {   }
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1476 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup((yyvsp[-4].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-4].expr_attribute)->loc, *((yyvsp[-4].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        (yyval.expr_attribute) = new expression_attribute;
        list<int> I;
        type_inf type;
        type = current_symbol->lookup((yyvsp[-4].expr_attribute)->loc)->type;
        (yyval.expr_attribute)->loc = current_symbol->gentemp(type);
        Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc,"");
        I = makelist(Quad_arr.index);
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch((yyvsp[-3].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.emit(COPY, (yyval.expr_attribute)->loc, (yyvsp[-4].expr_attribute)->loc, "");
        I = merge(I, makelist(Quad_arr.index));
        Quad_arr.emit(GOTO,"", "", "");
        Quad_arr.backpatch((yyvsp[-7].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-8].expr_attribute));
        Quad_arr.backpatch((yyvsp[-8].expr_attribute)->truelist, (yyvsp[-5].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[-8].expr_attribute)->falselist, (yyvsp[-1].expr_attribute)->instr);
        Quad_arr.backpatch(I, Quad_arr.index);
    }
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1517 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1519 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup((yyvsp[-2].expr_attribute)->loc)->type;
        sym_type2 = current_symbol->lookup((yyvsp[0].expr_attribute)->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attribute)->loc, *((yyvsp[0].expr_attribute)->inner));
            (yyvsp[0].expr_attribute)->loc = temp;
            (yyvsp[0].expr_attribute)->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            Quad_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc, *((yyvsp[-2].expr_attribute)->inner));
        }
        else
            Quad_arr.emit(COPY, (yyvsp[-2].expr_attribute)->loc, (yyvsp[0].expr_attribute)->loc, "");
        (yyval.expr_attribute) = (yyvsp[-2].expr_attribute);
    }
#line 3403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1543 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1544 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1545 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1546 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1547 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1548 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1549 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1550 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1551 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1552 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1553 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1557 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = (yyvsp[0].expr_attribute);
    }
#line 3477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1560 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1563 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1570 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {}
#line 3495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1572 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        init_declration_list *new_dec = new init_declration_list;
        new_dec = (yyvsp[-1].init_dec_list);
        int size = 0;
        type_inf *type = (yyvsp[-2].type_);
        if(type->type_name.compare("int")==0) size = 4;
        if(type->type_name.compare("double")==0) size = 8;
        if(type->type_name.compare("char")==0) size = 1;

        list<declaration*>::iterator it;
        for(it = (yyvsp[-1].init_dec_list)->declaration_list.begin(); it != (yyvsp[-1].init_dec_list)->declaration_list.end(); it++)
        {
            declaration *new_dec = *it;
		    if(new_dec->type!=NULL){
            if(new_dec->type->type_name.compare("function")==0)
            {
                string name = new_dec->dec_name;
                current_symbol = &GTable;
                Quad_arr.emit(_FUNCTION_END,name,"","");
            }
            
            symtab *ret, *f;
            symbol_table *nest;
            if(new_dec->type->type_name.compare("function")==0)
            {
                f = current_symbol->lookup(new_dec->dec_name, type->type_name);
                nest = f->nested_table;
                ret = nest->lookup("retVal", type->type_name, new_dec->pointer_count);
                f->offset = current_symbol->offset;
                f->size = size;
                f->init_val = NULL;
                continue;
            }
            }
            
            symtab *f1 = current_symbol->lookup(new_dec->dec_name, type->type_name);

            f1->nested_table = NULL;


            if(new_dec->alist == vector<int>() && new_dec->pointer_count == 0)
            {
                f1->offset = current_symbol->offset;
                //f1->offset = f1->offset + size;
                f1->type = *type;
                f1 = current_symbol->lookup(new_dec->dec_name, type->type_name);
            
                if(new_dec->init != NULL)
                {
            
                    string x = new_dec->init->loc;
                    Quad_arr.emit(COPY, new_dec->dec_name, x, "");
                    f1->init_val = current_symbol->lookup(x,f1->type.type_name)->init_val;
                }
                else
                    new_dec->init = NULL;
            }

            else if(new_dec -> pointer_count > 0)
            {
                symtab *sp;
                for(sp = current_symbol->sym_table; sp < &current_symbol->sym_table[current_symbol->no_of_entries]; sp++)
                {
                    if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                    {
                        sp->offset = current_symbol->offset-4;
                        sp->pointer_count = new_dec->pointer_count;
                        sp->type = *type;
                        sp->type.pointer_type = "ptr";
                        sp->size = 4;
                    }
                }
                
            }

            else if(new_dec->alist!=vector<int>())
            {
                symtab *sp;
                for(sp = current_symbol->sym_table; sp < &current_symbol->sym_table[current_symbol->no_of_entries]; sp++)
                {
                    if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                    {
                        int temp_size = size;
                        sp->offset = current_symbol->offset-4;
                        sp->type = *type;
			            sp->type.type_name = type->type_name;
                        sp->type.array_type = "array";
                        sp->type.pointer_type = "";
                        for(int i = 0; i < new_dec->alist.size(); i++)
                        {
                            sp->type.array_list.push_back(new_dec->alist[i]);
                        }
                        for (int i = 0; i < sp->type.array_list.size(); ++i)
                        {
                            temp_size = temp_size * sp->type.array_list[i];
                        }
                        sp->size = temp_size;
                        current_symbol->offset = current_symbol->offset + temp_size;
                    }
                }
                
            }

            
        }
    }
#line 3606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1682 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1685 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1688 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.type_) = (yyvsp[0].type_);
    }
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1692 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1695 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1698 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1701 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1704 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1711 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    { 
        (yyval.init_dec_list) = new init_declration_list;
        (yyval.init_dec_list)->declaration_list.push_back((yyvsp[0].declaration_list));
    }
#line 3672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1716 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].init_dec_list)->declaration_list.push_back((yyvsp[0].declaration_list));
        (yyval.init_dec_list) = (yyvsp[-2].init_dec_list);
    }
#line 3681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1725 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.declaration_list) = (yyvsp[0].declaration_list);
        (yyval.declaration_list)->init = NULL;
    }
#line 3690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1730 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.declaration_list) = (yyvsp[-2].declaration_list);
        (yyval.declaration_list)->init = (yyvsp[0].expr_attribute);
    }
#line 3699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1736 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> extern\n");}
#line 3705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1737 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> static\n");}
#line 3711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1738 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> auto\n");}
#line 3717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1739 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> register\n");}
#line 3723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1744 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
            (yyval.type_) = new type_inf;
			(yyval.type_)->type_name = string("void"); 
		}
#line 3732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1749 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
            (yyval.type_) = new type_inf;
			(yyval.type_)->type_name = string("char");
			(yyval.type_)->next = NULL;
		}
#line 3742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1754 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        }
#line 3749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1757 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
            (yyval.type_) = new type_inf;
			(yyval.type_)->type_name = string("int");
			(yyval.type_)->next = NULL;
			
			
		}
#line 3761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1764 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        }
#line 3768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1766 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        }
#line 3775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1769 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.type_) = new type_inf;
		(yyval.type_)->type_name = string("double");
		(yyval.type_)->next = NULL;
	}
#line 3785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1774 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1776 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1778 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1780 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1782 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1789 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
			(yyval.type_) = (yyvsp[0].type_);
		}
#line 3828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1793 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1795 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
                        }
#line 3842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1797 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
                        }
#line 3849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1801 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enum_specifier -> enum {enumerator_list}\n");}
#line 3855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1802 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enum_specifier -> enum IDENTIFIER {enumerator_list} \n");}
#line 3861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1803 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enum_specifier -> enum {enumerator_list, }\n");}
#line 3867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1804 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enum_specifier -> enum IDENTIFIER {enumerator_list ,}\n");}
#line 3873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1805 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enum_specifier->enum IDENTIFIER\n");}
#line 3879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1808 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enumerator_list -> enumerator\n");}
#line 3885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1809 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enumerator_list -> enumerator_list , enumerator\n");}
#line 3891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1812 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enumerator -> enumeration_constant\n");}
#line 3897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1813 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enumerator -> enumeration_constant = constant_exp\n");}
#line 3903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1816 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("enumeration_constant -> IDENTIFIER\n");}
#line 3909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1819 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("type_qualifier -> const\n");}
#line 3915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1820 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("type_qualifier -> restrict\n");}
#line 3921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1821 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("type_qualifier -> volatile\n");}
#line 3927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1824 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {printf("function_specifier -> inline\n");}
#line 3933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1827 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.declaration_list) = (yyvsp[0].declaration_list);
        (yyval.declaration_list)->pointer_count = (yyvsp[-1].type_)->pointer_count;
        //printf("declarator -> pointer direct_declarator\n");
    }
#line 3943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1833 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {

		(yyval.declaration_list) = (yyvsp[0].declaration_list);
        (yyval.declaration_list)->pointer_count = 0;
			//printf("declarator -> direct_declarator\n");
	}
#line 3954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1844 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {//printf("direct_declarator -> IDENTIFIER\n");
        (yyval.declaration_list) = new declaration; 
        (yyval.declaration_list)->dec_name = *((yyvsp[0].str));
    }
#line 3963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1849 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.declaration_list) = (yyvsp[-1].declaration_list);
    }
#line 3971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1853 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
	
        (yyval.declaration_list) = (yyvsp[-4].declaration_list);
        int idx = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc)->init_val->int_val;
        (yyval.declaration_list)->alist.push_back(idx);
    }
#line 3982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1860 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1863 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 3996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1866 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    }
#line 4003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1869 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //name of func is available
        list<function_definition*> l = (yyvsp[-1].func_list)->func_def_list;
        
        symbol_table *new_sym = new symbol_table;
        (yyval.declaration_list) = (yyvsp[-3].declaration_list);
        string name = (yyval.declaration_list)->dec_name;
        //cout<<name<<"\n";
        (yyval.declaration_list)->type = new type_inf;
        (yyval.declaration_list)->type->type_name = string("function");
        (yyval.declaration_list)->type->no_of_params = l.size();
        symtab *func_lookup = symbol->lookup((yyval.declaration_list)->dec_name, (yyval.declaration_list)->type->type_name);
		for(int i=0; i < symbol->no_of_entries; i++)
       		{
	    	if(symbol->sym_table[i].id.compare((yyval.declaration_list)->dec_name)==0)
	    	{
				symbol->sym_table[i].type.type_name = "function";
				symbol->sym_table[i].type.no_of_params = l.size();
	    	}
        }

        func_lookup -> nested_table = new_sym;

        list<function_definition*>::iterator it;
        for(it = l.begin(); it != l.end(); it++)
        {
            function_definition *temp = *it;
            new_sym -> lookup(temp->param_name, temp->type->type_name);
	    for(int i = 0; i<new_sym->no_of_entries; i++)
	    {
		if(new_sym->sym_table[i].id.compare(temp->param_name)==0)
		{
			if(temp->type->array_type.compare("array")==0){
				new_sym->sym_table[i].type.array_type = "array";
				new_sym->sym_table[i].type.idx = temp->type->idx;
				}
		}
	    }

            //func_lookup->nested_table -> lookup(temp->param_name, temp->type->type_name);
        }

        symtab *sp;
        for(sp = symbol->sym_table; sp < &symbol->sym_table[symbol->no_of_entries]; sp++)
        {
            //cout<<s<<"\n";
            //cout<<"loop\n";
            if(!sp->id.empty() && !sp->id.compare((yyval.declaration_list)->dec_name))
            {
                sp->nested_table = new_sym;
            }
        }
        current_symbol = new_sym;
        Quad_arr.emit(_FUNCTION_START, name,"","");
    }
#line 4063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1925 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("direct_declarator -> direct_declarator (identifier_list_opt)\n");

    }
#line 4072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1933 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    //printf("assignment_exp_opt -> assignment_exp\n");
   }
#line 4080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1940 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("type_qualifier_list_opt -> type_qualifier_list\n");
    }
#line 4088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1948 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("pointer -> '*'\n");
        (yyval.type_) = new type_inf;
        (yyval.type_)->type_name = string("ptr");
        (yyval.type_)->next = NULL;
        (yyval.type_)->pointer_type = string("ptr");
        (yyval.type_)->pointer_count = 1;
    }
#line 4101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1957 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
    //    printf("pointer -> *type_qualifier_list\n");
    }
#line 4109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1961 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("pointer -> *pointer\n");
        (yyval.type_) = new type_inf;
        (yyval.type_)->type_name = string("ptr");
        (yyval.type_)->next = NULL;
        (yyval.type_)->pointer_type = string("ptr");
        
        (yyval.type_)->pointer_count = (yyvsp[0].type_)->pointer_count + 1;
        
    }
#line 4124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1972 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("pointer -> *type_qualifier_list pointer\n");
    }
#line 4132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1978 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("type_qualifier_list -> type_qualifier\n");
    }
#line 4140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1982 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("type_qualifier_list -> type_qualifier_list type_qualifier\n");
    }
#line 4148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1989 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.func_list) = new function_list;
    }
#line 4156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1995 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.func_list) = new function_list;
        (yyval.func_list) = (yyvsp[0].func_list);
        //printf("parameter_type_list -> parameter_list\n");
    }
#line 4166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2001 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("parameter_type_list -> parameter_list, ELLIPSIS\n");
    }
#line 4174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2007 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //create a new list
        (yyval.func_list) = new function_list;
        (yyval.func_list)->func_def_list.push_back((yyvsp[0].function_def));

        //printf("parameter_list -> parameter_declaration\n");
    }
#line 4186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2015 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //make use of old list

        (yyvsp[-2].func_list)->func_def_list.push_back((yyvsp[0].function_def));
        (yyval.func_list) = (yyvsp[-2].func_list);
        //printf("parameter_list -> parameter_list, parameter_declaration\n");
    }
#line 4198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2025 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.function_def) = new function_definition;
        (yyval.function_def)->type = (yyvsp[-1].type_);
	if((yyvsp[0].declaration_list)->alist.size()>0)
		{(yyval.function_def)->type->array_type = "array";(yyval.function_def)->type->idx = (yyvsp[0].declaration_list)->alist[0];(yyval.function_def)->type->type_name = (yyvsp[-1].type_)->type_name;
	}
	for(int i=0; i<current_symbol->no_of_entries; i++)
	{
		if(current_symbol->sym_table[i].id.compare((yyvsp[0].declaration_list)->dec_name)==0)
		{
			if((yyvsp[0].declaration_list)->type->array_type.compare("array")==0 || current_symbol->sym_table[i].type.array_type.compare("array")==0)
			{
				current_symbol->sym_table[i].type.array_type = "array";
				(yyval.function_def)->type->array_type = "array";
			}
		}
	}
	(yyval.function_def)->param_name = (yyvsp[0].declaration_list)->dec_name;

        //printf("parameter_declaration -> declaration_specifiers declarator\n");
    }
#line 4224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 2047 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("parameter_declaration -> declaration_specifiers\n");
    }
#line 4232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2054 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("identifier_list -> IDENTIFIER\n");
    }
#line 4240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2058 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("identifier_list -> identifier_list, IDENTIFIER\n");
    }
#line 4248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 2065 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.type_) = (yyvsp[0].type_);
        //printf("type_name -> specifier_qualifier_list\n");
    }
#line 4257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 2073 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {//printf("initializer -> assignment_exp\n");
        (yyval.expr_attribute) = (yyvsp[0].expr_attribute);
    }
#line 4265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2077 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("initializer -> {initializer_list}\n");
    }
#line 4273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2081 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("initializer -> {initializer_list, }\n");
    }
#line 4281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2088 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("initializer_list -> initializer\n");
    }
#line 4289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 2092 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("initializer_list -> designation initializer\n");
    }
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 2096 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {//printf("initializer_list -> initializer_list, initializer\n");
    }
#line 4304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 2099 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("initializer_list -> initializer_list, designation initializer\n");
    }
#line 4312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2106 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("designation -> designator_list -\n");
    }
#line 4320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2113 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("designator_list -> designator\n");
    }
#line 4328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2117 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("designator_list -> designator_list designator\n");
    }
#line 4336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2123 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("designator -> [constant_exp]\n");
    }
#line 4344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2127 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("designator -> IDENTIFIER\n");
    }
#line 4352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2137 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> labeled_statement\n");
    }
#line 4360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2141 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> compound_statement\n");
    }
#line 4368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2145 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> expression_statement\n");
    }
#line 4376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2149 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> selection_statement\n");
    }
#line 4384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2153 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> iteration_statement\n");
    }
#line 4392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2157 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("statement -> jump_statement\n");
    }
#line 4400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2163 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("labeled_statement -> IDENTIFIER : statement\n");
    }
#line 4408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 2167 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("labeled_statement -> case constant_exp : statement\n");
    }
#line 4416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 2171 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("labeled_statement -> default : statement\n");
    }
#line 4424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 2178 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("compound_statement -> {}\n");
    }
#line 4432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 2182 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = (yyvsp[-1].expr_attribute);
        //printf("compound_statement -> {block_item_list}\n");
    }
#line 4441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 2190 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = (yyvsp[0].expr_attribute);
        Quad_arr.backpatch((yyvsp[0].expr_attribute)->nextlist, Quad_arr.index);
        //printf("block_item_list -> block_item\n");
    }
#line 4451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 2196 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        Quad_arr.backpatch((yyvsp[-2].expr_attribute)->nextlist, (yyvsp[-1].expr_attribute)->instr);
        (yyval.expr_attribute) = new expression_attribute;
        (yyval.expr_attribute)->nextlist = (yyvsp[0].expr_attribute)->nextlist;
        //printf("block_item_list -> block_item_list block_item\n");
    }
#line 4462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 2205 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        //printf("block_item -> declaration\n");
    }
#line 4471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 2210 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("block_item -> statement\n");
    }
#line 4479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 2216 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        //printf("expression_statement -> ;\n");
    }
#line 4488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 2221 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //$$ = $1;
        //printf("expression_statement -> exp ;\n");
    }
#line 4497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 2228 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        //if($3->type.type_name.compare("bool"))
        Quad_arr.backpatch((yyvsp[-4].expr_attribute)->nextlist, Quad_arr.index);

        //cout<<$3->type.type_name<<"\n";
        Quad_arr.convInt2Bool((yyvsp[-5].expr_attribute));
        
        Quad_arr.backpatch((yyvsp[-5].expr_attribute)->truelist, (yyvsp[-2].expr_attribute)->instr);
        //$$->nextlist

        (yyval.expr_attribute)->nextlist = merge((yyvsp[0].expr_attribute)->nextlist, (yyvsp[-1].expr_attribute)->nextlist);
        (yyval.expr_attribute)->nextlist = merge((yyval.expr_attribute)->nextlist, (yyvsp[-5].expr_attribute)->falselist);
        //printf("selection_statement -> if (exp) statement\n");
    }
#line 4517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2244 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;

        Quad_arr.backpatch((yyvsp[-8].expr_attribute)->nextlist , Quad_arr.index);

        Quad_arr.convInt2Bool((yyvsp[-9].expr_attribute));

        (yyval.expr_attribute)->nextlist = merge((yyvsp[-5].expr_attribute)->nextlist, (yyvsp[-4].expr_attribute)->nextlist);

        Quad_arr.backpatch((yyvsp[-9].expr_attribute)->truelist, (yyvsp[-6].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[-9].expr_attribute)->falselist, (yyvsp[-2].expr_attribute)->instr);

        (yyval.expr_attribute)->nextlist = merge((yyval.expr_attribute)->nextlist, (yyvsp[0].expr_attribute)->nextlist);
        (yyval.expr_attribute)->nextlist = merge((yyval.expr_attribute)->nextlist, (yyvsp[-1].expr_attribute)->nextlist);
        //printf("selection_statement -> if(exp) statement else statement\n");
    }
#line 4538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2261 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("selection_statement -> switch(exp) statement\n");
    }
#line 4546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2267 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch(makelist(Quad_arr.index-1),(yyvsp[-6].expr_attribute)->instr);    

        Quad_arr.backpatch((yyvsp[-3].expr_attribute)->nextlist,Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-4].expr_attribute));

        (yyval.expr_attribute) = new expression_attribute;
        Quad_arr.backpatch((yyvsp[0].expr_attribute)->nextlist, (yyvsp[-6].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[-4].expr_attribute)->truelist, (yyvsp[-1].expr_attribute)->instr);
        (yyval.expr_attribute)->nextlist = (yyvsp[-4].expr_attribute)->falselist;
        //printf("iteration_statement -> while(exp) statement\n");
    }
#line 4564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2281 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        Quad_arr.convInt2Bool((yyvsp[-2].expr_attribute));
        Quad_arr.backpatch((yyvsp[-6].expr_attribute)->nextlist, (yyvsp[-5].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[-2].expr_attribute)->truelist, (yyvsp[-7].expr_attribute)->instr);
        (yyval.expr_attribute)->nextlist = (yyvsp[-2].expr_attribute)->falselist;
        //printf("iteration_statement -> do statement while(exp);\n");
    }
#line 4577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2290 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
    
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch(makelist(Quad_arr.index-1),(yyvsp[-5].expr_attribute)->instr);    
        Quad_arr.backpatch((yyvsp[-7].expr_attribute)->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool((yyvsp[-8].expr_attribute));

        Quad_arr.backpatch((yyvsp[-3].expr_attribute)->nextlist,(yyvsp[-9].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[-8].expr_attribute)->truelist,(yyvsp[-1].expr_attribute)->instr);
        Quad_arr.backpatch((yyvsp[0].expr_attribute)->nextlist,(yyvsp[-5].expr_attribute)->instr);
    
        (yyval.expr_attribute)->nextlist = (yyvsp[-8].expr_attribute)->falselist;

        //printf("iteration_statement -> for(expression_opt expression_opt expression_opt) statement\n");
    }
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2307 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("iteration_statement -> for (declaration expression_opt expression_opt) statement\n");
    }
#line 4606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2313 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("expression_opt -> exp\n");
    }
#line 4614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2320 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("jump_statement -> goto IDENTIFIER :\n");
    }
#line 4622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2324 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("jump_statement -> continue ;\n");
    }
#line 4630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2328 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("jump_statement -> break;\n");
    }
#line 4638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2332 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;

        if(current_symbol->lookup("retVal")->type.type_name.compare("void")==0)
        {
            Quad_arr.emit(RETURN_VOID,"","","");
        }
        
        //printf("jump_statement -> return;\n");
    }
#line 4653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2343 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        (yyval.expr_attribute) = new expression_attribute;
        type_inf sym_type1, sym_type2, type3;
        sym_type1 = current_symbol->lookup("retVal")->type;
        sym_type2 = current_symbol->lookup((yyvsp[-1].expr_attribute)->loc)->type;
        for(int i=0; i<symbol->no_of_entries;i++)
	{
		if(symbol->sym_table[i].id.compare((yyvsp[-1].expr_attribute)->loc)==0)
			type3 = symbol->sym_table[i].type;
	}
	if(type3.type_name.compare("function")==0)
	{	
		string t = current_symbol->gentemp(sym_type1);
		Quad_arr.emit(COPY, t, (yyvsp[-1].expr_attribute)->loc, "");
		Quad_arr.emit(RETURN,t,"","");
	}
	else if(sym_type1.type_name == sym_type2.type_name)
        {
            Quad_arr.emit(RETURN, (yyvsp[-1].expr_attribute)->loc, "", "");
        }
	
        //printf("jump_statement -> return exp;\n");

    }
#line 4682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2374 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("translation_unit -> external_declaration\n");
    }
#line 4690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2378 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("translation_unit -> translation_unit external_declaration\n");
    }
#line 4698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2385 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("external_declaration -> function_definition\n");
    }
#line 4706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2389 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("external_declaration -> declaration\n");
    }
#line 4714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2396 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");
    }
#line 4722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2400 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //symbol->nested_table = NULL;
        //current_symbol->nested_table = NULL;
        
        declaration *new_dec = (yyvsp[-1].declaration_list);
        int size = 0;
        type_inf *type = (yyvsp[-2].type_);
        if(type->type_name.compare("int")==0) size = 4;
        if(type->type_name.compare("double")==0) size = 8;
        if(type->type_name.compare("char")==0) size = 1;
        if(type->type_name.compare("void")==0) size = 0;
        //cout<<$2->type->type_name;
        symbol_table *gt = &GTable;
        Quad_arr.emit(_FUNCTION_END,new_dec->dec_name,"","");
        symtab *func = gt->lookup((yyvsp[-1].declaration_list)->dec_name);
        //cout<<"function_definition "<<$2->dec_name<<"\n";
        //func->nested_table = new symbol_table;
        if(func->nested_table != NULL)
        {
            //cout<<"nested\n";
            //cout<<new_dec->dec_name<<" "<<new_dec->pointer_count<<type->type_name<<"\n";
            if((yyvsp[-1].declaration_list)->pointer_count>0)
                type->pointer_type = "ptr";
            symtab *ret = func->nested_table->lookup("retVal", type->type_name, (yyvsp[-1].declaration_list)->pointer_count);
            /*symtab *sp;
            for(sp = func->nested_table->sym_table; sp < &func->nested_table->sym_table[func->nested_table->no_of_entries]; sp++)
            {
                //cout<<s<<"\n";
                //cout<<"loop\n";
                if(!sp->id.empty() && !sp->id.compare($$->dec_name))
                {

                    sp->type = *type;
                    sp->pointer_count = $2->pointer_count;
                }
            }*/
        
            if((yyvsp[-1].declaration_list)->pointer_count>0)
            {
                ret->pointer_count = (yyvsp[-1].declaration_list)->pointer_count;
                ret->type.pointer_type = "ptr";
            }
            ret->offset = current_symbol->offset;
            ret->size = size;
            ret->init_val = NULL;
        }
        //current_symbol = func->nested_table;
        current_symbol = gt;
        (yyval.declaration_list) = (yyvsp[-1].declaration_list);
        //printf("function_definition -> declaration_specifiers declarator compound_statement\n");
    }
#line 4778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 2455 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("declaration_list -> declaration\n");
    }
#line 4786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 2459 "ass6_17CS10005_17CS10007.y" /* yacc.c:1646  */
    {
        //printf("declaration_list -> declaration_list declaration\n");
    }
#line 4794 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4798 "y.tab.c" /* yacc.c:1646  */
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
#line 2466 "ass6_17CS10005_17CS10007.y" /* yacc.c:1906  */

void yyerror(string s) 
{
	cout << s << endl;
}





