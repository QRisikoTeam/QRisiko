/****************************************************************************
** Meta object code from reading C++ file 'ImmagineCliccabile.h'
**
** Created: Thu 10. May 17:31:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImmagineCliccabile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImmagineCliccabile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImmagineCliccabile[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   20,   19,   19, 0x05,
      41,   19,   19,   19, 0x05,
      59,   19,   19,   19, 0x05,
      84,   79,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   19,   19,   19, 0x0a,
     116,   19,   19,   19, 0x0a,
     131,   19,   19,   19, 0x0a,
     145,   19,   19,   19, 0x08,
     167,  163,   19,   19, 0x08,
     181,   19,   19,   19, 0x08,

 // properties: name, type, flags
     201,  196, 0x01095001,
     218,  212, 0x82495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_ImmagineCliccabile[] = {
    "ImmagineCliccabile\0\0,\0Cliccato(bool,int)\0"
    "NoArmateChanged()\0ResponsiveChanged()\0"
    "iden\0ArmateChanged(int)\0NextVisual()\0"
    "UpdateVisual()\0SimulaClick()\0"
    "ImpostaMaschera()\0che\0clickID(bool)\0"
    "ResettaStile()\0bool\0Responsive\0short\0"
    "No_Armate\0"
};

const QMetaObject ImmagineCliccabile::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_ImmagineCliccabile,
      qt_meta_data_ImmagineCliccabile, 0 }
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
        switch (_id) {
        case 0: Cliccato((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: NoArmateChanged(); break;
        case 2: ResponsiveChanged(); break;
        case 3: ArmateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: NextVisual(); break;
        case 5: UpdateVisual(); break;
        case 6: SimulaClick(); break;
        case 7: ImpostaMaschera(); break;
        case 8: clickID((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: ResettaStile(); break;
        default: ;
        }
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = IsResponsive(); break;
        case 1: *reinterpret_cast< short*>(_v) = GetNoArmate(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: SetNoArmate(*reinterpret_cast< short*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ImmagineCliccabile::Cliccato(bool _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImmagineCliccabile::NoArmateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ImmagineCliccabile::ResponsiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ImmagineCliccabile::ArmateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
