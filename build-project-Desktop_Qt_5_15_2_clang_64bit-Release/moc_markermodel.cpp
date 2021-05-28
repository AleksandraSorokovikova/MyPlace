/****************************************************************************
** Meta object code from reading C++ file 'markermodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../client/include/markermodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'markermodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MarkerModel_t {
    QByteArrayData data[16];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarkerModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarkerModel_t qt_meta_stringdata_MarkerModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MarkerModel"
QT_MOC_LITERAL(1, 12, 15), // "propertyChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "address_"
QT_MOC_LITERAL(4, 38, 13), // "changeGeocode"
QT_MOC_LITERAL(5, 52, 11), // "set_address"
QT_MOC_LITERAL(6, 64, 14), // "set_coordinate"
QT_MOC_LITERAL(7, 79, 14), // "QGeoCoordinate"
QT_MOC_LITERAL(8, 94, 11), // "coordinate_"
QT_MOC_LITERAL(9, 106, 11), // "get_address"
QT_MOC_LITERAL(10, 118, 9), // "addMarker"
QT_MOC_LITERAL(11, 128, 10), // "coordinate"
QT_MOC_LITERAL(12, 139, 10), // "showMarker"
QT_MOC_LITERAL(13, 150, 9), // "longitude"
QT_MOC_LITERAL(14, 160, 8), // "latitude"
QT_MOC_LITERAL(15, 169, 12) // "insertMarker"

    },
    "MarkerModel\0propertyChanged\0\0address_\0"
    "changeGeocode\0set_address\0set_coordinate\0"
    "QGeoCoordinate\0coordinate_\0get_address\0"
    "addMarker\0coordinate\0showMarker\0"
    "longitude\0latitude\0insertMarker"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarkerModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   63,    2, 0x02 /* Public */,
       6,    1,   66,    2, 0x02 /* Public */,
       9,    0,   69,    2, 0x02 /* Public */,
      10,    1,   70,    2, 0x02 /* Public */,
      10,    0,   73,    2, 0x22 /* Public | MethodCloned */,
      12,    2,   74,    2, 0x02 /* Public */,
      15,    1,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 7,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   13,   14,
    QMetaType::Void, 0x80000000 | 7,   11,

       0        // eod
};

void MarkerModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MarkerModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->propertyChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->changeGeocode(); break;
        case 2: _t->set_address((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->set_coordinate((*reinterpret_cast< const QGeoCoordinate(*)>(_a[1]))); break;
        case 4: { QString _r = _t->get_address();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->addMarker((*reinterpret_cast< const QGeoCoordinate(*)>(_a[1]))); break;
        case 6: _t->addMarker(); break;
        case 7: _t->showMarker((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->insertMarker((*reinterpret_cast< const QGeoCoordinate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoCoordinate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MarkerModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MarkerModel::propertyChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MarkerModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_MarkerModel.data,
    qt_meta_data_MarkerModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MarkerModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarkerModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MarkerModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int MarkerModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MarkerModel::propertyChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
