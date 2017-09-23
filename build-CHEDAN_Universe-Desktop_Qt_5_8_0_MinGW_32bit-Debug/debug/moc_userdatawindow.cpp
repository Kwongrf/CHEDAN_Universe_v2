/****************************************************************************
** Meta object code from reading C++ file 'userdatawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CHEDAN_Universe/userdatawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userdatawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserdataWindow_t {
    QByteArrayData data[8];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserdataWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserdataWindow_t qt_meta_stringdata_UserdataWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserdataWindow"
QT_MOC_LITERAL(1, 15, 27), // "on_changePassButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 27), // "on_changeNameButton_clicked"
QT_MOC_LITERAL(4, 72, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(5, 101, 5), // "index"
QT_MOC_LITERAL(6, 107, 30), // "on_tableWidget_2_doubleClicked"
QT_MOC_LITERAL(7, 138, 24) // "on_messageButton_clicked"

    },
    "UserdataWindow\0on_changePassButton_clicked\0"
    "\0on_changeNameButton_clicked\0"
    "on_tableWidget_doubleClicked\0index\0"
    "on_tableWidget_2_doubleClicked\0"
    "on_messageButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserdataWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,

       0        // eod
};

void UserdataWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserdataWindow *_t = static_cast<UserdataWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_changePassButton_clicked(); break;
        case 1: _t->on_changeNameButton_clicked(); break;
        case 2: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_tableWidget_2_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_messageButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject UserdataWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserdataWindow.data,
      qt_meta_data_UserdataWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserdataWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserdataWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserdataWindow.stringdata0))
        return static_cast<void*>(const_cast< UserdataWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserdataWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
