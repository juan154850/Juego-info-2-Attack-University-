/****************************************************************************
** Meta object code from reading C++ file 'nivel1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AttackUniversity/nivel1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nivel1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nivel1_t {
    QByteArrayData data[19];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nivel1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nivel1_t qt_meta_stringdata_nivel1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "nivel1"
QT_MOC_LITERAL(1, 7, 12), // "moverSoldado"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "moverArabe"
QT_MOC_LITERAL(4, 32, 7), // "Puertas"
QT_MOC_LITERAL(5, 40, 13), // "colisionArabe"
QT_MOC_LITERAL(6, 54, 17), // "moverBalasJugador"
QT_MOC_LITERAL(7, 72, 15), // "dispararSoldado"
QT_MOC_LITERAL(8, 88, 12), // "dispararBoss"
QT_MOC_LITERAL(9, 101, 17), // "ColisionBalasBoss"
QT_MOC_LITERAL(10, 119, 16), // "generarBalasBoss"
QT_MOC_LITERAL(11, 136, 9), // "moverBoss"
QT_MOC_LITERAL(12, 146, 5), // "CBJCB"
QT_MOC_LITERAL(13, 152, 17), // "colisionesJugador"
QT_MOC_LITERAL(14, 170, 8), // "dialogos"
QT_MOC_LITERAL(15, 179, 7), // "oleadas"
QT_MOC_LITERAL(16, 187, 16), // "on_SALIR_clicked"
QT_MOC_LITERAL(17, 204, 18), // "on_ARDUINO_clicked"
QT_MOC_LITERAL(18, 223, 24) // "on_GUARDAPARTIDA_clicked"

    },
    "nivel1\0moverSoldado\0\0moverArabe\0Puertas\0"
    "colisionArabe\0moverBalasJugador\0"
    "dispararSoldado\0dispararBoss\0"
    "ColisionBalasBoss\0generarBalasBoss\0"
    "moverBoss\0CBJCB\0colisionesJugador\0"
    "dialogos\0oleadas\0on_SALIR_clicked\0"
    "on_ARDUINO_clicked\0on_GUARDAPARTIDA_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nivel1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    0,  112,    2, 0x0a /* Public */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void nivel1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nivel1 *_t = static_cast<nivel1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moverSoldado(); break;
        case 1: _t->moverArabe(); break;
        case 2: _t->Puertas(); break;
        case 3: _t->colisionArabe(); break;
        case 4: _t->moverBalasJugador(); break;
        case 5: _t->dispararSoldado(); break;
        case 6: _t->dispararBoss(); break;
        case 7: _t->ColisionBalasBoss(); break;
        case 8: _t->generarBalasBoss(); break;
        case 9: _t->moverBoss(); break;
        case 10: _t->CBJCB(); break;
        case 11: _t->colisionesJugador(); break;
        case 12: _t->dialogos(); break;
        case 13: _t->oleadas(); break;
        case 14: _t->on_SALIR_clicked(); break;
        case 15: _t->on_ARDUINO_clicked(); break;
        case 16: _t->on_GUARDAPARTIDA_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject nivel1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nivel1.data,
      qt_meta_data_nivel1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nivel1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nivel1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nivel1.stringdata0))
        return static_cast<void*>(const_cast< nivel1*>(this));
    return QWidget::qt_metacast(_clname);
}

int nivel1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
