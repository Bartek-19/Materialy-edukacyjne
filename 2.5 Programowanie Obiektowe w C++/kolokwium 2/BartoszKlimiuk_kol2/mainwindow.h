#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_data_clicked(const QDate &date);

    void on_dodaj_clicked();

    void on_PrzejdzDo_clicked();

    void on_Wyczysc_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
