#include "dane.hh"
#include<cmath>
using namespace mu;
#include<iostream>
using namespace std;


Dane::Dane(int e0, int e1, int e2, double *x0, int l, int ogr, int zmienne)
{
        epsilon0=e0;
    epsilon1=e1;
    epsilon2=e2;
    punkt_startowy=x0;
    liczba_iteracji=l;
    ilosc_zmiennych=zmienne; //zmienić to potem
    ilosc_ograniczen=ogr;
    variables=new double[ilosc_zmiennych];
    ograniczenia=new QString[ilosc_ograniczen];


}

double *Dane::Gradient()
{
    double *gradient=new double[ilosc_zmiennych];
    expr_parser.SetVariableID("x1", 0);
    expr_parser.SetVariableID("x2", 1);
    expr_parser.SetVariableID("x3", 2);
    expr_parser.SetVariableID("x4", 3);
    expr_parser.SetVariableID("x5", 4);
    int nerr = 0;
    Ev3::Expression expr = expr_parser.Parse(funkcja_celu->toStdString().c_str(),nerr);
    Ev3::Expression derivative[ilosc_zmiennych];
    for(int i=0;i<ilosc_zmiennych;i++){
           derivative[i]= Ev3::Diff(expr, i); //tu się liczą pochodne
          //std::cout <<"x"<<i<<" "<< derivative[i]->ToString() << std::endl;
           parser.SetExpr(derivative[i]->ToString());
           gradient[i]=parser.Eval();
          // std::cout <<"g"<<i<<" "<< gradient[i] << std::endl;


    }
   // for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"gragient"<<i<<" "<< gradient[i] << std::endl;

return gradient;
}

double Dane::Optimalize()
{

    //cout<<"ilosc ograniczen"<<ilosc_zmiennych<<endl;
    double wartosc_funkcji_celu=1000000000;
    variables=punkt_startowy; //koniecznie przed wywołaniem gradientu musisz ustawić variables tak jak chcesz
  //  double *g=Gradient();
    parser.DefineVar("x1", &variables[0]);
    parser.DefineVar("x2", &variables[1]);
    parser.DefineVar("x3", &variables[2]);
    parser.DefineVar("x4", &variables[3]);
    parser.DefineVar("x5", &variables[4]);
    NS();

   for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"koniec x"<<i<<" "<< variables[i] << std::endl;
    return wartosc_funkcji_celu;
}

double *Dane::NS()
{
   // for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"startowy"<<i<<" "<< variables[i] << std::endl;

    int n=ilosc_zmiennych; //l. zmiennych
    double g2=10;
    double epsilon=pow(10,-4);

    while(abs(g2)>epsilon){

    double *grad=Gradient();
    double ksi[n];
    double P=0;
    double ksi2=0;
    double tau_l=0;
    double tau_r=1;
    double tau, f,f0;
    double beta=0.25;
    bool the_end=1;
    double var[n];
    for (int i=0; i<n; i++) var[i]=variables[i];



    parser.SetExpr(funkcja_celu->toStdString());
    f0=parser.Eval();
  //  cout<<"f "<<f0<<endl;
    for (int i=0; i<n; i++) ksi[i]=(-1)*grad[i]; //wyznaczenie kierunku
    for (int i=0; i<n; i++) P=P+grad[i]*ksi[i]; //pochodna kierunkowa
//cout <<"p"<<" "<< P << std::endl;
    while(the_end){
        tau=0.5*(tau_l+tau_r);
        //cout <<"tau"<<" "<< tau<< std::endl;

        for (int i=0; i<n; i++) variables[i]=var[i]+tau*ksi[i];
        f=parser.Eval();
       // cout <<"fe"<<" "<< f0+(beta)*P*tau<< std::endl;

        if(f<f0+(1-beta)*P*tau){
        tau_l=tau;
        }
        else{
        if(f>f0+beta*P*tau){
        tau_r=tau;}
        else the_end=0;
        }

    }
    for (int i=0; i<n; i++) variables[i]=var[i]+tau*ksi[i];
    g2=0;
    for (int i=0; i<n; i++) g2=g2+grad[i]*grad[i];
    //cout <<"g2"<<" "<< g2 << std::endl;

}

    return variables;
}

double Dane::Function(double x1, double x2)
{
    return pow(x1,2)+pow(x2,2);
}

void Dane::setFunction(const QString fun)
{
    funkcja_celu=new QString(fun);
    cout<<"funkcja celu: "<<funkcja_celu->toStdString()<<endl;
    parser.DefineVar("x1", &variables[0]);
    parser.DefineVar("x2", &variables[1]);
    parser.DefineVar("x3", &variables[2]);
    parser.DefineVar("x4", &variables[3]);
    parser.DefineVar("x5", &variables[4]);
    parser.SetExpr(fun.toStdString());
}

void Dane::setConstr(QString *Constr_tab)
{
    for(int i=0;i<ilosc_ograniczen;i++){
    ograniczenia[i]=QString(Constr_tab[i]);
    }
}
