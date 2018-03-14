/****************************************************************************
** Meta object code from reading C++ file 'TutorialGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TutorialGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TutorialGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TutorialGUI_t {
    QByteArrayData data[16];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TutorialGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TutorialGUI_t qt_meta_stringdata_TutorialGUI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TutorialGUI"
QT_MOC_LITERAL(1, 12, 7), // "filterT"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "addNewTutorial"
QT_MOC_LITERAL(4, 36, 14), // "deleteTutorial"
QT_MOC_LITERAL(5, 51, 14), // "updateTutorial"
QT_MOC_LITERAL(6, 66, 17), // "sortButtonHandler"
QT_MOC_LITERAL(7, 84, 17), // "undoButtonHandler"
QT_MOC_LITERAL(8, 102, 12), // "playTutorial"
QT_MOC_LITERAL(9, 115, 12), // "nextTutorial"
QT_MOC_LITERAL(10, 128, 12), // "rateTutorial"
QT_MOC_LITERAL(11, 141, 8), // "deletePL"
QT_MOC_LITERAL(12, 150, 4), // "save"
QT_MOC_LITERAL(13, 155, 4), // "open"
QT_MOC_LITERAL(14, 160, 17), // "viewButtonHandler"
QT_MOC_LITERAL(15, 178, 12) // "populateView"

    },
    "TutorialGUI\0filterT\0\0addNewTutorial\0"
    "deleteTutorial\0updateTutorial\0"
    "sortButtonHandler\0undoButtonHandler\0"
    "playTutorial\0nextTutorial\0rateTutorial\0"
    "deletePL\0save\0open\0viewButtonHandler\0"
    "populateView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TutorialGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void TutorialGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TutorialGUI *_t = static_cast<TutorialGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterT(); break;
        case 1: _t->addNewTutorial(); break;
        case 2: _t->deleteTutorial(); break;
        case 3: _t->updateTutorial(); break;
        case 4: _t->sortButtonHandler(); break;
        case 5: _t->undoButtonHandler(); break;
        case 6: _t->playTutorial(); break;
        case 7: _t->nextTutorial(); break;
        case 8: _t->rateTutorial(); break;
        case 9: _t->deletePL(); break;
        case 10: _t->save(); break;
        case 11: _t->open(); break;
        case 12: _t->viewButtonHandler(); break;
        case 13: _t->populateView(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TutorialGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TutorialGUI.data,
      qt_meta_data_TutorialGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TutorialGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TutorialGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TutorialGUI.stringdata0))
        return static_cast<void*>(const_cast< TutorialGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int TutorialGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
