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
	signals:
		void done();
		void ListaOttenuta(QString);
	private slots:
		void httpDone(bool error);
		void FormServerList();
	private:
		void getFile(const QUrl &url);
		QHttp http;
		QFile file;
};
#endif