/****************************************************************************
** Meta object code from reading C++ file 'userobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sqlobjects/userobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserObject_t {
    QByteArrayData data[13];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserObject_t qt_meta_stringdata_UserObject = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserObject"
QT_MOC_LITERAL(1, 11, 2), // "id"
QT_MOC_LITERAL(2, 14, 8), // "username"
QT_MOC_LITERAL(3, 23, 8), // "password"
QT_MOC_LITERAL(4, 32, 5), // "email"
QT_MOC_LITERAL(5, 38, 4), // "name"
QT_MOC_LITERAL(6, 43, 7), // "credits"
QT_MOC_LITERAL(7, 51, 10), // "isElonMusk"
QT_MOC_LITERAL(8, 62, 7), // "isTesla"
QT_MOC_LITERAL(9, 70, 7), // "isHeart"
QT_MOC_LITERAL(10, 78, 6), // "isFire"
QT_MOC_LITERAL(11, 85, 10), // "fiftyFifty"
QT_MOC_LITERAL(12, 96, 11) // "hintGuesser"

    },
    "UserObject\0id\0username\0password\0email\0"
    "name\0credits\0isElonMusk\0isTesla\0isHeart\0"
    "isFire\0fiftyFifty\0hintGuesser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      12,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::Int, 0x00095003,
       7, QMetaType::Int, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::Int, 0x00095003,
      10, QMetaType::Int, 0x00095003,
      11, QMetaType::Int, 0x00095003,
      12, QMetaType::Int, 0x00095003,

       0        // eod
};

void UserObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UserObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getusername(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getpassword(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getemail(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getcredits(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getisElonMusk(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getisTesla(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getisHeart(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getisFire(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->getfiftyFifty(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->gethintGuesser(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UserObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setusername(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setpassword(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setemail(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setcredits(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setisElonMusk(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setisTesla(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setisHeart(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setisFire(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setfiftyFifty(*reinterpret_cast< int*>(_v)); break;
        case 11: _t->sethintGuesser(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject UserObject::staticMetaObject = { {
    QMetaObject::SuperData::link<TSqlObject::staticMetaObject>(),
    qt_meta_stringdata_UserObject.data,
    qt_meta_data_UserObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int UserObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
