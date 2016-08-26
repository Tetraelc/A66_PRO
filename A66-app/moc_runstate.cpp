/****************************************************************************
** Meta object code from reading C++ file 'runstate.h'
**
** Created: Fri Aug 26 14:09:15 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "runstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunState[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      34,   30,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,    9,    9,    9, 0x0a,
      75,    9,    9,    9, 0x08,
     108,  106,    9,    9, 0x08,
     133,    9,    9,    9, 0x08,
     175,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RunState[] = {
    "RunState\0\0openProgramwindow()\0Num\0"
    "ReturnworkedTotal(int)\0openRunStateWin()\0"
    "on_pushButton_Left_5_clicked()\0t\0"
    "timerEvent(QTimerEvent*)\0"
    "on_tableWidget_Run_itemSelectionChanged()\0"
    "on_pushButton_Left_1_clicked()\0"
    "on_pushButton_Left_4_clicked()\0"
};

void RunState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RunState *_t = static_cast<RunState *>(_o);
        switch (_id) {
        case 0: _t->openProgramwindow(); break;
        case 1: _t->ReturnworkedTotal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->openRunStateWin(); break;
        case 3: _t->on_pushButton_Left_5_clicked(); break;
        case 4: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 5: _t->on_tableWidget_Run_itemSelectionChanged(); break;
        case 6: _t->on_pushButton_Left_1_clicked(); break;
        case 7: _t->on_pushButton_Left_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RunState::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RunState::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RunState,
      qt_meta_data_RunState, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunState))
        return static_cast<void*>(const_cast< RunState*>(this));
    return QWidget::qt_metacast(_clname);
}

int RunState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RunState::openProgramwindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RunState::ReturnworkedTotal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
