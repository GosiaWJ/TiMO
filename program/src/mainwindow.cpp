#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"
#include<iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->x_20->setVisible(false);
    ui->x_30->setVisible(false);
    ui->x_40->setVisible(false);
    ui->x_50->setVisible(false);
    connect(ui->ilosc_zmiennych_spinbox,SIGNAL(valueChanged(int)),this,SLOT(zmien_ilosc_zmiennych(int)));

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

void MainWindow::on_epsilon0_spinbox_valueChanged(int arg1)
{
//data->set_e_0(arg1);
}

void MainWindow::on_epsilon1_spinbox_valueChanged(int arg1)
{
//data->set_e_1(arg1);
}

void MainWindow::on_epsilon2_spinbox_valueChanged(int arg1)
{
//data->set_e_2(arg1);
}

void MainWindow::on_oblicz_clicked()
{
    double *punkt_startowy;
    punkt_startowy=new double[ui->ilosc_zmiennych_spinbox->value()]; //odczytywaie punktu startowego
    punkt_startowy[0]=ui->x_10->text().toDouble();
    punkt_startowy[1]=ui->x_20->text().toDouble();
    punkt_startowy[2]=ui->x_30->text().toDouble();
    punkt_startowy[3]=ui->x_40->text().toDouble();
    punkt_startowy[4]=ui->x_50->text().toDouble();
    data = new Dane(ui->epsilon0_spinbox->value(),ui->epsilon1_spinbox->value(),ui->epsilon2_spinbox->value(),punkt_startowy,ui->l_edit->text().toInt(0),ui->lista_ograniczen->count(), ui->ilosc_zmiennych_spinbox->value());
    data->setFunction(ui->funkcja_celu_box->currentText());
    ui->funkcja_celu_box->addItem(ui->funkcja_celu_box->currentText());
   QString tablica_ograniczen[data->ilosc_ograniczen];
    for(int i=0;i<ui->lista_ograniczen->count();i++){
        tablica_ograniczen[i]=ui->lista_ograniczen->item(i)->text();
    }
   data->setConstr(tablica_ograniczen);
}



void MainWindow::zmien_ilosc_zmiennych(int arg1)
{
   int ilosc=arg1;
   if(ilosc==1)
   {ui->x_20->setVisible(false);
   ui->x_30->setVisible(false);
   ui->x_40->setVisible(false);
   ui->x_50->setVisible(false);
   }
    if(ilosc==2)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(false);
    ui->x_40->setVisible(false);
    ui->x_50->setVisible(false);
    }
    if(ilosc==3)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(false);
    ui->x_50->setVisible(false);
    }
    if(ilosc==4)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(true);
    ui->x_50->setVisible(false);
    }
    if(ilosc==5)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(true);
    ui->x_50->setVisible(true);
    }
}
