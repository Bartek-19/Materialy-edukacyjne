#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef tuple<string, string, int> Samochod;

int main()
{
    vector <Samochod> Pojazdy;
    Pojazdy.push_back(make_tuple("Mazda", "benzyna", 2018));
    Pojazdy.push_back(make_tuple("Peugeot", "diesel", 2019));
    Pojazdy.push_back(make_tuple("Skoda", "benzyna", 2009));
    Pojazdy.push_back(make_tuple("Toyota", "benzyna", 2025));
    Pojazdy.push_back(make_tuple("Audi", "diesel", 2020));
    Pojazdy.push_back(make_tuple("Hunday", "diesel", 2015));

    vector <Samochod> Benzyniaki;

    for_each(Pojazdy.begin(), Pojazdy.end(),
             [&Benzyniaki](Samochod s){ if(get<1>(s)=="benzyna") Benzyniaki.push_back(s); }
            );

    sort(Benzyniaki.begin(), Benzyniaki.end(),
         [](Samochod s1, Samochod s2)->bool{ return get<2>(s1) > get<2>(s2); }
        );

    for_each(Benzyniaki.begin(), Benzyniaki.end(),
             [](Samochod s){ cout<<get<0>(s)<<", "<<get<1>(s)<<", rok produkcji: "<<get<2>(s)<<endl; }
            );

    return 0;
}
