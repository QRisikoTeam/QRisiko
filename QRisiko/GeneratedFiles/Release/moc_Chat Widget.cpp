/****************************************************************************
** Meta object code from reading C++ file 'Chat Widget.h'
**
** Created: Sat 14. Apr 12:30:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chat Widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chat Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x05,
      69,   61,   11,   11, 0x25,
      94,   61,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   11,   11,   11, 0x08,
     138,  135,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     231,  218,   11,   11, 0x08,
     262,  258,   11,   11, 0x28,
     284,  258,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatWidget[] = {
    "ChatWidget\0\0Message,fromserver\0"
    "MessageRecieved(QString,bool)\0Message\0"
    "MessageRecieved(QString)\0"
    "MessageFromServer(QString)\0sendMessage()\0"
    "id\0addSmile(int)\0Connesso()\0"
    "ErroreConnessione()\0Inbox()\0"
    "connectionClosedByServer()\0msg,fromserv\0"
    "PrintMessage(QString,bool)\0msg\0"
    "PrintMessage(QString)\0"
    "StampaMessaggioUtente(QString)\0"
};

void ChatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChatWidget *_t = static_cast<ChatWidget *>(_o);
        switch (_id) {
        case 0: _t->MessageRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->MessageRecieved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->MessageFromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendMessage(); break;
        case 4: _t->addSmile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Connesso(); break;
        case 6: _t->ErroreConnessione(); break;
        case 7: _t->Inbox(); break;
        case 8: _t->connectionClosedByServer(); break;
        case 9: _t->PrintMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->PrintMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->StampaMessaggioUtente((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChatWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChatWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWidget,
      qt_meta_data_ChatWidget, &staticMetaObjectExtraData }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
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
QT_END_MOC_NAMESPACE