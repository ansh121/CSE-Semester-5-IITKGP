/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 26 "ass5_17CS10007_17CS10005.y" /* yacc.c:1909  */

	int intval;
	double real;
	char *str;
	OpcodeType op;
	SymNode *symnode;  
	SymTab* symtab;
	List* list;
	IdList* idlist;
	ParamList* paramlist;

#line 252 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
