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
#line 7 "asgn4_17CS10005.y" /* yacc.c:339  */
 
	#include <string.h>
	#include <stdio.h>
	extern int yylex();
	void yyerror(char *s);

#line 73 "y.tab.c" /* yacc.c:339  */

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
    AND = 258,
    DECREMENT = 259,
    EQUALEQUAL = 260,
    INCREMENT = 261,
    OR = 262,
    LEFTSHIFT = 263,
    RIGHTSHIFT = 264,
    LESSTHANEQUAL = 265,
    GREATERTHANEQUAL = 266,
    NOTEQUAL = 267,
    POINTER = 268,
    MULTIPLYASSIGN = 269,
    ELLIPSIS = 270,
    DIVIDEASSIGN = 271,
    MODASSIGN = 272,
    ADDASSIGN = 273,
    LEFTSHIFTASSIGN = 274,
    RIGHTSHIFTASSIGN = 275,
    SUBTRACTASSIGN = 276,
    ANDASSIGN = 277,
    XORASSIGN = 278,
    ORASSIGN = 279,
    SIZEOF = 280,
    EXTERN = 281,
    STATIC = 282,
    AUTO = 283,
    REGISTER = 284,
    VOID = 285,
    CHAR = 286,
    SHORT = 287,
    INT = 288,
    LONG = 289,
    FLOAT = 290,
    DOUBLE = 291,
    SIGNED = 292,
    UNSIGNED = 293,
    BOOL = 294,
    COMPLEX = 295,
    IMAGINARY = 296,
    ENUM = 297,
    CONST = 298,
    RESTRICT = 299,
    VOLATILE = 300,
    INLINE = 301,
    CASE = 302,
    DEFAULT = 303,
    IF = 304,
    ELSE = 305,
    SWITCH = 306,
    WHILE = 307,
    DO = 308,
    FOR = 309,
    GOTO = 310,
    CONTINUE = 311,
    BREAK = 312,
    RETURN = 313,
    INT_CONSTANT = 314,
    FLOAT_CONSTANT = 315,
    ENU_CONSTANT = 316,
    CHAR_CONSTANT = 317,
    IDENTIFIER = 318,
    STRING_LITERAL = 319
  };
#endif
/* Tokens.  */
#define AND 258
#define DECREMENT 259
#define EQUALEQUAL 260
#define INCREMENT 261
#define OR 262
#define LEFTSHIFT 263
#define RIGHTSHIFT 264
#define LESSTHANEQUAL 265
#define GREATERTHANEQUAL 266
#define NOTEQUAL 267
#define POINTER 268
#define MULTIPLYASSIGN 269
#define ELLIPSIS 270
#define DIVIDEASSIGN 271
#define MODASSIGN 272
#define ADDASSIGN 273
#define LEFTSHIFTASSIGN 274
#define RIGHTSHIFTASSIGN 275
#define SUBTRACTASSIGN 276
#define ANDASSIGN 277
#define XORASSIGN 278
#define ORASSIGN 279
#define SIZEOF 280
#define EXTERN 281
#define STATIC 282
#define AUTO 283
#define REGISTER 284
#define VOID 285
#define CHAR 286
#define SHORT 287
#define INT 288
#define LONG 289
#define FLOAT 290
#define DOUBLE 291
#define SIGNED 292
#define UNSIGNED 293
#define BOOL 294
#define COMPLEX 295
#define IMAGINARY 296
#define ENUM 297
#define CONST 298
#define RESTRICT 299
#define VOLATILE 300
#define INLINE 301
#define CASE 302
#define DEFAULT 303
#define IF 304
#define ELSE 305
#define SWITCH 306
#define WHILE 307
#define DO 308
#define FOR 309
#define GOTO 310
#define CONTINUE 311
#define BREAK 312
#define RETURN 313
#define INT_CONSTANT 314
#define FLOAT_CONSTANT 315
#define ENU_CONSTANT 316
#define CHAR_CONSTANT 317
#define IDENTIFIER 318
#define STRING_LITERAL 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "asgn4_17CS10005.y" /* yacc.c:355  */

	int intval;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    80,    73,     2,
      65,    66,    74,    75,    72,    76,    69,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    88,
      81,    87,    82,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    84,    71,    77,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    44,    44,    44,    46,    46,    46,    46,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      50,    50,    52,    52,    52,    52,    52,    52,    54,    54,
      54,    54,    54,    54,    56,    56,    58,    58,    59,    59,
      62,    62,    62,    64,    64,    64,    66,    66,    66,    66,
      66,    68,    68,    68,    70,    70,    72,    72,    74,    74,
      76,    76,    78,    78,    80,    80,    82,    82,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    86,
      86,    88,    90,    90,    92,    92,    92,    92,    92,    92,
      92,    92,    94,    94,    96,    96,    98,    98,    98,    98,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   102,   102,   102,   102,   105,   105,   105,
     105,   105,   107,   107,   109,   109,   111,   111,   111,   113,
     115,   115,   117,   117,   117,   117,   117,   117,   117,   117,
     119,   119,   121,   121,   123,   123,   123,   123,   125,   125,
     127,   127,   129,   129,   131,   131,   133,   133,   135,   137,
     137,   137,   139,   139,   139,   139,   141,   143,   143,   145,
     145,   147,   147,   147,   147,   147,   147,   149,   149,   149,
     151,   151,   153,   153,   155,   155,   157,   157,   159,   159,
     159,   161,   161,   161,   161,   163,   163,   163,   163,   163,
     165,   165,   167,   167,   169,   169,   169,   169,   171,   171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "DECREMENT", "EQUALEQUAL",
  "INCREMENT", "OR", "LEFTSHIFT", "RIGHTSHIFT", "LESSTHANEQUAL",
  "GREATERTHANEQUAL", "NOTEQUAL", "POINTER", "MULTIPLYASSIGN", "ELLIPSIS",
  "DIVIDEASSIGN", "MODASSIGN", "ADDASSIGN", "LEFTSHIFTASSIGN",
  "RIGHTSHIFTASSIGN", "SUBTRACTASSIGN", "ANDASSIGN", "XORASSIGN",
  "ORASSIGN", "SIZEOF", "EXTERN", "STATIC", "AUTO", "REGISTER", "VOID",
  "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED",
  "BOOL", "COMPLEX", "IMAGINARY", "ENUM", "CONST", "RESTRICT", "VOLATILE",
  "INLINE", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "INT_CONSTANT",
  "FLOAT_CONSTANT", "ENU_CONSTANT", "CHAR_CONSTANT", "IDENTIFIER",
  "STRING_LITERAL", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept", "constant",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
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
     315,   316,   317,   318,   319,    40,    41,    91,    93,    46,
     123,   125,    44,    38,    42,    43,    45,   126,    33,    47,
      37,    60,    62,    94,   124,    63,    58,    61,    59
};
# endif

#define YYPACT_NINF -277

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-277)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     937,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,   -40,  -277,  -277,
    -277,  -277,  -277,     1,    42,  -277,    86,  1069,  1069,  -277,
    1069,  1069,   986,     6,    25,   590,  -277,  -277,   -43,   -19,
      79,  -277,  -277,    42,  -277,   -55,  -277,   166,  -277,  -277,
    -277,  -277,   246,  -277,    86,  -277,   986,  1007,   134,     6,
    -277,  -277,   -19,    70,   116,  -277,  -277,  -277,  -277,     1,
    -277,   738,  -277,   986,   822,   822,   842,   864,    90,   100,
     153,   167,   383,   177,   183,   163,   179,   445,  -277,  -277,
    -277,  -277,   168,  -277,   537,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,    55,    32,   864,  -277,    93,
     152,   230,    71,    65,   197,   213,   231,   311,     9,  -277,
    -277,    35,  -277,  -277,  -277,  -277,   321,  -277,  -277,  -277,
    -277,  -277,   239,  -277,  -277,  -277,  -277,     1,   252,   256,
    -277,    43,   172,   884,   172,   185,   864,  -277,   -45,  -277,
    -277,   676,  -277,  -277,  -277,   537,  -277,  -277,   537,  -277,
    -277,  -277,   243,   383,   864,   864,   864,   278,   475,   244,
    -277,  -277,  -277,    78,   383,    45,   380,  -277,   380,   265,
    -277,  -277,   270,   758,   864,   272,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,   864,  -277,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,  -277,
    -277,  -277,  -277,  -277,  1048,  -277,   273,   864,   269,  -277,
     271,  -277,   -42,  -277,  -277,  -277,   864,   275,  -277,   188,
     738,    -4,  -277,   274,   276,   383,  -277,   109,   117,   118,
     279,   475,  -277,  -277,  -277,  -277,  -277,  -277,   780,  -277,
    -277,   119,  -277,    46,  -277,  -277,  -277,  -277,  -277,    93,
      93,   152,   152,   230,   230,   230,   230,    71,    71,    65,
     197,   213,   231,   311,   -50,  -277,  -277,  -277,  -277,   277,
    -277,  -277,  -277,   303,  -277,  -277,   633,  -277,  -277,  -277,
     318,   318,  -277,   383,   383,   383,   864,   800,   676,  -277,
    -277,   864,  -277,   864,  -277,  -277,  -277,  -277,   738,   291,
    -277,  -277,   147,   383,   148,   190,  -277,  -277,  -277,   383,
     255,  -277,   383,  -277,   653,  -277,  -277,  -277,  -277
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   126,   128,
     127,   129,   132,     0,   144,   203,     0,    84,    86,   112,
      88,    90,     0,   131,     0,     0,   200,   202,   121,     0,
       0,   148,   146,   145,    82,     0,    92,    94,    85,    87,
      89,    91,     0,   208,     0,   207,     0,     0,   140,   130,
       1,   201,     0,   124,     0,   122,   133,   149,   147,     0,
      83,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     8,     0,   180,    28,    29,    30,    31,
      32,    33,   186,     7,    10,    22,    34,     0,    36,    40,
      43,    46,    51,    54,    56,    58,    60,    62,    64,    66,
      79,     0,   184,   185,   171,   172,     0,   182,   173,   174,
     175,   176,    94,   209,   206,   156,   139,   155,     0,   150,
     152,     0,   140,   142,   141,     0,     0,   117,     0,    93,
       6,     0,   159,    95,   204,     0,    24,    23,     0,    26,
      34,    81,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   197,   198,     0,     0,     0,   114,   158,   116,     0,
      17,    16,     0,     0,     0,     0,    69,    70,    71,    72,
      74,    75,    73,    76,    77,    78,    68,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
     181,   183,   154,   137,     0,   138,     0,     0,    29,   143,
       0,   118,     0,   125,   119,   123,     0,     0,   162,     0,
       0,     0,   167,     0,     0,     0,   179,     0,     0,     0,
       0,     0,   195,   199,   177,     9,   113,   115,     0,    15,
      12,     0,    20,     0,    14,    67,    37,    38,    39,    41,
      42,    44,    45,    49,    50,    47,    48,    52,    53,    55,
      57,    59,    61,    63,     0,    80,   151,   153,   157,     0,
     136,   134,   120,     0,   170,   160,     0,   163,   166,   168,
       0,    27,   178,     0,     0,     0,     0,     0,     0,    35,
      13,     0,    11,     0,   135,   169,   161,   164,     0,   188,
     190,   191,     0,     0,     0,     0,    21,    65,   165,     0,
       0,   193,     0,    18,     0,   189,   192,   194,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -277,  -277,  -277,  -277,  -277,   -72,  -277,   -95,    63,    64,
      15,   102,   178,   180,   186,   187,   189,  -277,   -68,   -71,
    -277,   -63,  -140,   -13,    10,  -277,   332,  -277,   -79,    57,
    -277,   341,  -141,     4,  -277,   -12,   370,   264,  -277,   -11,
     402,  -277,  -277,   203,  -277,     0,   -70,    99,  -276,  -277,
     192,   -74,  -277,    37,  -277,   302,  -143,  -277,  -277,  -277,
    -277,   394,  -277,   403
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   105,   261,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     197,   121,   162,    25,    54,    45,    46,    27,    28,   177,
      29,    64,    65,    30,    31,    32,    33,   143,   230,    34,
     144,   138,   139,   140,   141,   179,   238,   239,   240,   241,
     242,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      35,    36,    37,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     152,   153,   156,   157,   159,   160,   233,   235,   167,   161,
      26,    40,   198,    42,    47,   176,   216,    69,    63,    53,
     318,    63,   218,    38,   173,   251,   234,    62,    41,   292,
      39,   175,    68,    70,    53,   160,   313,    48,    49,   122,
      50,    51,   132,   133,    63,    26,   186,    67,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   132,   318,   180,
     133,   181,    41,   236,    22,   237,    23,   137,   182,    55,
     210,    57,   229,    58,   160,    24,   176,   211,   161,   176,
     152,   206,   207,   298,    72,    18,    19,    20,    22,   246,
      23,   235,   175,   134,   217,   175,   293,   176,   178,   176,
     254,   247,   248,   249,   266,   267,   268,   218,   307,   225,
     154,   255,   262,   122,   312,   226,    24,   218,   218,   196,
     183,   263,   184,   219,   185,   222,   265,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,    66,    41,   285,    67,    22,
     218,    23,   208,   209,   284,   243,   289,   146,   244,   178,
      24,   142,   178,   309,   160,   164,   253,   199,   161,   152,
     297,   302,   200,   201,    44,   303,   163,    18,    19,    20,
     178,   218,   178,   304,   305,   310,   160,   147,   148,   218,
     218,   311,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   330,   332,    18,    19,    20,   165,   218,
     218,   273,   274,   275,   276,   152,   317,   202,   203,   319,
     320,   321,   166,   256,   137,   257,    52,   152,   204,   205,
     326,   160,   168,   322,   324,   327,   169,   152,   328,   331,
      74,   170,    75,    71,   174,   335,   231,   232,   337,   295,
     296,   333,   334,   152,   317,   269,   270,   171,   271,   272,
     212,    76,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    77,    78,    79,   213,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   277,   278,   215,   214,    52,    95,   223,    96,
      97,    98,    99,   100,   101,    74,    71,    75,   224,   245,
     250,   258,   252,   259,   102,   264,   288,   290,   294,   291,
     300,   329,   301,   336,   306,   314,    76,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    77,    78,
      79,   315,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    74,   308,    75,
     279,    52,   220,   280,    96,    97,    98,    99,   100,   101,
     281,   149,   282,   145,    59,   283,   227,   325,    76,   102,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    43,   287,   221,    61,
      77,    78,    79,   299,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    74,
      73,    75,     0,    52,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
      76,   102,     0,     0,     0,     0,     0,     0,     0,    74,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,    88,    89,    90,    91,   150,    93,
      94,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,    88,    89,    90,    91,   150,    93,
      94,    74,     0,    75,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,    76,   102,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     150,    93,    94,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    74,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    23,     0,    74,    76,    75,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      74,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,   150,    93,    94,     0,
     236,    76,   237,   151,   316,     0,    96,    97,    98,    99,
     100,   101,    88,    89,    90,    91,   150,    93,    94,     0,
     236,     0,   237,   151,   338,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,    88,    89,    90,    91,   150,
      93,    94,    74,   236,    75,   237,   151,     0,     0,    96,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,    74,    76,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    74,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,   150,    93,    94,    74,    76,    75,     0,   151,     0,
       0,    96,    97,    98,    99,   100,   101,    88,    89,    90,
      91,   150,    93,    94,   260,    76,    74,     0,    75,     0,
       0,    96,    97,    98,    99,   100,   101,     0,     0,    88,
      89,    90,    91,   150,    93,    94,    74,    76,    75,     0,
     308,     0,     0,    96,    97,    98,    99,   100,   101,    88,
      89,    90,    91,   150,    93,    94,   323,    76,    74,     0,
      75,     0,     0,    96,    97,    98,    99,   100,   101,     0,
       0,    88,    89,    90,    91,   150,    93,   155,    74,    76,
      75,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,    88,    89,    90,    91,   150,    93,   158,     0,    76,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     0,     0,    88,    89,    90,    91,   150,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,    88,    89,    90,    91,   150,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    96,   228,    98,
      99,   100,   101,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    52,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      71,    71,    74,    75,    76,    77,   146,   148,    82,    77,
       0,    23,   107,    24,    26,    94,     7,    72,    63,    32,
     296,    63,    72,    63,    87,   168,    71,    70,    24,    71,
      70,    94,    43,    88,    47,   107,    86,    27,    28,    52,
      30,    31,    54,    56,    63,    35,    14,    43,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    69,   334,     4,
      73,     6,    58,    67,    63,    69,    65,    57,    13,    32,
       5,    65,   143,    67,   146,    74,   155,    12,   146,   158,
     151,    10,    11,    87,    47,    43,    44,    45,    63,   163,
      65,   232,   155,    56,    85,   158,   236,   176,    94,   178,
     174,   164,   165,   166,   199,   200,   201,    72,   251,    66,
      73,    66,   183,   126,    68,    72,    74,    72,    72,    87,
      65,   184,    67,    88,    69,   137,   197,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    66,   142,   218,   144,    63,
      72,    65,    81,    82,   217,   155,   227,    87,   158,   155,
      74,    27,   158,   258,   236,    65,    88,    74,   236,   240,
     240,   245,    79,    80,    88,    66,    86,    43,    44,    45,
     176,    72,   178,    66,    66,    66,   258,    71,    72,    72,
      72,    72,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    66,    66,    43,    44,    45,    65,    72,
      72,   206,   207,   208,   209,   296,   296,    75,    76,   303,
     304,   305,    65,   176,   224,   178,    70,   308,     8,     9,
     311,   313,    65,   306,   307,   313,    63,   318,   318,   323,
       4,    88,     6,    87,    86,   329,    71,    72,   332,    71,
      72,    71,    72,   334,   334,   202,   203,    88,   204,   205,
      73,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    83,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   210,   211,     3,    84,    70,    71,    66,    73,
      74,    75,    76,    77,    78,     4,    87,     6,    72,    86,
      52,    66,    88,    63,    88,    63,    63,    68,    63,    68,
      66,    50,    66,    88,    65,    68,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    68,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     4,    70,     6,
     212,    70,    71,   213,    73,    74,    75,    76,    77,    78,
     214,    69,   215,    62,    34,   216,   142,   308,    25,    88,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    24,   224,   126,    35,
      47,    48,    49,   241,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     4,
      47,     6,    -1,    70,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    59,    60,    61,    62,    63,    64,
      65,     4,    -1,     6,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    88,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     4,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,     4,    25,     6,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
       4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    25,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    -1,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,     4,    67,     6,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    25,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,     4,    25,     6,    -1,    70,    -1,
      -1,    73,    74,    75,    76,    77,    78,    59,    60,    61,
      62,    63,    64,    65,    66,    25,     4,    -1,     6,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,     4,    25,     6,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    59,
      60,    61,    62,    63,    64,    65,    66,    25,     4,    -1,
       6,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,     4,    25,
       6,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    59,    60,    61,    62,    63,    64,    65,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    63,    65,    74,   112,   113,   116,   117,   119,
     122,   123,   124,   125,   128,   149,   150,   151,    63,    70,
     124,   122,   128,   129,    88,   114,   115,   124,   113,   113,
     113,   113,    70,   112,   113,   142,   152,    65,    67,   125,
       0,   150,    70,    63,   120,   121,    66,   122,   128,    72,
      88,    87,   142,   152,     4,     6,    25,    47,    48,    49,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    71,    73,    74,    75,    76,
      77,    78,    88,    90,    91,    92,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   110,   112,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   124,   112,   142,    63,    66,   113,   130,   131,
     132,   133,    27,   126,   129,   120,    87,    71,    72,   115,
      63,    70,   108,   135,   142,    65,    94,    94,    65,    94,
      94,   107,   111,    86,    65,    65,    65,   140,    65,    63,
      88,    88,    88,   110,    86,   110,   117,   118,   122,   134,
       4,     6,    13,    65,    67,    69,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    87,   109,    96,    74,
      79,    80,    75,    76,     8,     9,    10,    11,    81,    82,
       5,    12,    73,    83,    84,     3,     7,    85,    72,    88,
      71,   144,   124,    66,    72,    66,    72,   126,    74,   108,
     127,    71,    72,   111,    71,   121,    67,    69,   135,   136,
     137,   138,   139,   134,   134,    86,   140,   110,   110,   110,
      52,   145,    88,    88,   140,    66,   118,   118,    66,    63,
      66,    93,   108,   110,    63,   108,    96,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,   100,   100,   101,
     102,   103,   104,   105,   110,   108,    15,   132,    63,   108,
      68,    68,    71,   111,    63,    71,    72,   135,    87,   139,
      66,    66,   140,    66,    66,    66,    65,   145,    70,    96,
      66,    72,    68,    86,    68,    68,    71,   135,   137,   140,
     140,   140,   110,    66,   110,   136,   108,   107,   135,    50,
      66,   140,    66,    71,    72,   140,    88,   140,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   123,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   135,
     135,   135,   136,   136,   136,   136,   137,   138,   138,   139,
     139,   140,   140,   140,   140,   140,   140,   141,   141,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     146,   147,   147,   147,   147,   148,   148,   148,   148,   148,
     149,   149,   150,   150,   151,   151,   151,   151,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     3,     5,     6,     5,     4,     4,     3,
       0,     1,     0,     1,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       3,     4,     1,     2,     3,     4,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     3,     2,     1,     2
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
        case 9:
#line 46 "asgn4_17CS10005.y" /* yacc.c:1646  */
    { printf("PRIMARY_EXPRESSION\n");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 48 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("POSTFIX_EXPRESSION\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 50 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ARGUMENT EXPRESSION LIST\n");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 52 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("UNARY EXPRESSION\n");}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 54 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("UNARY OPERATOR\n");}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 56 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("CAST EXPRESSION\n");}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 60 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("MULTIPLICATIVE EXPRESSION\n");}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 62 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ADDITIVE EXPRESSION\n");}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 64 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("SHIFT EXPRESSION\n");}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 66 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("RELATIONAL EXPRESSION\n");}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 68 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("EQUALITY EXPRESSION\n");}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 70 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("AND_expression\n");}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 72 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("EXCLUSIVE OR EXPRESSION \n");}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 74 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("INCLUSIVE OR EXPRESSION\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 76 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("LOGICAL '&' EXPRESSION\n");}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 78 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("LOGICAL OR EXPRESSION \n");}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 80 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("CONDITIONAL EXPRESSION\n");}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 82 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ASSIGNMENT EXPRESSION\n");}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 84 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ASSIGNMENT OPERATOR\n");}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 86 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("EXPRESSION\n");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 88 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("CONSTANT EXPRESSION\n");}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 90 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DECLARATION\n");}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 92 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DECLARATION SPECIFIERS\n");}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 94 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("INIT DECLARATOR LIST\n");}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 96 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("INIT DECLARATOR\n");}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 98 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("STORAGE CLASS SPECIFIER\n");}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 100 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TYPE SPECIFIER\n");}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 102 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("SPECIFIER_QUALIFIER_LIST\n");}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 105 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ENUM_SPECIFIER\n");}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 107 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ENUMERATOR_LIST\n");}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 109 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ENUMERATOR\n");}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 111 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TYPE QUAIFIER \n");}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 113 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("FUNCTION SPECIFIER\n");}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 115 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DECLARATOR\n");}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 117 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DIRECT_DECLARATOR\n");}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 119 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TYPE QUALIFIER LIST OPT\n");}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 121 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ASSIGNMENT EXPRESSION OPT\n");}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 123 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("POINTER\n");}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 125 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TYPE QUALIFIER LIST\n");}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 127 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("PARAMETER TYPE LIST\n");}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 129 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("PARAMETER LIST\n");}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 131 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("PARAMETER DECLARATION\n");}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 133 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("IDENTIFIER LIST\n");}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 135 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TYPE NAME\n");}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 137 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("INITIALIZER\n");}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 139 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("INITIALIZER LIST\n");}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 141 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DESIGNATION\n");}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 143 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DESIGNATOR LIST\n");}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 145 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DESIGNATOR\n");}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 147 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("STATEMENT\n");}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 149 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("LABELED STATMENT\n");}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 151 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("COMPOUND STATEMENT\n");}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 153 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("BLOCK ITEM LIST\n");}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 155 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("BLOCK ITEM\n");}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 157 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("EXPRESSION STATEMENT\n");}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 159 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("SELECTION STATEMENT\n");}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 161 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("ITERATION STATEMENT\n");}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 163 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("JUMP STATEMENT\n");}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 165 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("TRANSLATION UNIT\n");}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 167 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("EXTERNAL DECLARATION\n");}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 169 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("FUNCTION DEFINITION\n");}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 171 "asgn4_17CS10005.y" /* yacc.c:1646  */
    {printf("DECLARATION LIST\n");}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2137 "y.tab.c" /* yacc.c:1646  */
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
#line 173 "asgn4_17CS10005.y" /* yacc.c:1906  */


void yyerror(char *s) {
	printf ("ERROR IS : %s",s);
}
