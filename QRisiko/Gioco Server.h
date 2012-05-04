#ifndef GIOCOSERVER_H
#define GIOCOSERVER_H
#include <QTcpServer>
#include <QList>
#include <QTcpServer>
#include "Gioco Thread.h"

class GiocoServer : public QTcpServer
{
	Q_OBJECT
	Q_PROPERTY(QString NomeServer READ GetNomeServer WRITE SetNomeServer)
	Q_PROPERTY(int MaxGiocatori READ GetMaxGiocatori WRITE SetMaxGiocatori)
public:
	GiocoServer(QObject *parent = 0);
	GiocoServer(const QString& Nome, const int& MaxPl, QObject *parent = 0);
	void SetNomeServer(const QString& Nome){NomeServer=Nome;}
	QString GetNomeServer() const {return NomeServer;}
	void SetMaxGiocatori(const int& MaxPl){MaxGiocatori=MaxPl;}
	int GetMaxGiocatori() const {return MaxGiocatori;}
private:
	void incomingConnection(int socketId);
	QList<GiocoThread*> clients;
	QString NomeServer;
	int MaxGiocatori;
	int NumGiocatori;
signals:
	void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
private slots:
	void FormaInfo(int SoDe);

};

#endif