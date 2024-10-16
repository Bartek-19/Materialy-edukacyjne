#include <iostream>
#include <cstdlib>
#include "Tpracownik.h"
#include "Tdzialania.h"
#include "Tstudent.h"

using namespace std;

int main()
{
    Tpracownik pracownik1, pracownik2;

    Tdzialania dzial;

    Tstudent student1;

    cout<<"Zadanie 2.2"<<endl;
    dzial.podajDane();
    cout<<"Suma:  "<<dzial.suma()<<endl;
    cout<<"Roznica:  "<<dzial.roznica()<<endl;
    cout<<"Iloczyn:  "<<dzial.iloczyn()<<endl;
    dzial.iloraz();
    cout<<"Potega a^b:  "<<dzial.potega()<<endl<<endl;

    cout<<endl<<"Zadanie 2.3"<<endl;

    cout<<endl<<"Pracownik 1"<<endl;
    pracownik1.wczytaj();

    cout<<endl<<"Pracownik 2"<<endl;
    pracownik2.wczytaj();

    pracownik1.wyswietl();
    pracownik2.wyswietl();

    cout<<endl<<"Zadanie 2.4"<<endl;
    student1.wczytaj();
    student1.wyswietl();

    return 0;
}
