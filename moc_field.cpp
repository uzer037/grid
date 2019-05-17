/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Field_t {
    QByteArrayData data[15];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Field_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Field_t qt_meta_stringdata_Field = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Field"
QT_MOC_LITERAL(1, 6, 7), // "resized"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 16), // "renameRootWindow"
QT_MOC_LITERAL(4, 32, 9), // "gPrintStr"
QT_MOC_LITERAL(5, 42, 10), // "gTimeStart"
QT_MOC_LITERAL(6, 53, 9), // "gTimeStop"
QT_MOC_LITERAL(7, 63, 4), // "load"
QT_MOC_LITERAL(8, 68, 4), // "game"
QT_MOC_LITERAL(9, 73, 9), // "gameCheck"
QT_MOC_LITERAL(10, 83, 8), // "gameLoop"
QT_MOC_LITERAL(11, 92, 13), // "compPoints_or"
QT_MOC_LITERAL(12, 106, 2), // "p1"
QT_MOC_LITERAL(13, 109, 2), // "p2"
QT_MOC_LITERAL(14, 112, 14) // "compPoints_and"

    },
    "Field\0resized\0\0renameRootWindow\0"
    "gPrintStr\0gTimeStart\0gTimeStop\0load\0"
    "game\0gameCheck\0gameLoop\0compPoints_or\0"
    "p1\0p2\0compPoints_and"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Field[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    2,   78,    2, 0x0a /* Public */,
      14,    2,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QPointF, QMetaType::QPointF,   12,   13,
    QMetaType::Bool, QMetaType::QPointF, QMetaType::QPointF,   12,   13,

       0        // eod
};

void Field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Field *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resized(); break;
        case 1: _t->renameRootWindow(); break;
        case 2: _t->gPrintStr(); break;
        case 3: _t->gTimeStart(); break;
        case 4: _t->gTimeStop(); break;
        case 5: _t->load(); break;
        case 6: _t->game(); break;
        case 7: _t->gameCheck(); break;
        case 8: _t->gameLoop(); break;
        case 9: { bool _r = _t->compPoints_or((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->compPoints_and((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Field::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Field::resized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Field::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Field::renameRootWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Field::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Field::gPrintStr)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Field::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Field::gTimeStart)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Field::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Field::gTimeStop)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Field::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_Field.data,
    qt_meta_data_Field,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Field::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Field.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Field::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Field::renameRootWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Field::gPrintStr()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Field::gTimeStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Field::gTimeStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
