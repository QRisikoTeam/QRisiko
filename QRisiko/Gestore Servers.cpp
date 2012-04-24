#include "Gestore Servers.h"
#include "Costanti Nazioni.h"

GestoreServers::GestoreServers(QObject *parent)
: QObject(parent)
{
	connect(&http, SIGNAL(done(bool)), this, SLOT(httpDone(bool)));
	ToDelete=false;
}

void GestoreServers::getFile(const QUrl &url)
{
	errore=false;
	file.setFileName("TempServerList.txt");
	http.setHost(url.host(), url.port(80));
	http.get(url.path(), &file);
	http.close();
}
void GestoreServers::httpDone(bool error)
{
	if (error) {
		emit erroreConnessione();
		errore=true;
	}
	else{
		file.close();
		if (ToDelete) file.remove();
	}
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
	if(!errore){
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
	}
	disconnect(this,SIGNAL(done()),this,SLOT(FormServerList()));
}
void GestoreServers::OttieniIP(){
	ToDelete=false;
	getFile(QUrl(Giocatori::PathToHttpServer+"/GetIP.php"));
	connect (this,SIGNAL(done()),this,SLOT(FormIP()));
}
void GestoreServers::FormIP(){
	if (!errore)
	{
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
	}
	disconnect(this,SIGNAL(done()),this,SLOT(FormIP()));
}

void GestoreServers::NotResponding(QString ipnr){
	ToDelete=true;
	getFile(QUrl(Giocatori::PathToHttpServer+"/NotResponding.php?IPNotResponding="+ipnr));
}