#include <iostream>
#include <ctime>
#include <cstdlib>

//wyslac na e.lukasik@pollub.pl - wszystkie rozwiazania do 14 - tytul "zajecia czwartek"

using namespace std;

struct elementLIFO{
    int dane;
    elementLIFO * nastepny;
};

bool czyPusty(elementLIFO *stos)
{
    bool pusty = false;

    if(stos==nullptr)
        pusty=true;

    return pusty;
}

void push(elementLIFO*&stos, int wartosc)
{
    elementLIFO *el = new elementLIFO;
    el->dane=wartosc;
    el->nastepny=stos;
    stos=el;
}

void pop(elementLIFO*&stos)
{
    elementLIFO *temp = stos;
    stos = stos->nastepny;
    delete temp;
    cout<<"Usunieto ostatni element stosu"<<endl;
}

int top(elementLIFO *stos)
{
    return stos->dane;
}

void zadanie9_1()
{
    elementLIFO *ws = nullptr;

    int wybor, liczba;

    cout<<endl<<"> Zadanie 9.1 <"<<endl<<endl;

    do{
        cout<<"Menu zadania:"<<endl;
        cout<<" 1. Sprawdzenie, czy stos jest pusty"<<endl;
        cout<<" 2. Dodanie elementu na stos"<<endl;
        cout<<" 3. Usuniecie elementu ze stosu"<<endl;
        cout<<" 4. Pobranie ostatniego elementu ze stosu"<<endl;
        cout<<" 5. Usuniecie wszystkich elementow ze stosu"<<endl;
        cout<<" 6. Wyjscie z programu"<<endl;
        cout<<"> ";
        cin>>wybor;
        cout<<endl;

        switch(wybor)
        {
        case 1:
            if(czyPusty(ws)==false)
                cout<<"Stos nie jest pusty"<<endl;
            else
                cout<<"Stos jest pusty"<<endl;
            break;
        case 2:
            srand(time(NULL));
            liczba = rand()%10 + 1;
            push(ws, liczba);
            break;
        case 3:
            if(czyPusty(ws)==true)
                cout<<"Stos jest pusty - nie mozna wykonac operacji"<<endl;
            else
                pop(ws);
            break;
        case 4:
            if(czyPusty(ws)==true)
                cout<<"Brak pierwszego elementu stosu"<<endl;
            else
                cout<<"Ostatni element stosu: "<<top(ws)<<endl;
            break;
        case 5:
            while(czyPusty(ws)==false)
                pop(ws);
            break;
        case 6:
            cout<<"    --- KONIEC PROGRAMU ---"<<endl;
            break;
        default:
            cout<<"Podano zly wybor!"<<endl;
        }
        cout<<endl;

    } while(wybor!=6);
}

int main()
{
    int wyborZadania;

    do{
        cout<<"Wybierz zadanie:"<<endl;
        cout<<" 0. Wyjscie z programu"<<endl;
        cout<<" 1. Zadanie 9.1"<<endl;
        cout<<" 2. Zadanie 9.2"<<endl;
        cout<<"Twoj wybor:  ";
        cin>>wyborZadania;

        switch(wyborZadania)
        {
        case 0:
            break;
        case 1:
            zadanie9_1();
            break;
        case 2:
            //zadanie9_2();
            break;
        default:
            cout<<"Wybierz jeszcze raz"<<endl;
        }
        cout<<endl;

    }while(wyborZadania!=0 && wyborZadania!=1 && wyborZadania!=2);

    return 0;
}
