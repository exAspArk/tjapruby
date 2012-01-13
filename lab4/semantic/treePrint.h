#include <stdio.h>

struct attrs
{
	char *name;
	char *value;
};

void printTag(char *tag,char *str)
{
	fprintf(stdout,"\n<%s>",tag);
	fprintf(stdout,"\'%s\'",str);
	fprintf(stdout,"</%s>",tag);
}
void printEmptyTag(char *tag)
{
	fprintf(stdout,"\n<%s>",tag);
	fprintf(stdout,"</%s>",tag);
}
void attrOpenTag(char *tag,struct attrs *curAttr,int count)
{
	int ind=0;
	printf("\n<%s",tag);
	while(ind<count)
	{
		fprintf(stdout," %s=\"%s\"",curAttr[ind].name,curAttr[ind].value);
		ind++;
	}
	fprintf(stdout,">");
}
// Только открывающий тег
void onlyOpenTag(char *openTag)
{
	fprintf(stdout,"\n<%s>", openTag);
}

// Только закрывающий тег
void onlyCloseTag(char *closeTag)
{
	fprintf(stdout,"\n</%s>",closeTag);
}
int tree_print();
void lst_print(struct Statements_list* stmts);
void stmt_print(struct Statement *stmt);
void expr_print(struct Expression *expr);
void expr_list_print(struct Expressions_list *expr_l);
void id_list_print(struct Expressions_list *id_l);
void name_and_type_print(struct Name_and_type_var * nameAndType);
char * floatToChar(float number, char* buff);

extern struct Program *prg;

int tree_print()
{
	if(prg != NULL)
	{
		onlyOpenTag("MainClass");
		lst_print(prg->stmts);
		onlyCloseTag("MainClass");
	}
	else
	{
		// иначе выводим сообщение об ошибке - ParseError
		printTag("Error", "Parse Error");
	}
	return 0;
}

// выводим stmt_list
void lst_print(struct Statements_list* stmts)
{
	struct Statement *stmt;
	onlyOpenTag("Stmt_List");

	// если лист не пкстой и есть что печатать, то начинаем все это дело печатать
	if(stmts != NULL)
	{
		stmt = stmts->stmt;

		while(stmt)
		{
			stmt_print(stmt);
			stmt=stmt->next;
		}
	}
	onlyCloseTag("Stmt_List");
}
// выводим stmt
void stmt_print(struct Statement *stmt)
{
	char buffer[255]={0};
	char buffer1[255]={0};
	struct attrs attribute[10];
	if (stmt!=NULL)
	{
		//onlyOpenTag("Stmt");
		switch(stmt->type)
		{
		case Expr:
			onlyOpenTag("Expr_Stmt");
			expr_print(stmt->expr);
			onlyCloseTag("Expr_Stmt");
			break;
		case While:
			onlyOpenTag("While");
			expr_print(stmt->expr);
			lst_print(stmt->block);
			onlyCloseTag("While");
			break;

		case If:
			onlyOpenTag("If");
			expr_print(stmt->expr);
			onlyOpenTag("Block");
			lst_print(stmt->block);
			onlyCloseTag("Block");
			if(stmt->next != NULL)
			{
				if(stmt->next->type == Else)	// если  не равно NULL, значит там чтото есть
				{
					onlyOpenTag("Else");
					onlyOpenTag("Block");
					lst_print(stmt->next->block);
					onlyCloseTag("Block");
					onlyCloseTag("Else");
				}
			}
			onlyCloseTag("If");
			break;

		case Class:
			//onlyOpenTag("Class");
			attribute[0].name="className";
			attribute[0].value=stmt->name_class->name_var;
			//name_and_type_print(stmt->name_class);
			if(stmt->name_parent_class != NULL)
			{
				attribute[1].name="parentClassName";
				attribute[1].value=stmt->name_parent_class->name_var;
				/*onlyOpenTag("ParentClass");
				name_and_type_print(stmt->name_parent_class);
				onlyCloseTag("ParentClass");*/
				attrOpenTag("Class",attribute,2);
			}
			else
				attrOpenTag("Class",attribute,1);
			lst_print(stmt->block);
			onlyCloseTag("Class");
			break;

		case For:
			onlyOpenTag("For");
			expr_print(stmt->id);
			expr_print(stmt->expr);
			lst_print(stmt->block);
			onlyCloseTag("For");
			break;

		

			// выводим приоритеты
		case stPublic:
			onlyOpenTag("Public");
			// если есть список функций, то выводим все функции
			if(stmt->def_body != NULL)
			{
				stmt_print(stmt->def_body);
			}
			else	
			{
				if (stmt->expr!=NULL)
				{
					switch(stmt->expr->var->type)
					{
					case CONSTANT:		/* константа: Var */ 
						printTag("Type", "CONSTANT");
						break;
					case LOCALVAR:		/* локальная переменная: Var */ 
						printTag("Type", "LOCALVAR");
						break;
					case GLOBALVAR:		/* глобальная переменная: Var */ 
						printTag("Type", "GLOBALVAR");
						break;
					case CLASSVAR:		/* переменная класса: Var */ 
						printTag("Type", "CLASSVAR");
						break;
					case OBJECTVAR:		/* переменная объекта: Var */ 
						printTag("Type", "OBJECTVAR");
						break;
					}

					printTag("Name", stmt->expr->var->name_var);
				}
			}
			onlyCloseTag("Public");
			break;
		case stPrivate:
			onlyOpenTag("Private");
			// если есть список функций, то выводим все функции
			if(stmt->def_body != NULL)
			{
				stmt_print(stmt->def_body);
			}
			else	
			{
				if (stmt->expr!=NULL)
				{
						switch(stmt->expr->var->type)
					{
					case CONSTANT:		/* константа: Var */ 
						printTag("Type", "CONSTANT");
						break;
					case LOCALVAR:		/* локальная переменная: Var */ 
						printTag("Type", "LOCALVAR");
						break;
					case GLOBALVAR:		/* глобальная переменная: Var */ 
						printTag("Type", "GLOBALVAR");
						break;
					case CLASSVAR:		/* переменная класса: Var */ 
						printTag("Type", "CLASSVAR");
						break;
					case OBJECTVAR:		/* переменная объекта: Var */ 
						printTag("Type", "OBJECTVAR");
						break;
					}
					printTag("Name", stmt->expr->var->name_var);
				}
			}
			onlyCloseTag("Private");
			break;
		case stProtected:
			onlyOpenTag("Protected");
			// если есть список функций, то выводим все функции
			if(stmt->def_body != NULL)
			{
				stmt_print(stmt->def_body);
			}
			else	
			{
				if (stmt->expr!=NULL)
				{
					switch(stmt->expr->var->type)
					{
					case CONSTANT:		/* константа: Var */ 
						printTag("Type", "CONSTANT");
						break;
					case LOCALVAR:		/* локальная переменная: Var */ 
						printTag("Type", "LOCALVAR");
						break;
					case GLOBALVAR:		/* глобальная переменная: Var */ 
						printTag("Type", "GLOBALVAR");
						break;
					case CLASSVAR:		/* переменная класса: Var */ 
						printTag("Type", "CLASSVAR");
						break;
					case OBJECTVAR:		/* переменная объекта: Var */ 
						printTag("Type", "OBJECTVAR");
						break;
					}
				
					printTag("Name", stmt->expr->var->name_var);
				}
			}
			onlyCloseTag("Protected");
			break;
		case Def:
			
				onlyOpenTag("DefineMethod");
				printTag("Method",stmt->expr->var->name_var);
				id_list_print(stmt->id_list);
				if(stmt->block)
					lst_print(stmt->block);
				onlyCloseTag("DefineMethod");
			

			break;

		
		case Break:
			printEmptyTag("Break");
			break;

		case Return:
			onlyOpenTag("Return");
			expr_print(stmt->expr);
			onlyCloseTag("Return");
			break;

		case Until:
			onlyOpenTag("Until");
			expr_print(stmt->expr);
			lst_print(stmt->block);
			onlyCloseTag("Until");
			break;
		}
		//onlyCloseTag("Stmt");
	}
}
// выводим  expr_list
void expr_list_print(struct Expressions_list *expr_l)
{
	struct Expression *expr;
	if (expr_l!=NULL)
	{
		onlyOpenTag("Expr_List");
		expr = expr_l->expr;
		while(expr)
		{
			expr_print(expr);
			expr= expr->next;
		}
		onlyCloseTag("Expr_List");
	}
}
// выводим  idintifer_list
void id_list_print(struct Expressions_list *id_l)
{
	struct Expression *id;		
	if (id_l!=NULL)
	{
		onlyOpenTag("Id_List");
		id = id_l->expr;
		while(id)
		{
			expr_print(id);
			id= id->next;
		}
		onlyCloseTag("Id_List");
	}
}

// выводим expr
void expr_print(struct Expression *expr)
{
	char buffer[255]={0};
	struct attrs attribute[10];
	char buff[255]={0};
	if (expr)
	{
		//onlyOpenTag("Expression");
		switch(expr->type)
		{
		case Int:
			attribute[0].name="Value";
			attribute[0].value=_itoa(expr->int_const, buffer, 10);
			attrOpenTag("Int",attribute,1);
			onlyCloseTag("Int");
			break;
		case Float:
			sprintf(buffer,"%g",expr->float_const);
			attribute[0].name="Value";
			attribute[0].value=buffer;
			attrOpenTag("Float",attribute,1);
			onlyCloseTag("Float");
			break;
		case Bool:
			attribute[0].name="Value";
			attribute[0].value=buffer;
			if(expr->bool_const == 0)
			{
				attribute[0].value="0";
				//printTag("Bool","false");
			}
			else if(expr->bool_const == 1)
			{
				attribute[0].value="1";
				//printTag("Bool","true");
			}
			attrOpenTag("Bool",attribute,1);
			onlyCloseTag("Bool");
			break;
		case Array:
			onlyOpenTag("Array");
			expr_list_print(expr->expr_List);
			onlyCloseTag("Array");
			break;
		case String:
			attribute[0].name="Value";
			attribute[0].value=expr->string_const;
			attrOpenTag("StringConst",attribute,1);
			onlyCloseTag("StringConst");
			break;
		case Id:
			switch(expr->var->type)
			{
			case CONSTANT:		/* константа: Var */ 
				printTag("Type", "CONSTANT");
				break;
			case LOCALVAR:		/* локальная переменная: Var */ 
				printTag("Type", "LOCALVAR");
				break;
			case GLOBALVAR:		/* глобальная переменная: Var */ 
				printTag("Type", "GLOBALVAR");
				break;
			case CLASSVAR:		/* переменная класса: Var */ 
				printTag("Type", "CLASSVAR");
				break;
			case OBJECTVAR:		/* переменная объекта: Var */ 
				printTag("Type", "OBJECTVAR");
				break;
			}
			printTag("Name", expr->var->name_var);
			break;
		case Const:
			switch(expr->var->type)
			{
			case CONSTANT:		
				printTag("Type", "CONSTANT");
				break;
			case LOCALVAR:		 
				printTag("Type", "LOCALVAR");
				break;
			case GLOBALVAR:		 
				printTag("Type", "GLOBALVAR");
				break;
			case CLASSVAR:		
				printTag("Type", "CLASSVAR");
				break;
			case OBJECTVAR:	
				printTag("Type", "OBJECTVAR");
				break;
			}
			printTag("Name", expr->var->name_var);
			break;
		case Plus:
			onlyOpenTag("Plus");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Plus");
			break;
		case Minus:
			onlyOpenTag("Minus");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Minus");
			break;
		case Multiply:
			onlyOpenTag("Multiply");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Multiply");
			break;
		case Division:
			onlyOpenTag("Division");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Division");
			break;
		case Uminus:
			onlyOpenTag("Uminus");
			expr_print(expr->right);
			onlyCloseTag("Uminus");
			break;
		case Uplus:
			onlyOpenTag("Uplus");
			expr_print(expr->right);
			onlyCloseTag("Uplus");
			break;
		case Assign:
			onlyOpenTag("Assign");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Assign");
			break;

		case AddAssign:
			onlyOpenTag("AddAndAssign");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("AddAndAssign");
			break;

		case SubAssign:
			onlyOpenTag("SubAndAssign");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("SubAndAssign");
			break;
		case MulAssign:
			onlyOpenTag("MultiAndAssign");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("MultiAndAssign");
			break;
		case DivAssign:
			onlyOpenTag("DivAndAssign");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("DivAndAssign");
			break;
		case CallArray:
			onlyOpenTag("CallArray");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("CallArray");
			break;
		case Self:
			printTag("Self","self");
			break;
		case Nil:
			printTag("Nil","nil");
			break;
		case Doublecolon:
			onlyOpenTag("Doublecolon");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Doublecolon");
			break;
		case More:
			onlyOpenTag("More");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("More");
			break;
		case Less:
			onlyOpenTag("Less");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("Less");
			break;
		case MoreEq:
			onlyOpenTag("MoreOrIs");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("MoreOrIs");
			break;
		case LessEq:
			onlyOpenTag("LessOrIs");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("LessOrIs");
			break;
		case LessMore:
			onlyOpenTag("LessIsMore");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("LessIsMore");
			break;

		case NotEquivalent:
			onlyOpenTag("NoEQ");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("NoEQ");
			break;

		case Equivalent:
			onlyOpenTag("EQ");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("EQ");
			break;

		case Or:
			onlyOpenTag("OrUp");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("OrUp");
			break;

		case And:
			onlyOpenTag("AndUp");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("AndUp");
			break;
		case OrWord:
			onlyOpenTag("OrDown");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("OrDown");
			break;
		case AndWord:
			onlyOpenTag("AndDown");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("AndDown");
			break;
		case Not:
			onlyOpenTag("NotUp");
			expr_print(expr->right);
			onlyCloseTag("NotUp");
			break;
		case NotWord:
			onlyOpenTag("NotDown");
			expr_print(expr->right);
			onlyCloseTag("NotDown");
			break;
		case ThreePoint:
			onlyOpenTag("ThreePoint");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("ThreePoint");
			break;
		case TwoPoint:
			onlyOpenTag("TwoPoint");
			expr_print(expr->left);
			expr_print(expr->right);
			onlyCloseTag("TwoPoint");
			break;
		case expDef:
			onlyOpenTag("CallMethod");
			expr_print(expr->left);
			printTag("Method",expr->right->var->name_var);
			expr_list_print(expr->expr_List);
			onlyCloseTag("CallMethod");
			break;
		case Print:
			onlyOpenTag("PrintMethod");
			expr_list_print(expr->expr_List);
			onlyCloseTag("PrintMethod");
			break;
		case Puts:
			onlyOpenTag("PMethod");
			expr_list_print(expr->expr_List);
			onlyCloseTag("PMethod");
			break;
		case Super:
			onlyOpenTag("Super");
			expr_list_print(expr->expr_List);
			onlyCloseTag("Super");
			break;
		}
		//onlyCloseTag("Expression");
	}
}

// Переводим число типа в float в строку
char * floatToChar(float number, char* buff)
{
	sprintf(buff,"%g",number);
	return buff;
}

void name_and_type_print(struct Name_and_type_var * nameAndType)
{
	if(nameAndType != NULL)
		printTag("ClassName",nameAndType->name_var);
}