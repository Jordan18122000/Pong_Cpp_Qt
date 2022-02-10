/****************************************************************************
** Meta object code from reading C++ file 'balle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../Documents/GitHub/Pong_Cpp_Qt/PONG_Cpp/balle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'balle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Balle_t {
    const uint offsetsAndSize[14];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Balle_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Balle_t qt_meta_stringdata_Balle = {
    {
QT_MOC_LITERAL(0, 5), // "Balle"
QT_MOC_LITERAL(6, 9), // "resetBall"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 4), // "move"
QT_MOC_LITERAL(22, 5), // "width"
QT_MOC_LITERAL(28, 6), // "height"
QT_MOC_LITERAL(35, 5) // "speed"

    },
    "Balle\0resetBall\0\0move\0width\0height\0"
    "speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Balle[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00015001, uint(-1), 0,
       5, QMetaType::Int, 0x00015001, uint(-1), 0,
       6, QMetaType::Int, 0x00015001, uint(-1), 0,

       0        // eod
};

void Balle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Balle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetBall(); break;
        case 1: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Balle::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Balle::resetBall)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Balle *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->width(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->height(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

const QMetaObject Balle::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Balle.offsetsAndSize,
    qt_meta_data_Balle,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Balle_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<Balle, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Balle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Balle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Balle.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Balle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Balle::resetBall()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
