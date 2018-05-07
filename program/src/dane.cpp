#include "dane.hh"
#include<cmath>
using namespace mu;


Dane::Dane(int e0, int e1, int e2, double x0, int l, int ogr, int zmienne)
{
    epsilon0=e0;
    epsilon1=e1;
    epsilon2=e2;
    punkt_startowy=x0;
    liczba_iteracji=l;
    ilosc_zmiennych=zmienne; //zmienić to potem
    ilosc_ograniczen=ogr;
    variables=new double[ilosc_zmiennych];
    ograniczenia=new mu::Parser[ilosc_ograniczen];

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
    funkcja_celu.DefineVar("x1", &variables[0]);
    funkcja_celu.DefineVar("x2", &variables[1]);
    funkcja_celu.DefineVar("x3", &variables[2]);
    funkcja_celu.DefineVar("x4", &variables[3]);
    funkcja_celu.DefineVar("x5", &variables[4]);
    funkcja_celu.SetExpr(fun.toStdString());

    funkcja_celu.Eval();
}

void Dane::setConstr(QString *Constr_tab)
{
    for(int i=0; i<Constr_tab->size();i++) {
        ograniczenia[i].DefineVar("x1", &variables[0]);
        ograniczenia[i].DefineVar("x2", &variables[1]);
        ograniczenia[i].DefineVar("x3", &variables[2]);
        ograniczenia[i].DefineVar("x4", &variables[3]);
        ograniczenia[i].DefineVar("x5", &variables[4]);
        ograniczenia[i].SetExpr(Constr_tab[i].toStdString());
    }
}
