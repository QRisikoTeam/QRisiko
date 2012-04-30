#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <QString>
#include "Costanti Nazioni.h"


class Giocatore{
public:
	Giocatore(QString n="", short CID=Giocatori::Spectator):NomeGiocatore(n), ColorID(CID){}
	QString GetUsername() const{return NomeGiocatore;}
	void setUserName(const QString& n){NomeGiocatore=n;}
	short GetColorID() const {return ColorID;}
	void SetColorID(const short& CID);
private:
	QString NomeGiocatore;
	short ColorID;	
};

#endif