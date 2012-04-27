#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <QString>


class Giocatore{
public:
	enum{Giallo=0, Blu=1, Rosso=2, Nero=3, Viola=4, Verde=5, Spectator=6};
	Giocatore(QString n="", short CID=Spectator):NomeGiocatore(n), ColorID(CID){}
	QString GetUsername() const{return NomeGiocatore;}
	void setUserName(const QString& n){NomeGiocatore=n;}
	short GetColorID() const {return ColorID;}
	void SetColorID(const short& CID);
private:
	QString NomeGiocatore;
	short ColorID;	
};

#endif