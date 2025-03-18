#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

int howManyProtectedAnimals(int n, Animal tab[]);
void howManyTrackerDogs(int n, Dog tab[]);
void howManyCats(int n, Cat tab[]);

int main()
{


    return 0;
}

int howManyProtectedAnimals(int n, Animal tab[])
{
    int x=0;
    for(int i=0; i<n; i++)
        x += tab[i].getProtected()==true;
    return x;
}

void howManyTrackerDogs(int n, Dog tab[])
{
    cout<<"Lista psów tropicieli:"<<endl;
    for(int i=0; i<n; i++)
    {
        if(tab[i].getSkillLevel(3) < tab[i].getSkillLevel(4))
            tab[i].info();
        cout<<endl;
    }
}

void howManyCats(int n, Cat tab[])
{
    int x;

    cout<<"Suma upolowanych myszy"<<endl;
    for(int i=0; i<n; i++)
    {
        x=0;
        for(int j=1; j<=5; j++)
            x+=tab[i].getMice(j);
        cout<<"> Kot "<<i+1<<": "<<x<<endl;
    }

}
