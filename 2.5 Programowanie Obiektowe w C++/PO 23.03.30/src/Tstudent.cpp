#include "Tstudent.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Tstudent::Tstudent()
{
    //ctor
    cout<<"Konstruktor domyslny klasy Tstudent"<<endl;
    liczbaOcen = 5;
    oceny = new float[liczbaOcen];
    uczelnia = "Politechnika Lubelska";
    wczytajOceny();
}

Tstudent::Tstudent(string i, string n, string u, int lo)
{
    cout<<"Konstruktor z parametrami klasy Tstudent"<<endl;
    imie = i;
    nazwisko = n;
    uczelnia = u;
    liczbaOcen = lo;
    oceny = new float[liczbaOcen];
    wczytajOceny();
}

//Konstruktor potomka z konstruktorem przodka
/*
Tstudent::Tstudent(string i, string n, string u, int lo):Tosoba(i, n)
{
    uczelnia = u;
    liczbaOcen = lo;
    oceny = new float[liczbaOcen];
}*/

void Tstudent::wczytaj()
{
    Tosoba::wczytaj();
    cout<<"Podaj nazwe uczelni:  ";
    fflush(stdin);
    getline(cin, uczelnia);
    do {
        cout<<"Podaj ilosc ocen:  ";
        cin>>liczbaOcen;
    } while(liczbaOcen <= 0);
    wczytajOceny();
}

void Tstudent::wczytajOceny()
{
    for(int i=0; i<liczbaOcen; i++)
    {
        do {cout<<"Podaj ocene "<<i+1<<":  ";
            cin>>oceny[i];
            if(oceny[i] < 2 || oceny[i] > 5)
                cout<<"Podano zla ocene!"<<endl;
        } while(oceny[i] < 2 || oceny[i] > 5);
    }
}

void Tstudent::wyswietl()
{
    bool zdane = czyZdane();

    Tosoba::wyswietl();
    cout<<"Uczelnia:  "<<uczelnia<<endl;
    for(int i=0; i<liczbaOcen; i++)
        cout<<"Ocena "<<i+1<<":  "<<oceny[i]<<endl;
    cout<<"Srednia:  "<<sredniaOcen()<<endl;
    cout<<"Status:  ";
    if(zdane == true)
        cout<<"Zdane"<<endl;
    else
        cout<<"Nie zdane"<<endl;

}

float Tstudent::sredniaOcen()
{
    float S=0;

    for(int i=0; i<liczbaOcen; i++)
        S+=oceny[i];

    S/=liczbaOcen;

    return S;
}

bool Tstudent::czyZdane()
{
    bool wynik = true;

    for(int i=0; i<liczbaOcen; i++)
        if(oceny[i]==2)
            wynik = false;

    return wynik;
}

Tstudent::~Tstudent()
{
    //dtor
    cout<<"Destruktor klasy Tstudent"<<endl;
    delete [] oceny;
}
