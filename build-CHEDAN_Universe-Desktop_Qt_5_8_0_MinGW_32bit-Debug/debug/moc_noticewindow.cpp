/****************************************************************************
** Meta object code from reading C++ file 'noticewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CHEDAN_Universe/noticewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noticewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NoticeWindow_t {
    QByteArrayData data[9];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoticeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoticeWindow_t qt_meta_stringdata_NoticeWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "NoticeWindow"
QT_MOC_LITERAL(1, 13, 23), // "on_noticeButton_toggled"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "checked"
QT_MOC_LITERAL(4, 46, 23), // "on_praiseButton_toggled"
QT_MOC_LITERAL(5, 70, 22), // "on_focusButton_toggled"
QT_MOC_LITERAL(6, 93, 24), // "on_messageButton_toggled"
QT_MOC_LITERAL(7, 118, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(8, 147, 5) // "index"

    },
    "NoticeWindow\0on_noticeButton_toggled\0"
    "\0checked\0on_praiseButton_toggled\0"
    "on_focusButton_toggled\0on_messageButton_toggled\0"
    "on_tableWidget_doubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoticeWindow[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void NoticeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NoticeWindow *_t = static_cast<NoticeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_noticeButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_praiseButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_focusButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_messageButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NoticeWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NoticeWindow.data,
      qt_meta_data_NoticeWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NoticeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoticeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NoticeWindow.stringdata0))
        return static_cast<void*>(const_cast< NoticeWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int NoticeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
