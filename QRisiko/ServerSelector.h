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
	private slots:
		void AvviaScansione(QString IPs);
		void Popola(QString N, int GioOnline, int MaxGio, QString IP);
		void OttieniIpSelezionato();
	protected:
		void resizeEvent(QResizeEvent * event);
	signals:
		void Ferma();
		void Selezionato(QString IP);
		void Annullato();
};
#endif