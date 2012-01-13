#include "semanticTree.h"

#include <stdio.h>
QString currentClass, rightClass = "";
MethodClass * currentMetod;
MethodClass * globalMain;
QMap<QString,ClassItem*> tableClass;
int globalCounter;
int globalCounterConst;
int globalCounterObject;
int globalCounterClass;
int globalCounterGlobal;

//  переопределение назначения
// запись в таблицу классов
QDataStream & operator << (QDataStream &stream, const ClassItem * item)
{
	stream << (item ? (int)1 : (int)0);
	if(!item)
		return stream;
	stream << item->access;
	stream << item->nameClass;
	stream << item->nameClassParent;
	stream << item->tableConstClass;
	stream << item->tableConstInClass;
	stream << item->tableMethodClass;
	stream << item->tablePoleClass;

	stream << item->tableObjectVar;
	stream << item->tableGLobalVar;
	stream << item->tableClassVar;
	return stream;
}
// запись в таблицу методов
QDataStream & operator << (QDataStream &stream, const MethodClass *method)
{
	stream << (method ? (int)1 : (int)0);
	if(!method)
		return stream;
	stream << method->descriptor;
	stream << method->isStatic;
	stream << method->level;
	stream << method->name;
	stream << method->num;
	stream << method->tableLocalVar;
	stream << method->tableConstatnVar;
    stream << method->tableParam;
	return stream;
}
// запись в таблицу локальных переменных
QDataStream & operator << (QDataStream &stream, const LocalVar *var)
{
	stream << (var ? (int)1 : (int)0);
	if(!var)
		return stream;
	stream << var->num;
	stream << var->name;
	stream << var->posFirst;
	stream << var->posLast;
	return stream;
}

QDataStream & operator << (QDataStream &stream, const ConstInClass *item)
{
	stream << (item ? (int)1 : (int)0);
	if(!item)
		return stream;
	stream << item->descriptor;
	stream << item->isStatic;
	stream << item->level;
	stream << item->name;
	stream << item->num;
	return stream;
}
// запись в таблицу полей
QDataStream & operator << (QDataStream &stream, const FieldClass *field)
{
	stream << (field ? (int)1 : (int)0);
	if(!field)
		return stream;
	stream << field->descriptor;
	stream << field->isStatic;
	stream << field->level;
	stream << field->name;
	stream << field->num;
	return stream;
}
QDataStream & operator << (QDataStream &stream, const ConstClass *item)
{
	stream << (item ? (int)1 : (int)0);
	if(!item)
		return stream;
	stream << item->const1;
	stream << item->const2;
	stream << item->const_Float;
	stream << item->const_Int;
	stream << item->const_Bool;
	stream << item->num;
	stream << item->type;
	stream << item->utf8;
	return stream;
}



//----
QDataStream & operator << (QDataStream &stream, const ConstantVar *item)
{
	stream << (item ? (int)1 : (int) 0);
	if(!item)
		return stream;
	stream << item->isStatic;
	stream << item->level;
	stream << item->name;
	stream << item->posFirst;
	stream << item->posLast;
	return stream;
}

QDataStream & operator << (QDataStream &stream, const ObjectVar *item)
{
	stream << (item ? (int)1 : (int) 0);
	if(!item)
		return stream;
	stream << item->level;
	stream << item->name;
	stream << item->posFirst;
	stream << item->posLast;
	return stream;
}
QDataStream & operator << (QDataStream &stream, const ClassVar *item)
{
	stream << (item ? (int)1 : (int) 0);
	if(!item)
		return stream;
	stream << item->level;
	stream << item->name;
	stream << item->posFirst;
	stream << item->posLast;
	return stream;
}

QDataStream & operator << (QDataStream &stream, const GlobalVar *item)
{
	stream << (item ? (int)1 : (int) 0);
	if(!item)
		return stream;
	stream << item->level;
	stream << item->name;
	stream << item->posFirst;
	stream << item->posLast;
	return stream;
}
void initialGlobalClass()
{
	currentClass = GLOBAL_CLASS;
	
	addClassToTable(currentClass, "java/lang/Object");

	ClassItem * class_g = tableClass[currentClass];
	if(prg->stmts != NULL)
		class_g->inTree = prg->stmts->stmt;
	else
		class_g->inTree = NULL;

	
	//find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"Code");	// добавляем ключевое слово Code

	//добовления в таблицу констант главного метода
	MethodClass *method = new MethodClass();
	method->level = Public;
	method->name = find_Utf8_InTableConstClass(class_g->tableConstClass,GLOBAL_CLASS_MAIN_NAME);
	method->descriptor = find_Utf8_InTableConstClass(class_g->tableConstClass,GLOBAL_CLASS_MAIN_DESCRIPTOR);
	method->num = class_g->tableMethodClass.size();
	method->isStatic = true;
	// создаем массив строк для аргументов главной функции main
	LocalVar * varl = new LocalVar();
	varl->name = "<local>";
	varl->num = 1;
	varl->posFirst = 0;
	varl->posLast = 0;
	//varl->num = findLocalVar(method->tableLocalVar, "<!!!>", 0);
	class_g->tableMethodClass << method;
	globalMain = method;
	currentMetod = method;

	find_NameAndType_InTableConstClass(class_g->tableConstClass,method->name,method->descriptor);

	// для вывода " new Exception("Error") "
	/*ConstClass * ErrorUtf8 = find_Utf8_InTableConstClass(class_g->tableConstClass, "Error");	// Добавляем слово "Error"
	ConstClass * ErrorClass = find_String_InTableConstClass(class_g->tableConstClass, ErrorUtf8);

	ErrorUtf8 = find_Utf8_InTableConstClass(class_g->tableConstClass, "java/lang/Exception");	// Добавляем класс Exception
	ErrorClass = find_Class_InTableConstClass(class_g->tableConstClass, ErrorUtf8);
	

	ConstClass * ErrorName = find_Utf8_InTableConstClass(class_g->tableConstClass,"<init>");
	ConstClass * ErrorType = find_Utf8_InTableConstClass(class_g->tableConstClass,"(Ljava/lang/String;)V");
	ConstClass * ErrorNameAndType = find_NameAndType_InTableConstClass(class_g->tableConstClass,ErrorName, ErrorType);
	ConstClass * methodRef = find_Methodref_InTableConstClass(class_g->tableConstClass, ErrorClass, ErrorNameAndType);*/

	// Добавляем ссылку для констурктора на базовый класс
	ConstClass * init_n = find_Utf8_InTableConstClass(class_g->tableConstClass,"<init>");
	ConstClass * init_t = find_Utf8_InTableConstClass(class_g->tableConstClass,"()V");
	ConstClass * init_nAt = find_NameAndType_InTableConstClass(class_g->tableConstClass,init_n, init_t);
	ConstClass * init_base_n = find_Utf8_InTableConstClass(class_g->tableConstClass,"java/lang/Object");
	ConstClass * init_base_c = find_Class_InTableConstClass(class_g->tableConstClass, init_base_n);
	ConstClass * methodRef = find_Methodref_InTableConstClass(class_g->tableConstClass, init_base_c, init_nAt);


	// Добавляем в таблицу методов
	MethodClass * meth = new MethodClass();
	meth->name = init_n;
    meth->num = class_g->tableMethodClass.count();
	meth->descriptor = init_t;
	meth->isStatic = true;
	meth->level = Public;
	findLocalVar(meth->tableLocalVar, "self",meth->tableLocalVar.size()+1);
	//globalCounter++;
	// генерируем код для вызова констуктора для галвного класса
	QByteArray arr;
	QDataStream streamB(&arr,QIODevice::WriteOnly);
	streamB << (unsigned char)25;				// ALOAD
	streamB << (unsigned char)0;
	streamB << (unsigned char)183;				// INVOKESPECIAL
	streamB << (unsigned short)methodRef->num;	// reference in CONSTANT_Methodref
	streamB << (unsigned char)177;				// _RETURN
	meth->methodCode=arr;
    class_g->tableMethodClass.append(meth);

 //  //добавление полей
	//ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Int_Var>");
	//ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"I");
	//ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Access_rule::Public);
	//name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Float_Var>");
	//type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"F");
	//nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Public);
	//name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<String_Var>");
	//type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"Ljava/lang/String;");
	//nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Public);

	//// добавление всех методов
 //   ConstClass * inRTL_u = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass");
	//ConstClass * inRTL = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,inRTL_u);
 //   /*ConstClass *nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "Pow");
 //   ConstClass *typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   ConstClass *methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);
 //  */ 
	//ConstClass *nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "toInt");
 //   ConstClass *typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)I");
 //  nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   ConstClass *methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Neg>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Mul>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Div>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Add>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Sub>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Great>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Less>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Ge>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Le>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Equ>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Nequ>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicNot>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicAnd>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicOr>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Assign>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "puts");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "print");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "([LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(I)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(F)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(Ljava/lang/String;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

}

void addClassToTable(QString newClass,QString classParent)
{
	ClassItem * class_g = new ClassItem(); // Создаем класс

	//ConstClass *const_class1 = new ConstClass();
	ConstClass *const_class1 = find_Utf8_InTableConstClass(class_g->tableConstClass, "Code");
	

	// Константа Class
	ConstClass * const_class = find_Class_InTableConstClass(class_g->tableConstClass,find_Utf8_InTableConstClass(class_g->tableConstClass,newClass));
	class_g->nameClass = const_class;

	if(!classParent.isEmpty())
	{
		// Константа родительского Class
		const_class = find_Class_InTableConstClass(class_g->tableConstClass,find_Utf8_InTableConstClass(class_g->tableConstClass,classParent));
		class_g->nameClassParent = const_class;
	}
	else
	{
		if(newClass != GLOBAL_CLASS)
		{
			const_class = find_Class_InTableConstClass(class_g->tableConstClass,find_Utf8_InTableConstClass(class_g->tableConstClass,"LBaseVarClass"));
			class_g->nameClassParent = const_class;
		}
	}

	//сохранение класса в таблице классов
	tableClass.insert(newClass,class_g);
	// добавдение "Code"
	//ConstClass *const_class1 = new ConstClass();
	//const_class1->type = CONSTANT_Utf8;
	//const_class1->utf8 = "Code";
	//const_class1->num = 1;
	//tableClass[currentClass]->tableConstClass.insert(0,const_class1);

 // //добавление полей
	//ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Int_Const>");
	//ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"I");
	//ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Public);
	//name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Float_Const>");
	//type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"F");
	//nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Public);
	//name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<String_Const>");
	//type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"Ljava/lang/String;");
	//nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var, type_var);
	//find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,Public);

	//// добавление всех методов
 //   ConstClass * inRTL_u = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass");
	//ConstClass * inRTL = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,inRTL_u);
 //   /*ConstClass *nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "Pow");
 //   ConstClass *typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   ConstClass *methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);
 //  */ 
	//ConstClass *nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "toInt");
 //   ConstClass *typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)I");
 //  nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   ConstClass *methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Neg>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Mul>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Div>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Add>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Sub>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Great>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Less>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Ge>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Le>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);


	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Equ>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Nequ>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicNot>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicAnd>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<LogicOr>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<Assign>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;LBaseVarClass;)LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "puts");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "print");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "([LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

 //   nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "gets");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()LBaseVarClass;");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(I)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(F)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(Ljava/lang/String;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	//nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
 //   typeMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "(LBaseVarClass;)V");
 //   nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,nameMethod, typeMeth);
 //   methRef =  find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass, inRTL, nameAndType);

	
}
int findLocalVar(QList<LocalVar*> &table, QString name, int nom_counter)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->name == name)
		{
			if(table[i]->posFirst == -1)
				table[i]->posFirst = nom_counter;
			table[i]->posLast = nom_counter;
			return i;
		}
	}
	LocalVar *temp = new LocalVar;
	temp->num = nom_counter;
	temp->name = name;
	temp->posLast = nom_counter;
	temp->posFirst = nom_counter;
	table << temp;
	return table.size()-1;
}

int findConstantVar(QList<ConstantVar*> &table, QString name, int num_counter)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->name == name)
		{
			if(table[i]->posFirst == -1)
				table[i]->posFirst = num_counter;
			table[i]->posLast = num_counter;
			return i;
		}
	}
	ConstantVar *temp = new ConstantVar();
	temp->name = name;
	temp->posLast = num_counter;
	temp->posFirst = num_counter;
	table << temp;
	return table.size()-1;
}

int findObjectVar(QList<ObjectVar*> &table, QString name, int num_counter)//, QList<FieldClass*> tableField)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->name == name)
		{
			if(table[i]->posFirst == -1)
				table[i]->posFirst = num_counter;
			table[i]->posLast = num_counter;
			return i;
		}
	}
	ObjectVar *temp = new ObjectVar();
	temp->name = name;
	temp->posLast = num_counter;
	temp->posFirst = num_counter;
	table << temp;
	return table.size()-1;
}

int findClassVar(QList<ClassVar*> &table, QString name, int num_counter)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->name == name)
		{
			if(table[i]->posFirst == -1)
				table[i]->posFirst = num_counter;
			table[i]->posLast = num_counter;
			return i;
		}
	}
	ClassVar *temp = new ClassVar();
	temp->name = name;
	temp->posLast = num_counter;
	temp->posFirst = num_counter;
	table << temp;
	return table.size()-1;
}

int findGlobalVar(QList<GlobalVar*> &table, QString name, int num_counter)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->name == name)
		{
			if(table[i]->posFirst == -1)
				table[i]->posFirst = num_counter;
			table[i]->posLast = num_counter;
			return i;
		}
	}
	GlobalVar *temp = new GlobalVar();
	temp->name = name;
	temp->posLast = num_counter;
	temp->posFirst = num_counter;
	table << temp;
	return table.size()-1;

}


ConstClass * find_Utf8_InTableConstClass(QList<ConstClass*> &table, QString constUtf8)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Utf8 && table[i]->utf8 == constUtf8)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Utf8;
	const_class->utf8 = constUtf8;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}
ConstClass * find_Class_InTableConstClass(QList<ConstClass*> &table, ConstClass *utf8)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Class && table[i]->const1 == utf8)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Class;
	const_class->const1 = utf8;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}
FieldClass * find_Field_InTableFieldClass(QList<FieldClass*> &table, ConstClass* name_field, ConstClass * type_field, Access_rule level)
{
	for(int i=0; i<table.size(); i++)
	{
		if(table[i]->name ==name_field )
			return table[i];
	}
	FieldClass * field = new FieldClass();
	field->descriptor = type_field;
	field->name = name_field;
	field->level = level;
	field->num = table.size()+1;
	table << field;
	return field;
}

ConstClass * find_NameAndType_InTableConstClass(QList<ConstClass*> &table, ConstClass *name, ConstClass *type)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_NameAndType && table[i]->const1 == name && table[i]->const2 == type)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_NameAndType;
	const_class->const1 = name;
	const_class->const2 = type;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}
ConstClass * find_Integer_InTableConstClass(QList<ConstClass*> &table, int integer)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Integer && table[i]->const_Int == integer)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Integer;
	const_class->const_Int = integer;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}
ConstClass * find_Float_InTableConstClass(QList<ConstClass*> &table, float Float)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Float && table[i]->const_Float == Float)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Float;
	const_class->const_Float = Float;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}
ConstClass * find_Bool_InTableConstClass(QList<ConstClass*> &table, bool Bool)
{
	ConstClass * tempClass;
	int size = table.size();
	for(int i=0; i<size; i++)
		tempClass = table[i];

	for(int i=0; i<table.size(); i++)
	{
		if(table[i]->type == CONSTANT_Bool && table[i]->const_Bool == Bool)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Bool;
	const_class->const_Bool = Bool;
	const_class->num = table.size()+1;
	//const_class->const1->
	table << const_class;
	return const_class;
}
ConstClass * find_String_InTableConstClass(QList<ConstClass*> &table, ConstClass *string)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_String && table[i]->const1 == string)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_String;
	const_class->const1 = string;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}

ConstClass * find_Fieldref_InTableConstClass(QList<ConstClass*> &table, ConstClass * Class, ConstClass * nameAndType)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Fieldref && table[i]->const1 == Class && table[i]->const2 == nameAndType)
			return table[i];
	}
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Fieldref;
	const_class->const1 = Class;
	const_class->const2 = nameAndType;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}

ConstClass * find_Methodref_InTableConstClass(QList<ConstClass*> &table, ConstClass * Class, ConstClass * nameAndType)
{
	for(int i=0;i<table.size();i++)
	{
		if(table[i]->type == CONSTANT_Methodref && table[i]->const1 == Class && table[i]->const2 == nameAndType)
			return table[i];
	}
    
	ConstClass *const_class = new ConstClass();
	const_class->type = CONSTANT_Methodref;
	const_class->const1 = Class;
	const_class->const2 = nameAndType;
	const_class->num = table.size()+1;
	table << const_class;
	return const_class;
}


// ----------------------------------------------------------------------------------------------
// ------------------------------------------- Дерево -------------------------------------------
// ----------------------------------------------------------------------------------------------
Program *semantic(Program *root)
{
	if(root != NULL)
	{
		semantic_lst(root->stmts);
		CreateTables(root);	// создаем таблицы
		prg=root;
		// записываем в файл
        QFile file("tjap.pain");
    
		if(file.open(QIODevice::WriteOnly))
		{
			QDataStream stream(&file);
			stream << tableClass;
			file.close();
		}
		//FILE* tree=freopen("codetree.xml","w",stdout);
		//tree_print();
		//fclose(tree);
		return root;
	}
	return 0;
}

// выводим stmt_list
void semantic_lst(struct Statements_list *stmts)
{
	if(stmts != NULL)
	{
		struct Statement *stmt;
		QString result;
		stmt = stmts->stmt;
		while(stmt)
		{
			stmt = semantic_stmt(stmt);
			if(stmt != NULL && stmt->next)
				stmt=stmt->next;
			else
				stmt = NULL;
		}
	}
}
// выводим stmt
Statement * semantic_stmt(struct Statement *stmt)
{
	struct Statement* result;

	struct Expression* temp_expr = (struct Expression*) malloc(sizeof(struct Expression));

	if (stmt != NULL)
	{
		switch(stmt->type)
		{
		case Expr:
			stmt->expr = semantic_expr(stmt->expr);
			return stmt;
			break;
		case While:
			stmt->expr = semantic_expr(stmt->expr);
			semantic_lst(stmt->block);
			return stmt;
			break;
		case If:
			stmt->expr = semantic_expr(stmt->expr);
			semantic_lst(stmt->block);
			if(stmt->next != NULL && stmt->next->type == Stmt_type::Else)	// если  не равно NULL и это именно ELSE, значит там что-то есть
			{
				semantic_lst(stmt->next->block);
			}
			return stmt;
			break;
		case Class:
			stmt->expr = semantic_expr(stmt->expr);
			if (stmt->expr_base!=NULL)
				stmt->expr_base = semantic_expr(stmt->expr_base);
			semantic_lst(stmt->block);
			return stmt;
			break;

			// выводим приоритеты
		case stPublic:
			if(stmt->block != NULL)
			{
				semantic_lst(stmt->block);
			}
			else	
			{
				if(stmt->def_body != NULL)
				{
					result = semantic_stmt(stmt->def_body);
					stmt->def_body = semantic_stmt(stmt->def_body);
				}
				if (stmt->expr!=NULL)
					stmt->expr = semantic_expr(stmt->expr);
				else
					stmt->next = semantic_stmt(stmt->next);
				return stmt;
			}
			break;
		case stPrivate:
			if(stmt->block != NULL)
			{
				semantic_lst(stmt->block);
			}
			else
			{
				if (stmt->expr!=NULL)
					stmt->expr = semantic_expr(stmt->expr);
				else
					stmt->next = semantic_stmt(stmt->next);
				return stmt;
			}
			break;
		case stProtected:
			if(stmt->block != NULL)
			{
				semantic_lst(stmt->block);
			}
			else
			{
				if (stmt->expr!=NULL)
					stmt->expr = semantic_expr(stmt->expr);
				else
					stmt->next = semantic_stmt(stmt->next);
				return stmt;
			}
			break;
		case Def:
			stmt->expr = semantic_expr(stmt->expr);
			semantic_id_list(stmt->id_list);
			semantic_lst(stmt->block);
			return stmt;
			break;

		case Break:
			return stmt;
			break;
		case Return:
			semantic_expr_list(stmt->expr_list);
			return stmt;
			break;

		case WhileFor:
			stmt->expr = semantic_expr(stmt->expr);	// начальное значение
			stmt->def_body = semantic_stmt(stmt->def_body);	// сам цикл while
			//stmt->Next->Next->Expr = semantic_expr(stmt->Next->Next->Expr);	// обработка итератора
			return stmt;
			break;

		case WhileUntil:
			stmt->expr = semantic_expr(stmt->expr);
			semantic_lst(stmt->block);
			return stmt;
			break;

		case Until:
			stmt->expr = semantic_expr(stmt->expr);
			semantic_lst(stmt->block);
			return stmt;
			break;

		case Print:
			stmt->expr = semantic_expr(stmt->expr);
			return stmt;
			break;

		case Puts:
			stmt->expr = semantic_expr(stmt->expr);
			return stmt;
			break;
        default:
            return NULL;
		}
	}
	else 
		return NULL;
}
// выводим  expr_list
void semantic_expr_list(struct Expressions_list *expr_l)
{
	struct Expression *expr;
	if (expr_l != NULL)
	{
		expr = expr_l->expr;
		while(expr)
		{
			expr = semantic_expr(expr);
			expr= expr->next;
		}
	}
}
// выводим  idintifer_list
void semantic_id_list(struct Expressions_list *id_l)
{
	struct Expression *id;
	if (id_l!=NULL)
	{		
		id = id_l->expr;
		while(id)
		{
			id = semantic_expr(id);
			id= id->next;
		}
	}
}
// выводим expr
Expression * semantic_expr(struct Expression *expr)
{
	char buff[255]={0};
	if (expr!=0)
	{
		switch(expr->type)
		{
		case Int:
			return expr;
			break;
		case Float:
			return expr;
			break;
		case Array:
			semantic_expr_list(expr->expr_List);
			return expr;
			break;
		case String:
			return expr;
			break;
		case Id:
			switch(expr->var->type)
			{
			case CONSTANT:		// константа: Var 
				return expr;
				break;
			case LOCALVAR:		// локальная переменная: Var 
				return expr;
				break;
			case GLOBALVAR:		// глобальная переменная: Var
				return expr;
				break;
			case CLASSVAR:		// переменная класса: Var 
				return expr;
				break;
			case OBJECTVAR:		// переменная объекта: Var
				return expr;
				break;
			}
			break;
		case Const:
			switch(expr->var->type)
			{
			case CONSTANT:		// константа: Var 
				return expr;
				break;
			case LOCALVAR:		// константа: Var 
				return expr;
				break;
			case GLOBALVAR:		// константа: Var  
				return expr;
				break;
			case CLASSVAR:		// константа: Var  
				return expr;
				break;
			case OBJECTVAR:		// константа: Var  
				return expr;
				break;
			}
			break;
		case Plus:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Minus:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Multiply:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Division:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Uminus:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Uplus:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Assign:
			expr=create_new_node(expr);
			expr->left = semantic_expr(expr->left);
			expr->Expr_base = semantic_expr(expr->Expr_base);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;

		case AddAssign:
			expr=create_new_node(expr);
			expr = semantic_expr(expr);
			return expr;
			break;

		case SubAssign:
			expr=create_new_node(expr);
			semantic_expr(expr);
			return expr;
			break;
		case MulAssign:
			expr=create_new_node(expr);
			semantic_expr(expr);
			return expr;
			break;
		case DivAssign:
			expr=create_new_node(expr);
			semantic_expr(expr);
			return expr;
			break;
		case CallArray:
			return expr;
			break;
		case Self:
			return expr;
			break;
		case Nil:
			return expr;
			break;
		case Doublecolon:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case More:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Less:
			expr->left = semantic_expr(expr->left);
			expr->right  =semantic_expr(expr->right);
			return expr;
			break;
		case MoreEq:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case LessEq:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case LessMore:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;

		case NotEquivalent:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;

		case Equivalent:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Or:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case And:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case OrWord:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case AndWord:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case Not:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case NotWord:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case ThreePoint:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case TwoPoint:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		case expDef:
			expr->left = semantic_expr(expr->left);
			expr->right = semantic_expr(expr->right);
			semantic_expr_list(expr->expr_List);
			return expr;
			break;
		case Super:
			semantic_expr_list(expr->expr_List);
			return expr;
			break;
        case Puts:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
        case Print:
			expr->right = semantic_expr(expr->right);
			return expr;
			break;
		}
	}
	else
	{
		return NULL;
	}
}
struct Expression * create_new_node(struct Expression *old_node)
{
	struct Expression *new_node=(struct Expression *)malloc(sizeof(struct Expression));
	struct Expression *temp_expr=(struct Expression *)malloc(sizeof(struct Expression));

	new_node->Expr_base=0;
	new_node->expr_List=0;
	new_node->left=0;
	new_node->next=0;
	new_node->right=0;
	new_node->string_const=0;
	new_node->var = 0;

	temp_expr->Expr_base=0;
	temp_expr->expr_List = 0;
	temp_expr->left=0;
	temp_expr->next=0;
	temp_expr->right=0;
	temp_expr->string_const=0;
	temp_expr->var=0;

	switch (old_node->type)
	{
		// a.b += 8 => a.b = a.b + 8
		case AddAssign:
			// создаем новый временный узел
			// создаем правую часть 
			temp_expr->type = Plus;
			temp_expr->left = old_node->left;
			temp_expr->right = old_node->right;

			new_node->right = temp_expr;
			
			new_node->type = Assign;
			new_node->left = old_node->left;
			
			return new_node;
			break;
		// a.b -= 4 => a.b = a.b - 4
		case SubAssign:
			// создаем новый временный узел
			// создаем правую часть 
			temp_expr->type = Minus;
			temp_expr->left = old_node->left;
			temp_expr->right = old_node->right;

			new_node->right = temp_expr;
			
			new_node->type = Assign;
			new_node->left = old_node->left;
			
			return new_node;
			break;
		// a.b *= 4 => a.b = a.b * 4
		case MulAssign:
			// создаем новый временный узел
			// создаем правую часть 
			temp_expr->type = Multiply;
			temp_expr->left = old_node->left;
			temp_expr->right = old_node->right;

			new_node->right = temp_expr;
			
			new_node->type = Assign;
			new_node->left = old_node->left;
			
			return new_node;
			break;

		// a.b /= 4 => a.b = a.b / 4
		case DivAssign:
			// создаем новый временный узел
			// создаем правую часть 
			temp_expr->type=Division;
			temp_expr->left = old_node->left;
			temp_expr->right = old_node->right;

			new_node->right = temp_expr;
			

			new_node->type = Assign;
			new_node->left = old_node->left;
			
			
			return new_node;
			break; 
		default:
			{
			switch (old_node->left->type)
			{
				// .=
				case expDef:
					new_node->type=PointAssign;
					new_node->left=old_node->left->left;
					new_node->Expr_base=old_node->left->right;
					new_node->right=old_node->right;
					return new_node;
					break;
				// []=
				case CallArray:
					new_node->type=ArrayAssign;
					new_node->left=old_node->left->left;
					new_node->Expr_base=old_node->left->right;
					new_node->right=old_node->right;
					return new_node;
					break;
			}
			if (old_node->right->type==Array && old_node->left->type==Id)
			{
				new_node=old_node->right;
				new_node->name=old_node->left->var->name_var;
				return new_node;
				break;
			}
			}
			break;
	}
	return old_node;
}

// -----------------------------------------------------------------------------------------------
// Заполняем таблицы переменных
// -----------------------------------------------------------------------------------------------
void CreateTables(Program *root)
{
	// если корень есть, то есть дерево не пустое
	if(root != NULL)
	{
		initialGlobalClass();			// инициализируем глобальный класс
		// теперь начинаем разбирать корень
		SemanticStatmentListTable(root->stmts);
	}
	else
		return;
}

// выводим stmt_list
QString SemanticStatmentListTable(Statements_list *stmts)
{
	// если не пустая структура
	if(stmts != NULL)
	{
		struct Statement *stmt;
		QString result = "";;
		stmt = stmts->stmt;
		while(stmt)
		{
			result.append(SemanticStatementTable(stmt));
			stmt=stmt->next;
		}
		if(result!="")
			return result;
		else 
			return "";
	}
	else
		return QString();
}
// выводим stmt
QString SemanticStatementTable(struct Statement *stmt)
{
	ClassItem * new_class;
	ConstClass * name_class;
	ConstClass * name_parent_class;
	ConstClass * method_class;
	ConstClass *name_method ;
    ConstClass *type_method ;
    ConstClass *nameAndType ;
    ConstClass *class_name ;
    ConstClass *_class ;
    ConstClass *methodRef ;

	ConstClass *tmp;

    ConstClass * global_class_N, * global_class_T, * global_class_NT, * global_class_CU, * global_class_C, * global_class_M;

	if (stmt!=NULL)
	{
		switch(stmt->type)
		{
		case Expr:
			SemanticExpressionTable(stmt->expr);
			break;
		case While:
			SemanticExpressionTable(stmt->expr);
			SemanticStatmentListTable(stmt->block);
			break;
		case WhileFor:
			SemanticExpressionTable(stmt->expr);	// начальное значение
			SemanticStatementTable(stmt->def_body);	// сам цикл while
			//SemanticExpressionTable(stmt->Next->Next->Expr);	// обработка итератора
			break;
		case WhileUntil:
			SemanticExpressionTable(stmt->expr);
			SemanticStatmentListTable(stmt->block);
			break;
		case If:
			SemanticExpressionTable(stmt->expr);
			SemanticStatmentListTable(stmt->block);
			if(stmt->next != NULL && stmt->next->type == Stmt_type::Else)	// если  не равно NULL and Next type is ELSE, значит там чтото есть
			{
				SemanticStatmentListTable(stmt->next->block);
			}
			break;
	
		case Class:
			currentClass = stmt->name_class->name_var;	// выбираем текущим классом тот класс, который разбираем

			if(stmt->name_parent_class != NULL)
				addClassToTable(stmt->name_class->name_var,stmt->name_parent_class->name_var);
			else
				addClassToTable(stmt->name_class->name_var);

			// добавляем консруктор для класса
			{
				ConstClass * init_n = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
				ConstClass * init_t = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()L" + currentClass + ";");
				ConstClass * init_nAt = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass, init_n, init_t);
				ConstClass * init_cU = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, stmt->name_class->name_var);
				ConstClass * init_c = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass, init_cU);
				ConstClass * init_M = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,init_c, init_nAt);	// methodRef для класса
               
                global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "<init>");
				global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "()L" + currentClass + ";");
				global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
				global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, stmt->name_class->name_var);
				global_class_C  = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
				global_class_M  = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);	// methodRef для класса

                //конструктор предка
				if(stmt->name_parent_class != NULL)
				{
					init_cU = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, stmt->name_parent_class->name_var);
				}
				else
				{
					init_cU = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "LBaseVarClass");
				}
				init_c = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass, init_cU);
                init_n = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
				init_t = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()V");
				init_nAt = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass, init_n, init_t);
				init_M = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,init_c, init_nAt);	// methodRef для родителя

				// Добавляем <init> в таблицу методов
				MethodClass * meth = new MethodClass();
				bool isHave=false;	// == true - метод уже записан
				// проверяем наличие метода 
				for(int i=0; i<tableClass[currentClass]->tableMethodClass.size();i++)
				{
					meth = tableClass[currentClass]->tableMethodClass[i];
					// если есть метод с таким же именем и типом доступа
					if(meth->name->utf8 == "<init>" && meth->level == Access_rule::Public)
					{
						isHave = true;
						break;
					}
				}
				// если метода еще нет, то записываем его
				meth = new MethodClass();
				if(!isHave)
				{
					ConstClass * init_n = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "<init>");
					ConstClass * init_t = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, "()V");
					meth->num = tableClass[currentClass]->tableMethodClass.size();
					meth->name = init_n;
					meth->descriptor = init_t;
                    meth->isStatic = true;
					meth->level = Access_rule::Public;
					findLocalVar(meth->tableLocalVar, "self", meth->tableLocalVar.size()+1);
					//globalCounter++;
					tableClass[currentClass]->tableMethodClass.append(meth);
				}
			}
			tmp = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, stmt->name_class->name_var);
			find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,tmp);
			tableClass[currentClass]->inTree = stmt;
			new_class = tableClass[currentClass];
			name_class = find_Utf8_InTableConstClass(new_class->tableConstClass,stmt->name_class->name_var); // имя класса
			
			// name parent's class
			if(stmt->name_parent_class != NULL)
			{
				name_parent_class = find_Utf8_InTableConstClass(new_class->tableConstClass, stmt->name_parent_class->name_var);
			}
			else
			{
				name_parent_class = NULL;
			}

			// if class have methodes
			if(stmt->block != NULL)
			{
				// then create methode
				SemanticStatmentListTable(stmt->block);
			}
			
			currentMetod=tableClass[GLOBAL_CLASS]->tableMethodClass[0];
			currentClass = GLOBAL_CLASS;
			break;

			// выводим приоритеты
		case stPublic:
			if(stmt->def_body)
			{
				currentMetod = new MethodClass();
				currentMetod->level = Public;
                currentMetod->num = tableClass[currentClass]->tableMethodClass.count();
				currentMetod->isStatic = false;
                
                //количество параметров метода
                int params = 0;
                if(stmt->def_body->id_list != NULL) {
                    struct Expression *id = stmt->def_body->id_list->expr;
	                while(id) {
		                params++;
		                id=id->next;
	                }
                }

                currentMetod->countArgs = params;

                QString methodName = stmt->def_body->expr->var->name_var;
                if(methodName == "initialize") {
                    methodName = "<init>";
                }
				currentMetod->name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, methodName);

                QString methodDescriptor = QString("(%1)L" + currentClass + ";").arg(SemanticIdintifierListTable(stmt->def_body->id_list));
                if(methodName == "<init>") {
                    methodDescriptor = QString("(%1)L").arg(SemanticIdintifierListTable(stmt->def_body->id_list)) + currentClass + ";";
                }

				if(!currentMetod->isStatic)
					findLocalVar(currentMetod->tableLocalVar,"self", currentMetod->tableLocalVar.size()+1);
				currentMetod->descriptor = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, methodDescriptor);
				currentMetod->tableParam=fromIdListToLocalVarList(stmt->def_body->id_list);
       
                ConstClass * global_class_n = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, methodName);
				ConstClass * global_class_t = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, methodDescriptor);

				//stmt->Def_body->Expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar,stmt->Def_body->Expr->Var->name, currentMetod->tableLocalVar.size());
				SemanticStatementTable(stmt->def_body);
				tableClass[currentClass]->tableMethodClass.append(currentMetod);
				//currentMetod->name->const2 = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,currentMetod->name,currentMetod->name->const2);
	
				// добавляем метод в Dynamic
				// если такого метода нет, то добавляем его 
				MethodClass * meth;
				bool isHave=false;	// == true - метод уже записан
				// проверяем наличие метода 
				for(int i=0; i<tableClass[GLOBAL_CLASS]->tableMethodClass.size();i++)
				{
					meth = tableClass[GLOBAL_CLASS]->tableMethodClass[i];
					// если есть метод с таким же именем, типом доступа и дескриптором
					if(meth->name->utf8 == currentMetod->name->utf8 && meth->level == currentMetod->level && meth->descriptor->utf8==currentMetod->descriptor->utf8)
					{
						 if((meth->isStatic && !currentMetod->isStatic) || (!meth->isStatic && currentMetod->isStatic))
						{
						  _set_errno(1);
						  perror("Error! Static/dynamic method exception!");
						  system("pause");
									  exit(0);
						}
						isHave = true;
						break;
					}
				}
				// если метода еще нет, то записываем его
				if(!isHave)
				{
					MethodClass * newMenthod= new MethodClass();// = *currentMetod;
					// записываем имя в таблицу методов
					newMenthod->num = tableClass[GLOBAL_CLASS]->tableMethodClass.size();
					
					// записываем имя и тип метода в таблицу констант для Dynamic
					ConstClass * nameM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->name->utf8);
                    ConstClass * typeM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->descriptor->utf8);
					find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,nameM,typeM);
					newMenthod->name = nameM;
					newMenthod->descriptor = typeM;
					newMenthod->methodCode = GenericErrorCode();
					newMenthod->isStatic = currentMetod->isStatic;
					newMenthod->level = currentMetod->level;
					findLocalVar(newMenthod->tableLocalVar,"self", newMenthod->tableLocalVar.size()+1);

					newMenthod->tableLocalVar.append(currentMetod->tableParam);
					newMenthod->tableConstatnVar = currentMetod->tableConstatnVar;
					tableClass[GLOBAL_CLASS]->tableMethodClass.append(newMenthod);
				}

				// выделяем текущим метода Главный метод (main)
				currentMetod = tableClass[GLOBAL_CLASS]->tableMethodClass[0];
				
			}
			else
			{
				stmt->expr->name="F";
				stmt->expr->level=Public;
				SemanticExpressionTable(stmt->expr);
			}
			break;
		case stPrivate:
			if(stmt->def_body)
			{
				currentMetod = new MethodClass();
				currentMetod->level = Private;
				currentMetod->isStatic = stmt->def_body->isStatic;
				currentMetod->name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,stmt->def_body->expr->var->name_var);
				if(!currentMetod->isStatic)
					findLocalVar(currentMetod->tableLocalVar,"self", currentMetod->tableLocalVar.size()+1);
				currentMetod->descriptor = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,QString("(%1)LBaseVarClass;").arg(SemanticIdintifierListTable(stmt->def_body->id_list)));
				currentMetod->num = 1;
				currentMetod->tableParam=fromIdListToLocalVarList(stmt->def_body->id_list);


				//stmt->Def_body->Expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar,stmt->Def_body->Expr->Var->name, currentMetod->tableLocalVar.size());

				SemanticStatementTable(stmt->def_body);
				tableClass[currentClass]->tableMethodClass.append(currentMetod);
                /*****LOOOK******/
				find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,currentMetod->name,currentMetod->descriptor);
				
				// добавляем метод в Dynamic
				// если такого метода нет, то добавляем его 
				MethodClass * meth = new MethodClass();
				bool isHave=false;	// == true - метод уже записан
				// проверяем наличие метода 
				for(int i=0; i<tableClass[GLOBAL_CLASS]->tableMethodClass.size();i++)
				{
					meth = tableClass[GLOBAL_CLASS]->tableMethodClass[i];
					// если есть метод с таким же именем и типом доступа
					 if(meth->name->utf8 == currentMetod->name->utf8 && meth->level == currentMetod->level && meth->descriptor->utf8==currentMetod->descriptor->utf8)
					 {
						if((meth->isStatic && !currentMetod->isStatic) || (!meth->isStatic && currentMetod->isStatic))
						{
						  _set_errno(1);
						  perror("Error! Static/dynamic method exception!");
						  system("pause");
						  exit(0);
						}
						isHave = true;
						break;
					}
				}
				// если метода еще нет, то записываем его
				if(!isHave)
				{
					MethodClass * newMenthod= new MethodClass();// = *currentMetod;
					// записываем имя в таблицу методов
					newMenthod->num = tableClass[GLOBAL_CLASS]->tableMethodClass.size();
					
					// записываем имя и тип метода в таблицу констант для Dynamic
					ConstClass * nameM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->name->utf8);
					ConstClass * typeM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->descriptor->utf8);
					find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,nameM,typeM);
					newMenthod->name = nameM;
					newMenthod->descriptor = typeM;
					newMenthod->isStatic = currentMetod->isStatic;
					newMenthod->level = currentMetod->level;
					findLocalVar(newMenthod->tableLocalVar,"self", newMenthod->tableLocalVar.size()+1);
					newMenthod->tableLocalVar.append(currentMetod->tableParam);
					newMenthod->methodCode = GenericErrorCode();
					tableClass[GLOBAL_CLASS]->tableMethodClass.append(newMenthod);
				}

				// выделяем текущим метода Главный метод (main)
				currentMetod = tableClass[GLOBAL_CLASS]->tableMethodClass[0];
			}
			else
			{
				stmt->expr->name="F";
				stmt->expr->level=Private;
				SemanticExpressionTable(stmt->expr);
			}
			break;
		case stProtected:
			if(stmt->def_body)
			{
				currentMetod = new MethodClass();
				currentMetod->level = Protected;
				currentMetod->isStatic = stmt->def_body->isStatic;
				currentMetod->name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,stmt->def_body->expr->var->name_var);
				if(!currentMetod->isStatic)
					findLocalVar(currentMetod->tableLocalVar,"self", currentMetod->tableLocalVar.size()+1);
				currentMetod->descriptor = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,QString("(%1)LBaseVarClass;").arg(SemanticIdintifierListTable(stmt->def_body->id_list)));
				//QString asd = QString("(%1)Lruby/types/Dynamic;").arg(SemanticIdintifierListTable(stmt->Id_List));
				currentMetod->num = 1;
				currentMetod->tableParam=fromIdListToLocalVarList(stmt->def_body->id_list);
				

				//stmt->Def_body->Expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar,stmt->Def_body->Expr->Var->name, currentMetod->tableLocalVar.size());

				SemanticStatementTable(stmt->def_body);
				tableClass[currentClass]->tableMethodClass.append(currentMetod);
				find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,currentMetod->name,currentMetod->descriptor);

				// добавляем метод в Dynamic
				// если такого метода нет, то добавляем его 
				MethodClass * meth = new MethodClass();
				bool isHave=false;	// == true - метод уже записан
				// проверяем наличие метода 
				for(int i=0; i<tableClass[GLOBAL_CLASS]->tableMethodClass.size();i++)
				{
					meth = tableClass[GLOBAL_CLASS]->tableMethodClass[i];
					// если есть метод с таким же именем и типом доступа
					if(meth->name->utf8 == currentMetod->name->utf8 && meth->level == currentMetod->level && meth->descriptor->utf8==currentMetod->descriptor->utf8)
					{
						if((meth->isStatic && !currentMetod->isStatic) || (!meth->isStatic && currentMetod->isStatic))
						{
						  _set_errno(1);
						  perror("Error! Static/dynamic method exception!");
						  system("pause");
						  exit(0);
						}
						isHave = true;
						break;
					}
				}
				// если метода еще нет, то записываем его
				if(!isHave)
				{
					MethodClass * newMenthod= new MethodClass();// = *currentMetod;
					// записываем имя в таблицу методов
					newMenthod->num = tableClass[GLOBAL_CLASS]->tableMethodClass.size();
					
					// записываем имя и тип метода в таблицу констант для Dynamic
					ConstClass * nameM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->name->utf8);
					ConstClass * typeM = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->descriptor->utf8);
					find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,nameM,typeM);
					newMenthod->name = nameM;
					newMenthod->descriptor = typeM;
					newMenthod->isStatic = currentMetod->isStatic;
					newMenthod->level = currentMetod->level;
					findLocalVar(newMenthod->tableLocalVar,"self", newMenthod->tableLocalVar.size()+1);
					newMenthod->tableLocalVar.append(currentMetod->tableParam);
					newMenthod->methodCode = GenericErrorCode();
					tableClass[GLOBAL_CLASS]->tableMethodClass.append(newMenthod);
				}

				// выделяем текущим метода Главный метод (main)
				currentMetod = tableClass[GLOBAL_CLASS]->tableMethodClass[0];
			}
			else
			{
				stmt->expr->name="F";
				stmt->expr->level=Protected;
				SemanticExpressionTable(stmt->expr);
			}
			break;
		case Def:
			nameAndType=find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,currentMetod->name,currentMetod->descriptor);
			name_class = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
			_class=find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,name_class);
			stmt->expr->constClass =find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);

            global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->name->utf8);
			global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentMetod->descriptor->utf8);
            global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
		    global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentClass);
		    global_class_C  = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
		    global_class_M  = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);	// methodRef для класса

            SemanticStatmentListTable(stmt->block);
            /*name_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,stmt->Expr->Var->name);
			type_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,QString("(%1)LBaseVarClass;").arg(SemanticIdintifierListTable(stmt->Id_List)));
			nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_method,type_method);
			class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
			_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
			// добавляем self в таблицу локальных переменных

			//methodRef = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);
			
			
			stmt->Expr->constClass = methodRef;*/
            break;

		
		case Break:
			break;
		case Return:
			SemanticExpressionListTable(stmt->expr_list);
			break;

		case Until:
			SemanticExpressionTable(stmt->expr);
			SemanticStatmentListTable(stmt->block);
			break;

		/*case Print:
			SemanticExpressionListTable(stmt->Expr_List);
			break;

		case Puts:
			SemanticExpressionTable(stmt->Expr);
			break;

		case Gets:
			//SemanticExpressionTable(stmt->Expr);
			break;*/
		}
		return QString();
	}
	else return "";
}
// выводим  expr_list
void SemanticExpressionListTable(struct Expressions_list *expr_l)
{
	struct Expression *expr;
	if (expr_l!=NULL)
	{
		expr = expr_l->expr;
		while(expr)
		{
			SemanticExpressionTable(expr);
			expr= expr->next;
		}
	}
}
// выводим expr
void SemanticExpressionTable(struct Expression *expr)
{
	char buff[255];
    ConstClass * global_class_N, * global_class_T, * global_class_NT, * global_class_CU, * global_class_C, * global_class_M;
    ConstClass * name_var, * type_var, * name_and_type, * class_name, * _class, * field_ref;
    
    //для поиска типа переменной
    QString typeName;

	if (expr!=NULL)
	{
		expr->numLocalVar = -1;
		expr->constClass = 0;
		
		switch(expr->type)
		{
		case Int:	// целочисленная константа
			//if(expr->Int_const > 129 || expr->Int_const < -128)
			expr->constClass = find_Integer_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->int_const);
            find_Integer_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, expr->int_const);
			// добаляем в таблицу локальных переменных
			/*{
				int num = findLocalVar(currentMetod->tableLocalVar, QString::number(expr->Int_const), currentMetod->tableLocalVar.size());
				expr->numLocalVar = num;
				if(num >= globalCounter)
					globalCounter++;
			}*/
            rightClass = "I";
			break;
		case Float:	// дробная константа 
			expr->constClass = find_Float_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->float_const);
			/*{
				int num = findLocalVar(currentMetod->tableLocalVar, QString::number(expr->Float_const),currentMetod->tableLocalVar.size());
				expr->numLocalVar = num;
				if(num >= globalCounter)
					globalCounter++;
			}*/
            rightClass = "F";
			break;
		case String:	// строковая константа
			{
				QString temp;// = "<" + expr->String_const + ">";
				temp.append("<");
				temp.append(expr->string_const);
				temp.append(">");
				/*int num = findLocalVar(currentMetod->tableLocalVar, temp, currentMetod->tableLocalVar.size());
				expr->numLocalVar = num;
				if(num >= globalCounter)
					globalCounter++;*/
			}
			expr->constClass = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->string_const);
			expr->constClass = find_String_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->constClass);
            rightClass = "java/lang/String";
			break;
		case Bool:		// логическая переменная
			//if(expr->Bool_const == 0)
			//	expr->constClass = find_Bool_InTableConstClass(tableClass[currentClass]->tableConstClass, false);
			//else
			//	expr->constClass = find_Bool_InTableConstClass(tableClass[currentClass]->tableConstClass, true);
            rightClass = "B";
			break;
		case Array:
			{
				ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, expr->name);
				ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"[LBaseVarClass;");
				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,name_var,type_var);
				expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->name, currentMetod->tableLocalVar.size());
				globalCounter++;
				SemanticExpressionListTable(expr->expr_List);
			}
			break;

		case CallArray:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;

		case Id:	// Id = var1 
			switch(expr->var->type)
			{
			case CONSTANT:		// константа: Var 
				//expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->Var->name, globalCounter);
				expr->numLocalVar = findConstantVar(currentMetod->tableConstatnVar, expr->var->name_var, globalCounterConst);
				globalCounterConst++;
				break;
			case LOCALVAR:		// локальная переменная: var
				{
                
                if(rightClass.count() == 0) {
                    rightClass = "LBaseVarClass;";
                }
                else if(rightClass.count() != 1 && rightClass[0] != 'L') {
                    rightClass = "L" + rightClass + ";";
                }
				ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
				ConstClass * type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, rightClass);
				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass, name_var, type_var);

                global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, expr->var->name_var);
                global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, rightClass);
                global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);

				if(QString(currentMetod->name->utf8)!="main")
				{
					bool is=0;
					//ищем локальную переменную с данным именем в полях класса
					for(int i=0; i<tableClass[currentClass]->tablePoleClass.size(); i++)
						if(tableClass[currentClass]->tablePoleClass[i]->descriptor->utf8 == type_var->utf8 && tableClass[currentClass]->tablePoleClass[i]->name->utf8 ==name_var->utf8 )
							is=1;
					if(!is)
					 expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->var->name_var, globalCounter);
				}
				
				if(QString(expr->name)=="F")
				{
					find_Field_InTableFieldClass(tableClass[GLOBAL_CLASS]->tablePoleClass,name_var,type_var,expr->level);
        
					name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
					type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");
					nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
					ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
					ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
					//find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);
					find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,expr->level);
				}
				else
					  expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->var->name_var, globalCounter);
				    
				globalCounter++;
				
				}
				break;
			case GLOBALVAR:		// глобальная переменная: Var
				expr->numLocalVar = findGlobalVar(tableClass[currentClass]->tableGLobalVar, expr->var->name_var, globalCounterGlobal);
				globalCounterGlobal++;
				break;
			case CLASSVAR:	// переменная класса: Var
				{
					ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, expr->var->name_var);
					ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"LBaseVarClass;");
					ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,name_var,type_var);

				expr->numLocalVar = findClassVar(tableClass[currentClass]->tableClassVar, expr->var->name_var, globalCounterClass);
				name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
				type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");
				find_Field_InTableFieldClass(tableClass[GLOBAL_CLASS]->tablePoleClass,name_var,type_var,expr->level);
                nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
				ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
				ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
				//find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);
				find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,expr->level);
					
				globalCounterClass++;
				}
				break;
			case OBJECTVAR:		// переменная объекта: @Var - поле
				{
                    QString className = rightClass;
                    //вызов метода
                    if(rightClass == "") {
                        bool found = false;
                        //ищем в классе тип переменной
                        for(int i = 0; i < tableClass[currentClass]->tablePoleClass.count(); i++) {
                            FieldClass * field = tableClass[currentClass]->tablePoleClass[i];

                            //нали связку переменной с типом
                            if(field->name->utf8 == expr->var->name_var) {
                                rightClass = field->descriptor->utf8;
                                //выходим
                                found = true;
                                i = tableClass[currentClass]->tableConstClass.count();
                            }
                        }
                        if(!found) {
                            _set_errno(1);
						    perror("Error! Can not use undefined object");
						    system("pause");
							exit(0);
                        }
                    }
                    //объявление
                    else if (rightClass.count() != 1 && rightClass[0] != 'L'){
                        rightClass = "L" + rightClass + ";";
                    }

                    className = rightClass;
                    if(rightClass[0] == 'L') {
                        className = rightClass.mid(1, rightClass.count() - 2);
                    }

                    // добавляем филдреф
				    name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
                    type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, rightClass);
				    name_and_type = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass, name_var, type_var);
				    class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, currentClass);
				    _class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
				    field_ref = find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass, _class, name_and_type);

                    global_class_N = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, expr->var->name_var);
				    global_class_T = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, rightClass);
				    global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
				    global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, currentClass);
				    global_class_C = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
				    global_class_M = find_Fieldref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);

				    expr->constClass = field_ref;

					//find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);
					if(expr->level<0)
						expr->level=Public;

                    //поле еще не добавлено

					find_Field_InTableFieldClass(tableClass[GLOBAL_CLASS]->tablePoleClass,name_var,type_var,expr->level);
					find_Field_InTableFieldClass(tableClass[currentClass]->tablePoleClass,name_var,type_var,expr->level);
					//expr->numLocalVar= findObjectVar(currentMetod->tablePoleVar,expr->Var->name,globalCounterObject);
					globalCounterObject++;
				}
				break;
			}
			break;
		case Const:
			switch(expr->var->type)
			{
			case CONSTANT:		// константа: Var 
				//expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->Var->name, globalCounter);
				expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->var->name_var, globalCounter);
				globalCounterConst++;
				break;
			case LOCALVAR:		// локальная переменная: var 
				expr->numLocalVar = findLocalVar(currentMetod->tableLocalVar, expr->var->name_var, globalCounter);
				globalCounter++;
				break;
			case GLOBALVAR:		// глобальная переменная: Var
				expr->numLocalVar = findGlobalVar(tableClass[currentClass]->tableGLobalVar, expr->var->name_var, globalCounterGlobal);
				globalCounterGlobal++;
				break;
			case CLASSVAR:		// переменная класса: Var 
				{
				expr->numLocalVar = findClassVar(tableClass[currentClass]->tableClassVar, expr->var->name_var, globalCounterClass);
				ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
				ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");

				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
				
				globalCounterClass++;
				}
				break;
			case OBJECTVAR:		// переменная объекта: Var
				expr->numLocalVar = findObjectVar(tableClass[currentClass]->tableObjectVar, expr->var->name_var, globalCounterObject);
				ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->var->name_var);
				ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");

				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
				
				// Добавляем в таблицу полей
				//expr->numLocalVar= findObjectVar(currentMetod->tablePoleVar,expr->Var->name,globalCounterObject);
				globalCounterObject++;
				break;
			}
			break;
		case Plus:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Minus:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Multiply:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Division:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Uminus:
			SemanticExpressionTable(expr->right);
			break;
		case Uplus:
			SemanticExpressionTable(expr->right);
			break;
		case Assign:
			// если справа от переменной стоит массив, то записываем левую часть в таблицу констатн с типом array
			if(expr->right->type == Array)
			{
				//ConstClass * tmpName = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,expr->Left->Var->name);
				ConstClass * tmpType = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"[LBaseVarClass;");
				// если спросят "зачем nameAndType добавлять в таблицу констант", закоментить эту строку
				//ConstClass * tmpNameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,tmpName,tmpType);
				//tmpNameAndType
				SemanticExpressionTable(expr->left);
				SemanticExpressionTable(expr->right);
				SemanticExpressionTable(expr->Expr_base);
                rightClass = "";
				return;
			}
			if(expr->left->var != 0 && expr->left->var->type == OBJECTVAR)
			{
				if(expr->right->var != 0 && expr->right->var->type == OBJECTVAR)
				{
					expr->left->numLocalVar = findObjectVar(tableClass[currentClass]->tableObjectVar, expr->left->var->name_var, globalCounterObject);
					globalCounterObject++;
					expr->right->numLocalVar = findObjectVar(tableClass[currentClass]->tableObjectVar, expr->right->var->name_var, globalCounterObject);
					globalCounterObject++;

					// добавляем филдреф
					ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->left->var->name_var);
					ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");
					ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
					ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
					ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
					ConstClass * fieldRef = find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass, _class, nameAndType);

					name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->right->var->name_var);
					type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");
					nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
					class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
					_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
					fieldRef = find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass, _class, nameAndType);
					expr->constClass=fieldRef;
                    rightClass = "";
					return;
				}
			}
			
			// делаем fieldRef на @var
			if(expr->left->var != 0 && (expr->left->var->type == OBJECTVAR || expr->left->var->type == CLASSVAR || expr->left->var->type == LOCALVAR))
			{
                SemanticExpressionTable(expr->right);	
				SemanticExpressionTable(expr->left);	// добавляем name and tipe

                rightClass = "";
				return;
			}
			if(expr->right->var != 0 && (expr->right->var->type == OBJECTVAR || expr->right->var->type == CLASSVAR || expr->right->var->type == LOCALVAR))
			{
				SemanticExpressionTable(expr->left);
				SemanticExpressionTable(expr->right);	// добавляем методреф
				// добавляем филдреф
				ConstClass * name_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, expr->right->var->name_var);
				ConstClass *type_var = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"LBaseVarClass;");
				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_var,type_var);
				ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,currentClass);
				ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
				ConstClass * fieldRef = find_Fieldref_InTableConstClass(tableClass[currentClass]->tableConstClass, _class, nameAndType);
				expr->right->constClass=fieldRef;
                rightClass = "";
				return;
			}
			
			{
				SemanticExpressionTable(expr->left);
				SemanticExpressionTable(expr->right);
				SemanticExpressionTable(expr->Expr_base);
			}
            rightClass = "";
			break;
		
		/* .= */
		case PointAssign:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			SemanticExpressionTable(expr->Expr_base);
			break;
		/* []= */
		case ArrayAssign:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			SemanticExpressionTable(expr->Expr_base);
			break;

		// Понятия не имею что делать с этим
		case Self:
			break;
		// Понятия не имею что делать и с этим тоже
		case Nil:
			break;

		case Doublecolon:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case More:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Less:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case MoreEq:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case LessEq:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case LessMore:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;

		case NotEquivalent:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;

		case Equivalent:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Or:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case And:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case OrWord:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case AndWord:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case Not:
			SemanticExpressionTable(expr->right);
			break;
		case NotWord:
			SemanticExpressionTable(expr->right);
			break;
		case ThreePoint:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case TwoPoint:
			SemanticExpressionTable(expr->left);
			SemanticExpressionTable(expr->right);
			break;
		case expDef:
            // если это не вызов метода new, то добавляем вызов - иначе пропускаем
            if(strcmp(expr->right->var->name_var, "new") != 0)
            {

                //проверка, описан ли такой класс
                rightClass = expr->left->var->name_var;
                QList<QString> classes = tableClass.keys();
                bool found = false;
                for(int i = 0; !found && i < classes.count(); i++) {
                    if(classes[i] == rightClass) {
                        found = true;
                        i = classes.count();
                    }
                }
                if(!found) {
                    _set_errno(1);
				    perror("unknown class");
				    system("pause");
					exit(0);
                }

                //количество параметров метода
                int params = 0;
                if(expr->expr_List != NULL) {
                    struct Expression *id = expr->expr_List->expr;
	                while(id) {
		                params++;
		                id=id->next;
	                }
                }
                found = false;
                for(int i = 0; !found && i < tableClass[rightClass]->tableMethodClass.count(); i++) {
                    if(tableClass[rightClass]->tableMethodClass[i]->name->utf8 == expr->right->var->name_var && tableClass[rightClass]->tableMethodClass[i]->countArgs == params) {
                        found = true;
                    }
                }
                if(!found) {
                    _set_errno(1);
				    perror("unknown method");
				    system("pause");
					exit(0);
                }

				SemanticExpressionTable(expr->left);
				ConstClass *name_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,expr->right->var->name_var);
				ConstClass *type_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,QString("(%1)LBaseVarClass;").arg(SemanticIdintifierListTable(expr->expr_List)));
				ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_method,type_method);

                //ищем в классе тип переменной
                for(int i = 0; i < tableClass[currentClass]->tablePoleClass.count(); i++) {
                    FieldClass * field = tableClass[currentClass]->tablePoleClass[i];

                    //нали связку переменной с типом
                    if(field->name->utf8 == expr->left->var->name_var) {
                        typeName = field->descriptor->utf8;
                        //выходим
                        i = tableClass[currentClass]->tableConstClass.count();
                    }
                }

                if(typeName[0] == 'L') {
                    typeName = typeName.mid(1, typeName.count() - 2);
                }
				ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, typeName);
				ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass, class_name);
				ConstClass *methodRef = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);

                global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,expr->right->var->name_var);
			    global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,QString("(%1)LBaseVarClass;").arg(SemanticIdintifierListTable(expr->expr_List)));
			    global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
			    global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, typeName);
			    global_class_C  = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
			    global_class_M  = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);

				expr->constClass = methodRef;
				
			}
			else //new
            {
                rightClass = expr->left->var->name_var;
                
                //проверка, что такой класс уже описан
                QList<QString> classes = tableClass.keys();
                bool found = false;
                for(int i = 0; !found && i < classes.count(); i++) {
                    if(classes[i] == rightClass) {
                        found = true;
                    }
                }
                if(!found) {
                    _set_errno(1);
				    perror("unknown class");
				    system("pause");
					exit(0);
                }

			    // добавляем консруктор для класса   
                ConstClass *name_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"<init>");
                ConstClass *type_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"()L" + rightClass + ";");
                ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_method,type_method);
                ConstClass *class_name  = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,expr->left->var->name_var);
                ConstClass *_class      = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
                ConstClass *methodRef   = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);
                
                // выбираем новым классом тот класс, который разбираем
				addClassToTable(rightClass);

                name_method = find_Utf8_InTableConstClass(tableClass[rightClass]->tableConstClass,"<init>");
                type_method = find_Utf8_InTableConstClass(tableClass[rightClass]->tableConstClass,"()L" + rightClass + ";");
                nameAndType = find_NameAndType_InTableConstClass(tableClass[rightClass]->tableConstClass,name_method,type_method);
                class_name  = find_Utf8_InTableConstClass(tableClass[rightClass]->tableConstClass,expr->left->var->name_var);
                _class      = find_Class_InTableConstClass(tableClass[rightClass]->tableConstClass,class_name);
                methodRef   = find_Methodref_InTableConstClass(tableClass[rightClass]->tableConstClass,_class,nameAndType);

                ConstClass * global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"<init>");
			    ConstClass * global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"()L" + rightClass + ";");
			    ConstClass * global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
			    ConstClass * global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,expr->left->var->name_var);
			    ConstClass * global_class_C  = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
			    ConstClass * global_class_M  = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);

                expr->constClass = methodRef;

				// Добавляем <init> в таблицу методов
                MethodClass * meth;
				bool isHave = false;	// == true - метод уже записан
				// проверяем наличие метода 
				for(int i=0; i<tableClass[rightClass]->tableMethodClass.size();i++)
				{
					meth = tableClass[rightClass]->tableMethodClass[i];
					// если есть метод с таким же именем и типом доступа
					if(meth->name->utf8 == "<init>" && meth->level == Access_rule::Public)
					{
						isHave = true;
						break;
					}
				}
                meth = new MethodClass();
				// если метода еще нет, то записываем его
				if(!isHave)
				{
					ConstClass * init_n = find_Utf8_InTableConstClass(tableClass[rightClass]->tableConstClass, "<init>");
					ConstClass * init_t = find_Utf8_InTableConstClass(tableClass[rightClass]->tableConstClass, "()L" + rightClass + ";");
					meth->num = tableClass[rightClass]->tableMethodClass.size();
					meth->name = init_n;
					meth->descriptor = init_t;
					meth->level = Access_rule::Public;
					findLocalVar(meth->tableLocalVar, "self", meth->tableLocalVar.size()+1);
					tableClass[rightClass]->tableMethodClass.append(meth);
				}
            }
			break;

            ///////////////////////////////////////////////////////////////////////////////
            /*
                ConstClass *name_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"<init>");
                ConstClass *type_method = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,"()V");
                ConstClass *nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass,name_method,type_method);
                ConstClass *class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,expr->left->var->name_var);
                ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,class_name);
                ConstClass *methodRef = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,nameAndType);

                ConstClass * global_class_N  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"<init>");
			    ConstClass * global_class_T  = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"()V");
			    ConstClass * global_class_NT = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_N, global_class_T);
			    ConstClass * global_class_CU = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,expr->left->var->name_var);
			    ConstClass * global_class_C  = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_CU);
			    ConstClass * global_class_M  = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, global_class_C, global_class_NT);

                expr->constClass = methodRef;

				MethodClass * meth = new MethodClass();
				//meth->num = -1;
				bool isHave=false;	// == true - метод new уже записан
				// проверяем наличие метода new (<init>)
				for(int i=0; i<tableClass[currentClass]->tableMethodClass.size();i++)
				{
					meth = tableClass[currentClass]->tableMethodClass[i];
					if(meth->name->utf8 == "<init>")
					{
						isHave = true;
						break;
					}
				}
				// если метода еще нет, то записываем его
				if(!isHave)
				{
					// записываем имя в таблицу методов
					MethodClass * method = new MethodClass();
					method->level = Public;
					method->name = name_method;
					method->descriptor = type_method;
					method->num = tableClass[currentClass]->tableMethodClass.size();
					method->isStatic = false;

					tableClass[currentClass]->tableMethodClass << method;
				}
                break;
                */
		case Super:
			{
                QString parentClass = tableClass[currentClass]->nameClassParent->const1->utf8;
                //проверка, существует ли родительский класс
                if(parentClass == "LBaseVarClass") {
                    _set_errno(1);
                    perror("have no parent class");
                    system("pause");
                    exit(0);
                }
                else {
                    //проверка, существует ли класс
                    QList<QString> classes = tableClass.keys();
                    bool found = false;
                    for(int i = 0; !found && i < classes.count(); i++) {
                        if(classes[i] == parentClass) {
                            found = true;
                            i = classes.count();
                        }
                    }
                    if(!found) {
                        _set_errno(1);
				        perror("unknown class");
				        system("pause");
				        exit(0);
                    }

                    //проверка, существует ли метод и совпадает ли количество параметров
                    int params = 0;
                    if(expr->expr_List != NULL) {
                        struct Expression *id = expr->expr_List->expr;
	                    while(id) {
		                    params++;
		                    id=id->next;
	                    }
                    }
                    found = false;
                    for(int i = 0; !found && i < tableClass[parentClass]->tableMethodClass.count(); i++) {
                        if(tableClass[parentClass]->tableMethodClass[i]->name->utf8 == currentMetod->name->utf8 && tableClass[parentClass]->tableMethodClass[i]->countArgs == params) {
                            found = true;
                        }
                    }
                    if(!found) {
                        _set_errno(1);
				        perror("unknown parent method");
				        system("pause");
				        exit(0);
                    }
                }
				// вызов родительского класса
				// currentClass - имя текущего класса
				// currentMethod - текущий метод
				// по текущему методу (имени текущего метода) ищем в текущем классе метод с таким же именем и делаем ссылку на его CONSTANT_Class
				ConstClass * _baseNameMeth = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, currentMetod->name->utf8);
				ClassItem  * _baseClass = tableClass[currentClass];
				_baseClass = tableClass[_baseClass->nameClassParent->const1->utf8];
				ConstClass * _methBaseClass = find_Utf8_InTableConstClass(_baseClass->tableConstClass, _baseNameMeth->utf8);
				ConstClass * _descrBaseMeth = find_Utf8_InTableConstClass(_baseClass->tableConstClass, QString("(%1)L").arg(SemanticIdintifierListTable(expr->expr_List)) + parentClass + ";");

				ConstClass * _descrMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,_descrBaseMeth->utf8);
				ConstClass * _nameMethod = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass, _baseNameMeth->utf8);
				ConstClass * _nameAndType = find_NameAndType_InTableConstClass(tableClass[currentClass]->tableConstClass, _nameMethod,_descrMethod);
				ConstClass *_class_name = find_Utf8_InTableConstClass(tableClass[currentClass]->tableConstClass,_baseClass->nameClass->const1->utf8);
				ConstClass *_class = find_Class_InTableConstClass(tableClass[currentClass]->tableConstClass,_class_name);
				ConstClass *methodRef = find_Methodref_InTableConstClass(tableClass[currentClass]->tableConstClass,_class,_nameAndType);
				expr->constClass = methodRef;
				SemanticExpressionListTable(expr->expr_List);
			}
			break;
		}
	}
	else
	{
		return;
	}
}	

// выводим  idintifer_list
QString SemanticIdintifierListTable(struct Expressions_list *id_l)
{
	struct Expression *id;
	if (!id_l)
		return "";
	QString result;	
	id = id_l->expr;
	while(id)
	{
		SemanticExpressionTable(id);
		id= id->next;
		result+="LBaseVarClass;";
	}
	  if(!result.isEmpty())
		return result;
	else
		return "";
}

// Генерирует код ошибки для всех методов базового класса - кроме main
QByteArray GenericErrorCode()
{
	// new Exception("Error");
	QByteArray arr;
	/*QDataStream streamB(&arr,QIODevice::WriteOnly);
	streamB << (unsigned char)187;		// NEW
	ConstClass * classUtf8 = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "java/lang/Exception");
	ConstClass * classC = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, classUtf8);
	
	streamB << (unsigned short) classC->num;
	
	streamB << (unsigned char) 89;		// DUP
	streamB << (unsigned char) 18;		// LDC
	classUtf8 = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "Error");
	classC = find_String_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, classUtf8);
	streamB << (unsigned char) classC->num;
	streamB << (unsigned char) 183;	// INVOKESPECIAL
	classUtf8 = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "java/lang/Exception");
	ConstClass * classClass = find_Class_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, classUtf8);
	classC = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, "<init>");
	ConstClass * typeC = find_Utf8_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,"(Ljava/lang/String;)V");
	ConstClass * nameAndTypeC = find_NameAndType_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass,classC,typeC);
	ConstClass * methodRef = find_Methodref_InTableConstClass(tableClass[GLOBAL_CLASS]->tableConstClass, classClass, nameAndTypeC);
	streamB << (unsigned short) methodRef->num;
	streamB << (unsigned char) 87; 	// POP
	streamB << (unsigned char) 1; 	// ACONST_NULL
	streamB << (unsigned char)176;	// ARETRUN
	//streamB << (unsigned char) 177;	// _RETURN*/
	return arr;
}

QList<LocalVar*> fromIdListToLocalVarList(Expressions_list* idList)
{
  QList<LocalVar*> result;
  Expression* id;
  int i=0;
  if(idList)
  {
      id = idList->expr;
	    while(id)
	    {
        LocalVar* param = new LocalVar;
        param->name=id->var->name_var;
        param->num=i++;
        result.append(param);
		    id= id->next;
	    }
  }
  return result;
}