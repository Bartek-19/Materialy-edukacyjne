#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex reg("-?([1-9]+[0-9]*[x]{1}\\^{1}[2-4]{1}[+-]{1}){0,3}([1-9]+[0-9]*[x]{1}[+-]{1}){0,1}([1-9]+[0-9]*){0,1}");
    string wyrazenia[] = {"5x^4+x^3+x-3", "5x^4+x^3+x", "-5x^4-4x^3+x^2-4", "5x4-2x^3+x-3", "5x^4+0x^3+x-3", "5x^4+x^3+x--3"};

    for(int i=0; i<6; i++) {
        cout<<"Wyrazenie "<<wyrazenia[i]<<" jest ";
        (regex_match(wyrazenia[i], reg)) ? cout<<"poprawne"<<endl : cout<<"niepoprawne"<<endl;
    }


    return 0;
}
