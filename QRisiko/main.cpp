#include "qrisiko.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QRisiko w;
	w.show();
	return a.exec();
}
