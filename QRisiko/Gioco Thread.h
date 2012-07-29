#ifndef GIOCOTHREAD_H
#define GIOCOTHREAD_H
#include <QThread>
#include <QString>
#include "Gioco Socket.h"

class GiocoThread : public QThread
{
	Q_OBJECT
public:
	GiocoThread(int soketDescriptor, QObject *parent);
	void run();
	int GetSocketDescriptor() const {return socketDescriptor;}
	void SendInfo(QString Nome, int Giocatori, int MaxGiocatori){emit InviaInformazioni(Nome,Giocatori,MaxGiocatori);}
signals:
	void GotRichiediInfo(int iden);
	void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
	void MandaMioID(int);
	void NuovoUtente(int);
	void CambiateInfo(int ident, const QString& NuovoNome, int NuovoColore);
	void UpdateInfo(int ident, const QString& NuovoNome, int NuovoColore);
	void IsReady(int ident);
	void IsNotReady(int ident);
	void StartGame();
	void Disonnesso(int ident);
	void GiocatoreDisconnesso(int ident);
	void IWantToJoin(int ident);
	void MandaInfoA(int destinazione, int ident, QString nome, int colore);
	void RicevutoID(int ident);
private:
	int socketDescriptor;
	QString text;
	GiocoSocket* socket;
private slots:
	void IdentificaInfoReq(){emit GotRichiediInfo(socketDescriptor);}
public slots:
	void stop();
	void ForzaDisconnessione();
};


#endif