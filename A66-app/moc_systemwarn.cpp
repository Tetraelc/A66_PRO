/****************************************************************************
** Meta object code from reading C++ file 'systemwarn.h'
**
** Created: Fri Aug 26 14:09:31 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "systemwarn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemwarn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SystemWarn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   33,   11,   11, 0x0a,
      62,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SystemWarn[] = {
    "SystemWarn\0\0ReturnProgramdbWin()\0"
    "WarnID\0SystemCheckAlarm(int)\0"
    "on_buttonBox_accepted()\0on_buttonBox_rejected()\0"
};

void SystemWarn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SystemWarn *_t = static_cast<SystemWarn *>(_o);
        switch (_id) {
        case 0: _t->ReturnProgramdbWin(); break;
        case 1: _t->SystemCheckAlarm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SystemWarn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SystemWarn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SystemWarn,
      qt_meta_data_SystemWarn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SystemWarn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SystemWarn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SystemWarn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemWarn))
        return static_cast<void*>(const_cast< SystemWarn*>(this));
    return QDialog::qt_metacast(_clname);
}

int SystemWarn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SystemWarn::ReturnProgramdbWin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
