/****************************************************************************
** Meta object code from reading C++ file 'chooselowermolddialog.h'
**
** Created: Sat Aug 27 09:56:57 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chooselowermolddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chooselowermolddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chooseLowerMoldDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_chooseLowerMoldDialog[] = {
    "chooseLowerMoldDialog\0\0num\0"
    "sig_sndLowerMold(int)\0on_buttonBox_accepted()\0"
};

void chooseLowerMoldDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        chooseLowerMoldDialog *_t = static_cast<chooseLowerMoldDialog *>(_o);
        switch (_id) {
        case 0: _t->sig_sndLowerMold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData chooseLowerMoldDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject chooseLowerMoldDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_chooseLowerMoldDialog,
      qt_meta_data_chooseLowerMoldDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &chooseLowerMoldDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *chooseLowerMoldDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *chooseLowerMoldDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chooseLowerMoldDialog))
        return static_cast<void*>(const_cast< chooseLowerMoldDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int chooseLowerMoldDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void chooseLowerMoldDialog::sig_sndLowerMold(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
