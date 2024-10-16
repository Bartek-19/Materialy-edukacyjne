#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct element{
    int number;
    element* next;
    element* prev;
};

void add_after(element& Biezacy, int Wartosc) {
    element* nowy = new element;
    nowy->number = Wartosc;

    nowy->next = Biezacy.next;
    nowy->prev = &Biezacy;

    Biezacy.next->prev = nowy;
    Biezacy.next = nowy;
}

void add_before(element& Biezacy, int Wartosc) {
    element* nowy = new element;
    nowy->number = Wartosc;

    nowy->next = &Biezacy;
    nowy->prev = Biezacy.prev;

    Biezacy.prev->next = nowy;
    Biezacy.prev = nowy;
}

int main()
{
    element* biezacy = nullptr;
    element* temp = new element;
    int wybor, i, wartosc;

    do{
        cout<<"Menu programu"<<endl;
        cout<<" 0. Wyjscie z programu"<<endl;
        cout<<" 1. Dodaj element po biezacym"<<endl;
        cout<<" 2. Dodaj element przed biezacy"<<endl;
        cout<<" 3. Usun element stojacy po biezacym"<<endl;
        cout<<" 4. Usun element stojacy przed biezacym"<<endl;
        cout<<" 5. Ile elementow ma lista"<<endl;
        cout<<" 6. Wydruk listy"<<endl;
        cout<<"> Podaj swoj wybor:  ";
        cin>>wybor;
        cout<<endl;

        srand(time(NULL));
        wartosc = rand()%50 + 1;

        if(biezacy==nullptr)
        {
            switch(wybor)
            {
            case 1:
            case 2:
                biezacy = new element;
                biezacy->number = wartosc;
                biezacy->next = biezacy;
                biezacy->prev = biezacy;
                break;
            case 3:
            case 4:
            case 6:
                cout<<"Nie mozna wykonac operacji - pusta lista"<<endl;
                break;
            case 5:
                cout<<"0"<<endl;
                break;
            default:
                cout<<"Podano zly numer"<<endl;
            }
        }
        else
        {
            switch(wybor)
            {
            case 1:
                add_after(*biezacy, wartosc);
                break;
            case 2:
                add_before(*biezacy, wartosc);
                break;
            case 3:
                if(biezacy->next == biezacy)
                    biezacy = nullptr;
                else
                {
                    biezacy->next = biezacy->next->next;
                    biezacy->next->prev = nullptr;
                    biezacy->next->prev = biezacy;
                }
                break;
            case 4:
                if(biezacy->prev == biezacy)
                    biezacy = nullptr;
                else
                {
                    biezacy->prev = biezacy->prev->prev;
                    biezacy->prev->next = nullptr;
                    biezacy->prev->next = biezacy;
                }
                break;
            case 5:
                temp = biezacy;
                i=0;
                do{
                    i++;
                    temp = temp->next;
                }while(temp!=biezacy);
                cout<<"Lista ma "<<i<<" elementow"<<endl;
                break;
            case 6:
                temp = biezacy;
                do{
                    cout<<"> "<<temp->number<<endl;
                    temp = temp->next;
                }while(temp!=biezacy);
                break;
            default:
                cout<<"Podano zly numer"<<endl;
            }
        }

        cout<<endl<<"--------------------------------------------------------------"<<endl<<endl;
    }while(wybor!=0);

    delete temp;
    delete biezacy;
    return 0;
}
