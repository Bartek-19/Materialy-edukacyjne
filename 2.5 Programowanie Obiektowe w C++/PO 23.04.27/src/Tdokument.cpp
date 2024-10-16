#include "Tdokument.h"
#include <iostream>
#include <cstdio>

using namespace std;

Tdokument::Tdokument()
{
    //ctor
    nazwa = "Dokument 1";
    numer = "00/2023";
    dataWystawienia.d = 1;
    dataWystawienia.m = 1;
    dataWystawienia.r = 2023;
}

void Tdokument::wczytaj()
{
    cout<<"Podaj numer dokumentu:  ";
    fflush(stdin);
    cin>>numer;
    cout<<"Podaj nazwe dokumentu:  ";
    fflush(stdin);
    getline(cin, nazwa);
    cout<<"Podaj date wystawienia (dd mm rrrr):  ";
    fflush(stdin);
    cin>>dataWystawienia.d>>dataWystawienia.m>>dataWystawienia.r;
}

void Tdokument::wyswietl()
{
    cout<<"Dokument numer "<<numer<<endl;
    cout<<nazwa<<endl;
    cout<<"Data wystawienia:  "<<dataWystawienia.d<<"."<<dataWystawienia.m<<"."<<dataWystawienia.r<<" r."<<endl;
}

Tdokument::~Tdokument()
{
    //dtor
}
