#include "Smiles Selector.h"
#include <QtGui>
SmilesSelector::SmilesSelector(QWidget* parent)
	:QWidget(parent)
{
	SmilesPerRow=8;
	QGridLayout *Lay= new QGridLayout;
	QSizePolicy politica(QSizePolicy::Preferred, QSizePolicy::Preferred);
	politica.setHorizontalStretch(0);
	politica.setVerticalStretch(0);
	for (int i=0;i<Smiles::Num_Smiles;i++){
		emotes[i]=new SmileButton(this,i);
		emotes[i]->setObjectName("emoticonButton"+i);
		emotes[i]->setContextMenuPolicy(Qt::NoContextMenu);
		politica.setHeightForWidth(emotes[i]->sizePolicy().hasHeightForWidth());
		emotes[i]->setSizePolicy(politica);
		emotes[i]->setMaximumSize(24,24);
		emotes[i]->setMinimumSize(24,24);
		QIcon icona;
		icona.addFile(Smiles::smiles_paths[i], QSize(), QIcon::Normal, QIcon::Off);
		emotes[i]->setIcon(icona);
		connect(emotes[i],SIGNAL(clicked(int)),this,SLOT(selezionato(int)));
		connect(emotes[i],SIGNAL(clicked(int)),this,SLOT(hide())) ;
		Lay->addWidget(emotes[i],i/SmilesPerRow,i%SmilesPerRow);
	}
	setLayout(Lay);
	QFrame* Sfondo=new QFrame(this);
	Sfondo->setGeometry(2,2,sizeHint().width()-4,sizeHint().height()-4);
	Sfondo->setStyleSheet("background-color: rgb(229, 229, 229);"
		"border-width: 1px;"
		"border-color: rgb(0, 0, 0);"
		"border-style: inset;"
		"border-radius: 5px;"
		);
	Sfondo->lower();
	hide();
}

void SmilesSelector::selezionato(int a){
	emit selected(a);
}

void SmilesSelector::show_toggle(){
	if (isVisible())
		hide();
	else
		show();
}

