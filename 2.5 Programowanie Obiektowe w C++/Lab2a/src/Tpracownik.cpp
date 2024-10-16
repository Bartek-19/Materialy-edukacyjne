#include "Tpracownik.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Tpracownik::wczytaj()
{
    cout<<endl<<"Podaj imie:  ";
    cin>>imie;
    cout<<"Podaj nazwisko:  ";
    cin>>nazwisko;
    cout<<"Podaj stawke pracownika:  ";
    cin>>stawka;
    cout<<"Podaj ilosc godzin przepracowanych przez pracownika:  ";
    cin>>godziny;
    cout<<"Podaj date zatrudnienia (DD MM RRRR):"<<endl;
    cin>>zatr.d>>zatr.m>>zatr.r;
}

float Tpracownik::wyplata()
{
    return stawka*godziny;
}

void Tpracownik::wyswietl()
{
    cout<<"Imie:               "<<imie<<endl;
    cout<<"Nazwisko:           "<<nazwisko<<endl;
    cout<<"Wyplata:            "<<fixed<<setprecision(2)<<wyplata()<<" zl."<<endl;
    cout<<"Data zatrudnienia:  "<<zatr.d<<"."<<zatr.m<<"."<<zatr.r<<" r."<<endl<<endl;
}
