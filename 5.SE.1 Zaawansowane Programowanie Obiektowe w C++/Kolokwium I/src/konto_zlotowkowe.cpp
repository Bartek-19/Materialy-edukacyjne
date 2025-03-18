#include "konto_zlotowkowe.h"
#include <iostream>

using namespace std;

konto_zlotowkowe::konto_zlotowkowe(int nr, float s)
{
    numer_konta = nr;
    saldo = s;
}

void konto_zlotowkowe::print()
{
    cout << "numer konta: "<< numer_konta << ", saldo: "<< saldo << " PLN"<< endl;
}
