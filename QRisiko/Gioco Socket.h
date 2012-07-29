#ifndef GIOCOSOCKET_H
#define GIOCOSOCKET_H
#include <QTcpSocket>
#include <QString>
class GiocoSocket : public QTcpSocket
{
	Q_OBJECT
	public:
		GiocoSocket(int soketDescriptor, QObject *parent = 0);
	private slots:
		void readClient();
	public slots:
		void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
		void MandaMioID(int ident);
		void NuovoUtente(int ident);
		void UpdateInfo(int ident,const QString& NuovoNome,int NuovoColore);
		void StartGame();
		void GiocatoreDisconnesso(int ident);
		void MandaInfoA(int destinazione, int ident, const QString& nome, int colore);
	private:
		quint16 nextBlockSize;
		int socketDescriptor;
	signals:
		void GotRichiediInfo();
		void CambiateInfo(int ident, const QString& NuovoNome, int NuovoColore);
		void GotAggiuntoArmate(int stato, int Num_Armate);
		void IsReady(int ident);
		void IsNotReady(int ident);
		void Disconnesso(int ident);
		void IWantToJoin(int ident);
		void RicevutoID(int ident);
};


#endif