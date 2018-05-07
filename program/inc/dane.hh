#ifndef DANE_HH
#define DANE_HH
#include<iostream>
#include<muParser.h>
#include<QString>

class Dane
{
mu::Parser parser;
QString *funkcja_celu;
QString *ograniczenia;

public:
    int epsilon0;
    int epsilon1;
    int epsilon2;
    int liczba_iteracji;
    int ilosc_zmiennych;
    int ilosc_ograniczen;
    double *punkt_startowy;
    double *variables;
    Dane(int e0, int e1, int e2, double *x0, int l, int ogr, int zmienne);
    void set_e_0(const int e0){epsilon0=e0;}
    void set_e_1(const int e1){epsilon1=e1;}
    void set_e_2(const int e2){epsilon2=e2;}
    void set_p_s(double* x0){punkt_startowy=x0;}
    void set_l_i(const int l){liczba_iteracji=l;}
    double Optimalize();
    double Function(double x1, double x2);
    void setFunction(const QString);
    void setConstr(QString *Constr_tab);

};

#endif // DANE_HH
