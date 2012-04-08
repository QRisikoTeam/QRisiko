#include "qrisiko.h"
#include <QtGui/QApplication>
#define QT_NO_TOOLTIP

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QRisiko w;
	w.show();
	return a.exec();
}
