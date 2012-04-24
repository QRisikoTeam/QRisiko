/****************************************************************************
** Meta object code from reading C++ file 'qrisiko.h'
**
** Created: Mon 23. Apr 17:03:45 2012
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
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   33,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QRisiko[] = {
    "QRisiko\0\0new_size\0resized(QSize)\0"
    "identita\0funziona(int)\0"
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
        case 1: funziona((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QRisiko::resized(QSize _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
