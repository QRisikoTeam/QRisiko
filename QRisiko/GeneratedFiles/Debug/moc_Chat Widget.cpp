/****************************************************************************
** Meta object code from reading C++ file 'Chat Widget.h'
**
** Created: Thu 10. May 17:31:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chat Widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chat Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x05,
      69,   61,   11,   11, 0x25,
      94,   61,   11,   11, 0x05,
     121,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,   11,  137,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     158,   11,   11,   11, 0x08,
     175,  172,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     268,  255,   11,   11, 0x08,
     299,  295,   11,   11, 0x28,
     321,  295,   11,   11, 0x08,
     352,  295,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatWidget[] = {
    "ChatWidget\0\0Message,fromserver\0"
    "MessageRecieved(QString,bool)\0Message\0"
    "MessageRecieved(QString)\0"
    "MessageFromServer(QString)\0DontSayEgitto()\0"
    "bool\0Avvia()\0Ferma()\0sendMessage()\0"
    "id\0addSmile(int)\0Connesso()\0"
    "ErroreConnessione()\0Inbox()\0"
    "connectionClosedByServer()\0msg,fromserv\0"
    "PrintMessage(QString,bool)\0msg\0"
    "PrintMessage(QString)\0"
    "StampaMessaggioUtente(QString)\0"
    "StampaBenvenutoServer(QString)\0"
};

const QMetaObject ChatWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWidget,
      qt_meta_data_ChatWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWidget))
        return static_cast<void*>(const_cast< ChatWidget*>(this));
    if (!strcmp(_clname, "Ui::Chat"))
        return static_cast< Ui::Chat*>(const_cast< ChatWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MessageRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: MessageRecieved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: MessageFromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: DontSayEgitto(); break;
        case 4: { bool _r = Avvia();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: Ferma(); break;
        case 6: sendMessage(); break;
        case 7: addSmile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: Connesso(); break;
        case 9: ErroreConnessione(); break;
        case 10: Inbox(); break;
        case 11: connectionClosedByServer(); break;
        case 12: PrintMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: PrintMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: StampaMessaggioUtente((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: StampaBenvenutoServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ChatWidget::MessageRecieved(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void ChatWidget::MessageFromServer(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatWidget::DontSayEgitto()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
