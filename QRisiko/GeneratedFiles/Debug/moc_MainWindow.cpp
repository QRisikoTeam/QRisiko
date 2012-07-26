/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Thu 26. Jul 15:51:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
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
     177,   11,   11,   11, 0x08,
     198,  191,   11,   11, 0x08,
     219,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     245,   11,   11,   11, 0x08,
     269,  264,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0MostraMappa()\0NascondiPrev()\0"
    "MostraSelettoreServer()\0MostraMainMenu()\0"
    "MostraTopMenu()\0NascondiTopMenu()\0"
    "MostraRegolamento()\0NascondiRegolamento()\0"
    "MostraPrePartita()\0StartServer()\0"
    "HostIP\0StartClient(QString)\0StopServer()\0"
    "StopClient()\0StartHostedMatch()\0Host\0"
    "StartJoinedMatch(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->MostraMappa(); break;
        case 1: _t->NascondiPrev(); break;
        case 2: _t->MostraSelettoreServer(); break;
        case 3: _t->MostraMainMenu(); break;
        case 4: _t->MostraTopMenu(); break;
        case 5: _t->NascondiTopMenu(); break;
        case 6: _t->MostraRegolamento(); break;
        case 7: _t->NascondiRegolamento(); break;
        case 8: _t->MostraPrePartita(); break;
        case 9: _t->StartServer(); break;
        case 10: _t->StartClient((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->StopServer(); break;
        case 12: _t->StopClient(); break;
        case 13: _t->StartHostedMatch(); break;
        case 14: _t->StartJoinedMatch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
