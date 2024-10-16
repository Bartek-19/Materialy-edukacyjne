#include "Tpracownik.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tpracownik::Tpracownik()
{
    //ctor
    cout<<"Konstruktor domyslny klasy Tpracownik"<<endl;
    firma = "Google";
    wyplata = 4567.89;
    premia = 10;
}

Tpracownik::Tpracownik(string i, string n, string nazwa, float w, int p)
{
    cout<<"Konstruktor z parametrami klasy Tpracownik"<<endl;
    imie = i;
    nazwisko = n;
    firma = nazwa;
    wyplata = w;
    premia = p;
}

void Tpracownik::wczytaj()
{
    Tosoba::wczytaj();
    cout<<"Podaj nazwe firmy:  ";
    fflush(stdin);
    getline(cin, firma);

    do {
        cout<<"Podaj wyplate miesieczna:  ";
        cin>>wyplata;
    } while(wyplata < 0);

    do {
        cout<<"Podaj premie pracownika (w %):  ";
        cin>>premia;
    } while(premia < 0);
}

void Tpracownik::wyswietl()
{
    Tosoba::wyswietl();
    cout<<"Nazwa firmy:  "<<firma<<endl<<"Przychod pracownika:  "<<fixed<<setprecision(2)<<przychod()<<endl;
}

float Tpracownik::przychod()
{
    return 12*wyplata*(1+premia/100.0);
}

Tpracownik::~Tpracownik()
{
    //dtor
    cout<<"Destruktor klasy Tpracownik"<<endl;
}
