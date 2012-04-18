#include "Gestore Servers.h"
#include "Costanti Nazioni.h"
#include <QMessageBox>

GestoreServers::GestoreServers(QObject *parent)
: QObject(parent)
{
	connect(&http, SIGNAL(done(bool)), this, SLOT(httpDone(bool)));
	ToDelete=false;
}

void GestoreServers::getFile(const QUrl &url)
{
	file.setFileName("TempServerList.txt");
	http.setHost(url.host(), url.port(80));
	http.get(url.path(), &file);
	http.close();
}
void GestoreServers::httpDone(bool error)
{
	if (error) QMessageBox::critical(0,tr("Errore"),tr("Errore durante la comunicazione con il server"));
	file.close();
	if (ToDelete) file.remove();
	emit done();
}
void GestoreServers::AddIP(){
	ToDelete=true;
	getFile(QUrl(Giocatori::PathToHttpServer+"/AggiungiIP.php"));
}
void GestoreServers::RemoveIP(){
	ToDelete=true;
	getFile(QUrl(Giocatori::PathToHttpServer+"/RimuoviIP.php"));
}
void GestoreServers::OttieniLista(){
	ToDelete=false;
	getFile(QUrl(Giocatori::PathToHttpServer+"/ElencoServers.txt"));
	connect (this,SIGNAL(done()),this,SLOT(FormServerList()));
}

void GestoreServers::FormServerList(){
	QString ServerList("");
	if(file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);
		while(!in.atEnd()) {
			ServerList.append(in.readLine());        	
		}
	}
	file.close();
	emit ListaOttenuta(ServerList);
	file.remove();
	disconnect(this,SIGNAL(done()),this,SLOT(FormServerList()));
}
void GestoreServers::OttieniIP(){
	ToDelete=false;
	getFile(QUrl(Giocatori::PathToHttpServer+"/GetIP.php"));
	connect (this,SIGNAL(done()),this,SLOT(FormIP()));
}
void GestoreServers::FormIP(){
	QString ServerList("");
	if(file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);
		while(!in.atEnd()) {
			ServerList.append(in.readLine());        	
		}
	}
	file.close();
	emit IPOttenuto(ServerList);
	file.remove();
	disconnect(this,SIGNAL(done()),this,SLOT(FormIP()));
}