#include "Tosoba.h"
#include <iostream>

using namespace std;

Tosoba::Tosoba()
{
    //ctor
    cout<<"Konstruktor domyslny klasy Tosoba"<<endl;
    imie = "Bartosz";
    nazwisko = "Klimiuk";
}

Tosoba::Tosoba(string i, string n)
{
    cout<<"Konstruktor z parametrami klasy Tosoba"<<endl;
    imie = i;
    nazwisko = n;
}

void Tosoba::wczytaj()
{
    cout<<"Podaj imie:  ";
    cin>>imie;
    cout<<"Podaj nazwisko:  ";
    cin>>nazwisko;
}

void Tosoba::wyswietl()
{
    cout<<"Imie:  "<<imie<<endl<<"Nazwisko:  "<<nazwisko<<endl;
}

Tosoba::~Tosoba()
{
    //dtor
    cout<<"Destruktor klasy Tosoba"<<endl;
}
