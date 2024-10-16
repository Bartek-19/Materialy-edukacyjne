/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCalendarWidget *data;
    QLabel *naglowek;
    QLabel *DataLabel;
    QGroupBox *Dane;
    QLabel *Kg_2;
    QLabel *KategoriaLabel;
    QLabel *PowtLabel;
    QPushButton *PrzejdzDo;
    QPushButton *dodaj;
    QLabel *MasaLabel;
    QLabel *CwiczenieLabel;
    QLabel *Kg;
    QLineEdit *cwiczenie;
    QLineEdit *masa;
    QComboBox *kategoria;
    QSpinBox *powtorzenia;
    QSpinBox *serie;
    QLabel *CiezarLabel;
    QLabel *Adnotacja2;
    QLabel *SerieLabel;
    QLabel *Adnotacja;
    QLineEdit *ciezar;
    QGroupBox *Wyniki;
    QPushButton *Wyczysc;
    QLabel *P1;
    QLabel *P2;
    QLabel *Kg_3;
    QLabel *Podsumowanie;
    QLabel *P3;
    QListWidget *ListaCiezarow;
    QLabel *DataPodsumowania;
    QLineEdit *PodsStatus;
    QLineEdit *PodsWielokrotnosc;
    QLabel *zalecenie;
    QListWidget *ListaCwiczen;
    QListWidget *ListaVol;
    QLineEdit *PodsCiezar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(881, 776);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        data = new QCalendarWidget(centralWidget);
        data->setObjectName(QString::fromUtf8("data"));
        data->setGeometry(QRect(40, 150, 401, 201));
        QFont font;
        font.setPointSize(10);
        data->setFont(font);
        naglowek = new QLabel(centralWidget);
        naglowek->setObjectName(QString::fromUtf8("naglowek"));
        naglowek->setGeometry(QRect(240, 10, 351, 31));
        QFont font1;
        font1.setPointSize(13);
        naglowek->setFont(font1);
        DataLabel = new QLabel(centralWidget);
        DataLabel->setObjectName(QString::fromUtf8("DataLabel"));
        DataLabel->setGeometry(QRect(40, 119, 161, 21));
        DataLabel->setFont(font);
        Dane = new QGroupBox(centralWidget);
        Dane->setObjectName(QString::fromUtf8("Dane"));
        Dane->setGeometry(QRect(470, 50, 391, 401));
        Kg_2 = new QLabel(Dane);
        Kg_2->setObjectName(QString::fromUtf8("Kg_2"));
        Kg_2->setGeometry(QRect(230, 30, 53, 21));
        KategoriaLabel = new QLabel(Dane);
        KategoriaLabel->setObjectName(QString::fromUtf8("KategoriaLabel"));
        KategoriaLabel->setGeometry(QRect(20, 120, 181, 21));
        QFont font2;
        font2.setPointSize(9);
        KategoriaLabel->setFont(font2);
        PowtLabel = new QLabel(Dane);
        PowtLabel->setObjectName(QString::fromUtf8("PowtLabel"));
        PowtLabel->setGeometry(QRect(20, 200, 151, 21));
        PowtLabel->setFont(font2);
        PrzejdzDo = new QPushButton(Dane);
        PrzejdzDo->setObjectName(QString::fromUtf8("PrzejdzDo"));
        PrzejdzDo->setGeometry(QRect(20, 360, 351, 28));
        PrzejdzDo->setFont(font);
        dodaj = new QPushButton(Dane);
        dodaj->setObjectName(QString::fromUtf8("dodaj"));
        dodaj->setGeometry(QRect(20, 310, 351, 28));
        dodaj->setFont(font);
        MasaLabel = new QLabel(Dane);
        MasaLabel->setObjectName(QString::fromUtf8("MasaLabel"));
        MasaLabel->setGeometry(QRect(20, 30, 161, 21));
        MasaLabel->setFont(font2);
        CwiczenieLabel = new QLabel(Dane);
        CwiczenieLabel->setObjectName(QString::fromUtf8("CwiczenieLabel"));
        CwiczenieLabel->setGeometry(QRect(20, 80, 161, 21));
        CwiczenieLabel->setFont(font2);
        Kg = new QLabel(Dane);
        Kg->setObjectName(QString::fromUtf8("Kg"));
        Kg->setGeometry(QRect(220, 240, 53, 21));
        cwiczenie = new QLineEdit(Dane);
        cwiczenie->setObjectName(QString::fromUtf8("cwiczenie"));
        cwiczenie->setGeometry(QRect(180, 80, 171, 22));
        masa = new QLineEdit(Dane);
        masa->setObjectName(QString::fromUtf8("masa"));
        masa->setGeometry(QRect(180, 30, 51, 22));
        kategoria = new QComboBox(Dane);
        kategoria->setObjectName(QString::fromUtf8("kategoria"));
        kategoria->setGeometry(QRect(200, 120, 171, 22));
        kategoria->setFont(font2);
        kategoria->setEditable(true);
        powtorzenia = new QSpinBox(Dane);
        powtorzenia->setObjectName(QString::fromUtf8("powtorzenia"));
        powtorzenia->setGeometry(QRect(170, 200, 42, 22));
        serie = new QSpinBox(Dane);
        serie->setObjectName(QString::fromUtf8("serie"));
        serie->setGeometry(QRect(130, 160, 42, 22));
        CiezarLabel = new QLabel(Dane);
        CiezarLabel->setObjectName(QString::fromUtf8("CiezarLabel"));
        CiezarLabel->setGeometry(QRect(20, 240, 151, 21));
        CiezarLabel->setFont(font2);
        Adnotacja2 = new QLabel(Dane);
        Adnotacja2->setObjectName(QString::fromUtf8("Adnotacja2"));
        Adnotacja2->setGeometry(QRect(20, 280, 331, 16));
        SerieLabel = new QLabel(Dane);
        SerieLabel->setObjectName(QString::fromUtf8("SerieLabel"));
        SerieLabel->setGeometry(QRect(20, 160, 111, 21));
        SerieLabel->setFont(font2);
        Adnotacja = new QLabel(Dane);
        Adnotacja->setObjectName(QString::fromUtf8("Adnotacja"));
        Adnotacja->setGeometry(QRect(20, 260, 351, 21));
        ciezar = new QLineEdit(Dane);
        ciezar->setObjectName(QString::fromUtf8("ciezar"));
        ciezar->setGeometry(QRect(170, 240, 51, 22));
        Wyniki = new QGroupBox(centralWidget);
        Wyniki->setObjectName(QString::fromUtf8("Wyniki"));
        Wyniki->setGeometry(QRect(30, 460, 831, 261));
        Wyczysc = new QPushButton(Wyniki);
        Wyczysc->setObjectName(QString::fromUtf8("Wyczysc"));
        Wyczysc->setGeometry(QRect(460, 210, 311, 28));
        Wyczysc->setFont(font);
        P1 = new QLabel(Wyniki);
        P1->setObjectName(QString::fromUtf8("P1"));
        P1->setGeometry(QRect(460, 50, 211, 21));
        P1->setFont(font2);
        P2 = new QLabel(Wyniki);
        P2->setObjectName(QString::fromUtf8("P2"));
        P2->setGeometry(QRect(460, 90, 251, 21));
        P2->setFont(font2);
        Kg_3 = new QLabel(Wyniki);
        Kg_3->setObjectName(QString::fromUtf8("Kg_3"));
        Kg_3->setGeometry(QRect(740, 50, 41, 21));
        Podsumowanie = new QLabel(Wyniki);
        Podsumowanie->setObjectName(QString::fromUtf8("Podsumowanie"));
        Podsumowanie->setGeometry(QRect(10, 20, 121, 21));
        Podsumowanie->setFont(font2);
        P3 = new QLabel(Wyniki);
        P3->setObjectName(QString::fromUtf8("P3"));
        P3->setGeometry(QRect(460, 130, 111, 21));
        P3->setFont(font2);
        ListaCiezarow = new QListWidget(Wyniki);
        ListaCiezarow->setObjectName(QString::fromUtf8("ListaCiezarow"));
        ListaCiezarow->setGeometry(QRect(340, 50, 61, 192));
        DataPodsumowania = new QLabel(Wyniki);
        DataPodsumowania->setObjectName(QString::fromUtf8("DataPodsumowania"));
        DataPodsumowania->setGeometry(QRect(130, 20, 111, 21));
        DataPodsumowania->setFont(font2);
        PodsStatus = new QLineEdit(Wyniki);
        PodsStatus->setObjectName(QString::fromUtf8("PodsStatus"));
        PodsStatus->setGeometry(QRect(570, 130, 81, 22));
        PodsStatus->setReadOnly(true);
        PodsWielokrotnosc = new QLineEdit(Wyniki);
        PodsWielokrotnosc->setObjectName(QString::fromUtf8("PodsWielokrotnosc"));
        PodsWielokrotnosc->setGeometry(QRect(710, 90, 61, 22));
        PodsWielokrotnosc->setReadOnly(true);
        zalecenie = new QLabel(Wyniki);
        zalecenie->setObjectName(QString::fromUtf8("zalecenie"));
        zalecenie->setGeometry(QRect(460, 170, 351, 21));
        zalecenie->setFont(font2);
        ListaCwiczen = new QListWidget(Wyniki);
        ListaCwiczen->setObjectName(QString::fromUtf8("ListaCwiczen"));
        ListaCwiczen->setGeometry(QRect(10, 50, 241, 192));
        ListaVol = new QListWidget(Wyniki);
        ListaVol->setObjectName(QString::fromUtf8("ListaVol"));
        ListaVol->setGeometry(QRect(260, 50, 71, 192));
        PodsCiezar = new QLineEdit(Wyniki);
        PodsCiezar->setObjectName(QString::fromUtf8("PodsCiezar"));
        PodsCiezar->setGeometry(QRect(680, 50, 61, 22));
        PodsCiezar->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        kategoria->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        naglowek->setText(QApplication::translate("MainWindow", "Kalkulator obci\304\205\305\274enia treningowego", 0, QApplication::UnicodeUTF8));
        DataLabel->setText(QApplication::translate("MainWindow", "Podaj dat\304\231 treningu", 0, QApplication::UnicodeUTF8));
        Dane->setTitle(QApplication::translate("MainWindow", "Dane do klakulatora", 0, QApplication::UnicodeUTF8));
        Kg_2->setText(QApplication::translate("MainWindow", "  kg", 0, QApplication::UnicodeUTF8));
        KategoriaLabel->setText(QApplication::translate("MainWindow", "Podaj kategori\304\231 \304\207wiczenia", 0, QApplication::UnicodeUTF8));
        PowtLabel->setText(QApplication::translate("MainWindow", "Podaj ilo\305\233\304\207 powt\303\263rze\305\204", 0, QApplication::UnicodeUTF8));
        PrzejdzDo->setText(QApplication::translate("MainWindow", "Przejd\305\272 do podsumowania", 0, QApplication::UnicodeUTF8));
        dodaj->setText(QApplication::translate("MainWindow", "Dodaj \304\207wiczenie", 0, QApplication::UnicodeUTF8));
        MasaLabel->setText(QApplication::translate("MainWindow", "Podaj swoj\304\205 mas\304\231 cia\305\202a", 0, QApplication::UnicodeUTF8));
        CwiczenieLabel->setText(QApplication::translate("MainWindow", "Podaj nazw\304\231 \304\207wiczenia", 0, QApplication::UnicodeUTF8));
        Kg->setText(QApplication::translate("MainWindow", "  kg", 0, QApplication::UnicodeUTF8));
        kategoria->clear();
        kategoria->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\304\206wiczenie si\305\202owe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Olimp. podn. ci\304\231\305\274ar\303\263w", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hipertroficzne", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Plajometryczne", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Akcesoryjne", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rehabilitacyjne", 0, QApplication::UnicodeUTF8)
        );
        kategoria->setCurrentText(QApplication::translate("MainWindow", "\304\206wiczenie si\305\202owe", 0, QApplication::UnicodeUTF8));
        CiezarLabel->setText(QApplication::translate("MainWindow", "Podaj ci\304\231\305\274ar roboczy*", 0, QApplication::UnicodeUTF8));
        Adnotacja2->setText(QApplication::translate("MainWindow", "  mas\304\231 cia\305\202a + ew. dodatkowe obci\304\205\305\274enie", 0, QApplication::UnicodeUTF8));
        SerieLabel->setText(QApplication::translate("MainWindow", "Podaj ilo\305\233\304\207 serii", 0, QApplication::UnicodeUTF8));
        Adnotacja->setText(QApplication::translate("MainWindow", "*w przypadku \304\207wiczenia z w\305\202asn\304\205 mas\304\205 cia\305\202a podaj swoj\304\205", 0, QApplication::UnicodeUTF8));
        Wyniki->setTitle(QApplication::translate("MainWindow", "Wyniki", 0, QApplication::UnicodeUTF8));
        Wyczysc->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207 wszystko", 0, QApplication::UnicodeUTF8));
        P1->setText(QApplication::translate("MainWindow", "\305\201\304\205czny cie\305\274ar podczas treningu:", 0, QApplication::UnicodeUTF8));
        P2->setText(QApplication::translate("MainWindow", "Ciezar jako wielokrotno\305\233\304\207 masy cia\305\202a:", 0, QApplication::UnicodeUTF8));
        Kg_3->setText(QApplication::translate("MainWindow", "  kg", 0, QApplication::UnicodeUTF8));
        Podsumowanie->setText(QApplication::translate("MainWindow", "Podsumowanie -", 0, QApplication::UnicodeUTF8));
        P3->setText(QApplication::translate("MainWindow", "Status treningu:", 0, QApplication::UnicodeUTF8));
        DataPodsumowania->setText(QString());
        zalecenie->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
