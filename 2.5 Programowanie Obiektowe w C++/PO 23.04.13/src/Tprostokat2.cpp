#include "Tprostokat2.h"
#include <iostream>
#include <cstdio>

using namespace std;

Tprostokat2::Tprostokat2()
{
    //ctor
    cout<<"Konstruktor klasy Tprostokat2"<<endl;
    nazwa = "Prostokat";
    OBW = 18;
    P = 20;
}

void Tprostokat2::rysuj()
{
    cout<<"Rysuje:  "<<nazwa<<endl<<endl;
    printf(" ____________\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|____________|\n\n");
}

void Tprostokat2::wyswietl()
{
    Ifigura::info();
    rysuj();
    cout<<endl<<"Pole = "<<Ifigura::pole()<<endl<<"Obwod = "<<Ifigura::obwod()<<endl<<endl;
}

Tprostokat2::~Tprostokat2()
{
    //dtor
    cout<<"Destruktor klasy Tprostokat2"<<endl;
}
