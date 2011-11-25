#include <stdio.h>
#include "grammatic_struct.h"
#include "grammatic_func.h"
#include <malloc.h>
extern int yylex(void);
// создание нового дерева
struct Program *create_program(struct Statements_list *lst)
{
	struct Program* program = (struct Program *)malloc(sizeof(struct Program));
	program->stmts = NULL;
	program->stmts = lst;
	return program;
}
struct Statement *create_if_stmt(struct Expression *expr, struct Statements_list *stmt_first,
									struct Statements_list *stmt_second)
{
	struct Statement* if_stmt = (struct Statement* )malloc(sizeof(struct Statement));
	struct Statement* else_stmt;
	if_stmt = clean_struct_statement(if_stmt);
	if_stmt->type = If;
	if_stmt->expr = expr;
	if_stmt->block = stmt_first;
	if(stmt_second!=NULL)
	{
		else_stmt = (struct Statement* )malloc(sizeof(struct Statement));
		else_stmt = clean_struct_statement(else_stmt);
		else_stmt ->type = Else;
		else_stmt->block = stmt_second;
		if_stmt->next = else_stmt;
	}
	else
		if_stmt->next = NULL;
	return if_stmt;
}
struct Statement* clean_struct_statement(struct Statement* stmt)
{
	stmt->block = NULL;
	stmt->def_body = NULL;
	stmt->expr = NULL;
	stmt->expr_base = NULL;
	stmt->expr_list = NULL;
	stmt->id = NULL;
	stmt->id_list = NULL;
	stmt->name_class = NULL;
	stmt->name_parent_class = NULL;
	stmt->next = NULL;
	return stmt;
}