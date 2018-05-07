#include <QCoreApplication>
#include <iostream>
#include<cmath>
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

double Derivative_part1(double x1, double x2, double h) //zmienić, żeby była różna liczba funkcji i różne funkcje
{
   return (Function2(x1+h/2, x2)-Function2(x1-h/2,x2))/h;
}
double Derivative_part2(double x1, double x2, double h) //zmienić, żeby była różna liczba funkcji i różne funkcje
{
   return (Function2(x1, x2+h/2)-Function2(x1,x2-h/2))/h;
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
double epsilon=pow(10,-3);
double zm_e, F, Pa, d, t, Pb, h, z, w, g2, F0;
int ZW=0;
int MIN_W_KIER=0; //nie wiemy jeszcze co to
int k=1;

F0=Function2(x[0],x[1]);
while(theEnd){
        grad[0]=Derivative_part1(x[0], x[1],h_pochodna);
        grad[1]=Derivative_part2(x[0], x[1],h_pochodna);

    for (int i=0; i<n; i++) {
        ksi[i]=(-1)*grad[i];
    }


    for (int i=0; i<n; i++) P=P+grad[i]*ksi[i];
    Ya=F0;
    Pa=P;
    ksi2=0;
    for (int i=0; i<n; i++) ksi2=ksi2+ksi[i]*ksi[i];
    zm_e=1/sqrt(ksi2);
    while(!(ZW==1 &&MIN_W_KIER)){ //tu sprawdzenie warunku "czy minimum w kierunku ksi?"- tak ozacza wyjście z pętli
        if(abs(zm_e)<epsilon) break;
        for (int i=0; i<n; i++) x[i]=x[i]+zm_e*ksi[i]; //nowy punkt
        F=Function2(x[0],x[1]);
        grad[0]=Derivative_part1(x[0], x[1],h_pochodna);
        grad[1]=Derivative_part2(x[0], x[1],h_pochodna);
        P=0;
        for (int i=0; i<n; i++) P=P+grad[i]*ksi[i];
        if(k<200) {
            cout<<"P<0 "<<P<<endl;
             cout<<"e= "<<zm_e<<endl;
        }
        if (ZW==1) {
            //dodać if który sprawdza czy minimum w kierunku ksi
           // cout<<"F= "<<F<<endl;
           // cout<<"k="<<k<<endl;
            if(abs(P)<pow(10,-2)){
                MIN_W_KIER=1;
                //cout<<"cośtam"<<endl;

            }
            else
            {
                if (P<0){
                    Ya=F; Pa=P; zm_e=d; t=zm_e;
                   // cout<<"P<0 "<<P<<endl;
                } else {
                    Yb=F; Pb=P; zm_e=h-d; t=0;
                   //cout<<"P>0 "<<P<<endl;

            }
            }
        }
        else{
            Yb=F; Pb=P;
            if(Yb>Ya && Pb>0)  {t=0; }
            else {
                Ya=Yb; Pa=Pb; zm_e=zm_e*2;
            }
        };
        if((ZW==1 && MIN_W_KIER==0) || (Yb>Ya && Pb>0)){
            z=ksi2*(Ya-Yb)/zm_e+Pa+Pb; // czy na pewno ksi2? i e?
            w=sqrt(pow(z,2)-Pa*Pb);
            d=zm_e*(Pb+w+z)/(Pb-Pa+2*w); //czy na pewno 2w?
            h=zm_e; ZW=1; zm_e=t-d;
        }
        ++k;
        if(k==200) break;
       //cout<<zm_e<<endl;
    }

   if(MIN_W_KIER==1)
   {
    MIN_W_KIER=0;
    ZW=0;
    g2=0;
    for (int i=0; i<n; i++) g2=g2+grad[i]*grad[i];

    if(g2<epsilon)    theEnd=0;
    else{
        if(F<F0) F0=F;
        else theEnd=0;
    }
    cout<<"dokonało się"<<endl;
    cout<<x[0]<<endl;
    cout<<x[1]<<endl;
   }
}

    return a.exec();
}
