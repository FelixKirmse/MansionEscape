/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created: Fri Nov 23 12:19:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/GUI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MansionEscape__GUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      48,   19,   19,   19, 0x08,
      76,   19,   19,   19, 0x08,
     104,   19,   19,   19, 0x08,
     135,   19,   19,   19, 0x08,
     162,   19,   19,   19, 0x08,
     189,   19,   19,   19, 0x08,
     217,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MansionEscape__GUI[] = {
    "MansionEscape::GUI\0\0on_Context1Button_pressed()\0"
    "on_Context2Button_pressed()\0"
    "on_Context3Button_pressed()\0"
    "on_CommentItemButton_pressed()\0"
    "on_InspectButton_pressed()\0"
    "on_ForwardButton_pressed()\0"
    "on_TurnLeftButton_pressed()\0"
    "on_TurnRightButton_pressed()\0"
};

void MansionEscape::GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GUI *_t = static_cast<GUI *>(_o);
        switch (_id) {
        case 0: _t->on_Context1Button_pressed(); break;
        case 1: _t->on_Context2Button_pressed(); break;
        case 2: _t->on_Context3Button_pressed(); break;
        case 3: _t->on_CommentItemButton_pressed(); break;
        case 4: _t->on_InspectButton_pressed(); break;
        case 5: _t->on_ForwardButton_pressed(); break;
        case 6: _t->on_TurnLeftButton_pressed(); break;
        case 7: _t->on_TurnRightButton_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MansionEscape::GUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MansionEscape::GUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MansionEscape__GUI,
      qt_meta_data_MansionEscape__GUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MansionEscape::GUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MansionEscape::GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MansionEscape::GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MansionEscape__GUI))
        return static_cast<void*>(const_cast< GUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MansionEscape::GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
