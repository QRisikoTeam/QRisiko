/****************************************************************************
** Meta object code from reading C++ file 'TopMenu.h'
**
** Created: Fri 27. Jul 16:17:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TopMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TopMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TopMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      21,    8,    8,    8, 0x05,
      31,    8,    8,    8, 0x05,
      45,    8,    8,    8, 0x05,
      59,    8,    8,    8, 0x05,
      70,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,    8,    8,    8, 0x0a,
     126,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TopMenu[] = {
    "TopMenu\0\0Abbandona()\0Opzioni()\0"
    "Regolamento()\0Statistiche()\0Riprendi()\0"
    "AnnullaSchieramento()\0"
    "EnableAnnullaSchieramentoButton()\0"
    "DisableAnnullaSchieramentoButton()\0"
};

void TopMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TopMenu *_t = static_cast<TopMenu *>(_o);
        switch (_id) {
        case 0: _t->Abbandona(); break;
        case 1: _t->Opzioni(); break;
        case 2: _t->Regolamento(); break;
        case 3: _t->Statistiche(); break;
        case 4: _t->Riprendi(); break;
        case 5: _t->AnnullaSchieramento(); break;
        case 6: _t->EnableAnnullaSchieramentoButton(); break;
        case 7: _t->DisableAnnullaSchieramentoButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TopMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TopMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TopMenu,
      qt_meta_data_TopMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TopMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TopMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TopMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TopMenu))
        return static_cast<void*>(const_cast< TopMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int TopMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TopMenu::Abbandona()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TopMenu::Opzioni()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TopMenu::Regolamento()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TopMenu::Statistiche()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TopMenu::Riprendi()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void TopMenu::AnnullaSchieramento()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
