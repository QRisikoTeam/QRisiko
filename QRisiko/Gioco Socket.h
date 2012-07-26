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
		void Disconnessione() {emit Disconnesso(socketDescriptor);}
	public slots:
		void InviaInformazioni(QString Nome, int Giocatori, int MaxGiocatori);
		void MandaMioID(int ident);
		void NuovoUtente(int ident);
		void UpdateInfo(int ident,const QString& NuovoNome,int NuovoColore);
		void StartGame();
		void GiocatoreDisconnesso(int ident);
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
};


#endif