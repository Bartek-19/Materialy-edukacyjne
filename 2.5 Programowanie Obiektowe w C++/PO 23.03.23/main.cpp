#include <iostream>
#include <cstring>
#include <iomanip>
#include "TosobaS.h"

using namespace std;

int main()
{
    char imie[20] = "Jan";
    char nazwisko[20] = "Kowalski";
    const int liczbaElementow = 5;

    cout<<endl<<"> Zadanie 4.2"<<endl<<endl;
    cout<<"Liczba obiektow: "<<TosobaS::ile()<<endl;
    cout<<"Kraj wszystkich obiektow:  "<<TosobaS::getKraj()<<endl<<endl;
    cout<<"Utworzenie obiektu os1:"<<endl;
    TosobaS os1;
    cout<<"Liczba obiektow: "<<os1.ile()<<endl<<endl;
    cout<<"Utworzenie obiektu os2"<<endl;
    TosobaS os2(nazwisko, imie, 69);
    cout<<"Liczba obiektow: "<<os2.ile()<<endl<<endl;
    cout<<"Utworzenie obiektu os3"<<endl;
    TosobaS *os3 = new TosobaS;
    cout<<"Liczba obiektow: "<<os3->ile()<<endl<<endl;
    cout<<"Utworzenie obiektu os4"<<endl;
    TosobaS &os4 = os1;
    cout<<"Liczba obiektow: "<<os4.ile()<<endl<<endl;
    cout<<"Utworzenie obiektu os5"<<endl;
    TosobaS os5(os1);
    cout<<"Liczba obiektow: "<<os5.ile()<<endl<<endl;
    delete os3;



    cout<<endl<<"> Zadanie 4.3"<<endl<<endl;

    cout<<"> Wersja z tablica obiektow:"<<endl<<endl;
    TosobaS tablicaObiektow[liczbaElementow];
    cout<<endl;
    for (int i=0; i<liczbaElementow; i++)
        tablicaObiektow[i].podajDane();
    cout<<endl;
    for (int i=0; i<liczbaElementow; i++)
        tablicaObiektow[i].wyswietl();


    cout<<endl<<"> Wersja z tablica wskaznikow na obiekty"<<endl<<endl;
    TosobaS *tablicaWskaznikow[liczbaElementow];
    for (int i=0; i<liczbaElementow; i++)
    {
        tablicaWskaznikow[i] = new TosobaS;
        tablicaWskaznikow[i]->podajDane();
    }
    cout<<endl;
    for (int i=0; i<liczbaElementow; i++)
    {
        tablicaWskaznikow[i]->wyswietl();
        delete tablicaWskaznikow[i];
    }

    return 0;
}
