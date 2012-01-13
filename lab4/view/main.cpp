#include <QtGui/QApplication>
#include "viewxml.h"

/*
	1. ������� �������.
		1.1. ������� �������� ������.
			1.1.1. ������� �������.
			1.1.1.1. ������� ��������� ����������.
		1.1.2. ������� �����.
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ViewXML w;
	w.show();
	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	return a.exec();
}
