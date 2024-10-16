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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_horizontalScrollBar_actionTriggered(int action);

    void on_pushButton_4_clicked();

    void on_Button_10_6_1_clicked();

    void on_Button_10_6_2_clicked();

    void on_Button_10_7_clicked();

    void on_Button_10_8_1_clicked();

    void on_Button_10_8_2_clicked();

    void on_Button_10_8_3_clicked();

    void on_Button_10_9_1_clicked();

    void on_Button_10_9_2_clicked();

    void on_Button_10_9_3_clicked();

    void on_actionPokaz_triggered();

    void on_actionUkryj_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWytnij_triggered();

    void on_actionWklej_triggered();

    void on_actionK1_triggered();

    void on_actionK2_triggered();

    void on_actionK3_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
