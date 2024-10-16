#include <iostream>
#include <math.h>

#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    int calka, metoda, m;
    double h, wynik;

    do{
        cout<<"Wybierz rodzaj calki:"<<endl;
        cout<<"1. (0->1)(sqrt(1+x)dx)"<<endl;
        cout<<"2. (0->2pi)[(sin^2(x)+2)dx]"<<endl;
        cout<<"3. (0->2)[(e^x * 2*x^3)dx]"<<endl;
        cout<<"> > > ";
        cin>>calka;
    }while(calka<0 || calka>3);
    cout<<endl;

    do{
        cout<<"Wybierz metode calkowania:"<<endl;
        cout<<"1. Metoda wzoru zlozonego trapezow"<<endl;
        cout<<"2. Metoda wzoru zlozonego Simpsona"<<endl;
        cout<<"> > > ";
        cin>>metoda;
    }while(metoda!=1 && metoda!=2);
    cout<<endl;

    do{
        cout<<"Podaj liczbe wezlow:  ";
        cin>>m;
    }while(m<=0);
    cout<<endl;

    if(metoda==2 && m%2==0)
    {
        cout<<"Przy metodzie Simpsona liczba podprzedzialow miedzy wezlami musi byc parzysta!"<<endl;
        exit(1);
    }

    double x[m], f[m];

    switch(calka)
    {
    case 1:
        h = 1.0/(m-1);
        break;
    case 2:
        h = 2.0*M_PI/(m-1);
        break;
    case 3:
        h = 2.0/(m-1);
        break;
    }

    x[0] = 0;
    for(int i=1; i<m; i++)
        x[i] = x[i-1] + h;

    switch(calka)
    {
    case 1:
        for(int i=0; i<m; i++)
            f[i] = sqrt(1+x[i]);
        break;
    case 2:
        for(int i=0; i<m; i++)
            f[i] = pow(sin(x[i]), 2) + 2;
        break;
    case 3:
        for(int i=0; i<m; i++)
            f[i] = exp(x[i]) * 2 * pow(x[i], 3);
        break;
    }

    if(metoda==1)
    {
        wynik = 0.5*(f[0]+f[m-1]);
        for(int i=1; i<m-1; i++)
            wynik += f[i];
        wynik *= h;
    }
    else
    {
        wynik = f[0] + f[m-1];
        for(int i=1; i<m-1; i++)
        {
            if(i%2==1)
                wynik += 4*f[i];
            else
                wynik += 2*f[i];
        }
        wynik *= h/3.0;
    }

    cout<<endl<<"Wynik calki = "<<wynik<<endl;;

    return 0;
}
