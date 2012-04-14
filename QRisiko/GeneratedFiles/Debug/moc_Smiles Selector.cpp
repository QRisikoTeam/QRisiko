/****************************************************************************
** Meta object code from reading C++ file 'Smiles Selector.h'
**
** Created: Sat 14. Apr 17:08:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Smiles Selector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Smiles Selector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SmilesSelector[] = {

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
      21,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   35,   15,   15, 0x08,
      54,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SmilesSelector[] = {
    "SmilesSelector\0\0iden\0selected(int)\0a\0"
    "selezionato(int)\0show_toggle()\0"
};

void SmilesSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SmilesSelector *_t = static_cast<SmilesSelector *>(_o);
        switch (_id) {
        case 0: _t->selected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->selezionato((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->show_toggle(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SmilesSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SmilesSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SmilesSelector,
      qt_meta_data_SmilesSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SmilesSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SmilesSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SmilesSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SmilesSelector))
        return static_cast<void*>(const_cast< SmilesSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int SmilesSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void SmilesSelector::selected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
