#include <iostream>
#include "Tosoba.h"
#include <string.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main()
{
    Tosoba osoba;
    Tosoba osoba1(1, 1, 2000);
    Tosoba * wsk1 = new Tosoba;
    Tosoba * wsk2 = new Tosoba(1, 1, 2000);
    Tosoba osoba2 = osoba;
    Tosoba &osoba3 = osoba;

    cout<<endl<<"Obiekt domyslny: ";
    osoba.wyswietl();
    osoba.info();

    cout<<"Obiekt przeciazony: "<<endl;
    osoba1.wczytaj();
    osoba1.wyswietl(2023);
    osoba1.info(2023);

    cout<<"Obiekt kopiujacy obiekt domyslny: "<<endl;
    osoba2.wyswietl();
    osoba2.info();

    cout<<"Obiekt referencyjny: "<<endl;
    osoba3.wyswietl();
    osoba3.wczytaj();

    cout<<endl<<"Obiekt domyslny po dzialaniu referencyjnego: "<<endl;
    osoba.wyswietl();
    cout<<endl<<"Obiekt-kopia po dzialaniu referencyjnego: "<<endl;
    osoba2.wyswietl();

    cout<<endl<<"Obiekt wskaznikowy domyslny: "<<endl;
    wsk1->wyswietl();
    wsk1->info();


    cout<<endl<<"Obiekt wskaznikowy przeciazony: "<<endl;
    wsk2->wczytaj();
    wsk2->wyswietl(2023);
    wsk2->info(2003);

    getchar();
    delete wsk1;
    delete wsk2;
    return 0;
}
