/****************************************************************************
** Meta object code from reading C++ file 'manualadjustdate.h'
**
** Created: Fri Aug 26 14:09:28 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manualadjustdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manualadjustdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManualAdjustDate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   18,   17,   17, 0x05,
      46,   18,   17,   17, 0x05,
      70,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,   17,   17,   17, 0x08,
     118,   17,   17,   17, 0x08,
     144,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ManualAdjustDate[] = {
    "ManualAdjustDate\0\0str\0sig_sndManualX(QString)\0"
    "sig_sndManualY(QString)\0sig_sndManualR(QString)\0"
    "on_toolButton_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_3_clicked()\0"
};

void ManualAdjustDate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManualAdjustDate *_t = static_cast<ManualAdjustDate *>(_o);
        switch (_id) {
        case 0: _t->sig_sndManualX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_sndManualY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_sndManualR((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->on_toolButton_2_clicked(); break;
        case 5: _t->on_toolButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ManualAdjustDate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ManualAdjustDate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManualAdjustDate,
      qt_meta_data_ManualAdjustDate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManualAdjustDate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManualAdjustDate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManualAdjustDate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManualAdjustDate))
        return static_cast<void*>(const_cast< ManualAdjustDate*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManualAdjustDate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ManualAdjustDate::sig_sndManualX(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ManualAdjustDate::sig_sndManualY(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ManualAdjustDate::sig_sndManualR(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
