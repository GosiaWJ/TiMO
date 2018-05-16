#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;


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
   // connect(data,SIGNAL(iteracja(int)),this,SLOT(dodaj_wynik(int)));
    ui->funkcja_celu_box->addItem("2*x1^2+x2^2-2*x1*x2");
    ui->funkcja_celu_box->addItem("x1^4+x2^4-2*x1^2*x2-4*x1+3");




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

    double start[2];
    double wynik[2];
    double p_s[5];
   // p_s=new double[n]; //odczytywaie punktu startowego
    p_s[0]=ui->x_10->text().toDouble();
    p_s[1]=ui->x_20->text().toDouble();
    p_s[2]=ui->x_30->text().toDouble();
    p_s[3]=ui->x_40->text().toDouble();
    p_s[4]=ui->x_50->text().toDouble();

    mu::Parser cosiek;
    double hehe=1;
    cosiek.DefineVar("var1", &hehe);
    cosiek.SetExpr("var1+3");
    cout<< "nie uda sie "<<cosiek.Eval()<<endl;

    //delete data;
    data = new Dane(ui->epsilon0_spinbox->value(),ui->epsilon1_spinbox->value(),ui->epsilon2_spinbox->value(),p_s,ui->l_edit->text().toInt(0),ui->lista_ograniczen->count(), ui->ilosc_zmiennych_spinbox->value());
    data->setFunction(ui->funkcja_celu_box->currentText());
    ui->funkcja_celu_box->addItem(ui->funkcja_celu_box->currentText());
    QString *tablica_ograniczen=new QString[data->ilosc_ograniczen];
    if(ui->lista_ograniczen->count()){
        for(int i=0;i<ui->lista_ograniczen->count();i++){
        tablica_ograniczen[i]=QString(ui->lista_ograniczen->item(i)->text());
    }
    data->setConstr(tablica_ograniczen);
    ui->wykres->setConstr(tablica_ograniczen,ui->lista_ograniczen->count());
    delete [] tablica_ograniczen;
     }
    else{} //co jak nie ma ograniczeń

    data->Optimalize();

    ui->wykres->setFunction(ui->funkcja_celu_box->currentText());
    if(ui->ilosc_zmiennych_spinbox->value()==2){
        ui->wykres->plot(data->punkty_powella[0],data->punkty_powella[1]);
    }
    dodaj_wynik();
    data->clear_powell_points();

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

void MainWindow::dodaj_wynik()
{
    string wiadomosc;
    for(int k=0;k<data->punkty_powella[0].size();k++){
    wiadomosc="Iteracja "+to_string(k+1)+": ";
    for(int i=0;i<data->ilosc_zmiennych;i++) wiadomosc+="x"+to_string(i)+" ="+to_string(data->punkty_powella[i].at(k))+ " ";
    ui->wyniki->addItem(wiadomosc.c_str());
    }
}
