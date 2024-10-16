#include "Tkolo2.h"
#include <iostream>
#include <cstdio>

using namespace std;

Tkolo2::Tkolo2()
{
    cout<<"konstruktor klasy Tkolo2"<<endl;
    nazwa = "kolo";
    OBW = 6.28;
    P = 3.14;
    //ctor
}

void Tkolo2::rysuj()
{
    cout<<"Rysuje:  "<<nazwa<<endl<<endl;

    printf("       oOOOOOOOo       \n");
    printf("    oOOOOOOOOOOOOOo    \n");
    printf("   OOOOOOOOOOOOOOOOO   \n");
    printf("  OOOOOOOOOOOOOOOOOOO  \n");
    printf(" OOOOOOOOOOOOOOOOOOOOO \n");
    printf(" OOOOOOOOOOOOOOOOOOOOO \n");
    printf(" OOOOOOOOOOOOOOOOOOOOO \n");
    printf("  OOOOOOOOOOOOOOOOOOO  \n");
    printf("   OOOOOOOOOOOOOOOOO   \n");
    printf("    OOOOOOOOOOOOOOO    \n");
    printf("      OOOOOOOOOOO      \n");
}

void Tkolo2::wyswietl()
{
    Ifigura::info();
    rysuj();
    cout<<endl<<"Pole = "<<Ifigura::pole()<<endl<<"Obwod = "<<Ifigura::obwod()<<endl<<endl;
}

Tkolo2::~Tkolo2()
{
    cout<<"Destruktor klasy Tkolo2"<<endl;
    //dtor
}
