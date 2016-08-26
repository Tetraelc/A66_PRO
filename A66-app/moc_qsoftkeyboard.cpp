/****************************************************************************
** Meta object code from reading C++ file 'qsoftkeyboard.h'
**
** Created: Fri Aug 26 14:09:18 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qsoftkeyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsoftkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qSoftKeyboard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,
      43,   14,   14,   14, 0x05,
      59,   14,   14,   14, 0x05,
      73,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   88,   14,   14, 0x08,
     143,  141,   14,   14, 0x08,
     167,   14,   14,   14, 0x08,
     186,   14,   14,   14, 0x08,
     211,   14,   14,   14, 0x08,
     234,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qSoftKeyboard[] = {
    "qSoftKeyboard\0\0key\0characterGenerated(int)\0"
    "SendBackspace()\0SendKeyBack()\0"
    "redoKeyValue()\0oldFocus,newFocus\0"
    "saveFocusWidget(QWidget*,QWidget*)\0w\0"
    "buttonClicked(QWidget*)\0BackspaceContent()\0"
    "on_closeButton_clicked()\0"
    "on_EscButton_clicked()\0on_BackButton_clicked()\0"
};

void qSoftKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qSoftKeyboard *_t = static_cast<qSoftKeyboard *>(_o);
        switch (_id) {
        case 0: _t->characterGenerated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendBackspace(); break;
        case 2: _t->SendKeyBack(); break;
        case 3: _t->redoKeyValue(); break;
        case 4: _t->saveFocusWidget((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 5: _t->buttonClicked((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 6: _t->BackspaceContent(); break;
        case 7: _t->on_closeButton_clicked(); break;
        case 8: _t->on_EscButton_clicked(); break;
        case 9: _t->on_BackButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qSoftKeyboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qSoftKeyboard::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_qSoftKeyboard,
      qt_meta_data_qSoftKeyboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qSoftKeyboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qSoftKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qSoftKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qSoftKeyboard))
        return static_cast<void*>(const_cast< qSoftKeyboard*>(this));
    return QDialog::qt_metacast(_clname);
}

int qSoftKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void qSoftKeyboard::characterGenerated(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qSoftKeyboard::SendBackspace()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qSoftKeyboard::SendKeyBack()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void qSoftKeyboard::redoKeyValue()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
