#ifndef GIOCOCLIENT_H
#define GIOCOCLIENT_H
#include <QTcpSocket>
#include "Costanti Nazioni.h"
class ClientGioco : public QObject{
	Q_OBJECT
	Q_PROPERTY(QString HostIP READ GetHostIP WRITE SetHostIP)
	Q_PROPERTY(int Porta READ GetPort WRITE SetPort)
	private:
		QTcpSocket Cliente;
		QString HostIP;
		int Porta;
		int MyID;
		quint16 nextBlockSize;
	public:
		ClientGioco(QString& HIP=QString("127.0.0.1"),int por=Comunicazioni::DefaultTCPPort,QObject* parent=0);
		QString GetHostIP() const{return HostIP;}
		void SetHostIP(const QString& a){HostIP=a;}
		int GetPort() const{return Porta;}
		void SetPort(const int& a){Porta=a;}
	public slots:
		void Connetti();
		void Disconnetti();
		void CambiateMieInfo(const QString& NuovoNome, int NuovoColore);
	signals:
		void Connesso();
		void Disconnesso();
		void NuovoGiocatore(int);
		void AggiornaInfo(int ident, const QString& NuovoNome, int NuovoColore);
	private slots:
		void IncomingTransmission();
	
};
#endif