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

class QRisiko : public QWidget
{
	Q_OBJECT
	private:
		ImmagineCliccabile *Stati[ID_Stati::num_stati];
		QLabel* Sfondo;
		GestoreServers* gestoreServer;

		//Pulsanti Menu Contestuale
		QPushButton* InfoStato;
		QPushButton* StatStato;
		QPushButton* AnnullaSchieramento;
		QPushButton* Seleziona;
		QPushButton* CambiaVista;
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
	protected:
		void resizeEvent (QResizeEvent * event);
		bool eventFilter(QObject *target, QEvent *event);
	signals:
		void resized(QSize new_size);
		void FaseCambiata(short);
		void Attaccato(int from, int to);
	public:
		QRisiko(QWidget *parent = 0);
		void SetPlayerName(const QString& n){Player.setUserName(n);}
		void SetPlayerColor(const short& CID){Player.SetColorID(CID);}
		void SetDurataAnimazioniMenu(const int& dur){DurataAnimazioniMenu=dur;}
		enum{Not_My_Turn=0, Schieramento=1, Attacco=2, Spostamento=3};
	private slots:
		void NascondiMenuContestuale();
		void funziona(bool che, int identita);
		void ResetSchieramento();
		void MostraMenuContestuale(QPoint pnt);
		void HideContextMenu();
		void UpdateVisual();
	public slots:
		void ProssimaFase();
		void CambiaVisuale();

};

#endif
