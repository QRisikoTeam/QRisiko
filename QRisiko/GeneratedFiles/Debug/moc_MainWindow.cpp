/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sat 5. May 14:20:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0MostraMappa()\0NascondiPrev()\0"
    "MostraSelettoreServer()\0MostraMainMenu()\0"
    "MostraTopMenu()\0NascondiTopMenu()\0"
    "MostraRegolamento()\0NascondiRegolamento()\0"
    "MostraPrePartita()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MostraMappa(); break;
        case 1: NascondiPrev(); break;
        case 2: MostraSelettoreServer(); break;
        case 3: MostraMainMenu(); break;
        case 4: MostraTopMenu(); break;
        case 5: NascondiTopMenu(); break;
        case 6: MostraRegolamento(); break;
        case 7: NascondiRegolamento(); break;
        case 8: MostraPrePartita(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
