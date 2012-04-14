#include "Chat Widget.h"
#include <QtGui/QApplication>
#define QT_NO_TOOLTIP


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatWidget w(0,"Il Beldus",QColor("#0000FF"),true,true/*false,"192.168.1.3"*/);
	w.Avvia();
	w.show();
	return a.exec();
}