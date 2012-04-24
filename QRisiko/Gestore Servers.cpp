#include "Gestore Servers.h"
#include "Costanti Nazioni.h"
#include <QNetworkRequest>
#include <QNetworkReply>

GestoreServers::GestoreServers(QObject *parent)
: QObject(parent)
{
	connect(&http, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpDone(QNetworkReply*)));
}

void GestoreServers::getFile(const QUrl &url)
{
	errore=false;
	QNetworkRequest indirizzo(url);
	http.get(indirizzo);
}
void GestoreServers::httpDone(QNetworkReply* reply)
{
	QString fetched("");
	if (reply->error() != QNetworkReply::NoError) {
		emit erroreConnessione();
		errore=true;
	}
	else{
		QTextStream in(reply);
		while(!in.atEnd()) {
			fetched.append(in.readLine());   
			fetched.append('\n');
		}
	}
	emit done(fetched);
}
void GestoreServers::AddIP(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/AggiungiIP.php"));
}
void GestoreServers::RemoveIP(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/RimuoviIP.php"));
}
void GestoreServers::OttieniLista(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/ElencoServers.txt"));
	connect (this,SIGNAL(done(QString)),this,SLOT(FormServerList(QString)));
}

void GestoreServers::FormServerList(QString fet){
	if (!errore) emit ListaOttenuta(fet);
	disconnect(this,SIGNAL(done(QString)),this,SLOT(FormServerList(QString)));
}
void GestoreServers::OttieniIP(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/GetIP.php"));
	connect (this,SIGNAL(done(QString)),this,SLOT(FormIP(QString)));
}
void GestoreServers::FormIP(QString fet){
	if (!errore) emit IPOttenuto(fet);
	disconnect(this,SIGNAL(done(QString)),this,SLOT(FormIP(QString)));
}

void GestoreServers::NotResponding(QString ipnr){
	QUrl url(Giocatori::PathToHttpServer+"/NotResponding.php");
	url.addQueryItem("IPNotResponding",ipnr);
	QString test1=url.toString();
	getFile(url);
}