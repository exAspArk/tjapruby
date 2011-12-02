
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     NIL = 259,
     SELF = 260,
     DEF = 261,
     BOOL = 262,
     SUPER = 263,
     WHILE = 264,
     FOR = 265,
     THEN = 266,
     DO = 267,
     IF = 268,
     ELSE = 269,
     IN = 270,
     BREAK = 271,
     END = 272,
     RETURN = 273,
     UNTIL = 274,
     CONST = 275,
     ID = 276,
     NL = 277,
     PUBLIC = 278,
     PRIVATE = 279,
     PROTECTED = 280,
     INT = 281,
     FLOAT = 282,
     STRING = 283,
     ORWORD = 284,
     ANDWORD = 285,
     NOTWORD = 286,
     DIVASSIGN = 287,
     MULASSIGN = 288,
     SUBASSIGN = 289,
     ADDASSIGN = 290,
     THREEPOINT = 291,
     TWOPOINT = 292,
     AND = 293,
     OR = 294,
     MOREEQ = 295,
     LESSEQ = 296,
     LESSMORE = 297,
     NEQ = 298,
     EQ = 299,
     UMINUS = 300,
     NOT = 301,
     UPLUS = 302,
     DOUBLECOLON = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "d:\\Programming\\Project\\tjapRuby\\lab3\\grammatic.y"

	long int_const;
	float float_const;
	char* string_const;
	int bool_const;
	
	struct Expression *exp;
	struct Statement *stm;
	struct Program *prg;
	struct Name_and_type_var *var;
	struct Statements_list *stm_l;
	struct Expressions_list *exp_l;
	struct Expressions_list * id_l;



/* Line 1676 of yacc.c  */
#line 117 "grammatic.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


