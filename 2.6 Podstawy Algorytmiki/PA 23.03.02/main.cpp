#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

void przydzielPamiec1D(int *&tab, int n)
{
    tab = new int[n];
}
//----------
void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
        *(tab+i) = rand() % (b-a+1) + a;
}
//----------
void usunTablice1D(int *&tab)
{
    delete []tab;
}
//----------
void wyswietl1D(int* tab, int n)
{
    for (int i=0; i<n; i++)
        cout<<"element "<<i<<":  "<<tab[i]<<endl;
}
//----------
void zadanie11_testowe()
{
    int* tablica;
    int n;
    cout<<"zadanie 1.1 - Tablice dynamiczne"<<endl;
    cout<<"Podaj ilosc elementow tablicy:  ";
    cin>>n;

    przydzielPamiec1D(tablica, n);
    wypelnijTablice1D(tablica, n, 1, 20);
    wyswietl1D(tablica, n);
    usunTablice1D(tablica);
}

void Zadanie1_2()
{
    int* tablica;
    int ilosc, a, b;
    int minimum, n;
    bool jest = true;

    cout<<endl<<"Zadanie 1.2"<<endl;

    do {
        cout<<"Podaj ilosc elementow:  ";
        cin>>ilosc;
        if (ilosc <= 0)
            cout<<"Podano za mala liczbe."<<endl;
    } while (ilosc <= 0);

    do {
        cout<<"Podaj wartosc minimalna przedzialu wartosci:  ";
        cin>>a;
        cout<<"Podaj wartosc maksymalna przedzialu wartosci:  ";
        cin>>b;
    } while(a>b || a<=0);

    przydzielPamiec1D(tablica, ilosc);
    wypelnijTablice1D(tablica, ilosc, a, b);
    wyswietl1D(tablica, ilosc);

    minimum = *tablica;
    for (int i=0; i<ilosc; i++)
    {
        if (tablica[i]<minimum)
            minimum = tablica[i];
    }

    for (n=floor(minimum/2); n>1; n--)
    {
        if (minimum%n==0)
        {
            jest = false;
            break;
        }
    }

    cout<<"Najmniejszy element tablicy: "<<minimum<<endl;
    if (jest)
        cout<<"Ten element jest liczba pierwsza."<<endl;
    else
        cout<<"Ten element nie jest liczba pierwsza."<<endl;
}

void Zadanie1_3()
{
    int* tablica;
    int ilosc, szukana, licz=0;

    cout<<endl<<"Zadanie 1.3";

    do {
        cout<<endl<<"Podaj ilosc elementow w tablicy:  ";
        cin>>ilosc;
    } while (ilosc<=0);

    przydzielPamiec1D(tablica, ilosc);
    wypelnijTablice1D(tablica, ilosc, 0, 9);
    wyswietl1D(tablica, ilosc);

    do {
        cout<<endl<<"Podaj szuakna liczbe z zakresu <0,9>:  ";
        cin>>szukana;
    } while(szukana < 0 || szukana > 9);

    for (int i=0; i<ilosc; i++)
        licz += tablica[i]==szukana;

    if (!licz)
        cout<<"Podana liczba nie wystepuje w tablicy"<<endl;
    else
        cout<<"Podana liczba wystepuje "<<licz<<" razy."<<endl;
}

void Zadanie1_4()
{
    int ilosc, suma=0, minimum, maksimum, MAX;
    int* tablica;

    cout<<endl<<"Zadanie 1.4"<<endl;

    do {
        cout<<endl<<"Podaj ilosc elementow w tablicy:  ";
        cin>>ilosc;
    } while (ilosc <= 0);

    do {
        cout<<"Podaj dolny zakres zbioru wartosci:  ";
        cin>>minimum;
        cout<<"Podaj gorny zakres zbioru wartosci:  ";
        cin>>maksimum;
    } while (minimum > maksimum);

    przydzielPamiec1D(tablica,ilosc);
    wypelnijTablice1D(tablica, ilosc, minimum, maksimum);
    wyswietl1D(tablica, ilosc);

    MAX = *tablica;
    for (int i=0; i<ilosc; i++)
        if (tablica[i] > MAX)
            MAX = tablica[i];

    cout<<endl<<"Najwieksza liczba w tablicy:  "<<MAX<<endl;

    MAX = abs(MAX);

    while (MAX > 0)
    {
        suma += MAX%10;
        MAX = MAX/10;
    }

    cout<<"Suma cyfr tej liczby wynosi:  "<<suma<<endl;
}

int main(int argc, const char * argv[]) {

    int wybor;

    do {
        cout<<endl<<"1. Zadanie 1.2"<< endl;
        cout<<"2. Zadanie 1.3"<< endl;
        cout<<"3. Zadanie 1.4"<< endl;
        cout<<"0. Wyjscie z programu"<< endl;
        cout<<"Wybierz numer z menu: ";
        cin>>wybor;

        switch (wybor)
        {
        case 0:
            cout<<endl<<"Koniec programu."<<endl;
            break;
        case 1:
            Zadanie1_2();
            break;
        case 2:
            Zadanie1_3();
            break;
        case 3:
            Zadanie1_4();
            break;
        default:
            cout<<endl<<"Zly wybor, wybierz jeszcze raz."<<endl;
        }
    } while(wybor);

    return 0;
}
