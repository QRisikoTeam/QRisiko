#ifndef GETIP_H
#define GETIP_H
#include <QNetworkAccessManager>
#include <QUrl>
#include <QFile>

class GestoreServers : public QObject
{
	Q_OBJECT
	public:
		GestoreServers(QObject *parent = 0);
		void AddIP();
		void RemoveIP();
		void OttieniLista();
		void OttieniIP();
		void NotResponding(QString ipnr);
	signals:
		void done(QString fet);
		void ListaOttenuta(QString lis);
		void IPOttenuto(QString IP);
		void erroreConnessione();
	private slots:
		void httpDone(QNetworkReply* reply);
		void FormServerList(QString fet);
		void FormIP(QString fet);
	private:
		bool errore;
		void getFile(const QUrl &url);
		QNetworkAccessManager* http;
		QFile file;
		QUrl OldUrl;
};
#endif