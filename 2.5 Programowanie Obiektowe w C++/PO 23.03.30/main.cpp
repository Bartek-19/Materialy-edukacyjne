#include "Tosoba.h"
#include "Tstudent.h"
#include "Tpracownik.h"
#include "TpracownikFizyczny.h"
#include "TpracownikUmyslowy.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<endl<<"--- ZADANIE 5.1 ---"<<endl<<endl;

    cout<<"> Tworzenie '*Osoba':"<<endl;
    Tosoba * osoba = new Tosoba;
    osoba->wyswietl();
    cout<<"> Zmiana zawartosci obiektu osoba:"<<endl;
    osoba->wczytaj();
    cout<<"Obiekt po zmianach:"<<endl;
    osoba->wyswietl();
    delete osoba;
    cout<<endl<<endl;

    cout<<"> Tworzenie 'Student1':"<<endl;
    Tstudent student1;
    cout<<"> Tworzenie 'Student2':"<<endl;
    Tstudent student2("Jan", "Kowalski", "UMCS", 3);
    cout<<endl<<"> Student1"<<endl;
    student1.wyswietl();
    cout<<endl<<"> Student2"<<endl;
    student2.wyswietl();
    cout<<endl<<"> Zmiana zamartosci obiektu Student1"<<endl;
    student1.wczytaj();
    cout<<endl<<"> Obiekty po zmianach"<<endl;
    cout<<"> Student1"<<endl;
    student1.wyswietl();
    cout<<"> Student2"<<endl;
    student2.wyswietl();

    //Tworzenie tablicy obiektow przeciazonych Tstudent:
    //Tstudent grupa[3] = { Tstudent(...), Tstudent(...), ... };

    cout<<endl<<endl;

    cout<<"> Tworzenie 'Pracownik1':"<<endl;
    Tpracownik pracownik1;
    cout<<"> Tworzenie '*Pracownik2':"<<endl;
    Tpracownik *pracownik2 = new Tpracownik("John", "Chena", "Warner Bros. Studio", 3000000.00, 15);
    cout<<endl<<"> Pracownik 1:"<<endl;
    pracownik1.wyswietl();
    cout<<endl<<"> Pracownik 2:"<<endl;
    pracownik2->wyswietl();
    cout<<endl<<"Zmiana zawartosci obiektu Pracownik2:"<<endl;
    pracownik2->wczytaj();
    cout<<endl<<"> Obiekty po zmianach"<<endl;
    cout<<"> Pracownik1"<<endl;
    pracownik1.wyswietl();
    cout<<"> Pracownik2"<<endl;
    pracownik2->wyswietl();
    delete pracownik2;

    cout<<endl<<endl;

    cout<<"> Tworzenie 'PracownikFizyczny1':"<<endl;
    TpracownikFizyczny pracFiz1("Jas", "Fasola", "Microsoft", 5051.49, 13, "Komik/Animator", "Kom1.1");
    cout<<"> Tworzenie '*PracownikFizyczny2':"<<endl;
    TpracownikFizyczny *pracFiz2 = new TpracownikFizyczny;
    cout<<endl<<"> PracownikFizyczny1:"<<endl;
    pracFiz1.wyswietl();
    cout<<endl<<"> PracownikFizyczny2:"<<endl;
    pracFiz2->wyswietl();
    cout<<endl<<"> Zmiana zawartosci obiektu PracownikFizyczny2:"<<endl;
    pracFiz2->wczytaj();
    cout<<endl<<"> Obiekty po zamianie:"<<endl;
    cout<<endl<<"> PracownikFizyczny1:"<<endl;
    pracFiz1.wyswietl();
    cout<<endl<<"> PracownikFizyczny2:"<<endl;
    pracFiz2->wyswietl();
    delete pracFiz2;

    cout<<endl<<endl;

    cout<<"> Tworzenie 'PracownikUmyslowy':"<<endl;
    TpracownikUmyslowy pracUmyslowy("Eric", "Wang", "Blindr", 15000, 3, "ML engenieer", "Data Management");
    cout<<endl<<"> PracownikUmyslowy:"<<endl;
    pracUmyslowy.wyswietl();
    cout<<endl<<"> Zmiana zawartosci obiektu PracownikUmyslowy:"<<endl;
    pracUmyslowy.wczytaj();
    cout<<endl<<"> Obiekt po zamianie:"<<endl;
    pracUmyslowy.wyswietl();

    cout<<endl<<endl;

    return 0;
}
