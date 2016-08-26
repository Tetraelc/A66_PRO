/****************************************************************************
** Meta object code from reading C++ file 'qsoftkeyvalue.h'
**
** Created: Fri Aug 26 14:09:22 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qsoftkeyvalue.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsoftkeyvalue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qSoftKeyvaule[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   32,   14,   14, 0x08,
      55,   14,   14,   14, 0x0a,
      79,   14,   74,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qSoftKeyvaule[] = {
    "qSoftKeyvaule\0\0AngleSelectAll()\0key\0"
    "sendCharacter(int)\0recKey_Backspace()\0"
    "bool\0reshowkeyvaule()\0"
};

void qSoftKeyvaule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qSoftKeyvaule *_t = static_cast<qSoftKeyvaule *>(_o);
        switch (_id) {
        case 0: _t->AngleSelectAll(); break;
        case 1: _t->sendCharacter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->recKey_Backspace(); break;
        case 3: { bool _r = _t->reshowkeyvaule();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qSoftKeyvaule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qSoftKeyvaule::staticMetaObject = {
    { &QInputContext::staticMetaObject, qt_meta_stringdata_qSoftKeyvaule,
      qt_meta_data_qSoftKeyvaule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qSoftKeyvaule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qSoftKeyvaule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qSoftKeyvaule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qSoftKeyvaule))
        return static_cast<void*>(const_cast< qSoftKeyvaule*>(this));
    return QInputContext::qt_metacast(_clname);
}

int qSoftKeyvaule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QInputContext::qt_metacall(_c, _id, _a);
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
void qSoftKeyvaule::AngleSelectAll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
