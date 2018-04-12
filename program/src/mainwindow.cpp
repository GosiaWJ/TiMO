#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dodaj_ograniczenie_clicked()
{
    ui->lista_ograniczen->addItem(ui->ograniczenie->text());

}

void MainWindow::on_usun_ograniczenie_clicked()
{
ui->ograniczenie->setText(ui->lista_ograniczen->currentItem()->text());
delete ui->lista_ograniczen->takeItem(ui->lista_ograniczen->currentRow());
ui->lista_ograniczen->clearSelection();
}
