#include "Tklient.h"
#include <iostream>
#include <cstdio>

using namespace std;

Tklient::Tklient()
{
    //ctor
    NIP = 1234567;
    imie = "Bartosz";
    nazwisko = "Klimiuk";
}

void Tklient::wczytaj()
{
    cout<<"Podaj imie klienta:  ";
    fflush(stdin);
    cin>>imie;
    cout<<"Podaj nazwisko klienta:  ";
    fflush(stdin);
    cin>>nazwisko;
    cout<<"Podaj NIP klienta (7 cyfr):  ";
    fflush(stdin);
    cin>>NIP;
}

void Tklient::wyswietl()
{
    cout<<nazwisko<<", "<<imie<<endl<<"NIP:  "<<NIP<<endl;
}

Tklient::~Tklient()
{
    //dtor
}
