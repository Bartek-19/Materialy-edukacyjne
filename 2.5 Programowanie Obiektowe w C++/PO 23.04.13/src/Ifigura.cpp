#include "Ifigura.h"
#include <iostream>
#include <cstdio>

using namespace std;

Ifigura::Ifigura()
{
    cout<<"Konstruktor klasy Ifigura"<<endl;
    nazwa = "Figura";
    OBW = 68.86;
    P = 96.97;
    //ctor
}

void Ifigura::info()
{
    cout<<nazwa<<endl;
}

void Ifigura::rysuj()
{
    cout<<"Rysuje:  "<<nazwa<<endl<<endl;
    printf("       __       \n");
    printf("      /  \\      \n");
    printf("      |  |      \n");
    printf("     /    \\     \n");
    printf("    /      \\    \n");
    printf("   /_      _\\   \n");
    printf("     \\    /     \n");
    printf("      \\/\\/      \n\n");
}

float Ifigura::obwod()
{
    return OBW;
}

float Ifigura::pole()
{
    return P;
}

void Ifigura::wyswietl()
{
    info();
    rysuj();
    cout<<endl<<"Pole = "<<pole()<<endl<<"Obwod = "<<obwod()<<endl<<endl;
}

Ifigura::~Ifigura()
{
    cout<<"Destruktor klasy Ifigura"<<endl;
    //dtor
}
