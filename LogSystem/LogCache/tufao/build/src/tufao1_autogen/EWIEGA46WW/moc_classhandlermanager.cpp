/****************************************************************************
** Meta object code from reading C++ file 'classhandlermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/classhandlermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classhandlermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tufao__ClassHandlerManager_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tufao__ClassHandlerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tufao__ClassHandlerManager_t qt_meta_stringdata_Tufao__ClassHandlerManager = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Tufao::ClassHandlerManager"
QT_MOC_LITERAL(1, 27, 13), // "handleRequest"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 18), // "HttpServerRequest&"
QT_MOC_LITERAL(4, 61, 7), // "request"
QT_MOC_LITERAL(5, 69, 19), // "HttpServerResponse&"
QT_MOC_LITERAL(6, 89, 8), // "response"
QT_MOC_LITERAL(7, 98, 12) // "urlNamespace"

    },
    "Tufao::ClassHandlerManager\0handleRequest\0"
    "\0HttpServerRequest&\0request\0"
    "HttpServerResponse&\0response\0urlNamespace"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tufao__ClassHandlerManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00095001,

       0        // eod
};

void Tufao::ClassHandlerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassHandlerManager *_t = static_cast<ClassHandlerManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->handleRequest((*reinterpret_cast< HttpServerRequest(*)>(_a[1])),(*reinterpret_cast< HttpServerResponse(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ClassHandlerManager *_t = static_cast<ClassHandlerManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->urlNamespace(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Tufao::ClassHandlerManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__ClassHandlerManager.data,
      qt_meta_data_Tufao__ClassHandlerManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tufao::ClassHandlerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tufao::ClassHandlerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__ClassHandlerManager.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "AbstractHttpServerRequestHandler"))
        return static_cast< AbstractHttpServerRequestHandler*>(this);
    return QObject::qt_metacast(_clname);
}

int Tufao::ClassHandlerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
