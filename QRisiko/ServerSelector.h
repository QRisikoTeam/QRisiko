#ifndef SERVERSELECTOR_H
#define SERVERSELECTOR_H
#include <QWidget>
#include <QFrame>
#include <QResizeEvent>
#include "ui_ServerLister.h"
#include "Gestore Servers.h"
#include "ServerSelector Thread.h"

class ServerSelector : public QWidget, public Ui::ServerLister{
	Q_OBJECT
	public:
		ServerSelector(QWidget* parent=0);
	private:
		QFrame* Sfondo;
		GestoreServers* ListGetter;
		ServerSelectorThread* Parallelo;
		bool manual;
		bool primaVolta;
	public slots:
		void Avvia();
	private slots:
		void AvviaScansione(QString IPs);
		void Popola(QString N, int GioOnline, int MaxGio, QString IP);
		void OttieniIpSelezionato();
		void NoConnection();
		void DaTabella(){manual=false;}
		void DaManuale(){manual=true;}
	protected:
		void resizeEvent(QResizeEvent * event);
		void keyPressEvent(QKeyEvent *keyev);
	signals:
		void Ferma();
		void Selezionato(QString IP);
		void Annullato();
};
#endif