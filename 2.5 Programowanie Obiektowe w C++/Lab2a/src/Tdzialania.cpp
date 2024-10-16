#include "Tdzialania.h"
#include <iostream>
#include <cmath>

using namespace std;

void Tdzialania::podajDane()
{
    cout<<"Podaj dwie liczby calkowite ";
    cin>>a>>b;
}

int Tdzialania::suma()
{
    return a+b;
}

int Tdzialania::roznica()
{
    return a-b;
}

int Tdzialania::iloczyn()
{
    return a*b;
}

void Tdzialania::iloraz()
{
    if (b!=0)
        cout<<"Iloraz:  "<<(float)a/b<<endl;
    else
        cout<<"Iloraz:  Dzielenie przez 0"<<endl;
}

double Tdzialania::potega()
{
    return pow(a, b);
}
