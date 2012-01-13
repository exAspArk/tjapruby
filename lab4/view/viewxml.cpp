#include "viewxml.h"

ViewXML::ViewXML(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	on_action_triggered();
	QFile file("tjap.pain");

	if(file.open(QIODevice::ReadOnly))
	{
		QDataStream stream(&file);
		stream >> tableClass;
		file.close();
	}

	QList<QString> keys = tableClass.keys();
	ClassItem item;
	ui.tw_table_classes->setRowCount(keys.size());
	for(int i=0;i<keys.size();i++)
	{
		item = tableClass[keys[i]];
		ui.comboClass->addItem(item.nameClass.const1->utf8);
		//ui.comboClass->addItem(item.nameClassParent.const1 ? item.nameClassParent.const1->utf8 : "");
		ui.tw_table_classes->setItem(i,0,new QTableWidgetItem(item.nameClass.const1->utf8));
		ui.tw_table_classes->setItem(i,1,new QTableWidgetItem(item.nameClassParent.const1 ? item.nameClassParent.const1->utf8 : ""));
	}
	connect(ui.comboClass,SIGNAL(currentIndexChanged(int)),this,SLOT(on_changedComboClass(int)));
	connect(ui.tw_table_classes,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(chooseClass(int)));
	connect(ui.tw_table_classes_method,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(chooseMethod(int)));
	ui.comboClass->setCurrentIndex(0);
    on_changedComboClass(0);
	ui.tw_table_classes->setVisible(false);
	//connect(ui.tw_table_classes_2,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(chooseMethod(int)));
}

void ViewXML::on_changedComboClass(int index)
{
	chooseClass(index);
	QString currentClass = ui.comboClass->itemText(index);
	ClassItem item = this->tableClass[currentClass];
	ui.labelParentClass->setText(item.nameClassParent.const1 ? item.nameClassParent.const1->utf8 : "");

}
ViewXML::~ViewXML()
{

}
void ViewXML::on_action_triggered()
{
	tableClass.clear();
  ui.curClass->clear();
  ui.curMethod->clear();
	ui.tw_table_classes_method->clearSelection();
	ui.tw_table_classes_method->setRowCount(0);
	
	ui.tw_table_classes->clearSelection();
	ui.tw_table_classes->setRowCount(0);

	ui.tw_table_class_const_var->clearSelection();
	ui.tw_table_class_const_var->setRowCount(0);

	ui.tw_table_local_var->clearSelection();
	ui.tw_table_local_var->setRowCount(0);
	
	ui.tw_table_class_fields->clearSelection();
	ui.tw_table_class_fields->setRowCount(0);
	QFile file("tjap.chexov");

	if(file.open(QIODevice::ReadOnly))
	{
		QDataStream stream(&file);
		stream >> tableClass;
		file.close();
	}

	QList<QString> keys = tableClass.keys();
	ClassItem item;
	ui.tw_table_classes->setRowCount(keys.size());
	for(int i=0;i<keys.size();i++)
	{
		item = tableClass[keys[i]];
		ui.tw_table_classes->setItem(i,0,new QTableWidgetItem(item.nameClass.const1->utf8));
		ui.tw_table_classes->setItem(i,1,new QTableWidgetItem(item.nameClassParent.const1 ? item.nameClassParent.const1->utf8 : ""));
	}
}
void ViewXML::chooseClass(int line)
{
	// если попали в границы, 
	// то выводим во все таблицы
	if (line>=0 && line <tableClass.size())
	{
		QString tmp=ui.tw_table_classes->item(line,0)->text();
		ClassItem classitem = tableClass[tmp];
		ui.curClass->setText(tmp);
		QList<ConstClass> ConstTable = classitem.tableConstClass;
		//ui.tw_table_classes->setRowCount(ConstTable.size());

		// выводим в таблицу констант
		PrintInTableClassConstant(ConstTable);

		// output in table "field"
		PrintInTableField(classitem.tablePoleClass);
		
		//PrintInTableLocalVar(classitem.tableMethodClass[i].tableLocalVar);
		/*ui.tw_table_class_const_var->setRowCount(classitem.tableConstInClass.size());
		for(int i=0;i<classitem.tableConstInClass.size();i++)
		{
			ui.tw_table_class_const_var->setItem(i,0,new QTableWidgetItem(QString("%1").arg(classitem.tableConstInClass[i].num)));
			ui.tw_table_class_const_var->setItem(i,2,new QTableWidgetItem(classitem.tableConstInClass[i].isStatic ? "true" : "false"));
			ui.tw_table_class_const_var->setItem(i,3,new QTableWidgetItem(classitem.tableConstInClass[i].name.utf8));
			ui.tw_table_class_const_var->setItem(i,4,new QTableWidgetItem(classitem.tableConstInClass[i].descriptor.utf8));
		}*/
		
		// output in table "Method"
		PrintInTableMethod(classitem.tableMethodClass);
		/*QList<ClassVar> ObjTable = classitem.tableClassVar;
		ClassVar var;
		//ui.tw_table_class_fields->setRowCount(ObjTable.size());
		for(int i=0;i<ObjTable.size();i++)
		{
			var = ObjTable[i];
			
			ui.tw_table_class_fields->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
			switch (var.level)
			{
			case Public:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Public"));
				break;
			case Protected:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Protected"));
				break;
			case Private:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Private"));
				break;
			}
			
			ui.tw_table_class_fields->setItem(i,2,new QTableWidgetItem(var.name));
			ui.tw_table_class_fields->setItem(i,3,new QTableWidgetItem(QString("%1").arg(var.posFirst)));
			ui.tw_table_class_fields->setItem(i,4,new QTableWidgetItem(QString("%1").arg(var.posLast)));
		}
		QList<ObjectVar> ObjTable = classitem.tableObjectVar;
		ObjectVar var;
		ui.tw_table_class_fields->setRowCount(ObjTable.size());
		for(int i=0;i<ObjTable.size();i++)
		{
			var = ObjTable[i];
			
			ui.tw_table_class_fields->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
			switch (var.level)
			{
			case Public:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Public"));
				break;
			case Protected:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Protected"));
				break;
			case Private:
				ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem("Private"));
				break;
			}
			
			ui.tw_table_class_fields->setItem(i,2,new QTableWidgetItem(var.name));
			ui.tw_table_class_fields->setItem(i,3,new QTableWidgetItem(QString("%1").arg(var.posFirst)));
			ui.tw_table_class_fields->setItem(i,4,new QTableWidgetItem(QString("%1").arg(var.posLast)));
		}*/
	}
}

void ViewXML::chooseMethod(int row)
{
	if(row>=0)
	{
		//QString tmp = ui.tw_table_local_var->item(ui.tw_table_local_var->currentRow(),0)->text();
		//ClassItem classitem = tableClass[ui.tw_table_local_var->item(ui.tw_table_local_var->currentRow(),0)->text()];
		QString tmp = ui.comboClass->itemText(ui.comboClass->currentIndex()); //ui.tw_table_classes->item(ui.tw_table_classes->currentRow(),0)->text();
    ui.curMethod->setText(ui.tw_table_classes_method->item(ui.tw_table_classes_method->currentRow(),3)->text());
		LocalVar loc;
		//ui.tw_table_classes_method->item(ui.tw_table_classes_method->currentRow(),3)->text();
		ClassItem classitem = tableClass[tmp];
		MethodClass method = classitem.tableMethodClass[row];
		int s = method.tableLocalVar.size();
		/*if(row < 0 || row >= method.tableLocalVar.size())
		{
			ui.tw_table_local_var->setRowCount(0);
			return;
		}*/
		if(method.tableLocalVar.size() == 0)
		{
			ui.tw_table_local_var->setRowCount(0);
			return;
		}
		// выводим локальные переменные метода
		ui.tw_table_local_var->setRowCount(method.tableLocalVar.size());
		for(int i=0;i<method.tableLocalVar.size();i++)
		{
			loc = method.tableLocalVar[i];
			ui.tw_table_local_var->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
			ui.tw_table_local_var->setItem(i,1,new QTableWidgetItem(method.tableLocalVar[i].name));
			/*ui.tw_table_local_var->setItem(i,2,new QTableWidgetItem(QString("%1").arg(method.tableLocalVar[i].posFirst)));
			ui.tw_table_local_var->setItem(i,3,new QTableWidgetItem(QString("%1").arg(method.tableLocalVar[i].posLast)));*/
		}


	}
}



QDataStream & operator >> (QDataStream &stream, ClassItem &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item = ClassItem();
		return stream;
	}
	int access;
	stream >> access;
	item.access = (RuleOfAccess)access;
	stream >> item.nameClass;
	stream >> item.nameClassParent;
	stream >> item.tableConstClass;
	stream >> item.tableConstInClass;
	stream >> item.tableMethodClass;
	stream >> item.tablePoleClass;

	stream >> item.tableObjectVar;
	stream >> item.tableGLobalVar;
	stream >> item.tableClassVar;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, MethodClass &method)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		method = MethodClass();
		return stream;
	}
	stream >> method.descriptor;
	stream >> method.isStatic;
	int level;
	stream >> level;
	method.level = (RuleOfAccess)level;
	stream >> method.name;
	stream >> method.num;
	stream >> method.tableLocalVar;
	stream >> method.tableConstanVar;
  stream >> method.tableParam;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, LocalVar &var)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		var =  LocalVar();
		return stream;
	}
	stream >> var.num;
	stream >> var.name;
	stream >> var.posFirst;
	stream >> var.posLast;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, ConstInClass &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item = ConstInClass();
		return stream;
	}
	stream >> item.descriptor;
	stream >> item.isStatic;
	int level;
	stream >> level;
	item.level = (RuleOfAccess)level;
	stream >> item.name;
	stream >> item.num;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, FieldClass &pole)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		pole = FieldClass();
		return stream;
	}
	stream >> pole.descriptor;
	stream >> pole.isStatic;
	int level;
	stream >> level;
	pole.level = (RuleOfAccess)level;
	stream >> pole.name;
	stream >> pole.num;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, ConstClass &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item =  ConstClass();
		return stream;
	}
	item.const1 = new ConstClass();
	stream >> *item.const1;
	item.const2 = new ConstClass();
	stream >> *item.const2;
	stream >> item.const_Float;
	stream >> item.const_Int;
	stream >> item.const_Bool;
	stream >> item.num;
	int type;
	stream >> type;
	item.type = (TypeConstClass)type;
	stream >> item.utf8;
	return stream;
}


QDataStream & operator >> (QDataStream &stream, ConstantVar &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item =  ConstantVar();
		return stream;
	}
	stream >> item.isStatic;
	int level;
	stream >> level;
	item.level = (RuleOfAccess)level;
	stream >> item.name;
	stream >> item.posFirst;
	stream >> item.posLast;
	return stream;
}

QDataStream & operator >> (QDataStream &stream, ObjectVar &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item =  ObjectVar();
		return stream;
	}
	int level;
	stream >> level;
	item.level = (RuleOfAccess)level;
	stream >> item.name;
	stream >> item.posFirst;
	stream >> item.posLast;
	return stream;
}
QDataStream & operator >> (QDataStream &stream, ClassVar &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item =  ClassVar();
		return stream;
	}
	int level;
	stream >> level;
	item.level = (RuleOfAccess)level;
	stream >> item.name;
	stream >> item.posFirst;
	stream >> item.posLast;
	return stream;
}

QDataStream & operator >> (QDataStream &stream, GlobalVar &item)
{
	int flag;
	stream >> flag;
	if(flag == 0)
	{
		item =  GlobalVar();
		return stream;
	}
	int level;
	stream >> level;
	item.level = (RuleOfAccess)level;;
	stream >> item.name;
	stream >> item.posFirst;
	stream >> item.posLast;
	return stream;
}

// ==================================================================
// =============== ВЫВОДИМ В ТАБЛИЦУ КОНСТАНТ КЛАССА ================
// ==================================================================
void ViewXML::PrintInTableClassConstant(QList<ConstClass> ConstTable)
{
	// в tw_table_class_const_var
	ConstClass tmp;
	int count = ConstTable.size();
	ui.tw_table_class_const_var->setRowCount(count);
	for (int i=0; i<ConstTable.size();i++)
		{
			tmp = ConstTable[i];
			ui.tw_table_class_const_var->setItem(i,0,new QTableWidgetItem(QString("%1").arg(ConstTable[i].num)));
			QString str1,str2;
			switch(ConstTable[i].type)
			{
			case CONSTANT_Utf8: 
				str1="CONSTANT_Utf8"; 
				str2=ConstTable[i].utf8;
				break;
			case CONSTANT_Integer:
				str1="CONSTANT_Integer"; 
				str2=QString("%1").arg(ConstTable[i].const_Int);
				break;
			case CONSTANT_Float:
				str1="CONSTANT_Float"; 
				//str2=QString("%1").arg(classitem.tableConstClass[i].const_Float);
				str2 = QString("%1").arg(ConstTable[i].const_Float,0,'f',5);
				break;
			case CONSTANT_String:
				str1="CONSTANT_String"; 
				str2=QString("%1").arg(ConstTable[i].const1->num);
				break;
			case CONSTANT_NameAndType:
				str1="CONSTANT_NameAndType"; 
				str2=QString("%1,%2").arg(ConstTable[i].const1->num).arg(ConstTable[i].const2->num);
				break;
			case CONSTANT_Class:
				str1="CONSTANT_Class"; 
				str2=QString("%1").arg(ConstTable[i].const1->num);
				break;
			case CONSTANT_Fieldref:
				str1="CONSTANT_Fieldref"; 
				str2=QString("%1,%2").arg(ConstTable[i].const1->num).arg(ConstTable[i].const2->num);
				break;
			case CONSTANT_Methodref:
				str1="CONSTANT_Methodref"; 
				str2=QString("%1,%2").arg(ConstTable[i].const1->num).arg(ConstTable[i].const2->num);
				break;
			case CONSTANT_Bool:
				str1="CONSTANT_Bool";
				if(ConstTable[i].const_Bool)
				{
					str2 = "true";
				}
				else
					str2 = "false";
				//str2=QString("%1").arg(QString::(ConstTable[i].const_Bool));
				break;
			}
			ui.tw_table_class_const_var->setItem(i,1,new QTableWidgetItem(str1));
			ui.tw_table_class_const_var->setItem(i,2,new QTableWidgetItem(str2));
		}
}

// =========================================================
// =========================================================
void ViewXML::PrintInTableField(QList<FieldClass> FieldClass)
{
	QString tmp;
	ui.tw_table_class_fields->setRowCount(FieldClass.size());
	for (int i=0;i<FieldClass.size();i++)
	{
		ui.tw_table_class_fields->setItem(i,0,new QTableWidgetItem(QString("%1").arg(FieldClass[i].num)));
		QString str;
		switch(FieldClass[i].level)
		{
		case Public:
			str="Public";
			break;
		case Protected:
			str="Protected";
			break;
		case Private:
			str="Private";
			break;
		}
		ui.tw_table_class_fields->setItem(i,1,new QTableWidgetItem(str));
		tmp = FieldClass[i].name.utf8;
		ui.tw_table_class_fields->setItem(i,2,new QTableWidgetItem(FieldClass[i].name.utf8));
		/*FieldClass[i].isStatic ? tmp = "true" : tmp ="false";
		ui.tw_table_class_fields->setItem(i,3,new QTableWidgetItem(FieldClass[i].isStatic ? "true" : "false"));
		tmp = FieldClass[i].descriptor.utf8;
		ui.tw_table_class_fields->setItem(i,4,new QTableWidgetItem(FieldClass[i].descriptor.utf8));*/
	}
}

// =========================================================
// =========================================================
void ViewXML::PrintInTableMethod(QList<MethodClass> MethodClass)
{
	QString tmp;
	ui.tw_table_classes_method->setRowCount(MethodClass.size());
	for(int i=0;i<MethodClass.size();i++)
	{
		tmp = QString("%1").arg(MethodClass[i].num);
		ui.tw_table_classes_method->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
		QString str;
		switch(MethodClass[i].level){
			case Public:
				str="Public";
				break;
			case Protected:
				str="Protected";
				break;
			case Private:
				str="Private";
				break;
		}
		ui.tw_table_classes_method->setItem(i,1,new QTableWidgetItem(str));
		MethodClass[i].isStatic ? tmp = "true" : tmp = "false";
		ui.tw_table_classes_method->setItem(i,2,new QTableWidgetItem(MethodClass[i].isStatic ? "true" : "false"));
		tmp = MethodClass[i].name.utf8;
		ui.tw_table_classes_method->setItem(i,3,new QTableWidgetItem(MethodClass[i].name.utf8));
		tmp = MethodClass[i].descriptor.utf8;
		ui.tw_table_classes_method->setItem(i,4,new QTableWidgetItem(MethodClass[i].descriptor.utf8));
	}
}
// =========================================================
// =========================================================
void ViewXML::PrintInTableLocalVar(QList<LocalVar> LocalVarClass)
{
	ui.tw_table_local_var->setRowCount(LocalVarClass.size());
	for(int i=0; i<LocalVarClass.size(); i++)
	{
		ui.tw_table_local_var->setItem(i,0,new QTableWidgetItem(QString("%1").arg(LocalVarClass[i].num)));
		ui.tw_table_local_var->setItem(i,1,new QTableWidgetItem(LocalVarClass[i].name));
		ui.tw_table_local_var->setItem(i,2,new QTableWidgetItem(QString("%1").arg(LocalVarClass[i].posFirst)));
		ui.tw_table_local_var->setItem(i,3,new QTableWidgetItem(QString("%1").arg(LocalVarClass[i].posLast)));
	}
}