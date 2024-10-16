#include "Tsasiad.h"
#include "Tdomownik.h"
#include <iostream>

using namespace std;

Tsasiad::Tsasiad(Tdomownik &D)
{
    //ctor
    nazwa = "Gienek";
}

void Tsasiad::info(Tdomownik &D)
{
    cout<<"Ja, sasiad "<<nazwa<<" znam sekret "<<D.nazwa<<": "<<D.sekret<<", oraz kod do domu: "<<D.getKod()<<endl;
}

Tsasiad::~Tsasiad()
{
    //dtor
}
