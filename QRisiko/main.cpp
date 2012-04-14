#include "MainWindow.h"
#include "Costanti Nazioni.h"
#include <QtGui/QApplication>
#define QT_NO_TOOLTIP

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
