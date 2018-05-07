#include <QCoreApplication>
#include <iostream>
using namespace std;
double Function(double x1, double x2)
{
   return pow(x1,2)+pow(x2,2);
}
double Function2(double x1, double x2)//robię dla tej funkcji
{
   return 2*pow(x1,2)+pow(x2,2)-2*x1*x2;
}
double Function3(double x1, double x2)
{
   return pow(x1,2)+2*pow(x2,2)-6*x1+x1*x2;
}

double Derivative_part(double x1, double x2, double h) //zmienić, żeby była różna liczba funkcji i różne funkcje
{
   return (Function2(x1+h, x2)-Function2(x1,x2))/h;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

double h_pochodna=0.1;
int n=2; //l. zmiennych
double x[n];
x[0]=2;x[1]=3;//wart. pocz.
double grad[n];
double ksi[n];
int theEnd=1;
double P=0;
double ksi2=0;
double Ya, Yb;
double epsilon=pow(10,-5);
double zm_e, F, Pa, d, t, Pb, h, z, w, g2, F0;
int ZW=0;
int MIN_W_KIER=0; //nie wiemy jeszcze co to
int k=1;

F0=Function2(x[0],x[1]);
while(theEnd){
    for (int i=0; i<n; i++) {
        grad[i]=Derivative_part(x[i], x[i+1%n],h_pochodna);
        ksi[i]=(-1)*grad[i];
    }
    for (int i=0; i<n; i++) P=P+grad[i]*grad[i];
    Ya=F0;
    Pa=P;
    for (int i=0; i<n; i++) ksi2=ksi2+ksi[i]*ksi[i];
    zm_e=1/sqrt(ksi2);
    while(!(ZW==1 && MIN_W_KIER==1)){ //tu sprawdzenie warunku "czy minimum w kierunku ksi?"- tak ozacza wyjście z pętli
        for (int i=0; i<n; i++) x[i]=x[i]+zm_e*ksi[i]; //nowy punkt
        F=Function2(x[0],x[1]);
        for (int i=0; i<n; i++) grad[i]=Derivative_part(x[i], x[i+1%n],h_pochodna);
        P=0;
        for (int i=0; i<n; i++) P=P+grad[i]*ksi[i];
        if (ZW==1) {
            if (P<0){
                Ya=F; Pa=P; zm_e=d; t=zm_e;
            } else {
                Yb=F; Pb=P; zm_e=h-d; t=0;
            };
        }
        else{
            Yb=F; Pb=P;
            if(Yb>Ya && Pb>0)  {t=0; }
            else {
                Ya=Yb; Pa=Pb; zm_e=zm_e*2;
            }
        };
        if((ZW==1) || (Yb>Ya && Pb>0)){
            z=ksi2*(Ya-Yb)/zm_e+Pa+Pb; // czy na pewno ksi2? i e?
            w=sqrt(pow(z,2)-Pa*Pb);
            d=zm_e*(Pb+w+z)/(Pb-Pa+2*w); //czy na pewno 2w?
            h=zm_e; ZW=1; zm_e=t-d;
        }
        ++k;
       // cout<<zm_e<<endl;
        if (k==100) {MIN_W_KIER=1; ZW=1;};
    }
    ZW=0;
    for (int i=0; i<n; i++) g2=g2+grad[i]*grad[i];
    //drukowanie wyników
    if(g2<epsilon)    theEnd=0;
    else{
        if(F<F0) F0=F;
        else theEnd=0;
    }
}
cout<<"dokonało się"<<endl;
    return a.exec();
}
