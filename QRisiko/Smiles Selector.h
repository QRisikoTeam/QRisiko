#ifndef SMILESSELECTOR_H
#define SMILESSELECTOR_H
#include <QWidget>
#include "SmileButton.h"
#include "Chat Const.h"
class SmilesSelector : public QWidget
{
	Q_OBJECT
	public:
		SmilesSelector(QWidget* parent);
		void SetSmilesPerRow(const int& spr){SmilesPerRow=spr;}
	signals:
		void selected(int iden);
	private:
		unsigned int SmilesPerRow;
		SmileButton* emotes[Smiles::Num_Smiles];
	private slots:
		void selezionato(int a);
	public slots:
		void show_toggle();
};
#endif
