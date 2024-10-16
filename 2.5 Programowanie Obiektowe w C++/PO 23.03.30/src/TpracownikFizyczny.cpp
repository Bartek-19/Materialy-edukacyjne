#include "TpracownikFizyczny.h"
#include <iostream>

using namespace std;

TpracownikFizyczny::TpracownikFizyczny()
{
    //ctor
    cout<<"Konstruktor domyslny klasy TpracownikFizyczny"<<endl;
    stanowisko = "Magazynier";
    nazwaBrygady = "Mag.1.3";
}

TpracownikFizyczny::TpracownikFizyczny(string i, string n, string nFirmy, float w, int p, string s, string nBrygady)
{
    cout<<"Konstruktor z parametrami klasy TpracownikFizyczny"<<endl;
    imie = i;
    nazwisko = n;
    firma = nFirmy;
    wyplata = w;
    premia = p;
    stanowisko = s;
    nazwaBrygady = nBrygady;
}

void TpracownikFizyczny::wczytaj()
{
    Tpracownik::wczytaj();
    cout<<"Podaj nazwe stanowiska:  ";
    fflush(stdin);
    getline(cin, stanowisko);
    cout<<"Podaj kod brygady:  ";
    fflush(stdin);
    getline(cin, nazwaBrygady);
}

void TpracownikFizyczny::wyswietl()
{
    Tpracownik::wyswietl();
    cout<<"Stanowisko:  "<<stanowisko<<endl<<"Nazwa Brygady:  "<<nazwaBrygady<<endl;
}

TpracownikFizyczny::~TpracownikFizyczny()
{
    //dtor
    cout<<"Destruktor klasy TpracownikFizyczny"<<endl;
}
