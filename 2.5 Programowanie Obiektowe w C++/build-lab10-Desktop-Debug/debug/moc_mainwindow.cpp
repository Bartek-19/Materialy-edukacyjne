/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab10/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     115,  110,   11,   11, 0x08,
     155,  148,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     304,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     358,   11,   11,   11, 0x08,
     385,   11,   11,   11, 0x08,
     412,   11,   11,   11, 0x08,
     439,   11,   11,   11, 0x08,
     466,   11,   11,   11, 0x08,
     493,   11,   11,   11, 0x08,
     520,   11,   11,   11, 0x08,
     548,   11,   11,   11, 0x08,
     576,   11,   11,   11, 0x08,
     603,   11,   11,   11, 0x08,
     627,   11,   11,   11, 0x08,
     651,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_checkBox_clicked()\0date\0"
    "on_calendarWidget_clicked(QDate)\0"
    "action\0on_horizontalScrollBar_actionTriggered(int)\0"
    "on_pushButton_4_clicked()\0"
    "on_Button_10_6_1_clicked()\0"
    "on_Button_10_6_2_clicked()\0"
    "on_Button_10_7_clicked()\0"
    "on_Button_10_8_1_clicked()\0"
    "on_Button_10_8_2_clicked()\0"
    "on_Button_10_8_3_clicked()\0"
    "on_Button_10_9_1_clicked()\0"
    "on_Button_10_9_2_clicked()\0"
    "on_Button_10_9_3_clicked()\0"
    "on_actionPokaz_triggered()\0"
    "on_actionUkryj_triggered()\0"
    "on_actionKopiuj_triggered()\0"
    "on_actionWytnij_triggered()\0"
    "on_actionWklej_triggered()\0"
    "on_actionK1_triggered()\0on_actionK2_triggered()\0"
    "on_actionK3_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_checkBox_clicked(); break;
        case 4: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->on_horizontalScrollBar_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_Button_10_6_1_clicked(); break;
        case 8: _t->on_Button_10_6_2_clicked(); break;
        case 9: _t->on_Button_10_7_clicked(); break;
        case 10: _t->on_Button_10_8_1_clicked(); break;
        case 11: _t->on_Button_10_8_2_clicked(); break;
        case 12: _t->on_Button_10_8_3_clicked(); break;
        case 13: _t->on_Button_10_9_1_clicked(); break;
        case 14: _t->on_Button_10_9_2_clicked(); break;
        case 15: _t->on_Button_10_9_3_clicked(); break;
        case 16: _t->on_actionPokaz_triggered(); break;
        case 17: _t->on_actionUkryj_triggered(); break;
        case 18: _t->on_actionKopiuj_triggered(); break;
        case 19: _t->on_actionWytnij_triggered(); break;
        case 20: _t->on_actionWklej_triggered(); break;
        case 21: _t->on_actionK1_triggered(); break;
        case 22: _t->on_actionK2_triggered(); break;
        case 23: _t->on_actionK3_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
