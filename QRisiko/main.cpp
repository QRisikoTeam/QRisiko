#include "MainWindow.h"
#include "Costanti Nazioni.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.showFullScreen();
	return a.exec();
}