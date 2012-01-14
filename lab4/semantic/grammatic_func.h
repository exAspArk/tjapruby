/* 	
	Тут объявляем функции для создания дерева
*/

// создание нового дерева
struct Program *create_program(struct Statements_list *lst);

// создание stmt для If
struct Statement *create_if_stmt(struct Expression *expr, struct Statements_list *stmt_first, struct Statements_list *stmt_second);

// создание списка операторов из одного оператора
struct Statements_list *create_stmt_list(struct Statement *stm);

// добавление оператора в список операторов
struct Statements_list *add_to_stmt_list(struct Statements_list *stm_list,struct Statement *stm);

// создание оператора из выражения
struct Statement *create_stmt(struct Expression *exp);

// создание оператора For
struct Statement *create_for_stmt(struct Expression *id,struct Expression *expr, struct Statements_list *stmt);

// создания оператора While
struct Statement *create_while_stmt(struct Expression *expr_first,struct Statements_list *stmt);

// создание оператора Break
struct Statement *create_break_stmt();

// создание оператора Until
struct Statement *create_until_stmt(struct Expression *expr_first,struct Statements_list *stmt);

// создание списка выражений из одного выражения
struct Expressions_list *create_expr_list(struct Expression *expr);

// добавление выражения в список выражений
struct Expressions_list *add_to_expr_list(struct Expressions_list *expr_list,struct Expression *expr);

// cозданиt оператора return
struct Statement *create_return_stmt(struct Expression *expr);

// бинарные операции
struct Expression * create_two_expr(enum ExprType Type,struct Expression *lhs,struct Expression *rhs);

// унарные операции
struct Expression * create_one_expr(enum ExprType Type, struct Expression *rhs);

// создание оператора класса
struct Statement *create_class_stmt(struct Name_and_type_var* name,struct Name_and_type_var* base_name,struct Statements_list *stmt);

struct Expression * create_expr(enum ExprType exprType);

struct Expression * create_expr_const(int var);
struct Expression * create_expr_id(int var);
struct Expression * create_expr_string(char * str);
struct Expression * create_expr_int(int var);
struct Expression * create_expr_float(float var);
struct Expression * create_expr_bool(int var);

// создание выражений из переменных
struct Expression * create_expr(enum ExprType exprType);

// создание оператора при определении метода
struct Statement *create_def_stmt(struct Name_and_type_var* name,struct Expressions_list* id_list, struct Statements_list * stmt_list);
//struct Statement *CreateDefStmtStatic(struct Name_and_type_var* name,struct Expressions_list* id_list, struct Statements_list * stmt_list);

// создание уровней доступа: public, private, protected
struct Statement *create_access_rule(enum AccessRule access,struct Name_and_type_var *_id,struct Statement * def_stmt);

// доступ к элементу массива
struct Expression * create_call_array_expr(struct Expression *name,struct Expression *expr);

// вызов метода
struct Expression * create_call_method(struct Expression *obj,struct Name_and_type_var *name,struct Expressions_list *expr_list);

// вызов gets
struct Expression * create_gets_stmt(struct Expressions_list *expr_list);

// вызов puts
struct Expression * create_puts_stmt(struct Expressions_list *expr_list);

// инициализация массива
struct Expression * create_array(struct Expressions_list *expr_l);

// Super
struct Expression * create_super_expr(struct Expressions_list *expr_list);

// создание списка идентификаторов
struct Expressions_list * create_id_list(struct Name_and_type_var *id);

// добавление в список идентификаторов
struct Expressions_list * add_to_id_list(struct Expressions_list *Id_list, struct Name_and_type_var *_id);

// Очищаем структуру Expression
struct Expression * clean_struct_expression(struct Expression * expr);

// Очищаем структуру Statement
struct Statement * clean_struct_statement(struct Statement * stmt);
