#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct element{
    char character;
    element* next;
};

struct Queue{
    element* head;
    element* tail;
};

void push(Queue &q, char value)
{
    element *el = new element;
    el->character = value;
    el->next = nullptr;

    if(q.tail!=nullptr)
        q.tail->next = el;
    else
        q.head = el;
    q.tail = el;
}

void pop(Queue &q)
{
    element *temp = q.head;
    q.head = q.head->next;
    delete temp;

    if(q.head==nullptr)
        q.tail = nullptr;
}

char first(Queue q)
{
    return q.head->character;
}

bool isEmpty(Queue q)
{
    if(q.head==nullptr)
        return true;
    else
        return false;
}

void wczytywanie(Queue &Q)
{
    string linia;
    ifstream plik;
    int j;

    plik.open("znaki2.txt");

    for(int i=0; i<4; i++)
    {
        getline(plik, linia);
        j=0;
        while(j<linia.length())
        {
            if(isupper(linia[j]))
                push(Q, char(linia[j]));
            j++;
        }
    }
}

int main()
{
    Queue Q;
    char znak;
    int wybor;

    Q.head = nullptr;
    Q.tail = nullptr;

    do{
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"> Menu programu <"<<endl;
        cout<<"1. Sprawdzenie, czy kolejka jest pusta"<<endl;
        cout<<"2. Dodanie elementu do kolejki"<<endl;
        cout<<"3. Usuniecie elementu z kolejki"<<endl;
        cout<<"4. Pokaz pierwszy element kolejki"<<endl;
        cout<<"5. Usuwanie wszystkich elementow z kolejki"<<endl;
        cout<<"6. Wczytanie znakow z pliku do kolejki"<<endl;
        cout<<"7. Koniec programu"<<endl<<"Twoj wybor:  ";
        cin>>wybor;
        cout<<endl;

        switch(wybor)
        {
        case 1:
            if(isEmpty(Q)==true)
                cout<<"Kolejka jest pusta"<<endl;
            else
                cout<<"Kolejka NIE jest pusta"<<endl;
            break;
        case 2:
            srand(time(NULL));
            znak = rand()%26 + 65;
            push(Q, znak);
            break;
        case 3:
            pop(Q);
            break;
        case 4:
            if(isEmpty(Q)==true)
                cout<<"Brak elementow w kolejce"<<endl;
            else
                cout<<"Pierwszy element kolejki:  "<<first(Q)<<endl;
            break;
        case 5:
            cout<<"Usuwanie kolejki"<<endl;
            while(Q.tail!=nullptr)
            {
                cout<<first(Q)<<endl;
                pop(Q);
            }
            cout<<"Usunieto wszystkie elementy"<<endl;
            break;
        case 6:
            wczytywanie(Q);
            break;
        case 7:
            cout<<"Koniec programu"<<endl;
            break;
        default:
            cout<<"Podano zly numer!"<<endl;
        }
        cout<<endl;
    }while(wybor!=7);


    return 0;
}
