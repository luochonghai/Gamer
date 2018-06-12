#include "stdafx.h"
#include "SE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SE w;
	w.show();
	return a.exec();
}
