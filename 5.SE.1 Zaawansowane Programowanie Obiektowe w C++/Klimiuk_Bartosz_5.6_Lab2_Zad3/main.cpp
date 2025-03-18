#include <iostream>
#include <ctime>
#include "Bufor.h"
#include "MeanBufor.h"
#include "MaxBufor.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Bufor *b1, *b2, *b3;

    b1 = new MaxBufor();
    for(int i=0; i<=b1->getSize()+1; i++)
        b1->add(rand()%50);
    b1->show();
    cout<<"Maksymalna wartosc bufora 1: "<<b1->calculate()<<endl<<endl;
    delete b1;

    b2 = new MeanBufor(15);
    for(int i=0; i<b2->getSize(); i++)
        b2->setFirst(rand()%50);
    b2->show();
    cout<<"Srednia z bufora 2: "<<b2->calculate()<<endl<<endl;
    delete b2;

    b3 = new MaxBufor(12);
    for(int i=0; i<b3->getSize(); i++)
        b3->setTab(i, rand()%50);
    b3->show();
    cout<<"Maksymalna wartosc bufora 3: "<<b3->calculate()<<endl<<endl;
    delete b3;

    return 0;
}
