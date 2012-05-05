/****************************************************************************
** Meta object code from reading C++ file 'TopMenu.h'
**
** Created: Sat 5. May 14:20:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TopMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TopMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TopMenu[] = {

 // content:
       5,       // revision
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

const QMetaObject TopMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TopMenu,
      qt_meta_data_TopMenu, 0 }
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
        switch (_id) {
        case 0: Abbandona(); break;
        case 1: Opzioni(); break;
        case 2: Regolamento(); break;
        case 3: Statistiche(); break;
        case 4: Riprendi(); break;
        case 5: AnnullaSchieramento(); break;
        case 6: EnableAnnullaSchieramentoButton(); break;
        case 7: DisableAnnullaSchieramentoButton(); break;
        default: ;
        }
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
