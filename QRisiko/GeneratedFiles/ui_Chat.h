/********************************************************************************
** Form generated from reading UI file 'Chat.ui'
**
** Created: Fri 27. Apr 10:44:55 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QGridLayout *gridLayout;
    QTextEdit *ChatText;
    QPushButton *reconnectButton;
    QTextEdit *MessageText;
    QPushButton *SmilesButton;
    QPushButton *SendButton;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(341, 194);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Chat->sizePolicy().hasHeightForWidth());
        Chat->setSizePolicy(sizePolicy);
        Chat->setMinimumSize(QSize(341, 194));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Chat Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chat->setWindowIcon(icon);
        gridLayout = new QGridLayout(Chat);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ChatText = new QTextEdit(Chat);
        ChatText->setObjectName(QString::fromUtf8("ChatText"));
        sizePolicy.setHeightForWidth(ChatText->sizePolicy().hasHeightForWidth());
        ChatText->setSizePolicy(sizePolicy);
        ChatText->setMinimumSize(QSize(323, 110));
        ChatText->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ChatText->setAcceptDrops(false);
        ChatText->setStyleSheet(QString::fromUtf8("#ChatText{border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255, 255);\n"
"border-radius: 3px;\n"
"selection-background-color: ltblue;}"));
        ChatText->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ChatText->setUndoRedoEnabled(false);
        ChatText->setReadOnly(true);
        ChatText->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(ChatText, 0, 0, 1, 3);

        reconnectButton = new QPushButton(Chat);
        reconnectButton->setObjectName(QString::fromUtf8("reconnectButton"));
        reconnectButton->setMinimumSize(QSize(323, 23));
        reconnectButton->setMaximumSize(QSize(16777215, 31));

        gridLayout->addWidget(reconnectButton, 1, 0, 1, 3);

        MessageText = new QTextEdit(Chat);
        MessageText->setObjectName(QString::fromUtf8("MessageText"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MessageText->sizePolicy().hasHeightForWidth());
        MessageText->setSizePolicy(sizePolicy1);
        MessageText->setMaximumSize(QSize(16777215, 31));
        MessageText->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-style: inset;\n"
"background-color: rgba(255, 255, 255, 255);\n"
"border-radius: 12px;\n"
"selection-background-color: ltblue; \n"
"padding: 7px;"));
        MessageText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MessageText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(MessageText, 2, 0, 1, 1);

        SmilesButton = new QPushButton(Chat);
        SmilesButton->setObjectName(QString::fromUtf8("SmilesButton"));
        SmilesButton->setMinimumSize(QSize(31, 31));
        SmilesButton->setMaximumSize(QSize(16777215, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Smiles/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
        SmilesButton->setIcon(icon1);

        gridLayout->addWidget(SmilesButton, 2, 1, 1, 1);

        SendButton = new QPushButton(Chat);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setMinimumSize(QSize(75, 31));
        SendButton->setMaximumSize(QSize(16777215, 31));
        SendButton->setCursor(QCursor(Qt::PointingHandCursor));
        SendButton->setDefault(true);
        SendButton->setFlat(false);

        gridLayout->addWidget(SendButton, 2, 2, 1, 1);

        QWidget::setTabOrder(MessageText, SendButton);
        QWidget::setTabOrder(SendButton, ChatText);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Chat", 0, QApplication::UnicodeUTF8));
        ChatText->setDocumentTitle(QApplication::translate("Chat", "Chat History", 0, QApplication::UnicodeUTF8));
        ChatText->setHtml(QApplication::translate("Chat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Chat History</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        reconnectButton->setText(QApplication::translate("Chat", "Riconnetti", 0, QApplication::UnicodeUTF8));
        MessageText->setHtml(QApplication::translate("Chat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        SmilesButton->setText(QString());
        SendButton->setText(QApplication::translate("Chat", "Invia", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
