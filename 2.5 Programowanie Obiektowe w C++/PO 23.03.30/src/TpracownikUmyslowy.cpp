#include "TpracownikUmyslowy.h"
#include <iostream>

using namespace std;

TpracownikUmyslowy::TpracownikUmyslowy()
{
    //ctor
    cout<<"Konstruktor domyslny klasy TpracownikUmyslowy"<<endl;
    stanowisko = "C++ Developer";
    dzial = "Software Development";
}

TpracownikUmyslowy::TpracownikUmyslowy(string i, string n, string nFirmy, float w, int p, string s, string d)
{
    cout<<"Konstruktor z parametrami klasy TpracownikUmyslowy"<<endl;
    imie = i;
    nazwisko = n;
    firma = nFirmy;
    wyplata = w;
    premia = p;
    stanowisko = s;
    dzial = d;
}

void TpracownikUmyslowy::wczytaj()
{
    Tpracownik::wczytaj();
    cout<<"Podaj stanowisko:  ";
    fflush(stdin);
    getline(cin, stanowisko);
    cout<<"Podaj dzial firmy:  ";
    fflush(stdin);
    getline(cin, dzial);
}

void TpracownikUmyslowy::wyswietl()
{
    Tpracownik::wyswietl();
    cout<<"Stanowisko:  "<<stanowisko<<endl<<"Dzial:  "<<dzial<<endl;
}

TpracownikUmyslowy::~TpracownikUmyslowy()
{
    //dtor
    cout<<"Destruktor klasy TpracownikUmyslowy"<<endl;
}
