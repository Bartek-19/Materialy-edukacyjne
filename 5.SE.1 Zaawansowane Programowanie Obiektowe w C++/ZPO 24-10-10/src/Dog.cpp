#include "Dog.h"

using namespace std;

Dog::Dog()
{
    //ctor
}

Dog::Dog(int limbs, string theName, bool protection)
{
    Dog::Animal(limbs, theName, protection);
}

Dog::Dog(int limbs, string theName, bool protection, string breedName, int guider, int tracker)
{
    Dog::Animal(limbs, theName, protection);
    setBreed(breedName);
    setSkillLevel(1, guider);
    setSkillLevel(2, tracker);
}

Dog::~Dog()
{
    //dtor
}

string Dog::getBreed()
{
    return breed;
}

int Dog::getSkillLevel(int type)
{
    int x;
    (type%2) ? x=levelOfGuideSkills : x=levelOfTrackerSkills;
    if(x<1 || x>10)
        return 0;
    else
        return x;
}

void Dog::setBreed(string breedName)
{
    breed = breedName;
}

void Dog::setSkillLevel(int type, int value)
{
    if(value<1)
        value=1;
    else if(value>10)
        value=10;
    type%2 ? levelOfGuideSkills=value : levelOfTrackerSkills=value;
}

void Dog::giveVoice()
{
    cout<<"Hau, hau"<<endl;
}

void Dog::info()
{
    Animal::info();
    cout<<"> Rasa: "<<getBreed()<<endl;
    cout<<"> Poziom umiejêtnoœci przewodnika (1-10): "<<getSkillLevel(1)<<endl;
    cout<<"> Poziom umiejêtnoœci tropiciela (1-10): "<<getSkillLevel(0)<<endl;
}
