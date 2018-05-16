#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include"dane.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Dane *data;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_dodaj_ograniczenie_clicked();

    void on_usun_ograniczenie_clicked();

    void on_epsilon0_spinbox_valueChanged(int arg1);

    void on_epsilon1_spinbox_valueChanged(int arg1);

    void on_epsilon2_spinbox_valueChanged(int arg1);

    void on_oblicz_clicked();

    void zmien_ilosc_zmiennych(int arg1);

    void dodaj_wynik();

    void on_plot_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HH
