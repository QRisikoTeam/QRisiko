/****************************************************************************
** Meta object code from reading C++ file 'ImmagineCliccabile.h'
**
** Created: Sat 21. Apr 15:50:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImmagineCliccabile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImmagineCliccabile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImmagineCliccabile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   19,   19,   19, 0x08,
      52,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImmagineCliccabile[] = {
    "ImmagineCliccabile\0\0Cliccato(int)\0"
    "ImpostaMaschera()\0clickID()\0"
};

void ImmagineCliccabile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImmagineCliccabile *_t = static_cast<ImmagineCliccabile *>(_o);
        switch (_id) {
        case 0: _t->Cliccato((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ImpostaMaschera(); break;
        case 2: _t->clickID(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImmagineCliccabile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImmagineCliccabile::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_ImmagineCliccabile,
      qt_meta_data_ImmagineCliccabile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImmagineCliccabile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImmagineCliccabile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImmagineCliccabile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImmagineCliccabile))
        return static_cast<void*>(const_cast< ImmagineCliccabile*>(this));
    return QPushButton::qt_metacast(_clname);
}

int ImmagineCliccabile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ImmagineCliccabile::Cliccato(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
