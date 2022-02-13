/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab1_calculator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[44];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 22), // "on_btn_numeric_clicked"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 19), // "on_btn_move_clicked"
QT_MOC_LITERAL(55, 13), // "clear_clicked"
QT_MOC_LITERAL(69, 20), // "on_btn_point_clicked"
QT_MOC_LITERAL(90, 14), // "result_clicked"
QT_MOC_LITERAL(105, 14), // "delete_clicked"
QT_MOC_LITERAL(120, 11), // "enableMoves"
QT_MOC_LITERAL(132, 1), // "i"
QT_MOC_LITERAL(134, 13), // "whatINeedToDo"
QT_MOC_LITERAL(148, 9), // "calcMath*"
QT_MOC_LITERAL(158, 14), // "mathInstrument"
QT_MOC_LITERAL(173, 12), // "enableDelete"
QT_MOC_LITERAL(186, 12), // "enableResult"
QT_MOC_LITERAL(199, 11), // "enablePoint"
QT_MOC_LITERAL(211, 9), // "enableNum"
QT_MOC_LITERAL(221, 10), // "enableSwap"
QT_MOC_LITERAL(232, 14), // "enableWerewolf"
QT_MOC_LITERAL(247, 12), // "enableAllBtn"
QT_MOC_LITERAL(260, 19), // "on_btn_swap_clicked"
QT_MOC_LITERAL(280, 23) // "on_btn_werewolf_clicked"

    },
    "MainWindow\0on_btn_numeric_clicked\0\0"
    "on_btn_move_clicked\0clear_clicked\0"
    "on_btn_point_clicked\0result_clicked\0"
    "delete_clicked\0enableMoves\0i\0whatINeedToDo\0"
    "calcMath*\0mathInstrument\0enableDelete\0"
    "enableResult\0enablePoint\0enableNum\0"
    "enableSwap\0enableWerewolf\0enableAllBtn\0"
    "on_btn_swap_clicked\0on_btn_werewolf_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    0 /* Private */,
       3,    0,  117,    2, 0x08,    1 /* Private */,
       4,    0,  118,    2, 0x08,    2 /* Private */,
       5,    0,  119,    2, 0x08,    3 /* Private */,
       6,    0,  120,    2, 0x08,    4 /* Private */,
       7,    0,  121,    2, 0x08,    5 /* Private */,
       8,    1,  122,    2, 0x08,    6 /* Private */,
      10,    1,  125,    2, 0x08,    8 /* Private */,
      13,    1,  128,    2, 0x08,   10 /* Private */,
      14,    1,  131,    2, 0x08,   12 /* Private */,
      15,    1,  134,    2, 0x08,   14 /* Private */,
      16,    1,  137,    2, 0x08,   16 /* Private */,
      17,    1,  140,    2, 0x08,   18 /* Private */,
      18,    1,  143,    2, 0x08,   20 /* Private */,
      19,    1,  146,    2, 0x08,   22 /* Private */,
      20,    0,  149,    2, 0x08,   24 /* Private */,
      21,    0,  150,    2, 0x08,   25 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_numeric_clicked(); break;
        case 1: _t->on_btn_move_clicked(); break;
        case 2: _t->clear_clicked(); break;
        case 3: _t->on_btn_point_clicked(); break;
        case 4: _t->result_clicked(); break;
        case 5: _t->delete_clicked(); break;
        case 6: _t->enableMoves((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->whatINeedToDo((*reinterpret_cast< calcMath*(*)>(_a[1]))); break;
        case 8: _t->enableDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->enableResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->enablePoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->enableNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->enableSwap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->enableWerewolf((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->enableAllBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_btn_swap_clicked(); break;
        case 16: _t->on_btn_werewolf_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<calcMath *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
