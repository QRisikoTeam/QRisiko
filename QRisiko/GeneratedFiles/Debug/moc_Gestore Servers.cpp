/****************************************************************************
** Meta object code from reading C++ file 'Gestore Servers.h'
**
** Created: Sun 15. Apr 19:27:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gestore Servers.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gestore Servers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GestoreServers[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      23,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   46,   15,   15, 0x08,
      67,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GestoreServers[] = {
    "GestoreServers\0\0done()\0ListaOttenuta(QString)\0"
    "error\0httpDone(bool)\0FormServerList()\0"
};

void GestoreServers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GestoreServers *_t = static_cast<GestoreServers *>(_o);
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->ListaOttenuta((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->httpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->FormServerList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GestoreServers::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GestoreServers::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GestoreServers,
      qt_meta_data_GestoreServers, &staticMetaObjectExtraData }
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GestoreServers::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GestoreServers::ListaOttenuta(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE