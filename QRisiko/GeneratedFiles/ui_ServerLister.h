/********************************************************************************
** Form generated from reading UI file 'ServerLister.ui'
**
** Created: Mon 23. Apr 08:54:44 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERLISTER_H
#define UI_SERVERLISTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerLister
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *AggiornamentoLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectButton;
    QPushButton *cancelButton;
    QTableWidget *TabellaServer;

    void setupUi(QWidget *ServerLister)
    {
        if (ServerLister->objectName().isEmpty())
            ServerLister->setObjectName(QString::fromUtf8("ServerLister"));
        ServerLister->resize(400, 300);
        gridLayout = new QGridLayout(ServerLister);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ServerLister);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        AggiornamentoLabel = new QLabel(ServerLister);
        AggiornamentoLabel->setObjectName(QString::fromUtf8("AggiornamentoLabel"));

        gridLayout->addWidget(AggiornamentoLabel, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        connectButton = new QPushButton(ServerLister);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(connectButton, 2, 2, 1, 1);

        cancelButton = new QPushButton(ServerLister);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(cancelButton, 2, 3, 1, 1);

        TabellaServer = new QTableWidget(ServerLister);
        if (TabellaServer->columnCount() < 3)
            TabellaServer->setColumnCount(3);
        TabellaServer->setObjectName(QString::fromUtf8("TabellaServer"));
        TabellaServer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TabellaServer->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TabellaServer->setDragDropOverwriteMode(false);
        TabellaServer->setSelectionMode(QAbstractItemView::SingleSelection);
        TabellaServer->setSelectionBehavior(QAbstractItemView::SelectRows);
        TabellaServer->setSortingEnabled(true);
        TabellaServer->setColumnCount(3);
        TabellaServer->horizontalHeader()->setHighlightSections(false);
        TabellaServer->verticalHeader()->setVisible(false);
        TabellaServer->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(TabellaServer, 1, 0, 1, 4);


        retranslateUi(ServerLister);

        QMetaObject::connectSlotsByName(ServerLister);
    } // setupUi

    void retranslateUi(QWidget *ServerLister)
    {
        ServerLister->setWindowTitle(QApplication::translate("ServerLister", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerLister", "Server Online", 0, QApplication::UnicodeUTF8));
        AggiornamentoLabel->setText(QApplication::translate("ServerLister", "Aggiornamento in Corso...", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("ServerLister", "Connetti", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ServerLister", "Annulla", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerLister: public Ui_ServerLister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERLISTER_H
