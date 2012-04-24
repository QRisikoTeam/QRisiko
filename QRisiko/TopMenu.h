#ifndef TOPMENU_H
#define TOPMENU_H
#include <QWidget>
#include <QFrame>
#include <QResizeEvent>
#include <QPushButton>
#include <QKeyEvent>

class TopMenu : public QWidget{
	Q_OBJECT
public:
	TopMenu(QWidget* parent=0);
	QPushButton *OpzioniButton;
	QPushButton *StatisticheButton;
	QPushButton *RegolamentoButton;
	QPushButton *abortButton;
	QPushButton *RiprendiButton;
private:
	QFrame* Sfondo;
protected:
	void resizeEvent(QResizeEvent * event);
	void keyPressEvent(QKeyEvent *keyev);
signals:
	void Abbandona();
	void Opzioni();
	void Regolamento();
	void Statistiche();
	void Riprendi();
};
#endif