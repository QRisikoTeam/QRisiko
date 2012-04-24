#include "Regolamento.h"
#include <QVBoxLayout>
Regolamento::Regolamento(QWidget* parent)
:QWidget(parent)
{
	setObjectName("Regolamento");
	QVBoxLayout *verticalLayout = new QVBoxLayout(this);
	Testo = new QTextBrowser(this);
	Testo->setObjectName("Testo");
	Testo->setTextInteractionFlags(Qt::TextSelectableByMouse);
	Testo->setSource(QUrl("qrc:/Generale/Regole.txt"));
	Testo->setOpenLinks(false);

	verticalLayout->addWidget(Testo);

	backButton = new QPushButton(this);
	backButton->setObjectName("backButton");
	backButton->setMinimumSize(QSize(0, 40));
	backButton->setDefault(true);
	backButton->setText(tr("Indietro"));
	connect(backButton,SIGNAL(clicked()),this,SIGNAL(Indietro()));

	verticalLayout->addWidget(backButton);

}