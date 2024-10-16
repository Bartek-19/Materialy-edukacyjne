#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void przydzielPamiec1D(int *&tab, int n)
{
    tab = new int[n];
}
//-------------------------------------------------------
void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
        *(tab+i) = rand() % (b-a+1) + a;
}
//------------------------------------------------------
void usunTablice1D(int *&tab)
{
    delete []tab;
}
//------------------------------------------------------
void wyswietl1D(int* tab, int n)
{
    int i;
    cout<<"[";
    for (i=0; i<n-1; i++)
        cout<<tab[i]<<", ";
    cout<<tab[i]<<"]"<<endl;
}
//
//
//
void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    int i = n-1, j;

    cout<<endl<<">Sortowanie Bombelkowe"<<endl<<endl;
    cout<<"Tablica przed posortowaniem:"<<endl;
    wyswietl1D(tab, n);

    switch(tryb)
    {
    case 1:
        while (i>0)
        {
            j = 0;
            while (j<i)
            {
                if(tab[j] > tab[j+1])
                    swap(tab[j], tab[j+1]);
                j++;
            }
            i--;
        }
        break;
    case 0:
        while (i>0)
        {
            j = 0;
            while (j<i)
            {
                if(tab[j] < tab[j+1])
                    swap(tab[j], tab[j+1]);
                j++;
            }
            i--;
        }
        break;
    }

    cout<<endl<<"Tablica po posortowaniu:"<<endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}
//----------------------------------------------------
void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{
    int i = n-2, j, temp;
    cout<<endl<<">Sortowanie przez wsytawianie"<<endl<<endl;
    cout<<"Tablica przed posortowaniem:"<<endl;
    wyswietl1D(tab, n);

    switch(tryb)
    {
    case 1:
        while(i>=0)
        {
            j = i;
            temp = tab[j];
            while (temp > tab[j+1] && j < n-1)
            {
                tab[j] = tab[j+1];
                j++;
            }
            tab[j]=temp;
            i--;
        }
        break;
    case 0:
        while(i>=0)
        {
            j = i;
            temp = tab[j];
            while (temp < tab[j+1] && j < n-1)
            {
                tab[j] = tab[j+1];
                j++;
            }
            tab[j]=temp;
            i--;
        }
        break;
    }

    cout<<endl<<"Tablica po posortowaniu:"<<endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}
//----------------------------------------------------
void sortowaniePrzezWybor(int* tab, int n, int tryb)
{
    int i = n-1, ind, j;
    cout<<endl<<">Sortowanie przez wybieranie"<<endl<<endl;
    cout<<"Tablica przed posortowaniem:"<<endl;
    wyswietl1D(tab, n);

    switch(tryb)
    {
    case 1:
        while (i>0)
        {
            ind = 0;
            j = 1;
            while (j<=i)
            {
                if (tab[j] > tab[ind])
                    ind = j;
                j++;
            }
            swap(tab[i], tab[ind]);
            i--;
        }
        break;
    case 0:
        while (i>0)
        {
            ind = 0;
            j = 1;
            while (j<=i)
            {
                if (tab[j] < tab[ind])
                    ind = j;
                j++;
            }
            swap(tab[i], tab[ind]);
            i--;
        }
        break;
    }

    cout<<endl<<"Tablica po posortowaniu:"<<endl;
    wyswietl1D(tab, n);
    usunTablice1D(tab);
}
//
//
//
int main()
{
    int wybor, n, tryb, a, b;
    int* tablica;

    do {
        cout<<"1. Zadanie 2.2 - BubbleSort"<<endl;
        cout<<"2. Zadanie 2.3 - InsertionSort"<<endl;
        cout<<"3. Zadanie 2.4 - SelectionSort"<<endl;
        cout<<"5. Wyjscie z programu"<<endl;
        cout<<"Wybierz numer:  ";
        cin>>wybor;
        cout<<endl;

        if (wybor==1 || wybor==2 || wybor==3)
        {
            do {
                cout<<"Podaj ilosc elementow w tablicy:  ";
                cin>>n;
            } while(n<=0);

            do {
                cout<<"Wybierz tryb sortowania\n 1.rosnaco\n 0.malejaco\n";
                cin>>tryb;
            } while(tryb!=0 && tryb!=1);

            do {
                cout<<"Podaj dolny zakres wartosci:  ";
                cin>>a;
                cout<<"Podaj gorny zakres wartosci:  ";
                cin>>b;
            } while(a>=b);

            przydzielPamiec1D(tablica, n);
            wypelnijTablice1D(tablica, n, a, b);
        }
        cout<<endl;

        switch(wybor)
        {
        case 5:
            cout<<"Koniec programu."<<endl;
            break;
        case 1:
            sortowanieBabelkowe(tablica, n, tryb);
            break;
        case 2:
            sortowaniePrzezWstawianie(tablica, n, tryb);
            break;
        case 3:
            sortowaniePrzezWybor(tablica, n, tryb);
            break;
        default:
            cout<<"Zly wybor"<<endl;
        }
        cout<<endl;
    } while(wybor!=5);

    return 0;
}
