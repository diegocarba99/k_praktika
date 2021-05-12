/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 39 "parser.y"

  #include "Kodea.h"
  #include "Lag.h"
  #include "SinboloTaula.h"
  #include "SinboloTaulenPila.h"

#line 55 "parser.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TID = 258,
    TFLOAT = 259,
    TINTEGER = 260,
    RPROGRAM = 261,
    RIF = 262,
    RWHILE = 263,
    RFOREVER = 264,
    RDO = 265,
    RPROC = 266,
    RUNTIL = 267,
    RELSE = 268,
    RSKIP = 269,
    REXIT = 270,
    RPRINTLN = 271,
    RREAD = 272,
    RINT = 273,
    RFLOAT = 274,
    RELSIF = 275,
    RAND = 276,
    ROR = 277,
    RNOT = 278,
    TMUL = 279,
    TASSIG = 280,
    TADD = 281,
    TSUB = 282,
    TDIV = 283,
    TCEQ = 284,
    TCGT = 285,
    TCLT = 286,
    TCGE = 287,
    TCLE = 288,
    TCNE = 289,
    TSEMIC = 290,
    TCOMMA = 291,
    TLPAREN = 292,
    TRPAREN = 293,
    TLBRACE = 294,
    TRBRACE = 295,
    TOUTPARAM = 296,
    TINOUTPARAM = 297,
    PRECED3 = 298,
    PRECED2 = 299,
    PRECED1 = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

    int ref;
    std::string *izena;
    std::string *mota;
    id_list *izenak;
    ref_list *next;
    azpiprog_st *azpi;
    expr_st *expr;
    ref_list_st *sent;
    var_st *var;

#line 124 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
