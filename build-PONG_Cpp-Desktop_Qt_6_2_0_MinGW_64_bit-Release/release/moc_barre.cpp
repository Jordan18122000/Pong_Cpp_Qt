/****************************************************************************
** Meta object code from reading C++ file 'barre.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../Documents/GitHub/Pong_Cpp_Qt/PONG_Cpp/barre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Barre_t {
    const uint offsetsAndSize[12];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Barre_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Barre_t qt_meta_stringdata_Barre = {
    {
QT_MOC_LITERAL(0, 5), // "Barre"
QT_MOC_LITERAL(6, 6), // "height"
QT_MOC_LITERAL(13, 5), // "width"
QT_MOC_LITERAL(19, 8), // "MoveType"
QT_MOC_LITERAL(28, 2), // "UP"
QT_MOC_LITERAL(31, 4) // "DOWN"

    },
    "Barre\0height\0width\0MoveType\0UP\0DOWN"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Barre[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       1,   24, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00015001, uint(-1), 0,
       2, QMetaType::Int, 0x00015001, uint(-1), 0,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    2,   29,

 // enum data: key, value
       4, uint(Barre::UP),
       5, uint(Barre::DOWN),

       0        // eod
};

void Barre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Barre *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->height(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->width(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject Barre::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Barre.offsetsAndSize,
    qt_meta_data_Barre,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Barre_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<Barre, std::true_type>



>,
    nullptr
} };


const QMetaObject *Barre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Barre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Barre.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Barre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
