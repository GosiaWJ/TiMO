#include "dane.hh"
#include<cmath>

Dane::Dane(int e0, int e1, int e2, double x0, int l)
{
    epsilon0=e0;
    epsilon1=e1;
    epsilon2=e2;
    punkt_startowy=x0;
    liczba_iteracji=l;

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
