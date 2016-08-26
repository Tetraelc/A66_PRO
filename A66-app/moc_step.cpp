/****************************************************************************
** Meta object code from reading C++ file 'step.h'
**
** Created: Fri Aug 26 15:58:19 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "step.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'step.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Step[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      20,    5,    5,    5, 0x0a,
      56,    5,    5,    5, 0x0a,
     102,    5,    5,    5, 0x0a,
     138,    5,    5,    5, 0x0a,
     174,    5,    5,    5, 0x0a,
     217,    5,    5,    5, 0x0a,
     256,    5,    5,    5, 0x0a,
     295,    5,    5,    5, 0x0a,
     332,    5,    5,    5, 0x0a,
     370,    5,    5,    5, 0x0a,
     406,    5,    5,    5, 0x0a,
     449,    5,    5,    5, 0x08,
     480,    5,    5,    5, 0x08,
     511,    5,    5,    5, 0x08,
     542,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Step[] = {
    "Step\0\0openStepWin()\0"
    "on_lineEdit_S_Angle_returnPressed()\0"
    "on_lineEdit_S_AngleCompensate_returnPressed()\0"
    "on_lineEdit_S_Yaxis_returnPressed()\0"
    "on_lineEdit_S_Xaxis_returnPressed()\0"
    "on_lineEdit_S_XaxisCorrect_returnPressed()\0"
    "on_lineEdit_S_distance_returnPressed()\0"
    "on_lineEdit_S_pressure_returnPressed()\0"
    "on_lineEdit_S_return_returnPressed()\0"
    "on_lineEdit_S_Holding_returnPressed()\0"
    "on_lineEdit_S_Raxis_returnPressed()\0"
    "on_tableWidget_Step_itemSelectionChanged()\0"
    "on_pushButton_Left_1_clicked()\0"
    "on_pushButton_Left_4_clicked()\0"
    "on_pushButton_Left_2_clicked()\0"
    "on_pushButton_Left_3_clicked()\0"
};

void Step::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Step *_t = static_cast<Step *>(_o);
        switch (_id) {
        case 0: _t->openStepWin(); break;
        case 1: _t->on_lineEdit_S_Angle_returnPressed(); break;
        case 2: _t->on_lineEdit_S_AngleCompensate_returnPressed(); break;
        case 3: _t->on_lineEdit_S_Yaxis_returnPressed(); break;
        case 4: _t->on_lineEdit_S_Xaxis_returnPressed(); break;
        case 5: _t->on_lineEdit_S_XaxisCorrect_returnPressed(); break;
        case 6: _t->on_lineEdit_S_distance_returnPressed(); break;
        case 7: _t->on_lineEdit_S_pressure_returnPressed(); break;
        case 8: _t->on_lineEdit_S_return_returnPressed(); break;
        case 9: _t->on_lineEdit_S_Holding_returnPressed(); break;
        case 10: _t->on_lineEdit_S_Raxis_returnPressed(); break;
        case 11: _t->on_tableWidget_Step_itemSelectionChanged(); break;
        case 12: _t->on_pushButton_Left_1_clicked(); break;
        case 13: _t->on_pushButton_Left_4_clicked(); break;
        case 14: _t->on_pushButton_Left_2_clicked(); break;
        case 15: _t->on_pushButton_Left_3_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Step::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Step::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Step,
      qt_meta_data_Step, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Step::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Step::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Step::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Step))
        return static_cast<void*>(const_cast< Step*>(this));
    return QWidget::qt_metacast(_clname);
}

int Step::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
