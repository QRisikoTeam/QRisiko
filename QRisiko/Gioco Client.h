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
		void RicevutoID();
		void SonoProntoARicevere();
	public:
		ClientGioco(const QString& HIP=QString("127.0.0.1"),int por=Comunicazioni::DefaultTCPPort,QObject* parent=0);
		QString GetHostIP() const{return HostIP;}
		void SetHostIP(const QString& a){HostIP=a;}
		int GetPort() const{return Porta;}
		void SetPort(const int& a){Porta=a;}
	public slots:
		void Connetti();
		void Disconnetti();
		void CambiateMieInfo(const QString& NuovoNome, int NuovoColore);
		void SonoPronto();
		void NonSonoPronto();
		void IWantToJoin();
	signals:
		void Connesso();
		void Disconnesso();
		void NuovoGiocatore(int);
		void AggiornaInfo(int ident, const QString& NuovoNome, int NuovoColore);
		void StartGame();
		void GiocatoreDisconnesso(int ident);
		void MyIDIs(int idnet);
	private slots:
		void IncomingTransmission();
	
};
#endif