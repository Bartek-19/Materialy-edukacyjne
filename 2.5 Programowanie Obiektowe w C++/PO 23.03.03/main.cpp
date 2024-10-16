#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>

using namespace std; // deklaracja uzycia przestrzeni std - import przestrzeni
//using std::cout;
//using std::cin;
//using std::endl;

struct data{
    int dzien;
    int miesiac;
    int rok;
};

struct pracownik{
    string imie;
    string nazwisko;
    float stawka;
    int godziny;
    data zatrudnienie;
};

pracownik wczytaj();

float pensja(pracownik P);

void wyswietl(pracownik P);

int main()
{
    //cout << "Hello world!" << endl;
    //std::cout << "Hello world!" << std::endl;

    //Zadanie 1.2

    char znak;
    int calk;
    float rzecz;
    char tablica[20];

    pracownik baza[3];

    cout<<"    Zadanie 1.2"<<endl;

    printf("Podaj znak, liczbe calkowita, rzeczywista i napis:  ");
    cin>>znak>>calk>>rzecz>>tablica;
    //scanf("%c %d %f %s", &znak, &calk, &rzecz, tablica);

    cout<<"Wersja 'printf': "<<endl;
    printf("%c  \n%5d  \n%10.2f  \n%20s", znak, calk, rzecz, tablica);

    cout<<endl<<"Wersja 'cout': "<<endl;
    cout<<znak<<endl<<
    setw(5)<<calk<<endl<<
    setw(10)<<fixed<<setprecision(2)<<rzecz<<endl<<
    setw(20)<<tablica<<endl<<endl;

    //Zadanie 1.4

    cout<<"\n    Zadanie 1.4"<<endl;
    cout<<"Baza danych pracownikow"<<endl<<endl;

    for (int i=0; i<3; i++)
    {
        cout<<endl<<"Pracownik "<<i<<endl;
        baza[i] = wczytaj();
    }

    cout<<endl<<"Baza pracownikow:"<<endl;
    cout<<setw(30)<<left<<"Nazwisko:"<<setw(20)<<left<<"Imie:"<<setw(20)<<left<<"Data zatrudnienia:";
    cout<<setw(15)<<left<<"Stawka"<<setw(15)<<left<<"Ilosc godzin:"<<setw(15)<<left<<"Pensja:"<<endl;

    for (int i=0; i<3; i++)
    {
        wyswietl(baza[i]);
    }

    return 0;
}

pracownik wczytaj()
{
    pracownik P;

    cout<<"Podaj imie:  ";
    cin>>P.imie;
    cout<<"Podaj nazwisko:  ";
    cin>>P.nazwisko;
    cout<<"Podaj stawke pracownika:  ";
    cin>>P.stawka;
    cout<<"Podaj ilosc godzin przepracowanych przez pracownika:  ";
    cin>>P.godziny;
    cout<<"Podaj date zatrudnienia pracownika (DD MM RRRR):"<<endl;
    cin>>P.zatrudnienie.dzien>>P.zatrudnienie.miesiac>>P.zatrudnienie.rok;

    return P;
}

float pensja(pracownik P)
{
    return P.stawka * P.godziny;
}

void wyswietl(pracownik P)
{
    float wyplata = pensja(P);
    cout<<setw(30)<<left<<P.nazwisko<<setw(20)<<left<<P.imie;
    cout<<setw(2)<<P.zatrudnienie.dzien<<"."<<setw(2)<<P.zatrudnienie.miesiac<<"."<<setw(4)<<P.zatrudnienie.rok<<setw(10)<<left<<" r.";
    cout<<setw(15)<<left<<P.stawka<<setw(15)<<left<<P.godziny;
    cout<<setw(15)<<left<<wyplata<<endl;
}
