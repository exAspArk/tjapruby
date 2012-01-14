#ifndef GRAMMATIC_STRUCT_H
#define GRAMMATIC_STRUCT_H

enum Access_rule {
	Public,
	Protected,
	Private
};

enum Var_type {
	CONSTANT,		// ���������: Var  
	LOCALVAR,		// ��������� ����������: var ��� _var 
	GLOBALVAR,		// ���������� ����������: $var 
	CLASSVAR,		// ���������� ������: @@var 
	OBJECTVAR		// ���������� �������: @var 
};

struct Name_and_type_var {
	char* name_var;		// ��� ���������� 
	enum Var_type type;	// � ��� 
};

enum Expr_type {
	Int,			// ����� ����� 
	Float,			// ������������ ����� 
	Array,			// ������ 
	String,			// ������ 
	Const,			// ��������� 
	Bool,			// ���������� ���
	expDef,			// ����� ������
	CallArray,		// ����� ������� 
	Id,				// ������������� 
	Plus,			// �������� ���� 
	Minus,			// �������� ����� 
	Multiply,		// ��������� 
	Division,		// �������  
	Uminus,			// ������� ����� 
	Uplus,			// ������� ����
	Assign,			// ������������� 
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
	enum Expr_type type;			// ��� ���������
	
	// �������� ���������
	long   int_const;				// ������������� ���������
	float  float_const;				// ������� ���������
	char * string_const;			// ��������� ��������� '' � ""
	int	   bool_const;				// ���������� �������� 
									// 0 - false
									// 1 - true

    struct Expression * Expr_base;

	struct Name_and_type_var * var;		// ���/������ ����������
	struct Expressions_list * expr_List; //������ ���������
	struct Expression * left;			// ����� �������
	struct Expression * right;			// ������ �������
    enum Access_rule level;         //������� �������
    int numLocalVar;                // ���������� ��� ����������
    char* name; // ���
	struct Expression * next;		// �������� ���������
    struct ConstClass * constClass; 
};

struct Expressions_list {
	struct Expression * expr;		// ��������� ���������
	struct Expression * next;		// ��������� ���������
};

struct Statement {
	enum Stmt_type type;				// ��� ���������
	struct Expression * expr;			// ��������� ��� ���������
	struct Expression * id;				//�������������
	struct Expression * expr_base;   	// ������ ������
	struct Expressions_list * expr_list;	// ��������� ��� ���������
	struct Statements_list * block;		// ��������� �� ���� 
	struct Statement * next;			// ��������� ��������
	struct Expressions_list * id_list; 	// ������ ����������
	struct Statement * def_body;	  		// ������� (������������ ��� �������� ������ �������)
    int isStatic;                       // 0 - �������� �����

	// ����� ��� �������
	struct Name_and_type_var* name_class;			// ��� ������
	struct Name_and_type_var* name_parent_class;	// ��� ������������� ������
};

struct Statements_list {
	struct Statement * stmt;
	struct Statement * next;
};

struct Program {
	struct Statements_list * stmts;
};

#endif