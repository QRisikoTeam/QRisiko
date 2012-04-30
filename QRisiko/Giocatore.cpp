#include "Giocatore.h"
void Giocatore::SetColorID(const short& CID){
	if (CID>=0 && CID <=6) ColorID=CID;
	else ColorID=Giocatori::Spectator;
}