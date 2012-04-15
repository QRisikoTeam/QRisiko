#include "Gestore Servers.h"
#include "Costanti Nazioni.h"

GestoreServers::GestoreServers(QObject *parent)
: QObject(parent)
{
	connect(&http, SIGNAL(done(bool)), this, SLOT(httpDone(bool)));
}

void GestoreServers::getFile(const QUrl &url)
{
	file.setFileName("Servers.txt");
	http.setHost(url.host(), url.port(80));
	http.get(url.path(), &file);
	http.close();
}
void GestoreServers::httpDone(bool error)
{
	if (error) QMessageBox::critical(this,tr("Errore"),tr("Errore durante la comunicazione con il server"));
	file.close();
	emit done();
}
void GestoreServers::AddIP(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/AggiungiIP.php"));
}
void GestoreServers::RemoveIP(){
	getFile(QUrl(Giocatori::PathToHttpServer+"/RimuoviIP.php"));
}
void GestoreServers::OttieniLista(){
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
	disconnect(this,SIGNAL(done()),this,SLOT(FormServerList()));
}
