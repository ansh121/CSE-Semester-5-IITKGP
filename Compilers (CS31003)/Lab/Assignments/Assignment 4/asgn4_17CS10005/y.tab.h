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
#line 19 "asgn4_17CS10005.y" /* yacc.c:1909  */

	int intval;

#line 186 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
