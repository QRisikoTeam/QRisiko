#include "Gestore Servers.h"
#include "Costanti Nazioni.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtGui>

GestoreServers::GestoreServers(QObject *parent)
: QObject(parent)
,http(NULL)
{
	
}

void GestoreServers::getFile(const QUrl &url)
{
	errore=false;
	QNetworkRequest indirizzo(url);
	http=new QNetworkAccessManager(this);
	connect(http, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpDone(QNetworkReply*)));
	http->get(indirizzo);
	qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
}
void GestoreServers::httpDone(QNetworkReply* reply)
{
	QString fetched("");
	if (reply->error() != QNetworkReply::NoError) {
		emit erroreConnessione();
		errore=true;
	}
	else{
		QUrl redirectUrl=reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
		if (!redirectUrl.isEmpty() && redirectUrl!=OldUrl){
			OldUrl=redirectUrl;
			getFile(OldUrl);
		}
		else{
			QTextStream in(reply);
			while(!in.atEnd()) {
				fetched.append(in.readLine());   
				fetched.append('\n');
			}
		}
	}
	http->deleteLater();
	qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
	emit done(fetched);
}
void GestoreServers::AddIP(){
	OldUrl=QUrl(Giocatori::PathToHttpServer+"/AggiungiIP.php");
	getFile(OldUrl);
}
void GestoreServers::RemoveIP(){
	OldUrl=QUrl(Giocatori::PathToHttpServer+"/RimuoviIP.php");
	getFile(OldUrl);
}
void GestoreServers::OttieniLista(){
	OldUrl=QUrl(Giocatori::PathToHttpServer+"/ElencoServers.txt");
	getFile(OldUrl);
	connect (this,SIGNAL(done(QString)),this,SLOT(FormServerList(QString)));
}

void GestoreServers::FormServerList(QString fet){
	if (!errore) emit ListaOttenuta(fet);
	disconnect(this,SIGNAL(done(QString)),this,SLOT(FormServerList(QString)));
}
void GestoreServers::OttieniIP(){
	OldUrl=QUrl(Giocatori::PathToHttpServer+"/GetIP.php");
	getFile(OldUrl);
	connect (this,SIGNAL(done(QString)),this,SLOT(FormIP(QString)));
}
void GestoreServers::FormIP(QString fet){
	if (!errore) emit IPOttenuto(fet);
	disconnect(this,SIGNAL(done(QString)),this,SLOT(FormIP(QString)));
}

void GestoreServers::NotResponding(QString ipnr){
	OldUrl=QUrl(Giocatori::PathToHttpServer+"/NotResponding.php");
	OldUrl.addQueryItem("IPNotResponding",ipnr);
	QString test1=OldUrl.toString();
	getFile(OldUrl);
}