#include <iostream>
#include <string>
#include "Tosoba3.h"

using namespace std;

int main()
{
    string ja("Klimiuk");
    cout<<"Adres obiektu 'ja':  "<<&ja<<endl;
    Tosoba3 os1(ja);
    cout<<"Adres obiektu 'os1': "<<&os1<<endl;
    cout<<"Nazwisko os1: "<<os1.getNazwisko()<<endl;

    return 0;
}
