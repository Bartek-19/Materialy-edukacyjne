#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex reg("([+-])?[0-9]+\\.[0-9]+");
    string liczba;
    cout<<"Podaj liczbe: ";
    cin>>liczba;
    if(regex_match(liczba, reg))
        cout<<"W podanym ciagu wystepuje liczba zmiennoprzecinkowa"<<endl;
    else
        cout<<"W podanym ciagu nie wystepuje liczba zmiennoprzecinkowa"<<endl;

    return 0;
}

//regex reg("([+-])?[0-9]+\\.[0-9]+")
// regex reg("[+-]?[0-9]+\\.[0-9]+")
// regex reg("[+-]?[:digit:]+\\.\\d+")
// regex reg(R"[+-]?\d+\.\d+")
