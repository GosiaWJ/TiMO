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
          // std::cout <<"x"<<i<<" "<< derivative[i]->ToString() << std::endl;
           parser.SetExpr(derivative[i]->ToString());
           gradient[i]=parser.Eval();

    }
return gradient;
}

double Dane::Optimalize()
{
    cout<<"ilosc ograniczen"<<ilosc_ograniczen<<endl;
    double wartosc_funkcji_celu=1000000000;
    variables=punkt_startowy; //koniecznie przed wywołaniem gradientu musisz ustawić variables tak jak chcesz
    double *g=Gradient();
    for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"x"<<i<<" "<< punkt_startowy[i] << std::endl;


    return wartosc_funkcji_celu;
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
  //  parser.Eval();
}

void Dane::setConstr(QString *Constr_tab)
{
    for(int i=0;i<ilosc_ograniczen;i++){
    ograniczenia[i]=QString(Constr_tab[i]);
    }
}
