#include "Smiles Selector.h"
#include <QtGui>
SmilesSelector::SmilesSelector(QWidget* parent)
	:QWidget(parent)
{
	//setStyleSheet("background-color: " +this->palette().background().color().name()+';');
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
		Lay->addWidget(emotes[i],i/8,i%8);
	}
	setLayout(Lay);
	hide();
}
void SmilesSelector::focusOutEvent ( QFocusEvent * event ){
	hide();
}
void SmilesSelector::selezionato(int a){
	emit selected(a);
}