#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

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
    void on_dodaj_ograniczenie_clicked();

    void on_usun_ograniczenie_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HH
