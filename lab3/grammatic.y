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
%left '*' '/'
%left USUB UPLUS NOT
%left '[' ']' '.'
%left nonassoc ')'
%start program
%%
program: stmt_list {$$ = prg = CreateProgram($1);}
	;
	
stmt_list: stmt_list_ne		{$$=$1;}
	|						{$$=NULL;}				
	;

stmt_list_ne: stmt			{$$ = create_stmt_list($1);}
	| stmt_list_ne stmt		{$$ = add_to_stmt_list($1,$2);}
	;

stmt: expr NL				{$$ = create_stmt($1);}	
	| NL					{$$=NULL;}		
	| if_stmt NL			{$$=$1;}			
	| for_stmt NL			{$$=$1;}	
	| while_stmt NL			{$$=$1;}	
	| until_stmt NL			{$$=$1;}	
	| RETURN expr NL		{$$ = create_return_stmt($2);}
	| BREAK NL				{$$ = create_break_stmt();}
	| class_stmt NL			{$$=$1;}
	| def_stmt NL			{$$=$1;}							
;
method_member: expr NL		{$$ = create_stmt($1);}	
	| NL					{$$=NULL;}		
	| if_stmt NL			{$$=$1;}			
	| for_stmt NL			{$$=$1;}	
	| while_stmt NL			{$$=$1;}	
	| until_stmt NL			{$$=$1;}	
	| RETURN expr NL		{$$ = create_return_stmt($2);}
	| BREAK NL				{$$ = create_break_stmt();}
	;
	
method_members_ne: method_member		{$$ = create_stmt_list($1);}
	| method_members_ne method_member	{$$ = add_to_stmt_list($1,$2);}
	;
	
method_members: method_members_ne		{$$=$1;}
	|									{$$=NULL;}
	;
	
if_stmt: IF expr THEN method_members_ne END 						{$$=create_if_stmt($2, $4, NULL);}
		| IF expr THEN method_members_ne ELSE method_members_ne END	{$$=create_if_stmt($2, $4, $6);}
		| IF expr NL method_members_ne END 							{$$=create_if_stmt($2, $4, NULL);}
		| IF expr NL method_members_ne ELSE method_members_ne END 	{$$=create_if_stmt($2, $4, $6);}
		;
		
for_stmt: FOR expr IN expr DO method_members_ne END  {$$=create_for_stmt($2,$4, $6);}		
		| FOR expr IN expr NL method_members_ne END  {$$=create_for_stmt($2,$4, $6);}
		;
		
while_stmt: WHILE expr DO method_members_ne END 	{$$=create_while_stmt($2,$4);}
		| WHILE expr NL method_members_ne END		{$$=create_while_stmt($2,$4);}
		;
	
until_stmt: UNTIL expr DO method_members_ne END 	{$$=create_until_stmt($2,$4);}
		| UNTIL expr NL method_members_ne END 		{$$=create_until_stmt($2,$4);}
		;

expr_list: expr_list ',' expr	{$$=add_to_expr_list($1,$3);}
		| expr					{$$=create_expr_list($1);}
		;

def_stmt: DEF ID NL method_members END	{$$create_def_stmt($2,NULL,$4);}			 
		| DEF ID '('id_listE')' NL method_members END {$$ = create_def_stmt($2,$4,$7);}	
		;
		
id_listE: id_list	{$$=$1;}									
		|			{$$=NULL;}										
		;
id_list: id_list ',' ID		{$$ = add_to_id_list($1,$3);}							
		| ID				{$$ = create_id_list($1);}									
		;
		
%%