
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
     SUPER = 262,
     WHILE = 263,
     FOR = 264,
     THEN = 265,
     DO = 266,
     IF = 267,
     ELSE = 268,
     IN = 269,
     BREAK = 270,
     END = 271,
     RETURN = 272,
     UNTIL = 273,
     PRINT = 274,
     PUTS = 275,
     CONST = 276,
     ID = 277,
     NL = 278,
     PUBLIC = 279,
     PRIVATE = 280,
     PROTECTED = 281,
     INT = 282,
     FLOAT = 283,
     STRING = 284,
     BOOL = 285,
     ORWORD = 286,
     ANDWORD = 287,
     NOTWORD = 288,
     DIVASSIGN = 289,
     MULASSIGN = 290,
     SUBASSIGN = 291,
     ADDASSIGN = 292,
     THREEPOINT = 293,
     TWOPOINT = 294,
     AND = 295,
     OR = 296,
     MOREEQ = 297,
     LESSEQ = 298,
     LESSMORE = 299,
     NEQ = 300,
     EQ = 301,
     UMINUS = 302,
     NOT = 303,
     UPLUS = 304,
     DOUBLECOLON = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "grammatic.y"

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
#line 119 "grammatic.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


