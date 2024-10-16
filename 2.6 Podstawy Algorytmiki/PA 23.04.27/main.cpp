#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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

void wydruk(student *T, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<setw(20)<<T[i].nazwisko<<setw(20)<<T[i].imie<<setw(5)<<T[i].punkty<<endl;
    }
}

void wyszukiwanieLiniowe(student *tab, int n, int pkt)
{
    int i=0, licznik=0;

    cout<<"> Studenci majacy "<<pkt<<" punktow:"<<endl;

    while(i < n)
    {
        if(tab[i].punkty == pkt)
        {
            cout<<setw(20)<<tab[i].nazwisko<<setw(20)<<tab[i].imie<<setw(5)<<tab[i].punkty<<endl;
            licznik++;
        }
        i++;
    }

    if(licznik==0)
        cout<<"Brak"<<endl;

    cout<<endl;
}

void sortowaniePrzezWstawianie(student* tab, int n)
{
    int i = n-2, j;

    student temp;

    while(i>=0)
    {
        j = i;
        temp = tab[j];
        while (temp.punkty > tab[j+1].punkty && j < n-1)
        {
            tab[j] = tab[j+1];
            j++;
        }
        tab[j]=temp;
        i--;
    }
}


void wyszukiwanieBisekcyjne(student *tab, int n, int pkt)
{
    int lewy=0, prawy=n-1, srodek, licznik=0;

    sortowaniePrzezWstawianie(tab, n);

    cout<<"> Studenci majacy "<<pkt<<" punktow:"<<endl;

    while(lewy <= prawy)
    {
        srodek = (int)((lewy+prawy)/2);

        if(tab[srodek].punkty==pkt)
        {
            cout<<setw(20)<<tab[srodek].nazwisko<<setw(20)<<tab[srodek].imie<<setw(5)<<tab[srodek].punkty<<endl;
            licznik++;
            lewy=srodek+1;
        }
        else if(pkt<tab[srodek].punkty)
            prawy=srodek-1;
        else
            lewy=srodek+1;
    }

    if(licznik==0)
        cout<<"Brak"<<endl;

    cout<<endl;
}

int main()
{
    int n, wybor, punkty;
    ifstream plik;
    string sciezka = "studenci.csv";
    student *tablicaStudentow = wczytajDane();

    plik.open(sciezka);
    plik >> n;
    plik.close();

    cout<<"> Tablica wejsciowa studentow:"<<endl<<endl;
    wydruk(tablicaStudentow, n);
    cout<<endl<<endl;

    while(wybor)
    {
        cout<<"> Wybierz opcje wyszukiwania ilosci punktow"<<endl;
        cout<<" 1. Wyszukiwanie liniowe"<<endl<<" 2. Wyszukiwanie bisekcyjne"<<endl;
        do {
            cout<<"Wybor:  ";
            cin>>wybor;
            cout<<endl;
        } while(wybor < 0 && wybor > 2);

        switch(wybor)
        {
        case 1:
            cout<<"Podaj szukana ilosc punktow:  ";
            cin>>punkty;
            cout<<endl;
            wyszukiwanieLiniowe(tablicaStudentow, n, punkty);
            break;
        case 2:
            cout<<"Podaj szukana ilosc punktow:  ";
            cin>>punkty;
            cout<<endl;
            wyszukiwanieBisekcyjne(tablicaStudentow, n, punkty);
            break;
        case 0:
            cout<<endl<<"Koniec programu"<<endl<<endl;
            break;
        default:
            cout<<"Blad programu"<<endl;
        }
        cout<<endl;
    }

    delete [] tablicaStudentow;

    return 0;
}
