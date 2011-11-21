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
%type <stm_l>method_members_ne
%type <exp>expr
%type <exp_l>expr_list
%type <stm_l>stmt_list
%type <stm_l>stmt_list_ne
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
%left USUB UPLUS NOT UMINUS
%left '[' ']' '.'
%left nonassoc ')'
%start program
%%
program: stmt_list {$$ = prg = CreateProgram($1)}
	;
	
stmt_list: stmt_list_ne		{$$=$1}
	|						{$$=NULL}				
	;

stmt_list_ne: stmt			{$$ = create_stmt_list($1)}
	| stmt_list_ne stmt		{$$ = add_to_stmt_list($1,$2)}
	;

stmt: expr NL				{$$ = create_stmt($1)}	
	| NL					{$$=NULL}		
	| if_stmt NL			{$$=$1}			
	| for_stmt NL			{$$=$1}	
	| while_stmt NL			{$$=$1}	
	| until_stmt NL			{$$=$1}	
	| RETURN expr NL		{$$ = create_return_stmt($2)}
	| BREAK NL				{$$ = create_break_stmt()}
	| class_stmt NL			{$$=$1}
	| def_stmt NL			{$$=$1}							
;
method_member: expr NL		{$$ = create_stmt($1)}	
	| NL					{$$=NULL}		
	| if_stmt NL			{$$=$1}			
	| for_stmt NL			{$$=$1}	
	| while_stmt NL			{$$=$1}	
	| until_stmt NL			{$$=$1}	
	| RETURN expr NL		{$$ = create_return_stmt($2)}
	| BREAK NL				{$$ = create_break_stmt()}
	;
	
method_members_ne: method_member		{$$ = create_stmt_list($1)}
	| method_members_ne method_member	{$$ = add_to_stmt_list($1,$2)}
	;
	
method_members: method_members_ne		{$$=$1}
	|									{$$=NULL}
	;
	
class_member: NL			{$$=NULL}
		| ID NL				{$$ = CreateAccessRule(Public,$1,NULL)}
		| def_stmt NL			{$$ = CreateAccessRule(Public,NULL,$1)}
		| PUBLIC ':' ID NL		{$$ = CreateAccessRule(Public,$3,NULL)}		
		| PRIVATE ':' ID NL		{$$ = CreateAccessRule(Private,$3,NULL)}		
		| PROTECTED ':' ID NL	{$$ = CreateAccessRule(Protected,$3,NULL)}	
		| PUBLIC def_stmt NL	{$$ = CreateAccessRule(Public,NULL,$2)}		
		| PRIVATE def_stmt NL	{$$ = CreateAccessRule(Private,NULL,$2)}	
		| PROTECTED def_stmt NL {$$ = CreateAccessRule(Protected,NULL,$2)}
		;

class_member_list: class_member 			{$$=CreateStmtList($1)}
		| class_member_list class_member	{$$=AddToStmtList($1,$2)}	
		 ;
		
if_stmt: IF expr THEN method_members_ne END 						{$$=create_if_stmt($2, $4, NULL)}
		| IF expr THEN method_members_ne ELSE method_members_ne END	{$$=create_if_stmt($2, $4, $6)}
		| IF expr NL method_members_ne END 							{$$=create_if_stmt($2, $4, NULL)}
		| IF expr NL method_members_ne ELSE method_members_ne END 	{$$=create_if_stmt($2, $4, $6)}
		;
		
for_stmt: FOR expr IN expr DO method_members_ne END  {$$=create_for_stmt($2,$4, $6)}		
		| FOR expr IN expr NL method_members_ne END  {$$=create_for_stmt($2,$4, $6)}
		;
		
while_stmt: WHILE expr DO method_members_ne END 	{$$=create_while_stmt($2,$4)}
		| WHILE expr NL method_members_ne END		{$$=create_while_stmt($2,$4)}
		;
	
until_stmt: UNTIL expr DO method_members_ne END 	{$$=create_until_stmt($2,$4)}
		| UNTIL expr NL method_members_ne END 		{$$=create_until_stmt($2,$4)}
		;

expr_list: expr_list ',' expr	{$$=add_to_expr_list($1,$3)}
		| expr					{$$=create_expr_list($1)}
		;

def_stmt: DEF ID NL method_members END	{$$create_def_stmt($2,NULL,$4)}			 
		| DEF ID '('id_listE')' NL method_members END {$$ = create_def_stmt($2,$4,$7)}	
		;
		
class_stmt: CLASS CONST NL class_member_list END 			{$$ = CreateClassStmt($2, NULL, $4)}			
		/*| CLASS CONST '<' CONST NL class_member_list END 	{$$ = CreateClassStmt($2, $4, $6)}*/
		;
		
id_listE: id_list	{$$=$1}									
		|			{$$=NULL}										
		;
id_list: id_list ',' ID		{$$ = add_to_id_list($1,$3)}							
		| ID				{$$ = create_id_list($1)}									
		;
		
expr: CONST													{$$ = create_expr(Const)}
	| ID													{$$ = create_expr(Id)}
	| STRING												{$$ = create_expr(String)}
	| INT													{$$ = create_expr(Int)}
	| FLOAT													{$$ = create_expr(Float)}
	| BOOL													{$$ = create_expr(Bool)}
	| NIL													{$$ = create_expr(Nil)}
	| SELF													{$$ = create_expr(Self)}
	| expr '+' expr											{$$ = create_two_expr(Plus,$1,$3)}
	| expr '-' expr											{$$ = create_two_expr(Minus,$1,$3)}
	| expr '*' expr											{$$ = create_two_expr(Multiply,$1,$3)}
	| expr '/' expr											{$$ = create_two_expr(Division,$1,$3)}
	| expr '<' expr											{$$ = create_two_expr(Less,$1,$3)}
	| expr '>' expr											{$$ = create_two_expr(More,$1,$3)}
	| expr '=' expr											{$$ = create_two_expr(Assign,$1,$3)}
	| '-' expr %prec UMINUS									{$$ = create_one_expr(Uminus, $2)}
	| '+' expr %prec UPLUS									{$$ = create_one_expr(Uplus, $2)}
	| expr '.' ID											{$$ = CreateCallMethod($1, $3, NULL);}
	| expr '.' ID '(' ')'									{$$ = CreateCallMethod($1, $3, NULL);}
	| expr '.' ID '(' expr_list ')'							{$$ = CreateCallMethod($1, $3, $5);}			
	| ID '(' ')'											{$$ = CreateCallMethod(NULL, $1, NULL);}
	| ID '(' expr_list ')'									{$$ = CreateCallMethod(NULL, $1, $3);}
	| SUPER													{$$ = CreateSuperExpr(NULL);}
	| SUPER '(' ')'											{$$ = CreateSuperExpr(NULL);}
	| SUPER '(' expr_list ')'								{$$ = CreateSuperExpr($3);}
	| init_array_expr										{$$=$1;}
	;
	
init_array_expr: '[' expr_list ']'                          {$$ = CreateArray($2);}
	| ARRAY '[' expr_list ']'								{$$ = CreateArray($3);}							
	;	
%%