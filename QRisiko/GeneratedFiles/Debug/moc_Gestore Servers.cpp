/****************************************************************************
** Meta object code from reading C++ file 'Gestore Servers.h'
**
** Created: Thu 10. May 17:31:25 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gestore Servers.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gestore Servers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GestoreServers[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x05,
      38,   34,   15,   15, 0x05,
      64,   61,   15,   15, 0x05,
      84,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,  104,   15,   15, 0x08,
     135,   16,   15,   15, 0x08,
     159,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GestoreServers[] = {
    "GestoreServers\0\0fet\0done(QString)\0lis\0"
    "ListaOttenuta(QString)\0IP\0IPOttenuto(QString)\0"
    "erroreConnessione()\0reply\0"
    "httpDone(QNetworkReply*)\0"
    "FormServerList(QString)\0FormIP(QString)\0"
};

const QMetaObject GestoreServers::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GestoreServers,
      qt_meta_data_GestoreServers, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GestoreServers::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GestoreServers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GestoreServers::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GestoreServers))
        return static_cast<void*>(const_cast< GestoreServers*>(this));
    return QObject::qt_metacast(_clname);
}

int GestoreServers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: done((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: ListaOttenuta((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: IPOttenuto((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: erroreConnessione(); break;
        case 4: httpDone((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: FormServerList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: FormIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GestoreServers::done(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GestoreServers::ListaOttenuta(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GestoreServers::IPOttenuto(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GestoreServers::erroreConnessione()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
