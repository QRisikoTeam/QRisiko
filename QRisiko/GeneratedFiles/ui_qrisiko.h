/********************************************************************************
** Form generated from reading UI file 'qrisiko.ui'
**
** Created: Thu 5. Apr 14:10:25 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRISIKO_H
#define UI_QRISIKO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRisikoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QRisikoClass)
    {
        if (QRisikoClass->objectName().isEmpty())
            QRisikoClass->setObjectName(QString::fromUtf8("QRisikoClass"));
        QRisikoClass->resize(600, 400);
        menuBar = new QMenuBar(QRisikoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QRisikoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QRisikoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QRisikoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QRisikoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QRisikoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QRisikoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QRisikoClass->setStatusBar(statusBar);

        retranslateUi(QRisikoClass);

        QMetaObject::connectSlotsByName(QRisikoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QRisikoClass)
    {
        QRisikoClass->setWindowTitle(QApplication::translate("QRisikoClass", "QRisiko", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QRisikoClass: public Ui_QRisikoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRISIKO_H
