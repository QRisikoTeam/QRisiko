#ifndef GETIP_H
#define GETIP_H
#include <QHttp>
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
		void done();
		void ListaOttenuta(QString lis);
		void IPOttenuto(QString IP);
	private slots:
		void httpDone(bool error);
		void FormServerList();
		void FormIP();
	private:
		bool errore;
		bool ToDelete;
		void getFile(const QUrl &url);
		QHttp http;
		QFile file;
};
#endif