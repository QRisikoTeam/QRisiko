#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QMainWindow>
#include "qrisiko.h"
#include "Chat Widget.h"
#include "MainMenu.h"
#include "ServerSelector.h"
#include "TopMenu.h"
#include "Regolamento.h"
#include "Costanti Nazioni.h"
#include "Pre Partita.h"
#include "Gestore Servers.h"
#include "Gioco Server.h"
#include "Gioco Client.h"
class QPushButton;

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QWidget* parent=0);
	private:
		Regolamento* regolamento;
		PrePartita* prePartita;
		TopMenu* Topmenu;
		MenuPrincipale* MainMenu;
		ServerSelector* SelettoreServer;
		QRisiko* mappa;
		ChatWidget* chat;
		QTextEdit* Log;
		QFrame* BottomFrame;
		QFrame* TopFrame;
		QFrame* Avviso;
		QPushButton* ChiudiAvviso;
		QLabel* IconaAvviso;
		QMovie* AnimazioneAvviso;
		QLabel* TestoAvviso;
		QWidget* CurrWidget;
		QWidget* PrevWidget;
		SizPos PrevWidgetSizPos;
		QLabel* BottomFrameCover;
		GestoreServers* GestoreOnline;
		GiocoServer* ServerGioco;
		ClientGioco* ClientDiGioco;
		int DurataAnimazioniMenu;
		void riposiziona();
	private slots:
		void MostraMappa();
		void NascondiPrev();
		void MostraSelettoreServer();
		void MostraMainMenu();
		void MostraTopMenu();
		void NascondiTopMenu();
		void MostraRegolamento();
		void NascondiRegolamento();
		void MostraPrePartita();
		void StartServer();
		void StartClient(const QString& HostIP);
		void StopServer();
		void StopClient();
		void StartMatch();
		void AggiornaChat(const QString& NuovoNome, int NuovoColore);
		void MostraAvviso(const QString& Testo);
		void MostraCaricamento(const QString& Testo);
		void NascondiAvviso();
	protected:
		void closeEvent(QCloseEvent *event);
		void resizeEvent(QResizeEvent *event);
		void keyPressEvent(QKeyEvent *keyev);
};

#endif