/****************************************************************************
** Meta object code from reading C++ file 'ServerSelector Thread.h'
**
** Created: Thu 26. Apr 19:11:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ServerSelector Thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerSelector Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerSelectorThread[] = {

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
      44,   22,   21,   21, 0x05,
      82,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,   21,   21,   21, 0x0a,
      98,   21,   21,   21, 0x08,
     105,   21,   21,   21, 0x08,
     116,   21,   21,   21, 0x08,
     136,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerSelectorThread[] = {
    "ServerSelectorThread\0\0N,GioOnline,MaxGio,IP\0"
    "InfoRicevute(QString,int,int,QString)\0"
    "finito()\0stop()\0Skip()\0Connesso()\0"
    "ErroreConnessione()\0OttieniInfo()\0"
};

void ServerSelectorThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerSelectorThread *_t = static_cast<ServerSelectorThread *>(_o);
        switch (_id) {
        case 0: _t->InfoRicevute((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->finito(); break;
        case 2: _t->stop(); break;
        case 3: _t->Skip(); break;
        case 4: _t->Connesso(); break;
        case 5: _t->ErroreConnessione(); break;
        case 6: _t->OttieniInfo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerSelectorThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerSelectorThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ServerSelectorThread,
      qt_meta_data_ServerSelectorThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerSelectorThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerSelectorThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerSelectorThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerSelectorThread))
        return static_cast<void*>(const_cast< ServerSelectorThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ServerSelectorThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ServerSelectorThread::InfoRicevute(QString _t1, int _t2, int _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerSelectorThread::finito()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
