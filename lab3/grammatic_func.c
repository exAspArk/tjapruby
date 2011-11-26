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
	struct Statement* else_stmt = NULL;
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
	if_stmt->next = else_stmt;
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
struct Statements_list *create_stmt_list(struct Statement *stm)
{
	struct Statements_list* stm_list = (struct Statements_list* )malloc(sizeof(struct Statements_list));
	stm_list->stmt = NULL;
	stm_list->next = NULL;

	if(stm!=NULL)
	{
		stm_list->next = stm;
		stm_list->stmt = stm;
		return stm_list;
	}
	return NULL;
}
struct Statements_list *add_stmt_list(struct Statements_list *stm_list,struct Statement *stm)
{
	struct Statement *if_once,*else_once;
	if(stm_list!=NULL)
	{
		if(stm!=NULL)
		{
			if(stm->type = If)
			{
				else_once = stm->next;
				if_once = stm;
				stm_list->next->next = if_once;
				stm_list->next = if_once;
				if(else_once!=NULL)
				{
					stm_list->next->next = else_once;
					stm_list->next = else_once;
				}
			}
			else
			{
				stm_list->next->next = stm;
				stm_list->next = stm;
			}
			return stm_list;
		}
		else
			return stm_list;
	}
	else
		return create_stmt_list(stm);
	return NULL;
}
struct Statement* create_stmt(struct Expression* expr)
{
	struct Statement* stm = (struct Statement* )malloc(sizeof(struct Statement));
	stm = clean_struct_statement(stm);

	stm->type = Expr;
	stm->expr = expr;
	return stm;
}
struct Statement* create_for_stmt(struct Expression* id,struct Expression* expr,struct Statements_list* stm_list)
{
	struct Statement* stm_for = NULL;
	if(id->type = Id)
	{
		stm_for = (struct Statement*)malloc(sizeof(struct Statement));
		stm_for = clean_struct_statement(stm_for);
		stm_for->type = For;
		stm_for->id = id;
		stm_for->block = stm_list;
	}
	return stm_for;
}

struct Expression* clean_struct_expression(struct Expression* expr)
{
	if(expr!=NULL)
	{
		expr->expr_List = NULL;
		expr->left = NULL;
		expr->next = NULL;
		expr->right = NULL;
		expr->var = NULL;
		expr->name = NULL;
		expr->string_const = NULL;
	}
	return expr;
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
