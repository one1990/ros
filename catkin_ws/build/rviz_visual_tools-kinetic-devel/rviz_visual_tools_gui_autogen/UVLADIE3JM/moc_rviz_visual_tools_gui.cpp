/****************************************************************************
** Meta object code from reading C++ file 'rviz_visual_tools_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz_visual_tools-kinetic-devel/src/rviz_visual_tools_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rviz_visual_tools_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui_t {
    QByteArrayData data[6];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui_t qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui = {
    {
QT_MOC_LITERAL(0, 0, 37), // "rviz_visual_tools::RvizVisual..."
QT_MOC_LITERAL(1, 38, 8), // "moveNext"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 8), // "moveAuto"
QT_MOC_LITERAL(4, 57, 12), // "moveFullAuto"
QT_MOC_LITERAL(5, 70, 8) // "moveStop"

    },
    "rviz_visual_tools::RvizVisualToolsGui\0"
    "moveNext\0\0moveAuto\0moveFullAuto\0"
    "moveStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rviz_visual_tools__RvizVisualToolsGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rviz_visual_tools::RvizVisualToolsGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RvizVisualToolsGui *_t = static_cast<RvizVisualToolsGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveNext(); break;
        case 1: _t->moveAuto(); break;
        case 2: _t->moveFullAuto(); break;
        case 3: _t->moveStop(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject rviz_visual_tools::RvizVisualToolsGui::staticMetaObject = {
    { &rviz::Panel::staticMetaObject, qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui.data,
      qt_meta_data_rviz_visual_tools__RvizVisualToolsGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *rviz_visual_tools::RvizVisualToolsGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rviz_visual_tools::RvizVisualToolsGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_rviz_visual_tools__RvizVisualToolsGui.stringdata0))
        return static_cast<void*>(const_cast< RvizVisualToolsGui*>(this));
    return rviz::Panel::qt_metacast(_clname);
}

int rviz_visual_tools::RvizVisualToolsGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::Panel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE