#include "Tdomownik.h"
#include <iostream>

using namespace std;

int Tdomownik::kod = 1234;

Tdomownik::Tdomownik(string N, string S)
{
    //ctor
    nazwa = N;
    sekret = S;
}

void Tdomownik::wyswietl()
{
    cout<<nazwa<<" - "<<sekret<<endl;
}

void Tdomownik::setKod()
{
    cout<<"Wprowadz nowy kod:  ";
    cin>>kod;
}

int Tdomownik::getKod()
{
    return kod;
}

Tdomownik::~Tdomownik()
{
    //dtor
}
