/****************************************************************************
** Meta object code from reading C++ file 'qrisiko.h'
**
** Created: Sat 5. May 14:20:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qrisiko.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrisiko.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QRisiko[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,    9,    8,    8, 0x05,
      33,    8,    8,    8, 0x05,
      61,   53,    8,    8, 0x05,
      80,    8,    8,    8, 0x05,
      96,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     127,  114,    8,    8, 0x08,
     150,  146,    8,    8, 0x08,
     180,    8,    8,    8, 0x08,
     198,    8,    8,    8, 0x08,
     217,  213,    8,    8, 0x08,
     238,    8,    8,    8, 0x08,
     258,  252,    8,    8, 0x08,
     281,    8,    8,    8, 0x0a,
     307,    8,    8,    8, 0x0a,
     322,    8,    8,    8, 0x0a,
     338,    8,    8,    8, 0x0a,
     354,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QRisiko[] = {
    "QRisiko\0\0new_size\0resized(QSize)\0"
    "FaseCambiata(short)\0from,to\0"
    "Attaccato(int,int)\0PrimoPiazzato()\0"
    "TutteDaPiazzare()\0che,identita\0"
    "funziona(bool,int)\0pnt\0"
    "MostraMenuContestuale(QPoint)\0"
    "HideContextMenu()\0UpdateVisual()\0frm\0"
    "DeleteExplosion(int)\0SimulaClick()\0"
    "ident\0AggiornaEtichetta(int)\0"
    "NascondiMenuContestuale()\0ProssimaFase()\0"
    "CambiaVisuale()\0DontSayEgitto()\0"
    "ResetSchieramento()\0"
};

const QMetaObject QRisiko::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QRisiko,
      qt_meta_data_QRisiko, 0 }
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
        switch (_id) {
        case 0: resized((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 1: FaseCambiata((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 2: Attaccato((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: PrimoPiazzato(); break;
        case 4: TutteDaPiazzare(); break;
        case 5: funziona((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: MostraMenuContestuale((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: HideContextMenu(); break;
        case 8: UpdateVisual(); break;
        case 9: DeleteExplosion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: SimulaClick(); break;
        case 11: AggiornaEtichetta((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: NascondiMenuContestuale(); break;
        case 13: ProssimaFase(); break;
        case 14: CambiaVisuale(); break;
        case 15: DontSayEgitto(); break;
        case 16: ResetSchieramento(); break;
        default: ;
        }
        _id -= 17;
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

// SIGNAL 3
void QRisiko::PrimoPiazzato()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QRisiko::TutteDaPiazzare()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
