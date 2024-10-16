#include "Tosoba3.h"
#include <iostream>

using namespace std;

Tosoba3::Tosoba3()
{
    //ctor
}

/*Tosoba3::Tosoba3(string naz)
{
    cout<<"Adres pola 'naz':    "<<&naz<<endl;
    nazwisko = naz;
    //this->nazwisko=naz;
}*/

/*Tosoba3::Tosoba3(string *naz)
{
    cout<<"Adres pola 'naz':    "<<naz<<endl;
    this->nazwisko = *naz;
}*/

Tosoba3::Tosoba3(string &naz)
{
    cout<<"Adres pola 'naz':    "<<&naz<<endl;
    this->nazwisko = naz;
}

/*Tosoba3::Tosoba3(const string &naz)
{
    cout<<"Adres pola 'naz':    "<<&naz<<endl;
    this->nazwisko = naz;
}*/

string Tosoba3::getNazwisko()
{
    return nazwisko;
}

Tosoba3::~Tosoba3()
{
    //dtor
}
