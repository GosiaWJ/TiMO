#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"
#include<iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = new Dane(ui->epsilon0_spinbox->value(),ui->epsilon1_spinbox->value(),ui->epsilon2_spinbox->value(),ui->punk_startowy_edit->text().toDouble(),ui->l_edit->text().toInt(0));
    std::cout<<"123";

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

void MainWindow::on_epsilon0_spinbox_valueChanged(const int arg1)
{
data->set_e_0(arg1);
}

void MainWindow::on_epsilon1_spinbox_valueChanged(int arg1)
{
    data->set_e_1(arg1);
}

void MainWindow::on_epsilon2_spinbox_valueChanged(int arg1)
{
    data->set_e_2(arg1);
}
