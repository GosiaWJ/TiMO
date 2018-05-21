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
    ui->funkcja_celu_box->addItem("(x1-2)^2+(x2-1)^2");
    ui->funkcja_celu_box->addItem("x1^4+x2^4-x1^2-x2^2");
    ui->funkcja_celu_box->addItem("(x1^2 +x2 -11)^2 +(x1 +x2^2 -7)^2");
    this->setWindowTitle("Powell&NS Optimisation Algorithm");
    ui->statusBar->setVisible(true);
    ui->statusBar->setUpdatesEnabled(true);
    ui->statusBar->showMessage("Ready!");

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

    ui->statusBar->showMessage("Busy");

    double start[2];
    double wynik[2];
    double p_s[5];
    p_s[0]=ui->x_10->text().toDouble();
    p_s[1]=ui->x_20->text().toDouble();
    p_s[2]=ui->x_30->text().toDouble();
    p_s[3]=ui->x_40->text().toDouble();
    p_s[4]=ui->x_50->text().toDouble();

    //delete data;
    data = new Dane(ui->epsilon0_spinbox->value(),ui->epsilon1_spinbox->value(),ui->epsilon2_spinbox->value(),p_s,ui->l_edit->text().toInt(0),ui->lista_ograniczen->count(), ui->ilosc_zmiennych_spinbox->value(),ui->tau_spinbox->value(),ui->beta_spinbox->value());
    data->setFunction(ui->funkcja_celu_box->currentText());
    ui->funkcja_celu_box->addItem(ui->funkcja_celu_box->currentText());
    QString *tablica_ograniczen=new QString[data->ilosc_ograniczen];
    if(ui->lista_ograniczen->count()){
        for(int i=0;i<ui->lista_ograniczen->count();i++){
        tablica_ograniczen[i]=QString(ui->lista_ograniczen->item(i)->text());
    }
    data->setConstr(tablica_ograniczen);
    if(ui->lista_ograniczen->count()>0) ui->wykres->setConstr(tablica_ograniczen,ui->lista_ograniczen->count());
    delete [] tablica_ograniczen;
     }
    else{} //co jak nie ma ograniczeń

    data->Optimalize();

    ui->wykres->setFunction(ui->funkcja_celu_box->currentText());
    if(ui->ilosc_zmiennych_spinbox->value()==2){
    ui->plot->setEnabled(true);
    }
    else ui->plot->setEnabled(false);

    dodaj_wynik();
    //data->clear_powell_points();
    ui->statusBar->showMessage("Done");


}



void MainWindow::zmien_ilosc_zmiennych(int arg1)
{
   int ilosc=arg1;
   if(ilosc==1)
   {ui->x_20->setVisible(false);
   ui->x_30->setVisible(false);
   ui->x_40->setVisible(false);
   ui->x_50->setVisible(false);
   ui->horizontalSpacer_8->changeSize(160,10);
   }
    if(ilosc==2)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(false);
    ui->x_40->setVisible(false);
    ui->x_50->setVisible(false);
    ui->horizontalSpacer_8->changeSize(125,10);
    }
    if(ilosc==3)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(false);
    ui->x_50->setVisible(false);
    ui->horizontalSpacer_8->changeSize(90,10);
    }
    if(ilosc==4)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(true);
    ui->x_50->setVisible(false);
    ui->horizontalSpacer_8->changeSize(55,10);
    }
    if(ilosc==5)
    {ui->x_20->setVisible(true);
    ui->x_30->setVisible(true);
    ui->x_40->setVisible(true);
    ui->x_50->setVisible(true);
    ui->horizontalSpacer_8->changeSize(15,10);
    }
}

void MainWindow::dodaj_wynik()
{
    ui->wyniki->clear();
    string wiadomosc;
    for(int k=0;k<data->punkty_powella[0].size();k++){
        if (k==0)     wiadomosc="Punkt startowy: ";
        else     wiadomosc="Iteracja "+to_string(k)+": ";
    for(int i=0;i<data->ilosc_zmiennych;i++) wiadomosc+="x"+to_string(i+1)+" ="+to_string(data->punkty_powella[i].at(k))+ " ";
    wiadomosc+="f(x) = "+to_string(data->punkty_powella[data->ilosc_zmiennych].at(k));
    ui->wyniki->addItem(wiadomosc.c_str());
    }
   //for(int i=0;i<data->punkty_powella[0].size();i++) cout<<"funkcja "<<data->punkty_powella[data->ilosc_zmiennych].at(i)<<endl;
    wiadomosc="\nKryterium stopu: ";
    switch(data->kryterium_stopu)
    {
    case 0:
        wiadomosc+="Minimum nieznaleziono"; break;
    case 1:
        wiadomosc+="kryterium gradientu"; break;
    case 2:
        wiadomosc+="||x^(i) - x^(i-1)||<= epsilon_1"; break;
    case 3:
        wiadomosc+="|f(x^(i))-f(x^(i-1))|<=epsilon_2"; break;
    case 4:
        wiadomosc+="przekroczona liczba iteracji"; break;
    case 5:
        wiadomosc+="c<c_min"; break;
    default:
        break;
    }
   ui->wyniki->addItem(wiadomosc.c_str());
}


void MainWindow::on_plot_clicked()
{
    ui->statusBar->showMessage("Plotting...");

    ui->wykres->plot(data->punkty_powella[0],data->punkty_powella[1],ui->x_1l_edit->text().toDouble(),ui->x_1p_edit->text().toDouble(),ui->x_2l_edit->text().toDouble(),ui->x_2p_edit->text().toDouble());
    ui->plot->setEnabled(true);
    ui->statusBar->showMessage("Done");

}
