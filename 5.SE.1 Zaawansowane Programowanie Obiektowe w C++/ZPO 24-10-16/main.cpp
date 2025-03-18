#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years(Employee** tab, int n);
int howManyEarnLessThanMeanBonus(Employee** tab, int n);

int main()
{
    int n=6;

    Employee** tab = new Employee*[6]; //Tablica siê nie inicjalizuje
    tab[0] = new Developer("maxiKaz", 27, 8, 8540.49);
    tab[1] = new Developer("Jomatech", 30, 6, 21000.00);
    tab[2] = new Developer("Kamilek", 35, 3, 7400.01);
    tab[3] = new Developer("Brajanowski", 21, 1, 4301.26);
    tab[4] = new TeamLeader("Cwaniakowski", 26, 0, 28000.09);
    tab[5] = new Developer("Janowski", 42, 18, 35056.17);

    cout<<"Funkcja 1:"<<endl;
    whoWorkMoreThan5Years(tab, n);

    cout<<endl<<"Funkcja 2:"<<endl;
    cout<<endl<<"Ilosc pracownikow otrzymujacych premie ponizej sredniej: "<<howManyEarnLessThanMeanBonus(tab, n)<<endl;

    for(int i=0; i<n; i++)
        delete tab[i];
    delete [] tab;

    return 0;
}

void whoWorkMoreThan5Years(Employee** tab, int n)
{
    for(int i=0; i<n; i++)
        if( tab[i]->getExperience() > 5 )
            tab[i]->show();
}

int howManyEarnLessThanMeanBonus(Employee** tab, int n)
{
    float meanBonus = 0;
    int howMany = 0;

    for(int i=0; i<n; i++)
        meanBonus += tab[i]->calculateBonus( tab[i]->getExperience() );

    meanBonus /= n;

    for(int i=0; i<n; i++)
        if( tab[i]->calculateBonus(tab[i]->getExperience()) < meanBonus )
            howMany++;

    return howMany;
}
