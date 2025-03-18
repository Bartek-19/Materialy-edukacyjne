#include "konto_dolarowe.h"
#include <iostream>

using namespace std;

float konto_dolarowe::przelicz()
{
    return saldo*kurs;
}

void konto_dolarowe::print()
{
    cout << "numer konta: "<< numer_konta << ", saldo: "<< przelicz() << " PLN"<< endl;
}
