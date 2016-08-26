/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Aug 26 15:58:11 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,
      49,   11,   11,   11, 0x05,
      68,   11,   11,   11, 0x05,
      87,   11,   11,   11, 0x05,
     108,   11,   11,   11, 0x05,
     134,   11,   11,   11, 0x05,
     155,   11,   11,   11, 0x05,
     172,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,   11,   11,   11, 0x0a,
     212,   11,   11,   11, 0x0a,
     230,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     392,   11,   11,   11, 0x08,
     419,   11,   11,   11, 0x08,
     451,   11,  446,   11, 0x08,
     481,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openStepWidget()\0"
    "openProgramWidget()\0openMouldsWidget()\0"
    "openManualWidget()\0openRunStateWidget()\0"
    "openSystemSettingWidget()\0"
    "openEasyBendWidget()\0openInfoWidget()\0"
    "sig_UpperPointAlarm()\0ReturnProgramdb()\0"
    "ReFlashProgName()\0on_pushButton_T3_clicked()\0"
    "on_pushButton_T2_clicked()\0"
    "on_toolButton_B0_clicked()\0"
    "on_toolButton_B1_clicked()\0"
    "on_toolButton_B2_clicked()\0"
    "on_toolButton_B3_clicked()\0"
    "on_toolButton_B4_clicked()\0"
    "on_toolButton_B5_clicked()\0bool\0"
    "on_toolButton_Start_clicked()\0"
    "on_toolButton_4_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openStepWidget(); break;
        case 1: _t->openProgramWidget(); break;
        case 2: _t->openMouldsWidget(); break;
        case 3: _t->openManualWidget(); break;
        case 4: _t->openRunStateWidget(); break;
        case 5: _t->openSystemSettingWidget(); break;
        case 6: _t->openEasyBendWidget(); break;
        case 7: _t->openInfoWidget(); break;
        case 8: _t->sig_UpperPointAlarm(); break;
        case 9: _t->ReturnProgramdb(); break;
        case 10: _t->ReFlashProgName(); break;
        case 11: _t->on_pushButton_T3_clicked(); break;
        case 12: _t->on_pushButton_T2_clicked(); break;
        case 13: _t->on_toolButton_B0_clicked(); break;
        case 14: _t->on_toolButton_B1_clicked(); break;
        case 15: _t->on_toolButton_B2_clicked(); break;
        case 16: _t->on_toolButton_B3_clicked(); break;
        case 17: _t->on_toolButton_B4_clicked(); break;
        case 18: _t->on_toolButton_B5_clicked(); break;
        case 19: { bool _r = _t->on_toolButton_Start_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: _t->on_toolButton_4_clicked(); break;
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openStepWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::openProgramWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::openMouldsWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::openManualWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::openRunStateWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::openSystemSettingWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::openEasyBendWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::openInfoWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MainWindow::sig_UpperPointAlarm()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
