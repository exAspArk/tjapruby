#ifndef VIEWXML_H
#define VIEWXML_H

#include <QtGui/QMainWindow>
#include "ui_viewxml.h"
#include <QFile>

//#include <QTXml>
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
//��������� ��������� ������
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
//��������� ���� ������
struct FieldClass
{
	FieldClass()
	{
		isStatic = false;
		num = -1;
	}
	int num;					//����� ���� ������ � ������� ����� ������ (���������� � 0)
	RuleOfAccess level;			//������� ������� � ���� ������
	bool isStatic;				//true - ����������� ����, false - �� �����������
	ConstClass name;			//����� ��������� CONSTANT_Utf8 � ������ ����
	ConstClass descriptor;	//����� ��������� CONSTANT_Utf8 � ������������ ����
};
struct ConstInClass
{
	ConstInClass()
	{
		isStatic = true;
		num = -1;
	}
	int num;					//����� ���� ������ � ������� ����� ������ (���������� � 0)
	RuleOfAccess level;			//������� ������� � ���� ������
	bool isStatic;				//true - ����������� ����, false - �� �����������
	ConstClass name;			//����� ��������� CONSTANT_Utf8 � ������ ����
	ConstClass descriptor;	//����� ��������� CONSTANT_Utf8 � ������������ ����
};
//��������� �������� ���������
struct LocalVar
{
	int num;
	QString name;
	int posFirst; //������� ������� �������������
	int posLast;  //������� ���������� �������������
};
//��������� ����� ������
struct MethodClass
{
	MethodClass()
	{
		num = -1;
		isStatic = false;
	}
	int num;						//����� ������ � ������� ������� ������ (���������� � 0)
	RuleOfAccess level;				//������� ������� � ������ ������
	bool isStatic;					//true - ����������� �����, false - �� �����������
	ConstClass  name;				//����� ��������� CONSTANT_Utf8 � ������ ������
	ConstClass  descriptor;		//����� ��������� CONSTANT_Utf8 � ������������ ������
	QList<LocalVar> tableLocalVar;	//������� ��������� ����������
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
//��������� �������� ������
struct ClassItem
{
	QList<ConstClass> tableConstClass;		//������� �������� ������
	QList<FieldClass> tablePoleClass;		//������� ����� ������
	QList<MethodClass> tableMethodClass;	//������� ������� ������
	QList<ConstInClass> tableConstInClass;	//������� ��������, ����������� ������ ������
	RuleOfAccess access;				//������� ������� ������ (��� ���� ��� ��� ������ ����, ���� �������� � ������)
	ConstClass nameClass;					//����� ��������� ������ ���� CONSTANT_Class 
	ConstClass nameClassParent;			//����� ��������� ������������� ������ ���� CONSTANT_Class

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

// ����� � ������� ��������

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
