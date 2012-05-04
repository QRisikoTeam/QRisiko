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
	void stop();
	void SendInfo(QString Nome, int Giocatori, int MaxGiocatori){emit InviaInformazioni(Nome,Giocatori,MaxGiocatori);}
signals:
	void GotRichiediInfo(int iden);
	void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
private:
	bool keepRunning;
	int socketDescriptor;
	QString text;
	GiocoSocket* socket;
private slots:
	void IdentificaInfoReq(){emit GotRichiediInfo(socketDescriptor);}
};


#endif