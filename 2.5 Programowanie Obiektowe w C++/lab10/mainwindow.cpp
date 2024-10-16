#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_5->setVisible(false);
    ui->lineEdit_6->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->lineEdit_7->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->lineEdit_8->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_2->setText( ui->lineEdit->text() );
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    float a = ui->lineEdit_3->text().toFloat();
    float b = ui->lineEdit_4->text().toFloat();

    float Pole = a*b;

    QString str1= "Pole = ";
    QString str2 = QString::number(Pole);

    str1 += str2;

    ui->lineEdit_5->setText(str1);

    ui->label_4->setText(str1);
}

void MainWindow::on_pushButton_3_clicked()
{
    double a = ui->lineEdit_6->text().toDouble();
    double b = ui->lineEdit_7->text().toDouble();
    int operat = ui->comboBox->currentIndex();
    double wynik;

    switch(operat)
    {
    case 0:
        wynik = a + b;
        break;
    case 1:
        wynik = a - b;
        break;
    case 2:
        wynik = a * b;
        break;
    case 3:
        if(b==0)
            ui->lineEdit_8->setText("Blad");
        else
            wynik = a / b;
        break;
    }

    if(ui->lineEdit_8->text() != "Blad")
        ui->lineEdit_8->setText(QString::number(wynik));
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->checkState()==Qt::Checked)
        ui->label_7->setText("Bartosz Klimiuk");
    else
        ui->label_7->setText("???");
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->label_8->setText( ui->calendarWidget->selectedDate().toString() );
}

void MainWindow::on_horizontalScrollBar_actionTriggered(int action)
{
    ui->label_9->setText( QString::number(ui->horizontalScrollBar->value()) );
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->append( ui->lineEdit_9->text() );
    ui->lineEdit_9->setText("");
}

void MainWindow::on_Button_10_6_1_clicked()
{
    ui->List_10_6->addItem( ui->Line_10_6->text() );

    ui->Label_10_6_4->setText( QString::number( ui->List_10_6->count() ) );

    float Suma = ui->Label_10_6_6->text().toFloat() + ui->Line_10_6->text().toFloat();
    ui->Label_10_6_6->setText( QString::number(Suma) );

    ui->Line_10_6->setText("");
}

void MainWindow::on_Button_10_6_2_clicked()
{
    ui->List_10_6->clear();

    ui->Label_10_6_4->setText("0");

    ui->Label_10_6_6->setText("0");

    ui->Line_10_6->setText("");
}

void MainWindow::on_Button_10_7_clicked()
{
    ui->List_10_6->addItem( QString::number(ui->Spin_10_7->value()) );

    ui->Label_10_6_4->setText( QString::number( ui->List_10_6->count() ) );

    float Suma = ui->Label_10_6_6->text().toFloat() + ui->Line_10_6->text().toFloat();
    ui->Label_10_6_6->setText( QString::number(Suma) );
}

void MainWindow::on_Button_10_8_1_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }

    QTextStream out(&file);

    out<<ui->textEdit->toPlainText();

    file.flush();
    file.close();
}

void MainWindow::on_Button_10_8_2_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    ui->textEdit->setPlainText(myText);

    file.close();
}

void MainWindow::on_Button_10_8_3_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_Button_10_9_1_clicked()
{
    if(ui->Button_10_9_1->isChecked())
    {
        this->setStyleSheet("background-color:red");
        ui->Button_10_9_2->setChecked(false);
        ui->Button_10_9_3->setChecked(false);
    }
}

void MainWindow::on_Button_10_9_2_clicked()
{
    if(ui->Button_10_9_2->isChecked())
    {
        this->setStyleSheet("background-color:green");
        ui->Button_10_9_1->setChecked(false);
        ui->Button_10_9_3->setChecked(false);
    }
}

void MainWindow::on_Button_10_9_3_clicked()
{
    if(ui->Button_10_9_2->isChecked())
    {
        this->setStyleSheet("background-color:grey");
        ui->Button_10_9_1->setChecked(false);
        ui->Button_10_9_3->setChecked(false);
    }
}

void MainWindow::on_actionPokaz_triggered()
{
    ui->label_5->setVisible(true);
    ui->lineEdit_6->setVisible(true);
    ui->comboBox->setVisible(true);
    ui->lineEdit_7->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->lineEdit_8->setVisible(true);
}

void MainWindow::on_actionUkryj_triggered()
{
    ui->label_5->setVisible(false);
    ui->lineEdit_6->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->lineEdit_7->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->lineEdit_8->setVisible(false);
}

void MainWindow::on_actionKopiuj_triggered()
{
    QTextStream out(stdin);

    out<<ui->textEdit->toPlainText();
}

void MainWindow::on_actionWytnij_triggered()
{
    QTextStream out(stdin);

    out<<ui->textEdit->toPlainText();

    ui->textEdit->clear();
}

void MainWindow::on_actionWklej_triggered()
{
    QTextStream in(stdin);

    ui->textEdit->setPlainText(in.readAll());
}

void MainWindow::on_actionK1_triggered()
{
    QMessageBox::information(this, "Komunikat 1", "informacja");
}

void MainWindow::on_actionK2_triggered()
{
    QMessageBox::warning(this, "Komunikat 1", "ostrzezenie", QMessageBox::Yes | QMessageBox::No |
                         QMessageBox::Cancel, QMessageBox::Yes);
}

void MainWindow::on_actionK3_triggered()
{
    QMessageBox::information(this, "Lorem Ipsum", "...i tak dalej...");
}
