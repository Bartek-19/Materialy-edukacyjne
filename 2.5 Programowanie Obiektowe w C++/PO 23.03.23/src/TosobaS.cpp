#include "TosobaS.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int TosobaS::liczbaObiektow = 0;

string TosobaS::kraj = "Polska";

TosobaS::TosobaS()
{
    cout<<"Utworzenie domyslnego obiektu TosobaS"<<endl;
    strcpy(nazwisko, "Klimiuk");
    strcpy(imie, "Bartosz");
    wiek = 20;
    liczbaObiektow++;
    //ctor
}

TosobaS::TosobaS(TosobaS &oryginal)
{
    cout<<"Utworzenie skopiowanego obiektu TosobaS"<<endl;
    liczbaObiektow++;
}

TosobaS::TosobaS(char *naz, char *im, int w)
{
    cout<<"Utworzenie przeciazonego obiektu TosobaS"<<endl;
    strcpy(imie, im);
    strcpy(nazwisko, naz);
    wiek = w;
    liczbaObiektow++;
}

void TosobaS::podajDane()
{
    cout<<"Podaj imie:  ";
    cin>>imie;
    cout<<"Podaj nazwisko:  ";
    cin>>nazwisko;
    cout<<"Podaj wiek:  ";
    cin>>wiek;
}

void TosobaS::wyswietl()
{
    cout<<setw(25)<<left<<imie<<setw(25)<<left<<nazwisko<<setw(10)<<left<<wiek<<kraj<<endl;
}

int TosobaS::ile()
{
    return liczbaObiektow;
}

string TosobaS::getKraj()
{
    return kraj;
}

TosobaS::~TosobaS()
{
    //cout<<"Niszczenie obiektu TosobaS"<<endl;
    liczbaObiektow--;
    //dtor
}
