/****************************************************************************
** Meta object code from reading C++ file 'chartWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../new/chartWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chartWidget_t {
    QByteArrayData data[11];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chartWidget_t qt_meta_stringdata_chartWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "chartWidget"
QT_MOC_LITERAL(1, 12, 7), // "setline"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "QLineSeries*"
QT_MOC_LITERAL(4, 34, 1), // "L"
QT_MOC_LITERAL(5, 36, 8), // "setRange"
QT_MOC_LITERAL(6, 45, 3), // "min"
QT_MOC_LITERAL(7, 49, 3), // "max"
QT_MOC_LITERAL(8, 53, 8), // "setTitle"
QT_MOC_LITERAL(9, 62, 5), // "title"
QT_MOC_LITERAL(10, 68, 7) // "refresh"

    },
    "chartWidget\0setline\0\0QLineSeries*\0L\0"
    "setRange\0min\0max\0setTitle\0title\0refresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,
       8,    1,   42,    2, 0x0a /* Public */,
      10,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void chartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chartWidget *_t = static_cast<chartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setline((*reinterpret_cast< QLineSeries*(*)>(_a[1]))); break;
        case 1: _t->setRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->refresh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineSeries* >(); break;
            }
            break;
        }
    }
}

const QMetaObject chartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chartWidget.data,
      qt_meta_data_chartWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *chartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chartWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int chartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
