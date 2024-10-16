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

void sortowanieQuickSort(student* tab, int lewy, int prawy)
{
    int srodek = (lewy + prawy)/2;
    student StudentSrodkowy = tab[srodek];
    int piwot = StudentSrodkowy.punkty;
    tab[srodek] = tab[prawy-1];
    int granica = lewy;
    int i = lewy;

    while (i < prawy)
    {
        if (tab[i].punkty < piwot)
        {
            swap(tab[granica], tab[i]);
            granica++;
        }
        i++;
    }

    tab[prawy] = tab[granica];
    tab[granica] = StudentSrodkowy;

    if (lewy < granica-1)
        sortowanieQuickSort(tab, lewy, granica-1);
    if (granica+1 < prawy)
        sortowanieQuickSort(tab, granica+1, prawy);

    /*switch(tryb)
    {
    case 0:

        break;
    case 1:

        break;
    }*/
}

void usunTabliceStudentow(student *&tab)
{
    delete []tab;
}

void wyswietlStudentow(student* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<setw(20)<<tab[i].imie<<setw(30)<<tab[i].nazwisko<<setw(10)<<tab[i].punkty<<endl;
    }
}

int main()
{
    student * tab;
    int liczbaStudentow;
    string sciezka;
    string linia, pomoc;
    ifstream plik;
    char sredniki;

    sciezka="studenci.csv";
    plik.open("studenci.csv");
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    //alokowanie pamiêci w tab o dlugosci liczbaStudentow
    //elementem tablicy jest struktura
    //student(imie, nazwisko, punkty)
    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();

    cout<<"Studenci przed posortowaniem:"<<endl;
    wyswietlStudentow(tab, liczbaStudentow);
    sortowanieQuickSort(tab, 0, liczbaStudentow-1);
    cout<<"Studenci po posortowaniu:"<<endl;
    wyswietlStudentow(tab, liczbaStudentow);



    return 0;
}
