#include "Tfaktura.h"
#include "Ttowar.h"
#include "Tklient.h"
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

Tfaktura::Tfaktura(Tklient *k, int n)
{
    //ctor
    klient = new Tklient;
    klient = k;
    liczbaTowarow = n;
    towary = new Ttowar[n];
}

void Tfaktura::wczytaj()
{
    delete [] towary;

    cout<<"> Dane do faktury"<<endl;
    Tdokument::wczytaj();

    cout<<"Podaj ilosc towarow:  ";
    fflush(stdin);
    cin>>liczbaTowarow;
    towary = new Ttowar[liczbaTowarow];

    for(int i=0; i<liczbaTowarow; i++)
    {
        cout<<"- Towar "<<i+1<<endl;
        towary[i].wczytaj();
    }
}

void Tfaktura::wyswietl()
{
    Tdokument::wyswietl();
    cout<<endl<<"Klient:  ";
    klient->wyswietl();
    cout<<endl;
    for(int i=0; i<liczbaTowarow; i++)
        towary[i].wyswietl();
    cout<<endl<<"Suma koncowa do zaplaty:  "<<fixed<<setprecision(2)<<suma()<<endl;
}

float Tfaktura::suma()
{
    float S;

    for(int i=0; i<liczbaTowarow; i++)
        S+=towary[i].oblicz();

    return S;
}

Tfaktura::~Tfaktura()
{
    //dtor
    delete klient;
    delete [] towary;
}
