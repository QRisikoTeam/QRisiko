#include "Gioco Server.h"
GiocoServer::GiocoServer(QObject *parent): QTcpServer(parent),NumGiocatori(1),FasePrePartita(true){}
GiocoServer::GiocoServer(const QString& Nome, const int& MaxPl, QObject *parent)
:QTcpServer(parent)
,NomeServer(Nome)
,MaxGiocatori(MaxPl)
,NumGiocatori(1)
,FasePrePartita(true)
{
	Pubblicatore=new GestoreServers(this);
	Pubblicatore->AddIP();
	IDs.append(Comunicazioni::ServerID);
	Pronti.append(false);
	ToCheck.append(false);
	Nomi.append("");
	Colori.append(Giocatori::Spectator);
	connect(this,SIGNAL(IsNotReady(int)),this,SLOT(RimuoviPronto(int)));
	connect(this,SIGNAL(IsReady(int)),this,SLOT(AggiungiPronto(int)));
	connect(this,SIGNAL(Disonnesso(int)),this,SLOT(GiocatoreDisconnesso(int)));
	connect(this,SIGNAL(StartGame()),this,SLOT(ImpostaPartitaIniziata()));
	connect(this,SIGNAL(UpdateInfo(int,QString,int)),this,SLOT(ImpostaChecks(int,QString,int)));
	connect(this,SIGNAL(IsPronto(int)),this,SLOT(ContinuaInvio(int)));
}
void GiocoServer::Termina(){
	for (QList<GiocoThread*>::iterator i=clients.begin();i!=clients.end();i++){
		(*i)->stop();
	}
	Pubblicatore->RemoveIP();
}
void GiocoServer::incomingConnection(int socketId)
{
	clients.append(new GiocoThread(socketId,this));
	connect(clients.last(), SIGNAL(finished()), clients.last(), SLOT(deleteLater()));
	connect(clients.last(),SIGNAL(GotRichiediInfo(int)),this,SLOT(FormaInfo(int)));
	connect(clients.last(),SIGNAL(IWantToJoin(int)),this,SLOT(WantsToJoin(int)));
	connect(this,SIGNAL(InviaInformazioni(QString,int,int)),clients.last(),SIGNAL(InviaInformazioni(QString,int,int)));
	

	clients.last()->start();
}
void GiocoServer::FormaInfo(int SoDe){
	for (int i=0;i<clients.size();i++){
		if (clients.at(i)->GetSocketDescriptor()==SoDe){
			clients.at(i)->SendInfo(NomeServer,NumGiocatori,MaxGiocatori);
			return;
		}
	}
}
int GiocoServer::TrovaIndice(int ident){
	int j=0;
	for (QList<GiocoThread*>::iterator i=clients.begin(); i!=clients.end();i++,j++){
		if((*i)->GetSocketDescriptor()==ident) return j;
	}
	return -1;
}
void GiocoServer::WantsToJoin(int ident){
	int Indice=TrovaIndice(ident);
	if(Indice==-1) return;
	connect(this,SIGNAL(NuovaConnessione(int)),clients.at(Indice),SIGNAL(MandaMioID(int)));
	connect(clients.at(Indice),SIGNAL(RicevutoID(int)),this,SLOT(GotHisID(int)));
	emit (NuovaConnessione(ident));
}
void GiocoServer::GotHisID(int ident){
	int Indice=TrovaIndice(ident);
	if(Indice==-1) return;
	disconnect(this,SIGNAL(NuovaConnessione(int)),clients.at(Indice),SIGNAL(MandaMioID(int)));
	connect(this,SIGNAL(NuovaConnessione(int)),clients.at(Indice),SIGNAL(NuovoUtente(int)));
	connect(clients.at(Indice),SIGNAL(CambiateInfo(int,QString,int)),this,SIGNAL(UpdateInfo(int,QString,int)));
	connect(this,SIGNAL(UpdateInfo(int,QString,int)),clients.at(Indice),SIGNAL(UpdateInfo(int,QString,int)));
	connect(clients.at(Indice),SIGNAL(IsReady(int)),this,SIGNAL(IsReady(int)));
	connect(clients.at(Indice),SIGNAL(IsNotReady(int)),this,SIGNAL(IsNotReady(int)));
	connect(this,SIGNAL(StartGame()),clients.at(Indice),SIGNAL(StartGame()));
	connect(clients.at(Indice),SIGNAL(Disonnesso(int)),this,SIGNAL(Disonnesso(int)));
	connect(this,SIGNAL(Disonnesso(int)),clients.at(Indice),SIGNAL(GiocatoreDisconnesso(int)));
	connect(this,SIGNAL(MandaInfoA(int,int,QString,int)),clients.last(),SIGNAL(MandaInfoA(int,int,QString,int)));
	connect(clients.last(),SIGNAL(SonoPronto(int)),this,SIGNAL(IsPronto(int)));
	IDs.append(ident);
	Pronti.append(false);
	ToCheck.append(false);
	Nomi.append("");
	Colori.append(Giocatori::Spectator);
	NumGiocatori++;
	contatore[ident]=0;
	MandaInfoA(ident,IDs.at(0),Nomi.at(0),Colori.at(0));
}
void GiocoServer::ControllaAvvio(){
	bool TuttiPronti=true;
	bool AlmenoUno=false;
	for (int i=0;i<Pronti.size() && TuttiPronti;i++){
		if (ToCheck.at(i) && !Pronti.at(i)) TuttiPronti=false;
		if (ToCheck.at(i) && !AlmenoUno) AlmenoUno=true;
	}
	if (TuttiPronti && AlmenoUno) emit StartGame();
}
void GiocoServer::AggiungiPronto(int ident){
	if (FasePrePartita)	{
		*(Pronti.begin()+IDs.indexOf(ident))=true;
		ControllaAvvio();
	}
}
void GiocoServer::RimuoviPronto(int ident){
	if (FasePrePartita) *(Pronti.begin()+IDs.indexOf(ident))=false;
}
void GiocoServer::GiocatoreDisconnesso(int ident){
	Pronti.erase(Pronti.begin()+IDs.indexOf(ident));
	ToCheck.erase(ToCheck.begin()+IDs.indexOf(ident));
	IDs.erase(IDs.begin()+IDs.indexOf(ident));
	ControllaAvvio();
	NumGiocatori--;
}
void GiocoServer::ImpostaChecks(int ident,const QString& nuovonome,int nuovocolore){
	*(ToCheck.begin()+IDs.indexOf(ident))= (nuovocolore!=Giocatori::Spectator);
	*(Nomi.begin()+IDs.indexOf(ident))=nuovonome;
	*(Colori.begin()+IDs.indexOf(ident))=nuovocolore;
}
void GiocoServer::ContinuaInvio(int destinazione){
	QMap<int,int>::iterator temp;
	if (!contatore.contains(destinazione)) return;
	MandaInfoA(destinazione,IDs.at(++contatore[destinazione]),Nomi.at(contatore[destinazione]),Colori.at(contatore[destinazione]));
	if(contatore[destinazione]==IDs.size()-1){
		contatore.remove(destinazione);
		temp=contatore.find(destinazione);
		if (temp!=contatore.end()){
			contatore.erase(temp);
		}
	}
}