/****************************************************************************
** Meta object code from reading C++ file 'collectWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../new/collectWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collectWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainWindow_t {
    QByteArrayData data[17];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWindow_t qt_meta_stringdata_mainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainWindow"
QT_MOC_LITERAL(1, 11, 10), // "open_close"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "readSetting"
QT_MOC_LITERAL(4, 35, 11), // "changeTable"
QT_MOC_LITERAL(5, 47, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 64, 4), // "item"
QT_MOC_LITERAL(7, 69, 5), // "cloum"
QT_MOC_LITERAL(8, 75, 11), // "changeChart"
QT_MOC_LITERAL(9, 87, 11), // "showSetting"
QT_MOC_LITERAL(10, 99, 10), // "showSender"
QT_MOC_LITERAL(11, 110, 11), // "showDebuger"
QT_MOC_LITERAL(12, 122, 10), // "serialSend"
QT_MOC_LITERAL(13, 133, 4), // "data"
QT_MOC_LITERAL(14, 138, 10), // "checkClarm"
QT_MOC_LITERAL(15, 149, 5), // "Data*"
QT_MOC_LITERAL(16, 155, 1) // "n"

    },
    "mainWindow\0open_close\0\0readSetting\0"
    "changeTable\0QTreeWidgetItem*\0item\0"
    "cloum\0changeChart\0showSetting\0showSender\0"
    "showDebuger\0serialSend\0data\0checkClarm\0"
    "Data*\0n"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    2,   61,    2, 0x0a /* Public */,
       8,    2,   66,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainWindow *_t = static_cast<mainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open_close(); break;
        case 1: _t->readSetting(); break;
        case 2: _t->changeTable((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeChart((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->showSetting(); break;
        case 5: _t->showSender(); break;
        case 6: _t->showDebuger(); break;
        case 7: _t->serialSend((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->checkClarm((*reinterpret_cast< Data*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject mainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainWindow.data,
      qt_meta_data_mainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
