#include "Cat.h"

Cat::Cat()
{
    //ctor
}

Cat::Cat(int limbs, string theName, bool protection)
{
    Cat::Animal(limbs, theName, protection);
}

Cat::~Cat()
{
    //dtor
}

void Cat::initMice(int mysze[5])
{
    for(int i=0; i<5; i++)
        (mysze[i]<0) ? mice[i] = 0 : mice[i] = mysze[i];
}

void Cat::initCat(int limbs, string theName, bool protection, int hunter, int mysze[5])
{
    Cat::Animal(limbs, theName, protection);
    setLevelOfMouseHunting(hunter);
    initMice(mysze);
}

void Cat::setLevelOfMouseHunting(int value)
{
    if(value<1)
        value=1;
    else if(value>10)
        value=10;
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting()
{
    if(levelOfMouseHunting<1 || levelOfMouseHunting>10)
        return 0;
    else
        return levelOfMouseHunting;
}

int Cat::getMice(int index)
{
    if(index<1 || index>5 || mice[index-1] < 0)
        return 0;
    else
        return mice[index-1];
}

void Cat::giveVoice()
{
    cout<<"Miau miau"<<endl;
}

void Cat::info()
{
    Animal::info();
    cout<<"> Poziom umiejêtnoœci polowania: "<<getLevelOfMouseHunting()<<endl;
    cout<<"> Zlapane myszy w ostatnich 5 latch: ";
    for(int i=1; i<=5; i++)
        cout<<"rok "<<i<<"->"<<getMice(i)<<" ";
    cout<<endl;
}
