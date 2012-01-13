#ifndef SEMANTICTREE_H
#define SEMANTICTREE_H

extern "C" {
#include "grammatic_struct.h"
#include "grammatic_func.h"

	extern void start(int argc,char* argv[]);
	extern struct Program *prg;

	//extern int tree_print();
}
#include <QString>
#include <QFile>
//#include "qtxml.h"
#include <QList>
#include <QMap>
#include <QDataStream>

#define GLOBAL_CLASS "LBaseVarClass"
#define GLOBAL_CLASS_MAIN_NAME "main"
#define GLOBAL_CLASS_MAIN_DESCRIPTOR "([Ljava/lang/String;)V"

enum TypeConstClass
{
	CONSTANT_Utf8 = 1,			// �������� ���������� ����� � ��������� utf8
	CONSTANT_Integer = 3,		// �������� 4-� ������� ���������
	CONSTANT_Float = 4,			// �������� 4-� ������� ���������
	CONSTANT_String = 8,		// �������� ����� ��������� CONSTANT_Utf8
	CONSTANT_NameAndType = 12,	// �������� ��� ������ �������� CONSTANT_Utf8 � ��� � ����������
	CONSTANT_Class = 7,			// �������� ����� ��������� CONSTANT_Utf8
	CONSTANT_Fieldref = 9,		// �������� ��� ������ ��������: CONSTANT_Class � CONSTANT_NameAndType
	CONSTANT_Methodref = 10,	// �������� ��� ������ ��������: CONSTANT_Class � CONSTANT_NameAndType
	CONSTANT_Bool = 14			// �������� ��������� ���������
};

/*enum AccessRule
{
	publicRule, privateRule, protectedRule
};*/

//��������� - ��������� �������
struct ConstClass
{
	ConstClass()
	{
		num = -1;
		const_Int = 0;
		const_Float = 0.0;
		const_Bool = false;
		const1 = 0;
		const2 = 0;
	}
	int num;				// ����� ��������� ������ � ������� �������� ������ (���������� � 1)
	TypeConstClass type;	// ��� ���������
	QString utf8;			// utf8 ������
	int const_Int;			// ������������� ���������
	float const_Float;		// ��������� float
	bool const_Bool;		// ��������� bool
	ConstClass * const1;	// ������ ����� ��������� ������
	ConstClass * const2;	// ������ ����� ��������� ������ - ����� ��� �����, ��������� 
};

//��������� - ���� ������
struct FieldClass
{
	FieldClass()
	{
		isStatic = false;
		num = -1;
		name = 0;
		descriptor = 0;
	}
	int num;					//����� ���� ������ � ������� ����� ������ (���������� � 0)
	Access_rule level;			//������� ������� � ���� ������
	bool isStatic;				//true - ����������� ����, false - �� �����������
	ConstClass * name;			//����� ��������� CONSTANT_Utf8 � ������ ����
	ConstClass * descriptor;	//����� ��������� CONSTANT_Utf8 � ������������ ����
};
struct ConstInClass
{
	ConstInClass()
	{
		isStatic = true;
		num = -1;
		name = 0;
		descriptor = 0;
	}
	int num;					//����� ���� ������ � ������� ����� ������ (���������� � 0)
	Access_rule level;			//������� ������� � ���� ������
	bool isStatic;				//true - ����������� ����, false - �� �����������
	ConstClass * name;			//����� ��������� CONSTANT_Utf8 � ������ ����
	ConstClass * descriptor;	//����� ��������� CONSTANT_Utf8 � ������������ ����
};
//��������� - �������� ���������
struct LocalVar
{
  LocalVar()
  {
    num=0;
    name="";
  }
	int num;
	QString name;
	int posFirst; //������� ������� �������������
	int posLast;  //������� ���������� �������������
};
//��������� - ��������� ������
struct ConstantVar
{
	ConstantVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Public;
		isStatic = true;
	}
	QString name;	    //��� ����������
	int posFirst;	    //������ ������� ������������� ����������
	int posLast;	    //������ ���������� ������������� ����������
	Access_rule level;	//������� �������, �� ��������� public
	bool isStatic; 
};
//��������� - ����������� ���������� ������ (@@var)
struct ObjectVar	
{
	ObjectVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Private;
	}
	QString name;	    //��� ����������
	int posFirst;	    //������ ��� ��������������
	int posLast;	    //��������� ��� ��������������
	Access_rule level;	//������� �������, �� ��������� private
};

//��������� - ���������� ������ (@var)
struct ClassVar
{
	ClassVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Protected;
	}
	QString name;	    //��� ����������
	int posFirst;	    //������ ��� ��������������
	int posLast;	    //��������� ��� ��������������
	Access_rule level;	//������� �������, �� ��������� private
};
struct GlobalVar
{
	GlobalVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Public;
	}
	QString name;	    //��� ����������
	int posFirst;	    //������ ��� ��������������
	int posLast;	    //��������� ��� ��������������
	Access_rule level;	//������� �������, �� ��������� private
};
//��������� ����� ������
struct MethodClass
{
	MethodClass()
	{
		num = -1;
		isStatic = false;
		name = 0;
		descriptor = 0;
		level = Public;
		methodCode=QByteArray();
        countArgs = 0;
	}
	int num;						// ����� ������ � ������� ������� ������ (���������� � 0)
	Access_rule level;				// ������� ������� � ������ ������
	bool isStatic;					// true - ����������� �����, false - �� �����������
	ConstClass * name;				// ����� ��������� CONSTANT_Utf8 � ������ ������
	ConstClass * descriptor;		// ����� ��������� CONSTANT_Utf8 � ������������ ������
	QList<LocalVar*> tableLocalVar;	// ������� ��������� ����������
	QList<ConstantVar*> tableConstatnVar;	// ������� ��������
	QList<LocalVar*> tableParam; //������� ���������� ������
	QByteArray methodCode;				// Java Byte Code ������.
    int countArgs;                  // ���������� ������������ ����������
};
//��������� �������� ������
struct ClassItem
{
	ClassItem()
	{
		nameClass = 0;
		nameClassParent = 0;
		access = Public;
		inTree = NULL;
	}
	QList<ConstClass*> tableConstClass;		//������� �������� ������
	QList<FieldClass*> tablePoleClass;		//������� ����� ������
	QList<MethodClass*> tableMethodClass;	//������� ������� ������
	QList<ConstInClass*> tableConstInClass;	//������� ��������, ����������� ������ ������
	Access_rule access;					    //������� ������� ������	
	ConstClass * nameClass;					//����� ��������� ������ ���� CONSTANT_Class 
	ConstClass * nameClassParent;			//����� ��������� ������������� ������ ���� CONSTANT_Class
	
	QList<ObjectVar*> tableObjectVar;       // @ - ����
	QList<ClassVar*> tableClassVar;         // ���������� ������
	QList<GlobalVar*> tableGLobalVar;       // ���������� ����������
	Statement *inTree;						// ������ �� ���� ������ � �������
};
QDataStream & operator << (QDataStream &stream, const ClassItem * item);
QDataStream & operator << (QDataStream &stream, const MethodClass *method);
QDataStream & operator << (QDataStream &stream, const LocalVar *var);
QDataStream & operator << (QDataStream &stream, const ConstInClass *item);
QDataStream & operator << (QDataStream &stream, const FieldClass *pole);
QDataStream & operator << (QDataStream &stream, const ConstClass *item);

QDataStream & operator << (QDataStream &stream, const ConstantVar *item);
QDataStream & operator << (QDataStream &stream, const ObjectVar *item);
QDataStream & operator << (QDataStream &stream, const ClassVar *item);
QDataStream & operator << (QDataStream &stream, const GlobalVar *item);



struct Program * semantic(Program *root);

struct Program * createTables(Program *root);

void semantic_lst(struct Statements_list*stmts);
Statement * semantic_stmt(struct Statement *stmt);
Expression * semantic_expr(struct Expression *expr);
void semantic_expr_list(struct Expressions_list *expr_l);
void semantic_id_list(struct Expressions_list *id_l);
struct Expression * create_new_node(struct Expression *old_node);
//extern struct Program *prg;

void addCode();
void initialGlobalClass();

void addClassToTable(QString newClass,QString classParent = QString(""));

// ���������� ����� ��������� � ������ 
// ���� ����� ��������� ���, �� ��������� ��� � ������� � ���������� ��� �����
int findLocalVar(QList<LocalVar*> &table, QString name, int num_counter);

// ���������� ����� ��������� � ������ 
// ���� ����� ��������� ���, �� ��������� ��� � ������� � ���������� ��� �����
int findConstantVar(QList<ConstantVar*> &table, QString name, int num_counter);	

int findObjectVar(QList<ObjectVar*> &table, QString name, int num_counter);	
int findClassVar(QList<ClassVar*> &table, QString name, int num_counter);	
int findGlobalVar(QList<GlobalVar*> &table, QString name, int num_counter);	
QList<LocalVar*> fromIdListToLocalVarList(Expressions_list* idList);


ConstClass * find_Utf8_InTableConstClass(QList<ConstClass*> &table, QString constUtf8);
ConstClass * find_Class_InTableConstClass(QList<ConstClass*> &table, ConstClass *utf8);
ConstClass * find_NameAndType_InTableConstClass(QList<ConstClass*> &table, ConstClass *name, ConstClass *type);
ConstClass * find_Integer_InTableConstClass(QList<ConstClass*> &table, int integer);
ConstClass * find_Float_InTableConstClass(QList<ConstClass*> &table, float Float);
ConstClass * find_Bool_InTableConstClass(QList<ConstClass*> &table, bool Bool);
ConstClass * find_String_InTableConstClass(QList<ConstClass*> &table, ConstClass *string);
ConstClass * find_Fieldref_InTableConstClass(QList<ConstClass*> &table, ConstClass * Class, ConstClass * nameAndType);
ConstClass * find_Methodref_InTableConstClass(QList<ConstClass*> &table, ConstClass * Class, ConstClass * nameAndType);
FieldClass * find_Field_InTableFieldClass(QList<FieldClass*> &table, ConstClass* name_field, ConstClass * type_field, Access_rule level);
// ------------------------------------------------------------------------------------
// ��� ��������� �������, �������, ���������� �� ������
// ------------------------------------------------------------------------------------
void CreateTables(Program *root);
QString SemanticStatmentListTable(Statements_list *stmts);
QString SemanticStatementTable(Statement *stmt);
void SemanticExpressionListTable(Expressions_list *expr_l);
//void SemanticIdintifierListTable(Idintifier_List *id_l);
void SemanticExpressionTable(Expression *expr);

QString SemanticIdintifierListTable(Expressions_list *id_l);

// ��������� ���� ��� ���������� (new Exception("Error"); )
QByteArray GenericErrorCode();
#endif//SEMANTICTREE_H