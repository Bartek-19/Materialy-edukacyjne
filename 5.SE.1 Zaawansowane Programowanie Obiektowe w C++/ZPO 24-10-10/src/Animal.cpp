#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal()
{
    //ctor
    protectedAnimal = true;
}

Animal::Animal(int limbNr1, string name1, bool isProtected)
{
    limbNr = limbNr1;
    name = name1;
    protectedAnimal = isProtected;
}

Animal::~Animal()
{
    //dtor
}

string Animal::getName()
{
    return name;
}

void Animal::setName(string newName)
{
    name = newName;
}

int Animal::getLimbNr()
{
    return limbNr;
}

void Animal::setLimbNr(int newLimbNr)
{
    limbNr = newLimbNr;
}

bool Animal::getProtected()
{
    return protectedAnimal;
}

void Animal::setProtected(bool isProtected)
{
    protectedAnimal = isProtected;
}

void Animal::giveVoice()
{
    cout<<"Chrum, miau, hau, piiiii"<<endl;
}

void Animal::info()
{
    cout<<"> Nazwa: "<<name<<endl<<"> Ilosc konczyn: "<<limbNr<<endl<<"> Czy jest pod ochrona: "<<protectedAnimal<<endl;
}
