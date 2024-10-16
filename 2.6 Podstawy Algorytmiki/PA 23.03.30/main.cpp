#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

student* wczytajDane()
{
    string sciezka, linia, pomoc;
    int n;
    ifstream plik;
    char sredniki;

    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> n;
    for(int i = 0; i < 2; i++)
    plik >> sredniki;

    student *tab = new student[n];

    for(int i=0; i<n; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty = atoi(pomoc.c_str());
    }
    plik.close();

    return tab;
}

void wydruk(student *T, int p, int k)
{
    for(int i=p; i<k; i++)
    {
        cout<<setw(20)<<T[i].nazwisko<<setw(20)<<T[i].imie<<setw(5)<<T[i].punkty<<endl;
    }
}

int podzial2czesci(student *T, int n, int granica)
{
    int i=0, j=n-1;

    while(i < j)
    {
        while(T[i].punkty <= granica && i < j)
            i++;
        while(T[j].punkty > granica && i < j)
            j--;

        if(i < j)
        {
            swap(T[i], T[j]);
            i++;
            j--;
        }
    }

    if(T[i].punkty <= granica)
        return i+1;
    else
        return i;
}

int podzial3czesci(student *T, int n, int liczba1, int *indeks)
{
    int i=-1, j=0, k=n;

    while(j<k)
    {
        if(T[j].punkty%liczba1==0)
        {
            i++;
            swap(T[i], T[j]);
            j++;
        }
        else if(T[j].punkty%liczba1==2)
        {
            k--;
            swap(T[k], T[j]);
        }
        else
            j++;
    }

    *indeks = i+1;

    return k;
}

int main()
{
    int n, wybor;
    int i2, i3, j3;
    ifstream plik;
    string sciezka = "studenci.csv";
    student *tablicaStudentow = wczytajDane();

    plik.open(sciezka);
    plik >> n;
    plik.close();

    do {
        cout<<"> Menu programu:"<<endl<<"0. Wyjscie"<<endl<<"1. Wyswietlenie calej tablicy"<<endl;
        cout<<"2. Podzial na dwie czesci"<<endl<<"3. Podzial na trzy czesci"<<endl;
        cout<<"Podaj swoj wybor:";
        cin>>wybor;
        cout<<endl;

        switch(wybor)
        {
        case 0:
            cout<<"Koniec programu"<<endl;
            break;
        case 1:
            wydruk(tablicaStudentow, 0, n);
            break;

        case 2:
            i2 = podzial2czesci(tablicaStudentow, n, 10);

            cout<<"Lista z punktacja nizsza niz 10:"<<endl;
            wydruk(tablicaStudentow, 0, i2);

            cout<<endl<<"Lista z punktacja wieksza niz 10:"<<endl;
            wydruk(tablicaStudentow, i2, n);
            break;

        case 3:
            j3 = podzial3czesci(tablicaStudentow, n, 3, &i3);

            cout<<"Lista studentow z liczba pumktow mod 3 = 0:"<<endl;
            wydruk(tablicaStudentow, 0, i3);

            cout<<endl<<"Lista studentow z liczba pumktow mod 3 = 1:"<<endl;
            wydruk(tablicaStudentow, i3, j3);

            cout<<endl<<"Lista studentow z liczba pumktow mod 3 = 2:"<<endl;
            wydruk(tablicaStudentow, j3, n);
            break;

        default:
            cout<<"Zly numer!"<<endl;
        }
        cout<<endl;

    } while(wybor!=0);

    delete [] tablicaStudentow;

    return 0;
}
