#include "dane.hh"
#include<cmath>
using namespace mu;


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

double Dane::Optimalize()
{
    double wartosc_funkcji_celu=1000000000;


    return wartosc_funkcji_celu;
}

double Dane::Function(double x1, double x2)
{
    return pow(x1,2)+pow(x2,2);
}

void Dane::setFunction(const QString fun)
{
    funkcja_celu=fun;
    parser.DefineVar("x1", &variables[0]);
    parser.DefineVar("x2", &variables[1]);
    parser.DefineVar("x3", &variables[2]);
    parser.DefineVar("x4", &variables[3]);
    parser.DefineVar("x5", &variables[4]);
    parser.SetExpr(fun.toStdString());
    parser.Eval();
}

void Dane::setConstr(QString *Constr_tab)
{
    for(int i=0; i<Constr_tab->size();i++) {
        ograniczenia[i]=Constr_tab[i];
    }
}
