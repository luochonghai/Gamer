#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//����ʾ����
#include "stdafx.h"
#include "SE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	Py_Initialize();
	QApplication a(argc, argv);
	SE w;
	w.show();
	return a.exec();
}
