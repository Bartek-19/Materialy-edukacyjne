#include "Tdata.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Tdata::Tdata()
{
    d = 7;
    m = 6;
    r = 2003;
    //ctor
}

void Tdata::wczytaj()
{
    cout<<"Podaj dzien:  ";
    cin>>d;
    cout<<"Podaj miesiac:  ";
    cin>>m;
    cout<<"Podaj rok:  ";
    cin>>r;
}

void Tdata::wyswietl()
{
    cout<<d<<"."<<m<<"."<<r<<" r."<<endl;
}

Tdata::getR()
{
    return r;
}

Tdata::~Tdata()
{
    //dtor
}
