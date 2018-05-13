#include "dane.hh"
#include<cmath>
using namespace mu;
#include<iostream>
#include<string>
#include<math.h>
#include<locale.h>

using namespace std;


Dane::Dane(int e0, int e1, int e2, double *x0, int l, int ogr, int zmienne)
{
    epsilon0=e0;
    epsilon1=e1;
    epsilon2=e2;
    punkt_startowy=new double[zmienne];
    punkt_startowy=x0;
    for (int i=0; i<zmienne; i++) cout<<"x"<<i<<" "<<punkt_startowy[i]<<endl;
    liczba_iteracji=l;
    ilosc_zmiennych=zmienne; //zmienić to potem
    ilosc_ograniczen=ogr;
    variables=new double[5];
    for (int i=0; i<zmienne; i++) variables[i]=0;
    ograniczenia=new QString[ilosc_ograniczen];
    setlocale(LC_ALL,"C");


}

Dane::~Dane()
{
    delete [] punkt_startowy;
    delete [] variables;
    delete [] ograniczenia;
    delete funkcja_celu;
}

double *Dane::Gradient(const string& fun)
{
    double *gradient=new double[ilosc_zmiennych];
    expr_parser.SetVariableID("x1", 0);
    expr_parser.SetVariableID("x2", 1);
    expr_parser.SetVariableID("x3", 2);
    expr_parser.SetVariableID("x4", 3);
    expr_parser.SetVariableID("x5", 4);
    int nerr = 0;
    Ev3::Expression expr = expr_parser.Parse(fun.c_str(),nerr);
    Ev3::Expression derivative[ilosc_zmiennych];
    for(int i=0;i<ilosc_zmiennych;i++){
           derivative[i]= Ev3::Diff(expr, i); //tu się liczą pochodne
           parser.SetExpr(derivative[i]->ToString());
           gradient[i]=parser.Eval();
    }

    return gradient;
}



void Dane::Optimalize()
{
    try{

    //cout<<"ilosc ograniczen"<<ilosc_zmiennych<<endl;

    variables=punkt_startowy; //koniecznie przed wywołaniem gradientu musisz ustawić variables tak jak chcesz
  //  double *g=Gradient();
    parser.DefineVar("x1", &variables[0]);
    parser.DefineVar("x2", &variables[1]);
    parser.DefineVar("x3", &variables[2]);
    parser.DefineVar("x4", &variables[3]);
    parser.DefineVar("x5", &variables[4]);
    Powell();

     for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"koniec x"<<i<<" "<< variables[i] << std::endl;
    }
     catch(mu::Parser::exception_type &e){
        cout<<"BŁĄD PARSERA" <<endl;
     }

}

double *Dane::NS(const string& fun)
{
    // for(int i=0;i<ilosc_zmiennych;i++)   std::cout <<"startowy"<<i<<" "<< variables[i] << std::endl;

     int n=ilosc_zmiennych; //l. zmiennych
     double g2=10;
     double epsilon=pow(10,epsilon0);

     while(abs(g2)>epsilon){

     double *grad=Gradient(fun);
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

     parser.SetExpr(fun);
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

double *Dane::Powell()
{
    double sigma[ilosc_ograniczen];
    double theta[ilosc_ograniczen];
    double g0[ilosc_ograniczen];
    double g[ilosc_ograniczen];
    double c,c0, cmin;
    double m1=0.25;
    double m2=10;
    bool krok_6=false;
    bool krok_6_p=false;
    int k=0;
    c=7;
    cmin=pow(10,-4); //to jest pewnie jakiś epsilon
    for (int i=0; i<ilosc_ograniczen; i++){
       sigma[i]=1;
       theta[i]=0;
    }
    for (int i=0; i<ilosc_ograniczen; i++) {
        parser.SetExpr(ograniczenia[i].toStdString());
        g0[i]=parser.Eval();
    }
    int theEnd=1;
    while(theEnd){

        string funkcja_powella;
        funkcja_powella=funkcja_celu->toStdString();

        for (int i=0; i<ilosc_ograniczen; i++) {
            cout<<i<<endl;

            if(H(g0[i]+theta[i])){
                string s=to_string(sigma[i]);
                string t=to_string(theta[i]);
                funkcja_powella+="+"+s+"*("+ograniczenia[i].toStdString()+"+"+t+")^2";
                cout<<"Dodano"<<endl;
            }
        }
        parser.SetExpr(funkcja_powella);
        cout<<"Funkcja Powella "<<funkcja_powella<<"Wartość" <<parser.Eval()<<endl;
        QString *funkcja;
        funkcja->fromStdString(funkcja_powella);
        NS(funkcja_powella);
        c0=c;
        c=0;
        for (int i=0; i<ilosc_ograniczen; i++) {
            parser.SetExpr(ograniczenia[i].toStdString());
            g[i]=parser.Eval();
            if(H(g0[i]+theta[i])) c=max(c,abs(g[i]));
        }
        if(c<cmin)   {
            theEnd=0;
            break;
        }
        else
        {
            if(c>=c0)
            {
                c=c0;
                //kroki 6-7
            //krok6
                stop:
                krok_6=true;
                for (int i=0; i<ilosc_ograniczen; i++) {
                    if(abs(g0[i])>m1*c0 && H(g[i]+theta[i]))
                    {
                        sigma[i]=m2*sigma[i];
                        theta[i]=theta[i]/m2;

                    }
                }
                //krok7
                k=k+1;
                for (int i=0; i<ilosc_ograniczen; i++) g0[i]=g[i];
                //
              //  emit iteracja(k);

            }
            else{//krok 8
                if(krok_6==false || k==0 || c<m1*c0) //jeśli poprzednio nie był wykonywany krok 6.
                    {
                            for (int i=0; i<ilosc_ograniczen; i++) theta[i]=min(g[i]+theta[i],0.0);
                            //ponownie krok 7;
                            k=k+1;
                            for (int i=0; i<ilosc_ograniczen; i++) g0[i]=g[i];
                }
                else { goto stop;} //przejscie do kroku 6

            }


        }

    }
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
