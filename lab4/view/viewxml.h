#ifndef VIEWXML_H
#define VIEWXML_H

#include <QtGui/QMainWindow>
#include "ui_viewxml.h"
#include <QFile>

//#include <QTXml>
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

enum RuleOfAccess
{
	Public,
	Protected,
	Private
};
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
	QString name;	// name of constant var
	int posFirst;	// first use var
	int posLast;	// last use var
	RuleOfAccess level;	// level of access to the var - default public
	bool isStatic;
};

// Struct of object var - @@var
struct ObjectVar	
{
	ObjectVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Private;
	}
	QString name;	// name of object var
	int posFirst;	// first use var
	int posLast;	// last use var
	RuleOfAccess level;	// level of access to the var - default private
};
//Структура константа класса
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
//Структура поле класса
struct FieldClass
{
	FieldClass()
	{
		isStatic = false;
		num = -1;
	}
	int num;					//номер поля класса в таблице полей класса (начинается с 0)
	RuleOfAccess level;			//уровень доступа к полю класса
	bool isStatic;				//true - статическое поле, false - не статическое
	ConstClass name;			//номер константы CONSTANT_Utf8 с именем поля
	ConstClass descriptor;	//номер константы CONSTANT_Utf8 с дескриптором поля
};
struct ConstInClass
{
	ConstInClass()
	{
		isStatic = true;
		num = -1;
	}
	int num;					//номер поля класса в таблице полей класса (начинается с 0)
	RuleOfAccess level;			//уровень доступа к полю класса
	bool isStatic;				//true - статическое поле, false - не статическое
	ConstClass name;			//номер константы CONSTANT_Utf8 с именем поля
	ConstClass descriptor;	//номер константы CONSTANT_Utf8 с дескриптором поля
};
//Структура локалная перменная
struct LocalVar
{
	int num;
	QString name;
	int posFirst; //позиция первого использования
	int posLast;  //позиция последнего использования
};
//структура метод класса
struct MethodClass
{
	MethodClass()
	{
		num = -1;
		isStatic = false;
	}
	int num;						//номер метода в таблице методов класса (начинается с 0)
	RuleOfAccess level;				//уровень доступа к методу класса
	bool isStatic;					//true - статический метод, false - не статический
	ConstClass  name;				//номер константы CONSTANT_Utf8 с именем метода
	ConstClass  descriptor;		//номер константы CONSTANT_Utf8 с дескриптором метода
	QList<LocalVar> tableLocalVar;	//таблица локальных переменных
	QList<ConstantVar> tableConstanVar;	// table of constant var
  QList<LocalVar> tableParam;
};
// Struct of class var - @var
struct ClassVar
{
	ClassVar()
	{
		name = "";
		posFirst = -1;
		posLast = -1;
		level = Protected;
	}
	QString name;	// name of class var
	int posFirst;	// first use var
	int posLast;	// last use var
	RuleOfAccess level;	// level of access to the var - default Protected
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
	QString name;
	int posFirst;
	int posLast;
	RuleOfAccess level;
};
//структура описания класса
struct ClassItem
{
	QList<ConstClass> tableConstClass;		//таблица констант класса
	QList<FieldClass> tablePoleClass;		//таблица полей класса
	QList<MethodClass> tableMethodClass;	//таблица методов класса
	QList<ConstInClass> tableConstInClass;	//таблица констант, объявленных внутри класса
	RuleOfAccess access;				//уровень доступа класса (фиг знаю что там должно быть, надо спросить у Сычева)
	ConstClass nameClass;					//номер константы класса типа CONSTANT_Class 
	ConstClass nameClassParent;			//номер константы родительского класса типа CONSTANT_Class

	QList<ObjectVar> tableObjectVar;
	QList<ClassVar> tableClassVar;
	QList<GlobalVar> tableGLobalVar;
};
QDataStream & operator >> (QDataStream &stream, ClassItem &item);
QDataStream & operator >> (QDataStream &stream, MethodClass &method);
QDataStream & operator >> (QDataStream &stream, LocalVar &var);
QDataStream & operator >> (QDataStream &stream, ConstInClass &item);
QDataStream & operator >> (QDataStream &stream, FieldClass &pole);
QDataStream & operator >> (QDataStream &stream, ConstClass &item);

QDataStream & operator >> (QDataStream &stream, ConstantVar &item);
QDataStream & operator >> (QDataStream &stream, ObjectVar &item);
QDataStream & operator >> (QDataStream &stream, ClassVar &item);
QDataStream & operator >> (QDataStream &stream, GlobalVar &item);

// вывод в таблицу констант

class ViewXML : public QMainWindow
{
	Q_OBJECT

public:
	ViewXML(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ViewXML();
	
private:
	Ui::ViewXMLClass ui;
	QMap<QString,ClassItem> tableClass;
	void PrintInTableClassConstant(QList<ConstClass> ConstTable);	// add in table "class constant"
	void PrintInTableField(QList<FieldClass> FieldClass);			// add in table "field"
	void PrintInTableMethod(QList<MethodClass> MethodClass);		// add in table "method"
	void PrintInTableLocalVar(QList<LocalVar> LocalVarClass);		// add in table "local var"
	//void PrintInTableLocalVar

private slots:
	void chooseClass(int);
	void chooseMethod(int);
	void on_action_triggered();
	void on_changedComboClass(int index);
};

#endif // VIEWXML_H
