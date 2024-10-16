#include "Tosoba.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstring>

using namespace std;

Tosoba::Tosoba()
{
    cout<<"konstruktor domyslny klasy Tosoba"<<endl;
    strcpy(nazwisko, "Klimiuk");
    imie = "Bartosz";
    dataUr.d = 7;
    dataUr.m = 6;
    dataUr.r = 2003;
}

Tosoba::Tosoba(int dd, int mm, int rr)
{
    dataUr.d = dd;
    dataUr.m = mm;
    dataUr.r = rr;
}

void Tosoba::wczytaj()
{
    cout<<"imie:  ";
    cin>>imie;
    cout<<"nazwisko:  ";
    cin>>nazwisko;
    cout<<"data urodzenia:"<<endl;
    cin>>dataUr.d>>dataUr.m>>dataUr.r;
}

void Tosoba::wyswietl()
{
    cout<<endl<<imie<<endl<<nazwisko<<endl;
    cout<<dataUr.d<<"."<<dataUr.m<<"."<<dataUr.r<<" r."<<endl;
}

void Tosoba::info()
{
    int wiek = 2023 - dataUr.r;

    if (wiek > 50)
        cout<<"Osoba 50+"<<endl;
    else if (wiek > 30)
        cout<<"Osoba 30+"<<endl;
    else if (wiek >= 18)
        cout<<"Osoba dorosla"<<endl;
    else
        cout<<"Dziecko"<<endl;
    cout<<endl;
}

void Tosoba::wyswietl(int rok)
{
    cout<<endl<<imie<<endl<<nazwisko<<endl;
    cout<<rok - dataUr.r<<" lat"<<endl;
}

void Tosoba::info(int rok)
{
    cout<<"Osiagniecie pelnoletnosci w "<<dataUr.r + 18<<" roku"<<endl<<endl;
}

Tosoba::~Tosoba()
{
    cout<<"destruktor klasy Tosoba"<<endl;
}
