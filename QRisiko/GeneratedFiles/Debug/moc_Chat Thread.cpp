/****************************************************************************
** Meta object code from reading C++ file 'Chat Thread.h'
**
** Created: Thu 12. Apr 12:35:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chat Thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chat Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x05,
      69,   61,   11,   11, 0x25,

 // slots: signature, parameters, type, tag, flags
      94,   61,   11,   11, 0x0a,
     115,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatThread[] = {
    "ChatThread\0\0Message,fromserver\0"
    "MessageRecieved(QString,bool)\0Message\0"
    "MessageRecieved(QString)\0SendMessage(QString)\0"
    "Connesso()\0ErroreConnessione()\0Inbox()\0"
    "connectionClosedByServer()\0"
};

void ChatThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChatThread *_t = static_cast<ChatThread *>(_o);
        switch (_id) {
        case 0: _t->MessageRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->MessageRecieved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Connesso(); break;
        case 4: _t->ErroreConnessione(); break;
        case 5: _t->Inbox(); break;
        case 6: _t->connectionClosedByServer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChatThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChatThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ChatThread,
      qt_meta_data_ChatThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatThread))
        return static_cast<void*>(const_cast< ChatThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ChatThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ChatThread::MessageRecieved(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE