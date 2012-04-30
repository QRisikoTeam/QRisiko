/****************************************************************************
** Meta object code from reading C++ file 'MainMenu.h'
**
** Created: Mon 30. Apr 13:13:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuPrincipale[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      27,   15,   15,   15, 0x05,
      34,   15,   15,   15, 0x05,
      44,   15,   15,   15, 0x05,
      53,   15,   15,   15, 0x05,
      61,   15,   15,   15, 0x05,
      69,   15,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MenuPrincipale[] = {
    "MenuPrincipale\0\0HostLoad()\0Join()\0"
    "HostNew()\0Option()\0About()\0Rules()\0"
    "Exit()\0"
};

void MenuPrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MenuPrincipale *_t = static_cast<MenuPrincipale *>(_o);
        switch (_id) {
        case 0: _t->HostLoad(); break;
        case 1: _t->Join(); break;
        case 2: _t->HostNew(); break;
        case 3: _t->Option(); break;
        case 4: _t->About(); break;
        case 5: _t->Rules(); break;
        case 6: _t->Exit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MenuPrincipale::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MenuPrincipale::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MenuPrincipale,
      qt_meta_data_MenuPrincipale, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuPrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuPrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuPrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuPrincipale))
        return static_cast<void*>(const_cast< MenuPrincipale*>(this));
    return QWidget::qt_metacast(_clname);
}

int MenuPrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void MenuPrincipale::HostLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MenuPrincipale::Join()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MenuPrincipale::HostNew()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MenuPrincipale::Option()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MenuPrincipale::About()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MenuPrincipale::Rules()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MenuPrincipale::Exit()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
