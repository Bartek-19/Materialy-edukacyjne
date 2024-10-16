#include "Tosoba2.h"
#include "Tdata.h"
#include <cstdlib>
#include <cmath>
#include <string.h>

using namespace std;

Tosoba2::Tosoba2()
{
    imie = "Bartosz";
    nazwisko = "Klimiuk";
    motto = "Life sucks, and then you die.";
    //ctor
}

Tosoba2::Tosoba2(string naz, string im, Tdata d)
{
    imie = im;
    nazwisko = naz;
    dataUr = d;
}

void Tosoba2::wczytaj()
{
    cout<<"Podaj imie:  ";
    cin>>imie;
    cout<<"podaj nazwisko:  ";
    cin>>nazwisko;
    cout<<"Podaj motto:  ";
    getline(cin, motto);
    dataUr.wczytaj();
}

void Tosoba2::wyswietl()
{
    cout<<imie<<endl;
    cout<<nazwisko<<endl;
    dataUr.wyswietl();
    cout<<motto<<endl;
}

string Tosoba2::GetNazwiskoImie()
{
    return imie + " " + nazwisko;
}

int Tosoba2::roznicaWieku(Tosoba2 & partner)
{
    return fabs(dataUr.getR() - partner.dataUr.getR());
}

Tosoba2 Tosoba2::dluzszeNazwisko(Tosoba2 &partner)
{
    int a=nazwisko.length() , b=partner.nazwisko.length();
    string c="Nazwiska sa rowne";

    if(a > b)
        return *this;
    else if(a < b)
        return partner;
    else
        cout<<c<<endl;
}

Tosoba2::~Tosoba2()
{
    cout<<endl<<"Destruktor obiektu Tosoba"<<endl;
    //dtor
}
