/****************************************************************************
** Meta object code from reading C++ file 'meteo_statistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../meteo_statistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meteo_statistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_meteo_statistics_t {
    QByteArrayData data[6];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_meteo_statistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_meteo_statistics_t qt_meta_stringdata_meteo_statistics = {
    {
QT_MOC_LITERAL(0, 0, 16), // "meteo_statistics"
QT_MOC_LITERAL(1, 17, 20), // "calculate_statistics"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 33), // "on_unit_combo_currentIndexCha..."
QT_MOC_LITERAL(4, 73, 11), // "import_data"
QT_MOC_LITERAL(5, 85, 18) // "SQL_set_connection"

    },
    "meteo_statistics\0calculate_statistics\0"
    "\0on_unit_combo_currentIndexChanged\0"
    "import_data\0SQL_set_connection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_meteo_statistics[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void meteo_statistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        meteo_statistics *_t = static_cast<meteo_statistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->calculate_statistics();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->on_unit_combo_currentIndexChanged();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->import_data(); break;
        case 3: _t->SQL_set_connection(); break;
        default: ;
        }
    }
}

const QMetaObject meteo_statistics::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_meteo_statistics.data,
      qt_meta_data_meteo_statistics,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *meteo_statistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *meteo_statistics::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_meteo_statistics.stringdata0))
        return static_cast<void*>(const_cast< meteo_statistics*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int meteo_statistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
