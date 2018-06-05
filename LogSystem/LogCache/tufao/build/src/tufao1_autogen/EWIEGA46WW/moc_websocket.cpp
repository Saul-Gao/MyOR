/****************************************************************************
** Meta object code from reading C++ file 'websocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/websocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tufao__WebSocket_t {
    QByteArrayData data[19];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tufao__WebSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tufao__WebSocket_t qt_meta_stringdata_Tufao__WebSocket = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Tufao::WebSocket"
QT_MOC_LITERAL(1, 17, 4), // "pong"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "data"
QT_MOC_LITERAL(4, 28, 5), // "close"
QT_MOC_LITERAL(5, 34, 11), // "sendMessage"
QT_MOC_LITERAL(6, 46, 3), // "msg"
QT_MOC_LITERAL(7, 50, 17), // "sendBinaryMessage"
QT_MOC_LITERAL(8, 68, 15), // "sendUtf8Message"
QT_MOC_LITERAL(9, 84, 4), // "ping"
QT_MOC_LITERAL(10, 89, 13), // "onSocketError"
QT_MOC_LITERAL(11, 103, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 132, 5), // "error"
QT_MOC_LITERAL(13, 138, 11), // "onSslErrors"
QT_MOC_LITERAL(14, 150, 16), // "QList<QSslError>"
QT_MOC_LITERAL(15, 167, 6), // "errors"
QT_MOC_LITERAL(16, 174, 11), // "onConnected"
QT_MOC_LITERAL(17, 186, 11), // "onReadyRead"
QT_MOC_LITERAL(18, 198, 14) // "onDisconnected"

    },
    "Tufao::WebSocket\0pong\0\0data\0close\0"
    "sendMessage\0msg\0sendBinaryMessage\0"
    "sendUtf8Message\0ping\0onSocketError\0"
    "QAbstractSocket::SocketError\0error\0"
    "onSslErrors\0QList<QSslError>\0errors\0"
    "onConnected\0onReadyRead\0onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tufao__WebSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   72,    2, 0x0a /* Public */,
       5,    1,   73,    2, 0x0a /* Public */,
       7,    1,   76,    2, 0x0a /* Public */,
       8,    1,   79,    2, 0x0a /* Public */,
       9,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x08 /* Private */,
      13,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    0,   92,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QByteArray,    6,
    QMetaType::Bool, QMetaType::QByteArray,    6,
    QMetaType::Bool, QMetaType::QByteArray,    6,
    QMetaType::Bool, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tufao::WebSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebSocket *_t = static_cast<WebSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pong((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->close(); break;
        case 2: { bool _r = _t->sendMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->sendBinaryMessage((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->sendUtf8Message((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->ping((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->onSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 8: _t->onConnected(); break;
        case 9: _t->onReadyRead(); break;
        case 10: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WebSocket::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocket::pong)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Tufao::WebSocket::staticMetaObject = {
    { &AbstractMessageSocket::staticMetaObject, qt_meta_stringdata_Tufao__WebSocket.data,
      qt_meta_data_Tufao__WebSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tufao::WebSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tufao::WebSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tufao__WebSocket.stringdata0))
        return static_cast<void*>(this);
    return AbstractMessageSocket::qt_metacast(_clname);
}

int Tufao::WebSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractMessageSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Tufao::WebSocket::pong(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
