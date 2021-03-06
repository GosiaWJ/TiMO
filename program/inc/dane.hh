#ifndef DANE_HH
#define DANE_HH
#include <muParser.h>
#include <QString>
#include <iostream>
#include <string>
#include "inc/diff/expression.h"
#include "inc/diff/parser.h"
#include <QVector>

using namespace std;
#include<QObject>
class Dane
{
mu::Parser parser;
QString *funkcja_celu;
Ev3::ExpressionParser expr_parser;



public:
    int epsilon0;
    int epsilon1;
    int epsilon2;
    int liczba_iteracji;
    int ilosc_zmiennych;
    int ilosc_ograniczen;
    double tau_r;
    double beta;
    double *punkt_startowy;
    int kryterium_stopu=0;
    double *variables;
    QVector<double> *punkty_powella;
    QString *ograniczenia;
    Dane(int e0, int e1, int e2, double *x0, int l, int ogr, int zmienne, double t, double b);
    void set_e_0(const int e0){epsilon0=e0;}
    void set_e_1(const int e1){epsilon1=e1;}
    void set_e_2(const int e2){epsilon2=e2;}
    void set_p_s(double* x0){punkt_startowy=x0;}
    void set_l_i(const int l){liczba_iteracji=l;}
    double* Gradient(const string& fun);
    void Optimalize();
    double NS(const string& fun);
    void Powell();
    void clear_powell_points(){
        for(int i=0;i<ilosc_zmiennych+1;i++) punkty_powella[i].clear();
    }

    int H(double x){
        if(x>0) return 1;
        else return 0;
    }
    double Function(double x1, double x2);
    void setFunction(const QString);
    void setConstr(QString *Constr_tab);
    ~Dane();
signals:
    //void iteracja(int k);

};

#endif // DANE_HH
