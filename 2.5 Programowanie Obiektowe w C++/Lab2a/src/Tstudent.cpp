#include "Tstudent.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

float Tstudent::sredniaOcen()
{
    float S;

    for(int i=0; i<3; i++)
        S += oceny[i];

    return S / 3.0;
}

bool Tstudent::czyZdal()
{
    for(int i=0; i<3; i++)
    {
        if (oceny[i]==2)
            {zdal = false;
            break;}
        else
            zdal = true;
    }

    return zdal;
}

void Tstudent::wczytaj()
{
    int i = 0;

    cout<<"Podaj imie:  ";
    cin>>imie;
    cout<<"Podaj nazwisko:  ";
    cin>>nazwisko;

    while (i<3)
    {
        cout<<"Podaj ocene "<<i+1<<":  ";
        cin>>oceny[i];
        if(oceny[i] < 2 || oceny[i] > 5)
            cout<<" !Podano zla ocene! "<<endl;
        else
            i++;
    }

    srednia = sredniaOcen();

    zdal = czyZdal();
}

void Tstudent::wyswietl()
{
    cout<<endl<<"Imie:       "<<imie<<endl;
    cout<<"Nazwisko:   "<<nazwisko<<endl;
    cout<<"Srednia:    "<<fixed<<setprecision(2)<<srednia<<endl;
    cout<<"Status:     ";
    if (zdal == true)
        cout<<"Zdal"<<endl<<endl;
    else
        cout<<"Nie zdal"<<endl<<endl;
}
