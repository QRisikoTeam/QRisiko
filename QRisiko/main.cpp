#include "Chat Widget.h"
#include "temp.h"
#include <QtGui/QApplication>
#define QT_NO_TOOLTIP


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Player p1("Il Beldus", QColor("#0000FF"));
	ChatWidget w(0,p1);
	w.show();
	return a.exec();
}