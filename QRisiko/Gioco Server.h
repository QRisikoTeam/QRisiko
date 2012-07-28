#ifndef GIOCOSERVER_H
#define GIOCOSERVER_H
#include <QTcpServer>
#include <QList>
#include <QMap>
#include "Gioco Thread.h"
#include "Costanti Nazioni.h"
#include "Gestore Servers.h"

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
	void SegnalaGiocatoreServer(){emit (NuovaConnessione(Comunicazioni::ServerID));}
private:
	void incomingConnection(int socketId);
	int TrovaIndice(int ident);
	void ControllaAvvio();
	QList<GiocoThread*> clients;
	QString NomeServer;
	int MaxGiocatori;
	int NumGiocatori;
	QList<int> IDs;
	QList<QString> Nomi;
	QList<int> Colori;
	QList<bool> Pronti;
	QList<bool> ToCheck;
	bool FasePrePartita;
	GestoreServers* Pubblicatore;
	QMap<int,int> contatore;
signals:
	void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
	void NuovaConnessione(int Ident);
	void UpdateInfo(int ident,const QString& nuovonome,int nuovocolore);
	void IsReady(int ident);
	void IsNotReady(int ident);
	void StartGame();
	void Disconnesso(int ident);
	void MandaInfoA(int destinazione, int ident, QString nome, int colore);
	void IsPronto(int ident);
private slots:
	void FormaInfo(int SoDe);
	void AggiungiPronto(int ident);
	void RimuoviPronto(int ident);
	void GiocatoreDisconnesso(int ident);
	void ImpostaPartitaIniziata(){FasePrePartita=false;}
	void ImpostaChecks(int ident,const QString& nuovonome,int nuovocolore);
	void ContinuaInvio(int destinazione);
public slots:
	void WantsToJoin(int ident);
	void GotHisID(int ident);
	void ServerPronto(){emit IsReady(Comunicazioni::ServerID);}
	void ServerNonPronto(){emit IsNotReady(Comunicazioni::ServerID);}
	void CambiateInfoServer(QString NuovoNome, int NuovoColore){emit UpdateInfo(Comunicazioni::ServerID,NuovoNome,NuovoColore);}
	void Termina();
	

};

#endif