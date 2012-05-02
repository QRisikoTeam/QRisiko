#ifndef QRISIKO_H
#define QRISIKO_H
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include "ImmagineCliccabile.h"
#include "Costanti Nazioni.h"
#include "Gestore Servers.h"
#include "Sfondo Risiko.h"
#include "Giocatore.h"
#include <QMap>
#include <QTimer>
#include <QMovie>

class QRisiko : public QWidget
{
	Q_OBJECT
	private:
		ImmagineCliccabile *Stati[ID_Stati::num_stati];
		QLabel* Segnali[ID_Stati::num_stati];
		QLabel* Sfondo;
		GestoreServers* gestoreServer;

		//Pulsanti Menu Contestuale
		QPushButton* InfoStato;
		QPushButton* StatStato;
		QPushButton* AnnullaSchieramento;
		QPushButton* Seleziona;
		QPushButton* CambiaVista;
		QPushButton* AnnullaMenuContestuale;
		int ContextMenuOnState;

		QVector<short> ID_Attaccabili[ID_Stati::num_stati];
		void Popola_ID_Attaccabili();
		short fase;
		Giocatore Player;
		int AttackFrom_ID;
		int ArmiesToPlace;
		int ArmiesLeftToPlace;
		QMap<int,int> Aggiunte;
		int DurataAnimazioniMenu;
		const double PiGreco;

		//Don't Say Egitto
		QLabel* Esplosione;
		QTimer* TimerEsplosione;
		QMovie* MovieEsplosione;
	protected:
		void resizeEvent (QResizeEvent * event);
		bool eventFilter(QObject *target, QEvent *event);
	signals:
		void resized(QSize new_size);
		void FaseCambiata(short);
		void Attaccato(int from, int to);
		void PrimoPiazzato();
		void TutteDaPiazzare();
	public:
		QRisiko(QWidget *parent = 0);
		void SetPlayerName(const QString& n){Player.setUserName(n);}
		void SetPlayerColor(const short& CID){Player.SetColorID(CID);}
		void SetDurataAnimazioniMenu(const int& dur){DurataAnimazioniMenu=dur;}
		short GetFase() const {return fase;}
		bool IsContextMenuVisible() const {return InfoStato->isVisible();}
		enum{Not_My_Turn=0, Schieramento=1, Attacco=2, Spostamento=3};
	private slots:
		void funziona(bool che, int identita);
		void MostraMenuContestuale(QPoint pnt);
		void HideContextMenu();
		void UpdateVisual();
		void DeleteExplosion(int frm);
		void SimulaClick();
	public slots:
		void NascondiMenuContestuale();
		void ProssimaFase();
		void CambiaVisuale();
		void DontSayEgitto();
		void ResetSchieramento();

};

#endif
