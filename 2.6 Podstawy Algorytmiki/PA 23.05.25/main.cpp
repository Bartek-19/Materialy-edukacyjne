#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

struct element{
    int number;
    element* next;
};

struct single_list{
    element* head;
    element* tail;
    int counter=0;
};

void add_tail(single_list &L, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;

    if(L.tail!=nullptr)
        L.tail->next = el;
    else
        L.head = el;

    L.tail = L.tail->next;
    L.counter++;
}

void add_head(single_list &L, int value)
{
    element* el = new element;
    el->number = value;
    el->next = L.head;
    L.head = el;

    if(L.tail==nullptr)
        L.tail = el;

    L.counter++;
}

void add_position(single_list &L, int value, int position)
{
    element* el = new element;
    el->number = value;

    element* temp = L.head;

    int i=1;

    while(i<position-1)
    {
        temp = temp->next;
        i++;
    }

    el->next = temp->next;
    temp->next = el;

    L.counter++;
}

void delete_tail(single_list &L)
{
    if(L.counter == 1)
    {
        L.tail = nullptr;
        L.head = nullptr;
    }
    else
    {
        element* bef_temp = L.head;
        int i=1;

        while(i<L.counter-1)
        {
            bef_temp = bef_temp->next;
            i++;
        }

        L.tail = bef_temp;
        L.tail->next = nullptr;
    }

    L.counter--;
}

void delete_head(single_list &L)
{
    element* temp = L.head;
    L.head = L.head->next;

    if(L.counter == 1)
        L.tail = nullptr;

    L.counter--;

    delete temp;
}

void delete_position(single_list &L, int position)
{
    element* prev = L.head;
    int i=1;

    while(i<position-1)
    {
        prev = prev->next;
        i++;
    }
    element* temp = prev->next;
    prev->next = temp->next;

    L.counter--;

    delete temp;
}

void show(single_list L)
{
    int i=1;
    element* temp = L.head;

    while(i<=L.counter)
    {
        cout<<i<<"> "<<temp->number<<endl;
        temp = temp->next;
        i++;
    }
}

float srednia(single_list L)
{
    int i=1;
    float S=0;
    element* temp = L.head;

    while(i <= L.counter)
    {
        S+=temp->number;
        i++;
        temp = temp->next;
    }

    S/=L.counter*1.0;

    return S;
}

int main()
{
    single_list* Lista = new single_list;
    int wybor, pozycja, wartosc, i, iMaks;
    float S;
    element *ElMaksymalny=nullptr, *temp=nullptr;
    Lista->head = nullptr;
    Lista->tail = nullptr;

    do{
        cout<<"Menu programu:"<<endl;
        cout<<"0.  Wyjscie z programu"<<endl;
        cout<<"1.  Sprawdzenie, czy lista jest pusta"<<endl;
        cout<<"2.  Dodanie elementu na koniec listy"<<endl;
        cout<<"3.  Dodanie elementu na poczatek listy"<<endl;
        cout<<"4.  Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5.  Usuniecie elementu z konca listy"<<endl;
        cout<<"6.  Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7.  Usuniecie elementu znajdujacego sie na okreslonej pozycji"<<endl;
        cout<<"8.  Pobranie pierwszego elementu z listy"<<endl;
        cout<<"9.  Pobranie ostatniego elementu z listy"<<endl;
        cout<<"10. Srednia arytmetyczna elementow listy"<<endl;
        cout<<"11. Znalezienie elementu maksymalnego z listy"<<endl;
        cout<<"12. Wyswietlenie calej listy"<<endl;
        cout<<"13. Usuniecie calej listy"<<endl;
        cout<<"> TWOJ WYBOR:  ";
        cin>>wybor;
        cout<<endl;

        srand(time(NULL));
        wartosc = rand()%50 + 1;

        if(Lista->counter == 0)
        {
            switch(wybor)
            {
            case 0:
                cout<<"Koniec programu"<<endl;
                break;
            case 1:
                cout<<"Lista jest pusta"<<endl;
                break;
            case 2:
            case 3:
                add_head(*Lista, wartosc);
                break;
            case 4:
                cout<<"Brak mozliwosci wyboru pozycji - dodawanie na poczatek listy"<<endl;
                add_head(*Lista, wartosc);
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                cout<<"Nie mozna wykonac operacji - lista jest pusta"<<endl;
                break;
            default:
                cout<<"Podano zly numer"<<endl;
            }
        }
        else
        {
            switch(wybor)
            {
            case 0:
                cout<<"Koniec programu"<<endl;
                break;
            case 1:
                cout<<"Lista nie jest pusta"<<endl;
                break;
            case 2:
                add_tail(*Lista, wartosc);
                break;
            case 3:
                add_head(*Lista, wartosc);
                break;
            case 4:
                if(Lista->counter == 1)
                    cout<<"Nie mozna wykonac operacji - za malo elementow"<<endl;
                else
                {
                    do{
                        cout<<"Podaj na jaka pozycje chcesz dodac element:  ";
                        cin>>pozycja;
                        if(pozycja<=0 || pozycja>Lista->counter)
                            cout<<"Podano pozycje spoza mozliwego zakresu"<<endl;
                    }while(pozycja<=0 || pozycja > Lista->counter);
                    add_position(*Lista, wartosc, pozycja);
                }
                break;
            case 5:
                delete_tail(*Lista);
                break;
            case 6:
                delete_head(*Lista);
                break;
            case 7:
                do{
                    cout<<"Podaj z jakiej pozycje chcesz usunac element:  ";
                    cin>>pozycja;
                    if(pozycja<=0 || pozycja>Lista->counter)
                        cout<<"Podano pozycje spoza mozliwego zakresu"<<endl;
                } while(pozycja<=0 || pozycja>Lista->counter);
                delete_position(*Lista, pozycja);
                break;
            case 8:
                cout<<"Pierwszy element> "<<Lista->head->number<<endl;
                break;
            case 9:
                cout<<"ostatni element> "<<Lista->tail->number<<endl;
                break;
            case 10:
                S=srednia(*Lista);
                cout<<"Srednia elementow = "<<S<<endl;
                break;
            case 11:
                i=1;
                iMaks=1;
                ElMaksymalny = Lista->head;
                temp = Lista->head;
                while(i <= Lista->counter)
                {
                    if(temp->number > ElMaksymalny->number)
                    {
                        ElMaksymalny = temp;
                        iMaks = i;
                    }
                    temp = temp->next;
                    i++;
                }
                cout<<"Najwiekszy element to "<<ElMaksymalny->number<<" stojacy na pozycji "<<iMaks<<endl;
                delete ElMaksymalny;
                delete temp;
                break;
            case 12:
                show(*Lista);
                break;
            case 13:
                while(Lista->counter > 0)
                    delete_tail(*Lista);
                cout<<"Usunieto"<<endl;
                break;
            default:
                cout<<"Podano zly numer"<<endl;
            }
        }

        cout<<endl<<"--------------------------------------------------------------------"<<endl<<endl;

    }while(wybor!=0);

    delete Lista;

    return 0;
}
