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
#line 30 "ass6_17CS10005_17CS10007.y" /* yacc.c:1909  */

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

#line 199 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
