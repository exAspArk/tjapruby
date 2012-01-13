#include <QtGui/QApplication>
#include "viewxml.h"

/*
	1. Таблица классов.
		1.1. Таблица констант класса.
			1.1.1. Таблица методов.
			1.1.1.1. Таблица локальных переменных.
		1.1.2. Таблица полей.
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ViewXML w;
	w.show();
	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	return a.exec();
}
