/****************************************************************************
** Meta object code from reading C++ file 'serial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../new/serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serial_t {
    QByteArrayData data[11];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serial_t qt_meta_stringdata_serial = {
    {
QT_MOC_LITERAL(0, 0, 6), // "serial"
QT_MOC_LITERAL(1, 7, 6), // "readed"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "Data*"
QT_MOC_LITERAL(4, 21, 13), // "originMessage"
QT_MOC_LITERAL(5, 35, 7), // "message"
QT_MOC_LITERAL(6, 43, 19), // "on_serial_readyRead"
QT_MOC_LITERAL(7, 63, 4), // "open"
QT_MOC_LITERAL(8, 68, 4), // "flag"
QT_MOC_LITERAL(9, 73, 5), // "write"
QT_MOC_LITERAL(10, 79, 4) // "data"

    },
    "serial\0readed\0\0Data*\0originMessage\0"
    "message\0on_serial_readyRead\0open\0flag\0"
    "write\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Bool,    8,
    QMetaType::LongLong, QMetaType::QByteArray,   10,

       0        // eod
};

void serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serial *_t = static_cast<serial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readed((*reinterpret_cast< Data*(*)>(_a[1]))); break;
        case 1: _t->originMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->on_serial_readyRead(); break;
        case 3: { bool _r = _t->open((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { qint64 _r = _t->write((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (serial::*_t)(Data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial::readed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (serial::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial::originMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject serial::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_serial.data,
      qt_meta_data_serial,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serial.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void serial::readed(Data * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void serial::originMessage(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
