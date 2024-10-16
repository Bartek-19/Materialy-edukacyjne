#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

double ciezar=0, ciezarW=0, masaCiala, obciazenie, obciazenieW;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Dane->setVisible(false);

    ui->Wyniki->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_data_clicked(const QDate &date)
{
    ui->Dane->setVisible(true);

    ui->DataPodsumowania->setText( date.toString() );
}

void MainWindow::on_dodaj_clicked()
{
    int waga, indeks;
    double temp;

    ui->ListaCwiczen->addItem( ui->cwiczenie->text() );
    ui->ListaCiezarow->addItem( ui->ciezar->text() + QString(" kg") );
    ui->ListaVol->addItem( QString::number(ui->serie->value()) + QString("x") + QString::number(ui->powtorzenia->value()) );

    temp = ui->serie->value() * ui->powtorzenia->value() * ui->ciezar->text().toDouble();

    ciezar += temp;

    indeks = ui->kategoria->currentIndex();
    switch(indeks)
    {
    case 0:
        waga=10;
        break;
    case 1:
        waga=40;
        break;
    case 2:
        waga=6;
        break;
    case 3:
        waga=4;
        break;
    case 4:
        waga=5;
        break;
    case 5:
        waga=1;
        break;
    }

    ciezarW += temp * waga;

    ui->cwiczenie->clear();
    ui->ciezar->clear();
    ui->serie->setValue(0);
    ui->powtorzenia->setValue(0);
    ui->kategoria->setCurrentIndex(0);
}

void MainWindow::on_PrzejdzDo_clicked()
{
    masaCiala = ui->masa->text().toDouble();

    if(masaCiala <= 0)
        QMessageBox::information(this, "Ostrzeżenie", "Podano złą masę ciała - podaj poprawną i spróbuj jeszcze raz");
    else
    {
        ui->PodsCiezar->setText( QString::number(ciezar) );
        obciazenie = ciezar/masaCiala;
        obciazenieW = ciezarW/masaCiala;
        ui->PodsWielokrotnosc->setText( QString::number(obciazenie) );

        if(obciazenieW<0)
            ui->zalecenie->setText("Błąd danych!");
        else if(obciazenieW<=180)
        {
            ui->PodsStatus->setText("Lekki");
            ui->zalecenie->setText("Można ćwiczyć na następny dzień");
        }
        else if(obciazenieW<=1000)
        {
            ui->PodsStatus->setText("Średni");
            ui->zalecenie->setText("Zaleca się 1 dzień przerwy");
        }
        else
        {
            ui->PodsStatus->setText("Ciężki");
            ui->zalecenie->setText("Zaleca się 2 dni przerwy");
        }

        ui->Wyniki->setVisible(true);
    }
}



void MainWindow::on_Wyczysc_clicked()
{
    ui->masa->clear();
    ui->ciezar->clear();
    ui->cwiczenie->clear();
    ui->kategoria->setCurrentIndex(0);
    ui->serie->setValue(0);
    ui->powtorzenia->setValue(0);

    ui->DataPodsumowania->clear();
    ui->ListaCwiczen->clear();
    ui->ListaVol->clear();
    ui->ListaCiezarow->clear();

    ui->PodsCiezar->clear();
    ui->PodsWielokrotnosc->clear();
    ui->PodsStatus->clear();
    ui->zalecenie->clear();

    ui->Wyniki->setVisible(false);
    ui->Dane->setVisible(false);
}
