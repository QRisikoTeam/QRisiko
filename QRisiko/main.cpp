#include "MainWindow.h"
#include <QtGui/QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSplashScreen *splash=new QSplashScreen;
	splash->setPixmap(QPixmap(":/Generale/Simbolo.png"));
	splash->show();
	splash->showMessage(QObject::tr("Caricamento..."),Qt::AlignBottom | Qt::AlignHCenter);
	MainWindow w;
	w.showFullScreen();
	//w.show();
	splash->finish(&w);
	delete splash;
	return a.exec();
}