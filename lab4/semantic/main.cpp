
#include <QtCore/QCoreApplication>
#include "semanticTree.h"
#include "treePrint.h"

int main(int argc, char *argv[])
{
	struct Program *new_root;
	QCoreApplication a(argc, argv);
	start(argc,argv);

	new_root = semantic(prg);

	return a.exec();
}
