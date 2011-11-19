%{
#include <stdio.h>
extern int yylex(void);

struct Programm *prg;
%}
%union{
	long int_const;
	float float_const;
	char* string_const;
	int bool_const;
	
	struct Expression *exp;
	struct Statement *stm;
	struct Program *prg;
	struct StatementsList *stm_l;
	struct ExpressionsList *exp_l;
	struct ExpressionsList * id_l;
}

%type <prg>program
%type <stm>stmt
%type <stm>class_member
%type <stm_l>class_member_list
%type <stm>method_member
%type <stm_l>method_members
%type <stm_l>method_members_NE
%type <exp>expr
%type <exp_l>expr_list
%type <stm_l>stmt_list
%type <stm_l>stmt_listNE
%type <stm>def_stmt
%type <stm>if_stmt
%type <stm>for_stmt
%type <stm>while_stmt
%type <stm>until_stmt
%type <stm>class_stmt
%type <id_l>id_list
%type <id_l>id_listE
%type <exp>init_array_expr

%token CLASS
%token NIL
%token SELF
%token DEF
%token BOOL
%token SUPER
%token WHILE
%token FOR
%token THEN
%token DO
%token IF
%token ELSE
%token IN
%token BREAK
%token END		
%token RETURN
%token UNTIL

%token<Var> CONST	
%token<Var> ID		
%token NL

%token PUBLIC
%token PRIVATE
%token PROTECTED
%token ARRAY

%token <int_const>INT
%token <float_const>FLOAT
%token <string_const>STRING

%left ANDWORD ORWORD
%left NOTWORD
%right '=' ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN
%left TWOPOINT THREEPOINT
%left OR
%left AND
%left '-' '+'