/****************************************************************************
** Meta object code from reading C++ file 'sender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../new/sender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sender_t {
    QByteArrayData data[15];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sender_t qt_meta_stringdata_Sender = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Sender"
QT_MOC_LITERAL(1, 7, 8), // "sendding"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "buttonEmit0"
QT_MOC_LITERAL(4, 29, 11), // "buttonEmit1"
QT_MOC_LITERAL(5, 41, 11), // "buttonEmit2"
QT_MOC_LITERAL(6, 53, 11), // "buttonEmit3"
QT_MOC_LITERAL(7, 65, 11), // "buttonEmit4"
QT_MOC_LITERAL(8, 77, 11), // "buttonEmit5"
QT_MOC_LITERAL(9, 89, 11), // "buttonEmit6"
QT_MOC_LITERAL(10, 101, 11), // "buttonEmit7"
QT_MOC_LITERAL(11, 113, 11), // "buttonEmit8"
QT_MOC_LITERAL(12, 125, 11), // "buttonEmit9"
QT_MOC_LITERAL(13, 137, 12), // "buttonEmit10"
QT_MOC_LITERAL(14, 150, 12) // "buttonEmit11"

    },
    "Sender\0sendding\0\0buttonEmit0\0buttonEmit1\0"
    "buttonEmit2\0buttonEmit3\0buttonEmit4\0"
    "buttonEmit5\0buttonEmit6\0buttonEmit7\0"
    "buttonEmit8\0buttonEmit9\0buttonEmit10\0"
    "buttonEmit11"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   82,    2, 0x0a /* Public */,
       4,    0,   83,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Sender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sender *_t = static_cast<Sender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendding((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->buttonEmit0(); break;
        case 2: _t->buttonEmit1(); break;
        case 3: _t->buttonEmit2(); break;
        case 4: _t->buttonEmit3(); break;
        case 5: _t->buttonEmit4(); break;
        case 6: _t->buttonEmit5(); break;
        case 7: _t->buttonEmit6(); break;
        case 8: _t->buttonEmit7(); break;
        case 9: _t->buttonEmit8(); break;
        case 10: _t->buttonEmit9(); break;
        case 11: _t->buttonEmit10(); break;
        case 12: _t->buttonEmit11(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Sender::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sender::sendding)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Sender::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Sender.data,
      qt_meta_data_Sender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sender.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Sender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Sender::sendding(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
