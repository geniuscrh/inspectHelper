/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inspectHelper/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[387];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "httpReplySlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 41, 5), // "reply"
QT_MOC_LITERAL(5, 47, 18), // "on_testBtn_clicked"
QT_MOC_LITERAL(6, 66, 19), // "on_loginBtn_clicked"
QT_MOC_LITERAL(7, 86, 25), // "on_getSiteListBtn_clicked"
QT_MOC_LITERAL(8, 112, 18), // "on_SignBtn_clicked"
QT_MOC_LITERAL(9, 131, 27), // "on_site_table_doubleClicked"
QT_MOC_LITERAL(10, 159, 5), // "index"
QT_MOC_LITERAL(11, 165, 23), // "on_checkSignBtn_clicked"
QT_MOC_LITERAL(12, 189, 24), // "on_checkSignBtn2_clicked"
QT_MOC_LITERAL(13, 214, 23), // "on_getPlanIdBtn_clicked"
QT_MOC_LITERAL(14, 238, 28), // "on_clearSiteTableBtn_clicked"
QT_MOC_LITERAL(15, 267, 23), // "on_getCookieBtn_clicked"
QT_MOC_LITERAL(16, 291, 23), // "on_timeStartBtn_clicked"
QT_MOC_LITERAL(17, 315, 10), // "updateTime"
QT_MOC_LITERAL(18, 326, 20), // "receiveAutoThreadMsg"
QT_MOC_LITERAL(19, 347, 9), // "ThreadMsg"
QT_MOC_LITERAL(20, 357, 1), // "s"
QT_MOC_LITERAL(21, 359, 8), // "loadSite"
QT_MOC_LITERAL(22, 368, 18) // "on_hideBtn_clicked"

    },
    "MainWindow\0httpReplySlot\0\0QNetworkReply*\0"
    "reply\0on_testBtn_clicked\0on_loginBtn_clicked\0"
    "on_getSiteListBtn_clicked\0on_SignBtn_clicked\0"
    "on_site_table_doubleClicked\0index\0"
    "on_checkSignBtn_clicked\0"
    "on_checkSignBtn2_clicked\0"
    "on_getPlanIdBtn_clicked\0"
    "on_clearSiteTableBtn_clicked\0"
    "on_getCookieBtn_clicked\0on_timeStartBtn_clicked\0"
    "updateTime\0receiveAutoThreadMsg\0"
    "ThreadMsg\0s\0loadSite\0on_hideBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      21,    1,  114,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->httpReplySlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->on_testBtn_clicked(); break;
        case 2: _t->on_loginBtn_clicked(); break;
        case 3: _t->on_getSiteListBtn_clicked(); break;
        case 4: _t->on_SignBtn_clicked(); break;
        case 5: _t->on_site_table_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_checkSignBtn_clicked(); break;
        case 7: _t->on_checkSignBtn2_clicked(); break;
        case 8: _t->on_getPlanIdBtn_clicked(); break;
        case 9: _t->on_clearSiteTableBtn_clicked(); break;
        case 10: _t->on_getCookieBtn_clicked(); break;
        case 11: _t->on_timeStartBtn_clicked(); break;
        case 12: _t->updateTime(); break;
        case 13: _t->receiveAutoThreadMsg((*reinterpret_cast< ThreadMsg(*)>(_a[1]))); break;
        case 14: _t->loadSite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_hideBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
