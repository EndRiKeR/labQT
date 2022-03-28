/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Laboratation3/mainwindow.h"
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
    const uint offsetsAndSize[52];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 24), // "on_btnChooseFile_clicked"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 5), // "block"
QT_MOC_LITERAL(43, 5), // "value"
QT_MOC_LITERAL(49, 22), // "on_btnLoadData_clicked"
QT_MOC_LITERAL(72, 20), // "on_btnOutput_clicked"
QT_MOC_LITERAL(93, 29), // "on_btnCalculateMetrix_clicked"
QT_MOC_LITERAL(123, 5), // "group"
QT_MOC_LITERAL(129, 3), // "col"
QT_MOC_LITERAL(133, 11), // "writeRegion"
QT_MOC_LITERAL(145, 6), // "output"
QT_MOC_LITERAL(152, 9), // "needCheck"
QT_MOC_LITERAL(162, 10), // "inputInMas"
QT_MOC_LITERAL(173, 19), // "std::vector<double>"
QT_MOC_LITERAL(193, 8), // "prepDraw"
QT_MOC_LITERAL(202, 20), // "inputYearsAndNumbers"
QT_MOC_LITERAL(223, 7), // "drawing"
QT_MOC_LITERAL(231, 5), // "graph"
QT_MOC_LITERAL(237, 7), // "serifsY"
QT_MOC_LITERAL(245, 4), // "draw"
QT_MOC_LITERAL(250, 6), // "serifs"
QT_MOC_LITERAL(257, 4), // "text"
QT_MOC_LITERAL(262, 1), // "i"
QT_MOC_LITERAL(264, 3), // "y_t"
QT_MOC_LITERAL(268, 9) // "serifsOnY"

    },
    "MainWindow\0on_btnChooseFile_clicked\0"
    "\0block\0value\0on_btnLoadData_clicked\0"
    "on_btnOutput_clicked\0on_btnCalculateMetrix_clicked\0"
    "group\0col\0writeRegion\0output\0needCheck\0"
    "inputInMas\0std::vector<double>\0prepDraw\0"
    "inputYearsAndNumbers\0drawing\0graph\0"
    "serifsY\0draw\0serifs\0text\0i\0y_t\0serifsOnY"
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
       3,    1,  117,    2, 0x08,    1 /* Private */,
       5,    0,  120,    2, 0x08,    3 /* Private */,
       6,    0,  121,    2, 0x08,    4 /* Private */,
       7,    0,  122,    2, 0x08,    5 /* Private */,
       8,    1,  123,    2, 0x08,    6 /* Private */,
      10,    0,  126,    2, 0x08,    8 /* Private */,
      11,    1,  127,    2, 0x08,    9 /* Private */,
      13,    1,  130,    2, 0x08,   11 /* Private */,
      15,    0,  133,    2, 0x08,   13 /* Private */,
      16,    0,  134,    2, 0x08,   14 /* Private */,
      17,    0,  135,    2, 0x08,   15 /* Private */,
      18,    1,  136,    2, 0x08,   16 /* Private */,
      20,    0,  139,    2, 0x08,   18 /* Private */,
      21,    0,  140,    2, 0x08,   19 /* Private */,
      22,    2,  141,    2, 0x08,   20 /* Private */,
      25,    0,  146,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,   12,
    0x80000000 | 14, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   23,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnChooseFile_clicked(); break;
        case 1: _t->block((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btnLoadData_clicked(); break;
        case 3: _t->on_btnOutput_clicked(); break;
        case 4: _t->on_btnCalculateMetrix_clicked(); break;
        case 5: _t->group((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { QString _r = _t->writeRegion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->output((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: { std::vector<double> _r = _t->inputInMas((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<double>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->prepDraw(); break;
        case 10: _t->inputYearsAndNumbers(); break;
        case 11: _t->drawing(); break;
        case 12: _t->graph((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->draw(); break;
        case 14: _t->serifs(); break;
        case 15: _t->text((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->serifsOnY(); break;
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

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
