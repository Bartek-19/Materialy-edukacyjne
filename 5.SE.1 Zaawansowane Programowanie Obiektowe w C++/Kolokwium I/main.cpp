#include <iostream>
#include "konto_zlotowkowe.h"
#include "konto_dolarowe.h"

using namespace std;

int main()
{
    konto_dolarowe* k1 = new konto_dolarowe(12345678, 1200.12, 4.07);
    k1->print();
    delete k1;

    konto_dolarowe* k2 = new konto_dolarowe(11111111, -10010.38, 4.16);
    k2->print();
    delete k2;

    return 0;
}
