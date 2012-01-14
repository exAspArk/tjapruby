#ifndef GRAMMATIC_STRUCT_H
#define GRAMMATIC_STRUCT_H

enum Access_rule {
	Public,
	Protected,
	Private
};

enum Var_type {
	CONSTANT,		// константа: Var  
	LOCALVAR,		// локальная переменная: var или _var 
	GLOBALVAR,		// глобальная переменная: $var 
	CLASSVAR,		// переменная класса: @@var 
	OBJECTVAR		// переменная объекта: @var 
};

struct Name_and_type_var {
	char* name_var;		// имя переменной 
	enum Var_type type;	// её тип 
};

enum Expr_type {
	Int,			// целое число 
	Float,			// вещественное число 
	Array,			// массив 
	String,			// строка 
	Const,			// константа 
	Bool,			// догический тип
	expDef,			// вызов метода
	CallArray,		// вызов массива 
	Id,				// идентификатор 
	Plus,			// бинарный плюс 
	Minus,			// бинарный минус 
	Multiply,		// умножение 
	Division,		// деление  
	Uminus,			// унарный минус 
	Uplus,			// унарный плюс
	Assign,			// присвавивание 
	AddAssign,		// +=
	SubAssign,		// -= 
	MulAssign,	// *= 
	DivAssign,		// /= 
	More,			// > 
	Less,			// < 
	MoreEq,			// >= 
	LessEq,			// <= 
	LessMore,		// <=> 
	NotEquivalent,	// != 
	Equivalent,		// == 
	Or,				// ||  
	And,			// && 
	OrWord,			// or 
	AndWord,		// and 
	Not,			// ! 
	NotWord,		// not 
	TwoPoint,		// .. 
	ThreePoint,		// ... 
	Self,			// self 
	Nil,			// nil 
	Doublecolon,	// :: 
	Super,
	Gets,
	Puts,
    PointAssign,    // .=
    ArrayAssign     // []=
};

enum Stmt_type {
	While,
	If, 
	Class,
	For, 
	Then, 
	Do, 
	Def,  
	Else, 
	Break, 
	Return,
	Until, 
	Expr,
	stPublic,
	stPrivate,
	stProtected,
    WhileFor,
    WhileUntil
};

struct Expression {
	enum Expr_type type;			// тип выражения
	
	// значение выражения
	long   int_const;				// целочисленная константа
	float  float_const;				// дробная константа
	char * string_const;			// строковая константа '' и ""
	int	   bool_const;				// логическое значение 
									// 0 - false
									// 1 - true

    struct Expression * Expr_base;

	struct Name_and_type_var * var;		// тип/доступ переменной
	struct Expressions_list * expr_List; //список выражений
	struct Expression * left;			// левый операнд
	struct Expression * right;			// правый операнд
    enum Access_rule level;         //уровень доступа
    int numLocalVar;                // количество лок переменных
    char* name; // имя
	struct Expression * next;		// следущее выражение
    struct ConstClass * constClass; 
};

struct Expressions_list {
	struct Expression * expr;		// начальное выражение
	struct Expression * next;		// следующее выражение
};

struct Statement {
	enum Stmt_type type;				// тип выражения
	struct Expression * expr;			// выражение для оператора
	struct Expression * id;				//идентификатор
	struct Expression * expr_base;   	// предок класса
	struct Expressions_list * expr_list;	// выражения для оператора
	struct Statements_list * block;		// указатель на блок 
	struct Statement * next;			// следующий оператор
	struct Expressions_list * id_list; 	// список параметров
	struct Statement * def_body;	  		// функция (используется при создании правил доступа)
    int isStatic;                       // 0 - нестатич метод

	// часть для классов
	struct Name_and_type_var* name_class;			// имя класса
	struct Name_and_type_var* name_parent_class;	// имя родительского класса
};

struct Statements_list {
	struct Statement * stmt;
	struct Statement * next;
};

struct Program {
	struct Statements_list * stmts;
};

#endif