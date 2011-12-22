%{

#include <stdio.h>
#include <malloc.h>
#include "grammatic_struct.h"
#include "grammatic_func.h"
#define YYERROR_VERBOSE 
extern int yylex(void);

struct Program *prg;

%}
%union {
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
}

%type <prg>program
%type <stm>stmt
%type <stm>class_member
%type <stm_l>class_member_list
%type <stm>method_member
%type <stm>method_member_s
%type <stm_l>method_members
%type <stm_l>method_members_ne
%type <stm_l>method_members_ne_do
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
%token PRINT
%token P

%token<var> CONST	
%token<var> ID		
%token NL

%token PUBLIC
%token PRIVATE
%token PROTECTED

%token <int_const>INT
%token <float_const>FLOAT
%token <string_const>STRING
%token <bool_const>BOOL

%left ANDWORD ORWORD
%left NOTWORD
%right '=' ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN
%left TWOPOINT THREEPOINT
%left OR AND
%left '-' '+'
%left '*' '/'
%left '>' '<' LESSEQ MOREEQ
%left EQ NEQ LESSMORE
%left UPLUS NOT UMINUS
%left '[' ']' '.'
%left DOUBLECOLON

%nonassoc ')'

%start program

%%
program: stmt_list {$$ = prg = create_program($1)}
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
method_member_s: expr		{$$ = create_stmt($1)}		
	| if_stmt 			{$$=$1}			
	| for_stmt		{$$=$1}	
	| while_stmt		{$$=$1}	
	| until_stmt		{$$=$1}	
	;
method_members_ne: method_member		{$$ = create_stmt_list($1)}
	| method_members_ne method_member	{$$ = add_to_stmt_list($1,$2)}
	;
method_members_ne_do: method_member_s			{$$ = create_stmt_list($1)}
	|method_members_ne_do ',' method_member_s	{$$ = add_to_stmt_list($1,$3)}
	
method_members: method_members_ne		{$$=$1}
	|									{$$=NULL}
	;
	
class_member: NL				{$$=NULL}
		| ID NL					{$$ = create_access_rule(Public,$1,NULL)}
		| def_stmt NL			{$$ = create_access_rule(Public,NULL,$1)}
		| PUBLIC ':' ID NL		{$$ = create_access_rule(Public,$3,NULL)}		
		| PRIVATE ':' ID NL		{$$ = create_access_rule(Private,$3,NULL)}		
		| PROTECTED ':' ID NL	{$$ = create_access_rule(Protected,$3,NULL)}	
		| PUBLIC def_stmt NL	{$$ = create_access_rule(Public,NULL,$2)}		
		| PRIVATE def_stmt NL	{$$ = create_access_rule(Private,NULL,$2)}	
		| PROTECTED def_stmt NL {$$ = create_access_rule(Protected,NULL,$2)}
		;

class_member_list: class_member 			{$$=create_stmt_list($1)}
		| class_member_list class_member	{$$=add_to_stmt_list($1,$2)}	
		 ;
		
if_stmt: IF expr THEN method_members_ne END 									{$$=create_if_stmt($2, $4, NULL)}
		| IF expr THEN method_members_ne ELSE method_members_ne END				{$$=create_if_stmt($2, $4, $6)}
		| IF expr NL method_members_ne END 										{$$=create_if_stmt($2, $4, NULL)}
		| IF expr THEN method_members_ne_do NL END 									{$$=create_if_stmt($2, $4, NULL)}
		| IF expr THEN method_members_ne_do ELSE method_members_ne END				{$$=create_if_stmt($2, $4, $6)}
		
for_stmt: FOR expr IN expr DO method_members_ne END {$$=create_for_stmt($2,$4, $6)}		
		| FOR expr IN expr NL method_members_ne END {$$=create_for_stmt($2,$4, $6)}
		| FOR expr IN expr DO method_members_ne_do END {$$=create_for_stmt($2,$4, $6)}		
		;
		
while_stmt: WHILE expr DO method_members_ne END 	{$$=create_while_stmt($2,$4)}
		| WHILE expr NL method_members_ne END		{$$=create_while_stmt($2,$4)}
		|WHILE expr DO method_members_ne_do END 	{$$=create_while_stmt($2,$4)}
		;
	
until_stmt: UNTIL expr DO method_members_ne END 	{$$=create_until_stmt($2,$4)}
		| UNTIL expr NL method_members_ne END 		{$$=create_until_stmt($2,$4)}
		| UNTIL expr DO method_members_ne_do END 	{$$=create_until_stmt($2,$4)}
		;

expr_list: expr_list ',' expr						{$$=add_to_expr_list($1,$3);}
		| expr										{$$=create_expr_list($1);}
		;

def_stmt: DEF ID NL method_members END						{$$ = create_def_stmt($2,NULL,$4);}			 
		| DEF ID '('id_listE')' NL method_members END 		{$$ = create_def_stmt($2,$4,$7);}	
		;
		
class_stmt: CLASS CONST NL class_member_list END 			{$$ = create_class_stmt($2, NULL, $4)}			
		| CLASS CONST '<' CONST NL class_member_list END 	{$$ = create_class_stmt($2, $4, $6)}
		;
		
id_listE: id_list	{$$=$1}									
		|			{$$=NULL}										
		;
id_list: id_list ',' ID		{$$ = add_to_id_list($1,$3)}							
		| ID				{$$ = create_id_list($1)}									
		;
		
expr: CONST													{$$ = create_expr_const($1)}
	| ID													{$$ = create_expr_id($1)}
	| STRING												{$$ = create_expr_string($1)}
	| INT													{$$ = create_expr_int($1)}
	| FLOAT													{$$ = create_expr_float($1)}
	| BOOL													{$$ = create_expr_bool($1)}
	| NIL													{$$ = create_expr(Nil)}
	| SELF													{$$ = create_expr(Self)}
	| expr '+' expr											{$$ = create_two_expr(Plus,$1,$3)}
	| expr '-' expr											{$$ = create_two_expr(Minus,$1,$3)}
	| expr '*' expr											{$$ = create_two_expr(Multiply,$1,$3)}
	| expr '/' expr											{$$ = create_two_expr(Division,$1,$3)}
	| expr '<' expr											{$$ = create_two_expr(Less,$1,$3)}
	| expr '>' expr											{$$ = create_two_expr(More,$1,$3)}
	| expr '=' expr											{$$ = create_two_expr(Assign,$1,$3)}
	| expr LESSEQ expr										{$$ = create_two_expr(LessEq,$1,$3);}
	| expr MOREEQ expr										{$$ = create_two_expr(MoreEq,$1,$3);}
	| expr EQ expr											{$$ = create_two_expr(Equivalent,$1,$3);}
	| expr NEQ expr											{$$ = create_two_expr(NotEquivalent,$1,$3);}
	| expr LESSMORE expr									{$$ = create_two_expr(LessMore,$1,$3);}
	| expr ANDWORD expr 									{$$ = create_two_expr(AndWord,$1,$3)}
	| expr ORWORD expr										{$$ = create_two_expr(OrWord,$1,$3)}
	| NOTWORD expr %prec NOTWORD							{$$ = create_one_expr(NotWord, $2);}
	| expr OR expr											{$$ = create_two_expr(Or,$1,$3);}
	| expr AND expr											{$$ = create_two_expr(And,$1,$3);}
	| NOT expr %prec NOT   									{$$ = create_one_expr(Not, $2);}	
	| expr DOUBLECOLON expr									{$$ = create_two_expr(Doublecolon,$1,$3);}
	| expr ADDASSIGN expr									{$$ = create_two_expr(AddAssign,$1,$3);}		
	| expr SUBASSIGN expr									{$$ = create_two_expr(SubAssign,$1,$3);}
	| expr MULASSIGN expr									{$$ = create_two_expr(MulAssign,$1,$3);}
	| expr DIVASSIGN expr									{$$ = create_two_expr(DivAssign,$1,$3);}	
	| expr TWOPOINT expr			 						{$$ = create_two_expr(TwoPoint,$1,$3);}
	| expr THREEPOINT expr									{$$ = create_two_expr(ThreePoint,$1,$3);}	
	| '-' expr %prec UMINUS									{$$ = create_one_expr(Uminus, $2)}
	| '+' expr %prec UPLUS									{$$ = create_one_expr(Uplus, $2)}
	| expr '.' ID											{$$ = create_call_method($1, $3, NULL);}
	| expr '.' ID '(' ')'									{$$ = create_call_method($1, $3, NULL);}
	| expr '.' ID '(' expr_list ')'							{$$ = create_call_method($1, $3, $5);}	
	| PRINT '(' expr_list ')'								{$$ = create_print_stmt($3)}
	| P '(' expr_list ')'									{$$ = create_p_stmt($3)}
	| ID '(' ')'											{$$ = create_call_method(NULL, $1, NULL);}
	| ID '(' expr_list ')'									{$$ = create_call_method(NULL, $1, $3);}
	| SUPER													{$$ = create_super_expr(NULL);}
	| SUPER '(' ')'											{$$ = create_super_expr(NULL);}
	| SUPER '(' expr_list ')'								{$$ = create_super_expr($3);}
	| init_array_expr										{$$=$1;}
	| expr '[' expr ']'										{$$ = create_call_array_expr($1,$3);}
	;
	
	init_array_expr: '[' expr_list ']'                      {$$ = create_array($2);}
	;
%%

