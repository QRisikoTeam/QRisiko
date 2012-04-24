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

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QWidget* parent=0);
	private:
		Regolamento* regolamento;
		TopMenu* Topmenu;
		MenuPrincipale* MainMenu;
		ServerSelector* SelettoreServer;
		QRisiko* mappa;
		ChatWidget* chat;
		QTextEdit* Log;
		QFrame* BottomFrame;
		QFrame* TopFrame;
		QWidget* CurrWidget;
		QWidget* PrevWidget;
		SizPos PrevWidgetSizPos;
		QLabel* BottomFrameCover;
		int DurataAnimazioniMenu;
		void riposiziona();
	private slots:
		void MostraMappa();
		void NascondiPrev(){PrevWidget->hide();}
		void MostraSelettoreServer();
		void MostraMainMenu();
		void MostraTopMenu();
		void NascondiTopMenu();
		void MostraRegolamento();
		void NascondiRegolamento();
	protected:
		void closeEvent(QCloseEvent *event);
		void resizeEvent(QResizeEvent *event);
		void keyPressEvent(QKeyEvent *keyev);
};

#endif