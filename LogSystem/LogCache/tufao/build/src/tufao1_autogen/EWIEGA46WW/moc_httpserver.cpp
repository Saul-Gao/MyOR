/****************************************************************************
** Meta object code from reading C++ file 'httpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/httpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tufao__HttpServer_t {
    QByteArrayData data[13];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tufao__HttpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tufao__HttpServer_t qt_meta_stringdata_Tufao__HttpServer = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Tufao::HttpServer"
QT_MOC_LITERAL(1, 18, 12), // "requestReady"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "Tufao::HttpServerRequest&"
QT_MOC_LITERAL(4, 58, 7), // "request"
QT_MOC_LITERAL(5, 66, 26), // "Tufao::HttpServerResponse&"
QT_MOC_LITERAL(6, 93, 8), // "response"
QT_MOC_LITERAL(7, 102, 5), // "close"
QT_MOC_LITERAL(8, 108, 15), // "onNewConnection"
QT_MOC_LITERAL(9, 124, 7), // "qintptr"
QT_MOC_LITERAL(10, 132, 16), // "socketDescriptor"
QT_MOC_LITERAL(11, 149, 14), // "onRequestReady"
QT_MOC_LITERAL(12, 164, 9) // "onUpgrade"

    },
    "Tufao::HttpServer\0requestReady\0\0"
    "Tufao::HttpServerRequest&\0request\0"
    "Tufao::HttpServerResponse&\0response\0"
    "close\0onNewConnection\0qintptr\0"
    "socketDescriptor\0onRequestReady\0"
    "onUpgrade"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tufao__HttpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x08 /* Private */,
      11,    0,   48,    2, 0x08 /* Private */,
      12,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tufao::HttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpServer *_t = static_cast<HttpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestReady((*reinterpret_cast< Tufao::HttpServerRequest(*)>(_a[1])),(*reinterpret_cast< Tufao::HttpServerResponse(*)>(_a[2]))); break;
        case 1: _t->close(); break;
        case 2: _t->onNewConnection((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 3: _t->onRequestReady(); break;
        case 4: _t->onUpgrade(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (HttpServer::*_t)(Tufao::HttpServerRequest & , Tufao::HttpServerResponse & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::requestReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Tufao::HttpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tufao__HttpServer.data,
      qt_meta_data_Tufao__HttpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tufao::HttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tufao::HttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__HttpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tufao::HttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tufao::HttpServer::requestReady(Tufao::HttpServerRequest & _t1, Tufao::HttpServerResponse & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
