#include <iostream>
#include "Ttime.h"

using namespace std;

Ttime operator*(Ttime T, int N);

bool operator==(Ttime T1, Ttime T2);

ostream & operator<<(ostream & O, Ttime &Czas);

int main()
{
    Ttime lot1(6, 15), lot2(1, 45), oczekiwanie(0, 55);
    Ttime czasCalkowity(0, 0), czasWydluzony(0, 0), lot3(2, 25);

    cout<<"Czas lotu Chicago-Paryz    "<<lot1<<endl;
    cout<<"Czas oczekiwania w Paryzu  "<<oczekiwanie<<endl;
    cout<<"Czas lotu Paryz-Warszawa   "<<lot2<<endl;

    czasCalkowity=lot1+lot2;
    czasCalkowity=oczekiwanie+czasCalkowity;

    cout<<"Calkowity czas podrozy     "<<czasCalkowity<<endl<<endl<<endl;

    czasWydluzony = lot1 * 4;
    lot3 = lot3 * 2;

    cout<<"Lot Paryz-Warszawa po wydluzeniu czasu ";
    if(czasWydluzony==lot3)
        cout<<"jest ";
    else
        cout<<"nie jest ";
    cout<<"rowny czasem wzgledem lotu Warszawa-Londyn"<<endl<<endl;

    return 0;
}

Ttime operator*(Ttime T, int N)
{
    int G, M;

    G = T.getHours() * N;
    M = T.getMinutes() * N;

    G += M/60;
    M = M%60;

    Ttime wynik(G, M);

    return wynik;
}

bool operator==(Ttime T1, Ttime T2)
{
    if(T1.getHours()==T2.getHours() && T1.getMinutes()==T2.getMinutes())
        return true;
    else
        return false;
}

ostream & operator<<(ostream & O, Ttime &Czas)
{
    O<<Czas.getHours()<<" h. "<<Czas.getMinutes()<<" min."<<endl;

    return O;
}
