#include "Tkwadrat2.h"
#include <iostream>
#include <cstdio>

using namespace std;

Tkwadrat2::Tkwadrat2()
{
    //ctor
    cout<<"Konstruktor klasy Tkwadrat2"<<endl;
    nazwa = "kwadrat";
    OBW = 16;
    P = 16;
}

void Tkwadrat2::rysuj()
{
    cout<<"Rysuje:  "<<nazwa<<endl<<endl;
    printf(" ______________________\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|______________________|\n\n");
}

void Tkwadrat2::wyswietl()
{
    Ifigura::info();
    rysuj();
    cout<<endl<<"Pole = "<<Ifigura::pole()<<endl<<"Obwod = "<<Ifigura::obwod()<<endl<<endl;
}

Tkwadrat2::~Tkwadrat2()
{
    //dtor
    cout<<"Destruktor klasy Tkwadrat2"<<endl;
}
