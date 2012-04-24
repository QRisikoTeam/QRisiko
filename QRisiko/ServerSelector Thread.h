#ifndef SERVERSELECTORTHREAD_H
#define SERVERSELECTORTHREAD_H
#include <QThread>
#include <QStringList>
#include <QTcpSocket>
#include "Costanti Nazioni.h"

class ServerSelectorThread : public QThread
{
	Q_OBJECT
	public:
		ServerSelectorThread(const QStringList& Lista, unsigned int Port=Comunicazioni::DefaultTCPPort, QObject *parent=0);
		void run();
		void SetTimeout(const int& to){TimeoutTime=to;}
		int GetTimeout() const {return TimeoutTime;}
		void SetPorta(const unsigned int& por){Porta=por;}
		unsigned int GetPorta() const {return Porta;}
	public slots:
		void stop();
	signals:
		void InfoRicevute(QString N, int GioOnline, int MaxGio, QString IP);
		void finito();
	private:
		unsigned int Porta;
		bool keepRunning;
		bool Prossimo;
		QTcpSocket* socket;
		QStringList ListaIPs;
		QString currentIP;
		int TimeoutTime;
	private slots:
		void Skip(){
			Prossimo=true;
		}
		void Connesso();
		void ErroreConnessione();
		void OttieniInfo();
};


#endif