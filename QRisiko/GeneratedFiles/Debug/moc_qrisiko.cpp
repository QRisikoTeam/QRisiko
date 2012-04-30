/****************************************************************************
** Meta object code from reading C++ file 'qrisiko.h'
**
** Created: Mon 30. Apr 14:23:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qrisiko.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrisiko.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QRisiko[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,    9,    8,    8, 0x05,
      33,    8,    8,    8, 0x05,
      61,   53,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,    8,    8,    8, 0x08,
     119,  106,    8,    8, 0x08,
     138,    8,    8,    8, 0x08,
     162,  158,    8,    8, 0x08,
     192,    8,    8,    8, 0x08,
     210,    8,    8,    8, 0x08,
     225,    8,    8,    8, 0x0a,
     240,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QRisiko[] = {
    "QRisiko\0\0new_size\0resized(QSize)\0"
    "FaseCambiata(short)\0from,to\0"
    "Attaccato(int,int)\0NascondiMenuContestuale()\0"
    "che,identita\0funziona(bool,int)\0"
    "ResetSchieramento()\0pnt\0"
    "MostraMenuContestuale(QPoint)\0"
    "HideContextMenu()\0UpdateVisual()\0"
    "ProssimaFase()\0CambiaVisuale()\0"
};

void QRisiko::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QRisiko *_t = static_cast<QRisiko *>(_o);
        switch (_id) {
        case 0: _t->resized((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 1: _t->FaseCambiata((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 2: _t->Attaccato((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->NascondiMenuContestuale(); break;
        case 4: _t->funziona((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->ResetSchieramento(); break;
        case 6: _t->MostraMenuContestuale((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->HideContextMenu(); break;
        case 8: _t->UpdateVisual(); break;
        case 9: _t->ProssimaFase(); break;
        case 10: _t->CambiaVisuale(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QRisiko::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QRisiko::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QRisiko,
      qt_meta_data_QRisiko, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QRisiko::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QRisiko::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QRisiko::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRisiko))
        return static_cast<void*>(const_cast< QRisiko*>(this));
    return QWidget::qt_metacast(_clname);
}

int QRisiko::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QRisiko::resized(QSize _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QRisiko::FaseCambiata(short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QRisiko::Attaccato(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
