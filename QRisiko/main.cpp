#include "MainWindow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.showFullScreen();
	//w.show();
	return a.exec();
}