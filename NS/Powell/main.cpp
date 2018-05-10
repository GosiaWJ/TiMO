#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    string wyraz, nastepny, wynik;
    double a=11.890;
    char buf[50];
    char buffer [50];
      int n;
      n=sprintf (buffer, "%l plus", a);
nastepny=buffer.append("23");
    cout << "Polaczony tekst to: \"" << nastepny << "\"" << endl;

    return( 0 );
}
