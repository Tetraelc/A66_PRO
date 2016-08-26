/****************************************************************************
** Meta object code from reading C++ file 'program.h'
**
** Created: Wed Jul 27 13:58:48 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "program.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'program.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Program[] = {

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
       9,    8,    8,    8, 0x0a,
      31,    8,   26,    8, 0x08,
      67,    8,   26,    8, 0x08,
      97,    8,    8,    8, 0x08,
     126,    8,    8,    8, 0x08,
     157,    8,    8,    8, 0x08,
     192,    8,    8,    8, 0x08,
     237,    8,    8,    8, 0x08,
     275,    8,    8,    8, 0x08,
     316,    8,    8,    8, 0x08,
     357,  352,    8,    8, 0x08,
     409,    8,    8,    8, 0x08,
     457,    8,    8,    8, 0x08,
     504,    8,    8,    8, 0x08,
     544,    8,    8,    8, 0x08,
     587,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Program[] = {
    "Program\0\0openProgramWin()\0bool\0"
    "on_pushButton_Program_New_clicked()\0"
    "on_pushButton_P_Del_clicked()\0"
    "on_pushButton_P_Up_clicked()\0"
    "on_pushButton_P_Down_clicked()\0"
    "on_lineEdit_P_Name_returnPressed()\0"
    "on_lineEdit_P_boardThickness_returnPressed()\0"
    "on_lineEdit_P_UpMolds_returnPressed()\0"
    "on_lineEdit_P_LowerMolds_returnPressed()\0"
    "on_lineEdit_P_Total_returnPressed()\0"
    "arg1\0on_comboBox_P_material_currentIndexChanged(QString)\0"
    "on_tableWidget_Programdb_itemSelectionChanged()\0"
    "on_lineEdit_P_boardThickness_editingFinished()\0"
    "on_lineEdit_P_UpMolds_editingFinished()\0"
    "on_lineEdit_P_LowerMolds_editingFinished()\0"
    "on_lineEdit_P_Total_editingFinished()\0"
};

void Program::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Program *_t = static_cast<Program *>(_o);
        switch (_id) {
        case 0: _t->openProgramWin(); break;
        case 1: { bool _r = _t->on_pushButton_Program_New_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->on_pushButton_P_Del_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->on_pushButton_P_Up_clicked(); break;
        case 4: _t->on_pushButton_P_Down_clicked(); break;
        case 5: _t->on_lineEdit_P_Name_returnPressed(); break;
        case 6: _t->on_lineEdit_P_boardThickness_returnPressed(); break;
        case 7: _t->on_lineEdit_P_UpMolds_returnPressed(); break;
        case 8: _t->on_lineEdit_P_LowerMolds_returnPressed(); break;
        case 9: _t->on_lineEdit_P_Total_returnPressed(); break;
        case 10: _t->on_comboBox_P_material_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_tableWidget_Programdb_itemSelectionChanged(); break;
        case 12: _t->on_lineEdit_P_boardThickness_editingFinished(); break;
        case 13: _t->on_lineEdit_P_UpMolds_editingFinished(); break;
        case 14: _t->on_lineEdit_P_LowerMolds_editingFinished(); break;
        case 15: _t->on_lineEdit_P_Total_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Program::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Program::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Program,
      qt_meta_data_Program, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Program::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Program::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Program::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Program))
        return static_cast<void*>(const_cast< Program*>(this));
    return QWidget::qt_metacast(_clname);
}

int Program::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
