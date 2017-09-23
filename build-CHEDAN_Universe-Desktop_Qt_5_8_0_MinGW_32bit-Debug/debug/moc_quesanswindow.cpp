/****************************************************************************
** Meta object code from reading C++ file 'quesanswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CHEDAN_Universe/quesanswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quesanswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuesAnsWindow_t {
    QByteArrayData data[13];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuesAnsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuesAnsWindow_t qt_meta_stringdata_QuesAnsWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QuesAnsWindow"
QT_MOC_LITERAL(1, 14, 27), // "on_answerQuesButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(4, 66, 5), // "index"
QT_MOC_LITERAL(5, 72, 22), // "on_freshButton_clicked"
QT_MOC_LITERAL(6, 95, 23), // "on_praiseButton_clicked"
QT_MOC_LITERAL(7, 119, 24), // "on_focusTZButton_clicked"
QT_MOC_LITERAL(8, 144, 24), // "on_focusDZButton_clicked"
QT_MOC_LITERAL(9, 169, 23), // "on_inviteButton_clicked"
QT_MOC_LITERAL(10, 193, 24), // "on_aboutTZButton_clicked"
QT_MOC_LITERAL(11, 218, 24), // "on_aboutDZButton_clicked"
QT_MOC_LITERAL(12, 243, 24) // "on_commentButton_clicked"

    },
    "QuesAnsWindow\0on_answerQuesButton_clicked\0"
    "\0on_tableWidget_clicked\0index\0"
    "on_freshButton_clicked\0on_praiseButton_clicked\0"
    "on_focusTZButton_clicked\0"
    "on_focusDZButton_clicked\0"
    "on_inviteButton_clicked\0"
    "on_aboutTZButton_clicked\0"
    "on_aboutDZButton_clicked\0"
    "on_commentButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuesAnsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuesAnsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuesAnsWindow *_t = static_cast<QuesAnsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_answerQuesButton_clicked(); break;
        case 1: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_freshButton_clicked(); break;
        case 3: _t->on_praiseButton_clicked(); break;
        case 4: _t->on_focusTZButton_clicked(); break;
        case 5: _t->on_focusDZButton_clicked(); break;
        case 6: _t->on_inviteButton_clicked(); break;
        case 7: _t->on_aboutTZButton_clicked(); break;
        case 8: _t->on_aboutDZButton_clicked(); break;
        case 9: _t->on_commentButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QuesAnsWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QuesAnsWindow.data,
      qt_meta_data_QuesAnsWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QuesAnsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuesAnsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QuesAnsWindow.stringdata0))
        return static_cast<void*>(const_cast< QuesAnsWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int QuesAnsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
