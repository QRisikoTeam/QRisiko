/****************************************************************************
** Meta object code from reading C++ file 'ServerSelector.h'
**
** Created: Fri 27. Jul 16:17:16 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ServerSelector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerSelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      27,   24,   15,   15, 0x05,
      48,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   15,   15,   15, 0x0a,
      72,   68,   15,   15, 0x08,
     118,   96,   15,   15, 0x08,
     150,   15,   15,   15, 0x08,
     173,   15,   15,   15, 0x08,
     188,   15,   15,   15, 0x08,
     200,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerSelector[] = {
    "ServerSelector\0\0Ferma()\0IP\0"
    "Selezionato(QString)\0Annullato()\0"
    "Avvia()\0IPs\0AvviaScansione(QString)\0"
    "N,GioOnline,MaxGio,IP\0"
    "Popola(QString,int,int,QString)\0"
    "OttieniIpSelezionato()\0NoConnection()\0"
    "DaTabella()\0DaManuale()\0"
};

void ServerSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerSelector *_t = static_cast<ServerSelector *>(_o);
        switch (_id) {
        case 0: _t->Ferma(); break;
        case 1: _t->Selezionato((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Annullato(); break;
        case 3: _t->Avvia(); break;
        case 4: _t->AvviaScansione((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->Popola((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 6: _t->OttieniIpSelezionato(); break;
        case 7: _t->NoConnection(); break;
        case 8: _t->DaTabella(); break;
        case 9: _t->DaManuale(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerSelector,
      qt_meta_data_ServerSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerSelector))
        return static_cast<void*>(const_cast< ServerSelector*>(this));
    if (!strcmp(_clname, "Ui::ServerLister"))
        return static_cast< Ui::ServerLister*>(const_cast< ServerSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ServerSelector::Ferma()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ServerSelector::Selezionato(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerSelector::Annullato()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
