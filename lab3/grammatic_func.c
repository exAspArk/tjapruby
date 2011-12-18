#include <stdio.h>
#include "grammatic_struct.h"
#include "grammatic_func.h"
#include "grammatic.tab.h"
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
struct Statements_list *add_to_stmt_list(struct Statements_list *stm_list,struct Statement *stm)
{
	struct Statement *if_once,*else_once;
	if(stm_list!=NULL)
	{
		if(stm!=NULL)
		{
			if(stm->type == If)
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
		stm_for->expr  = expr;
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
// создания оператора While
struct Statement *create_while_stmt(struct Expression *expr_first,struct Statements_list *stmt)
{
	struct Statement *result = (struct Statement*) malloc (sizeof(struct Statement));	
	result = clean_struct_statement(result);
	
	result->type = While;			
	result->expr = expr_first;		
	result->block = stmt;	
	return result;
}

// создание оператора Break
struct Statement *create_break_stmt()
{
	struct Statement *result = (struct Statement*) malloc (sizeof(struct Statement));	
	result = clean_struct_statement(result);
	result->type = Break;			
	return result;
}

// создание оператора Until
struct Statement *create_until_stmt(struct Expression *expr_first,struct Statements_list *stmt)
{
	struct Statement *result = (struct Statement*) malloc (sizeof(struct Statement));	
	result = clean_struct_statement(result);
	result->type = Until;		
	result->expr = expr_first;	
	result->block = stmt;
	 
	return result;
}

// создание списка выражений из одного выражения
struct Expressions_list *create_expr_list(struct Expression *expr)
{
	struct Expressions_list *result=(struct Expressions_list *)malloc(sizeof(struct Expressions_list));

	result->expr = 0;
	result->next = 0;

	if(expr != NULL)
	{
		result->expr=expr;
		result->next=expr;
		return result;
	}
	return NULL;
}

// добавление выражения в список выражений
struct Expressions_list *add_to_expr_list(struct Expressions_list *expr_list,struct Expression *expr)
{
	struct Expressions_list *result=(struct Expressions_list *)malloc(sizeof(struct Expressions_list));
	// если expr_list не пустой
	if(expr_list != NULL)
	{
		expr_list->next->next = expr;
		expr_list->next = expr;
		return expr_list;
	}
	else
		// иначе создаем новый expr_list
		create_expr_list(expr);
}

// cозданиt оператора return
struct Statement *create_return_stmt(struct Expression *expr)
{
	struct Statement *result = (struct Statement *) malloc (sizeof(struct Statement));	
	result = clean_struct_statement(result);

	result->type = Return;			
	result->expr = expr;		
	return result;
}


// бинарные операции
struct Expression * create_two_expr(enum Expr_type Type,struct Expression *lhs,struct Expression *rhs)
{
	struct Expression *result = (struct Expression *) malloc(sizeof(struct Expression));

	result = clean_struct_expression(result);
	
	result->type = Type;
	result->left=lhs;
	result->right=rhs;
	return result;
}

// унарные операции
struct Expression * create_one_expr(enum Expr_type Type, struct Expression *rhs)
{
	struct Expression *result = (struct Expression *) malloc(sizeof(struct Expression));

	result = clean_struct_expression(result);

	result->type = Type;
	result->right= rhs;
	return result;
}

// создание оператора класса	
struct Statement *create_class_stmt(struct Name_and_type_var * name, struct Name_and_type_var* base_name, struct Statements_list* stm)
{
	struct Statement *result = (struct Statement*)malloc(sizeof(struct Statement));

	result = clean_struct_statement(result);

	// если тип const, то это имя класса, создаем класс
	if (name->type==CONSTANT)
	{
		if(base_name == NULL || base_name->type == CONSTANT)
		{
			result->type = Class;			// тип Class
			result->name_class = name;		// имя класса
			result->name_parent_class = base_name;	// имя родительского класса
			
			result->block = stm;				// записываем список функций
			return result;
		}
	}
	return NULL;
}

// создание выражений из переменных
struct Expression * create_expr(enum Expr_type exprType)
{
	struct Expression *result = (struct Expression *)malloc(sizeof(struct Expression));
	//struct Name_and_type_var *ver = (struct Name_and_type_var*)malloc(sizeof(struct Name_and_type_var));
	result = clean_struct_expression(result);

	result->type = exprType;
	switch(exprType)
	{
		case Int:
			result->int_const = yylval.int_const;
			break;
		case Float:
			result->float_const= yylval.float_const;
			break;
		case String:
			result->string_const = yylval.string_const;
			break;
		case Id:
			//ver->name_var = yylval.var->name_var;
			//ver->type = yylval.var->type;
			result->var = yylval.var;
			break;
		case Const:
			result->var = yylval.var;
			break;
		case Bool:
			result->bool_const = yylval.bool_const;
			break;
	}
	return result;
}

// создание уровней доступа: public, private, protected
struct Statement *create_access_rule(enum AccessRule access, struct Name_and_type_var *_id, struct Statement * def_stmt)
{
	// если делаем для переменной
	if(_id != NULL)
	{
		if(_id->type != LOCALVAR && _id->type != CLASSVAR)
			return NULL;
		else
		{
			struct Statement *result=(struct Statement *)malloc(sizeof(struct Statement));
			struct Expression *expr = (struct Expression *)malloc(sizeof(struct Expression));
			
			result = clean_struct_statement(result);
			switch(access)
			{
			case Public:
				result->type = stPublic;
				break;
			case Private:
				result->type = stPrivate;
				break;
			case Protected:
				result->type = stProtected;
				break;
			}
			expr = clean_struct_expression(expr);

			expr->type = Id;
			
			expr->var = _id;

			result->expr = expr;
			return result;
		}
	}
	else
	{
		// если делаем для функции
		struct Statement *result=(struct Statement *)malloc(sizeof(struct Statement));
		
		result = clean_struct_statement(result);

		switch(access)
		{
		case Public:
			result->type = stPublic;
			break;
		case Private:
			result->type = stPrivate;
			break;
		case Protected:
			result->type = stProtected;
			break;
		}
		result->def_body = def_stmt;

		return result;
	}
	
}

// доступ к элементу массива
struct Expression * create_call_array_expr(struct Expression *name,struct Expression *expr)
{
	struct Expression *result = (struct Expression *)malloc(sizeof(struct Expression));

	result = clean_struct_expression(result);

	result->type=CallArray;
	result->left = name;
	result->right = expr;
	return result;
}


// вызов метода
struct Expression * create_call_method(struct Expression *obj,struct Name_and_type_var *name,struct Expressions_list *expr_list )
{
	if(name->type != LOCALVAR)
	{
		return NULL;
	}
	else
	{
		struct Expression *result = (struct Expression *)malloc(sizeof(struct Expression));
		struct Expression *expr = (struct Expression *)malloc(sizeof(struct Expression));

		result = clean_struct_expression(result);

		result->type=expDef;
		result->left=obj;

		expr = clean_struct_expression(expr);

		expr->type = Id;
		expr->var = name;
		result->right=expr;

		result->expr_List = expr_list;
		return result;
	}
}

// инициализация массива
struct Expression * create_array(struct Expressions_list *expr_list)
{
	struct Expression *result = (struct Expression *)malloc(sizeof(struct Expression));

	result = clean_struct_expression(result);

	result->expr_List=expr_list;
	result->type=Array;
	return result;
}

// Super
struct Expression * create_super_expr(struct Expressions_list *expr_list)
{
	struct Expression *result = (struct Expression *)malloc(sizeof(struct Expression));

	result = clean_struct_expression(result);

	result->type = Super;
	result->expr_List = expr_list;
	return result;
}

// создание списка идентификаторов
struct Expressions_list * create_id_list(struct Name_and_type_var *id)
{
	struct Expressions_list *result=(struct Expressions_list *)malloc(sizeof(struct Expressions_list));
	struct Expression *expr_id = (struct Expression *)malloc(sizeof(struct Expression));
	result->expr = 0;
	result->next = 0;

	expr_id = clean_struct_expression(expr_id);

	expr_id->type = Id;
	expr_id->var = id;

	if(id != NULL)
	{
		result->expr=expr_id;
		result->next=expr_id;
		return result;
	}
	else
	{
		return NULL;
	}
}

// добавление в список идентификаторов
struct Expressions_list * add_to_id_list(struct Expressions_list *id_list, struct Name_and_type_var *id)
{
	struct Expression *expr_id = (struct Expression *)malloc(sizeof(struct Expression));
	// если в списке уже чтото есть
	if(id_list != NULL)
	{
		// и есть что добавлять
		if(id != NULL)
		{
			
			expr_id = clean_struct_expression(expr_id);

			expr_id->type = Id;
			expr_id->var = id;
		
			id_list->next->next = expr_id;
			id_list->next = expr_id;
			return id_list;
		}
	}
	else
		create_id_list(id);
	return NULL;
}

// создание нестатичных функций
struct Statement *create_def_stmt(struct Name_and_type_var* name,struct Expressions_list* id_list, struct Statements_list * stmt_list)
{
	struct Statement *result=(struct Statement *)malloc(sizeof(struct Statement));
	struct Expression *expr=(struct Expression *)malloc(sizeof(struct Expression));

	result = clean_struct_statement(result);

	expr = clean_struct_expression(expr);


	if (name->type==LOCALVAR)
	{
		expr->type = Id;
		expr->var = name;

		result->type=Def;
		result->expr=expr;
		if(id_list != NULL)
		{
			result->id_list=id_list;
		}
		else
		{
			result->id_list=NULL;
		}
		result->block=stmt_list;

		return result;
	}
	else
	{
		return NULL;
	}
}
