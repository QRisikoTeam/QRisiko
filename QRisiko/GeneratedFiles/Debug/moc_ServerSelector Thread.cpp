/****************************************************************************
** Meta object code from reading C++ file 'ServerSelector Thread.h'
**
** Created: Sat 5. May 14:20:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ServerSelector Thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerSelector Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerSelectorThread[] = {

 // content:
       5,       // revision
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

const QMetaObject ServerSelectorThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ServerSelectorThread,
      qt_meta_data_ServerSelectorThread, 0 }
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
        switch (_id) {
        case 0: InfoRicevute((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: finito(); break;
        case 2: stop(); break;
        case 3: Skip(); break;
        case 4: Connesso(); break;
        case 5: ErroreConnessione(); break;
        case 6: OttieniInfo(); break;
        default: ;
        }
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
