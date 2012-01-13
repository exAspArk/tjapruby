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
	CONSTANT_Utf8 = 1,			// содержит актуальный текст в кодировке utf8
	CONSTANT_Integer = 3,		// содержит 4-х байтную константу
	CONSTANT_Float = 4,			// содержит 4-х байтную константу
	CONSTANT_String = 8,		// содержит номер константы CONSTANT_Utf8
	CONSTANT_NameAndType = 12,	// содержит два номера констант CONSTANT_Utf8 — имя и дескриптор
	CONSTANT_Class = 7,			// содержит номер константы CONSTANT_Utf8
	CONSTANT_Fieldref = 9,		// содержит два номера констант: CONSTANT_Class и CONSTANT_NameAndType
	CONSTANT_Methodref = 10,	// содержит два номера констант: CONSTANT_Class и CONSTANT_NameAndType
	CONSTANT_Bool = 14			// содержит булевскую константу
};

/*enum AccessRule
{
	publicRule, privateRule, protectedRule
};*/

//Структура - константа классов
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
	int num;				// номер константы класса в таблице констант класса (начинается с 1)
	TypeConstClass type;	// тип константы
	QString utf8;			// utf8 строка
	int const_Int;			// целочисленная константа
	float const_Float;		// константа float
	bool const_Bool;		// константа bool
	ConstClass * const1;	// первый номер константы класса
	ConstClass * const2;	// второй номер константы класса - нужна для полей, требующих 
};

//Структура - поле класса
struct FieldClass
{
	FieldClass()
	{
		isStatic = false;
		num = -1;
		name = 0;
		descriptor = 0;
	}
	int num;					//номер поля класса в таблице полей класса (начинается с 0)
	Access_rule level;			//уровень доступа к полю класса
	bool isStatic;				//true - статическое поле, false - не статическое
	ConstClass * name;			//номер константы CONSTANT_Utf8 с именем поля
	ConstClass * descriptor;	//номер константы CONSTANT_Utf8 с дескриптором поля
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
	int num;					//номер поля класса в таблице полей класса (начинается с 0)
	Access_rule level;			//уровень доступа к полю класса
	bool isStatic;				//true - статическое поле, false - не статическое
	ConstClass * name;			//номер константы CONSTANT_Utf8 с именем поля
	ConstClass * descriptor;	//номер константы CONSTANT_Utf8 с дескриптором поля
};
//Структура - локалная перменная
struct LocalVar
{
  LocalVar()
  {
    num=0;
    name="";
  }
	int num;
	QString name;
	int posFirst; //позиция первого использования
	int posLast;  //позиция последнего использования
};
//Структура - константа класса
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
	QString name;	    //имя переменной
	int posFirst;	    //индекс первого использования переменной
	int posLast;	    //индекс последнего использования переменной
	Access_rule level;	//уровень доступа, по умолчанию public
	bool isStatic; 
};
//Структура - статическая переменная класса (@@var)
struct ObjectVar	
{
	ObjectVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Private;
	}
	QString name;	    //имя переменной
	int posFirst;	    //первый раз использовалась
	int posLast;	    //последний раз использовалась
	Access_rule level;	//уровень доступа, по умолчанию private
};

//Структура - переменная класса (@var)
struct ClassVar
{
	ClassVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Protected;
	}
	QString name;	    //имя переменной
	int posFirst;	    //первый раз использовалась
	int posLast;	    //последний раз использовалась
	Access_rule level;	//уровень доступа, по умолчанию private
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
	QString name;	    //имя переменной
	int posFirst;	    //первый раз использовалась
	int posLast;	    //последний раз использовалась
	Access_rule level;	//уровень доступа, по умолчанию private
};
//структура метод класса
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
	int num;						// номер метода в таблице методов класса (начинается с 0)
	Access_rule level;				// уровень доступа к методу класса
	bool isStatic;					// true - статический метод, false - не статический
	ConstClass * name;				// номер константы CONSTANT_Utf8 с именем метода
	ConstClass * descriptor;		// номер константы CONSTANT_Utf8 с дескриптором метода
	QList<LocalVar*> tableLocalVar;	// таблица локальных переменных
	QList<ConstantVar*> tableConstatnVar;	// таблица констант
	QList<LocalVar*> tableParam; //таблица параметров метода
	QByteArray methodCode;				// Java Byte Code метода.
    int countArgs;                  // количество передаваемых параметров
};
//структура описания класса
struct ClassItem
{
	ClassItem()
	{
		nameClass = 0;
		nameClassParent = 0;
		access = Public;
		inTree = NULL;
	}
	QList<ConstClass*> tableConstClass;		//таблица констант класса
	QList<FieldClass*> tablePoleClass;		//таблица полей класса
	QList<MethodClass*> tableMethodClass;	//таблица методов класса
	QList<ConstInClass*> tableConstInClass;	//таблица констант, объявленных внутри класса
	Access_rule access;					    //уровень доступа класса	
	ConstClass * nameClass;					//номер константы класса типа CONSTANT_Class 
	ConstClass * nameClassParent;			//номер константы родительского класса типа CONSTANT_Class
	
	QList<ObjectVar*> tableObjectVar;       // @ - поле
	QList<ClassVar*> tableClassVar;         // переменные класса
	QList<GlobalVar*> tableGLobalVar;       // глобальные переменные
	Statement *inTree;						// ссылка на узел дерева в таблице
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

// возвращает номер локальной в классе 
// если такой константы нет, то добавляет его в таблицу и возвращает его номер
int findLocalVar(QList<LocalVar*> &table, QString name, int num_counter);

// возвращает номер константы в классе 
// если такой константы нет, то добавляет его в таблицу и возвращает его номер
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
// для выделения классов, методов, переменных из дерева
// ------------------------------------------------------------------------------------
void CreateTables(Program *root);
QString SemanticStatmentListTable(Statements_list *stmts);
QString SemanticStatementTable(Statement *stmt);
void SemanticExpressionListTable(Expressions_list *expr_l);
//void SemanticIdintifierListTable(Idintifier_List *id_l);
void SemanticExpressionTable(Expression *expr);

QString SemanticIdintifierListTable(Expressions_list *id_l);

// Генерация кода для исключения (new Exception("Error"); )
QByteArray GenericErrorCode();
#endif//SEMANTICTREE_H