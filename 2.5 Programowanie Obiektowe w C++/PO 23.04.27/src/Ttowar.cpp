#include "Ttowar.h"
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

Ttowar::Ttowar()
{
    //ctor
    kod = "000001";
    nazwa = "Taczki";
    cena = 99.99;
    ilosc = 5;
}

void Ttowar::wczytaj()
{
    cout<<"Podaj kod towaru:  ";
    fflush(stdin);
    cin>>kod;
    cout<<"Podaj nazwe towaru:  ";
    fflush(stdin);
    getline(cin, nazwa);
    cout<<"Podaj cene towaru:  ";
    fflush(stdin);
    cin>>cena;
    cout<<"Podaj ilosc towaru:  ";
    fflush(stdin);
    cin>>ilosc;
}

void Ttowar::wyswietl()
{
    cout<<setw(20)<<nazwa<<setw(10)<<kod<<fixed<<setprecision(2)<<setw(10)<<cena<<setw(6)<<ilosc<<fixed<<setprecision(2)<<setw(10)<<oblicz()<<endl;
}

float Ttowar::oblicz()
{
    return ilosc*cena;
}

Ttowar::~Ttowar()
{
    //dtor
}
