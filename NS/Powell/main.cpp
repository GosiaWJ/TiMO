#include <QCoreApplication>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //1
    int n=2; //ilosc zmiennych
    int m=5; //ilosc ograniczen
    double x[n];
    double x0[n];
    x0[0]=2;x0[1]=3; //punkt początkowy
    double g0[m]; //wartosci otraniczen w punkcie poczatkowym x0
    double g[m]; //wartosci ograniczen w nowym puncie x
    double c = pow(10,-5); //max wartosc przekroczenia ograniczen
    double c0 = pow(10,-5); //max wartosc przekroczenia ograniczen poczatkowa
    double c_min= pow(10,-5); //wymagana dokladnosc
    int k=0; //iteracja
    double sigma[m]; // wektor wsp kary
    double theta[m]; //wektor przesuniec kary

    double m1=0.25; double m2=10;

    for(int i=0;i<m;i++){
        sigma[m]=1;
        theta[m]=0;
    }
    double f,F; //f - wartość funkcji w punkcie x

    int theEnd=1;
    while(theEnd){
        for(int i=0;i<m;i++) g0[i]=1; //wyliczanie wartości f-cji ograniczen w x0
//2
        f=2; //policzyć wartość funkcji w punkcie x0
        F=f;
        for(int i=0;i<m;i++){
            if(g[i]+theta[i]<0)  F=F+sigma[i]*pow(g[i]+theta[i],2); //wyliczanie funkcji F w punkcie x0
        }
        // wyliczamy NS dla funkcji F, znajdujemy nowe x
        for(int i=0;i<n;i++) x0[i]=x[i];
        c0=c;
//3
        c=0;
        for(int i=0;i<m;i++){
            g[i]=g[i]; //wyliczyc nowe wartosci ograniczen dla  nowego x
            if(g0[i]+theta[i]<0) c=max(c, abs(g[i]));
        }
//4
        if(c<c_min) {
            theEnd=0;
            break;
        } else{
//5
            if(c>=c0){
                c=c0;
//6
                if(k==0 || k==1) {
                    for(int i=0;i<m;i++){
                        if((abs(g0[i])>m1*c0) && (g[i]+theta[i]<0)){
                            sigma[i]=m2*sigma[i];
                        }
                        theta[i]=min(g[i]+theta[i],0.0);
                    }
                }  else {
                    for(int i=0;i<m;i++){
                        if((abs(g0[i])>m1*c0) && (g[i]+theta[i]<0)){
                            sigma[i]=m2*sigma[i];
                            theta[i]=theta[i]/m2;
                        }
                    }
                }
//7
                k++;
                for(int i=0;i<n;i++) x0[i]=x[i];
            } else {
//8
                if(c<=m1*c0) {
                    for(int i=0;i<m;i++){
                        theta[i]=min(g[i]+theta[i],0.0);
                    }
                } else {
                    for(int i=0;i<m;i++){
                        if((abs(g0[i])>m1*c0) && (g[i]+theta[i]<0)){
                            sigma[i]=m2*sigma[i];
                            theta[i]=theta[i]/m2;
                        }
                    }
                }

            }
        }
    }

    return a.exec();
}
