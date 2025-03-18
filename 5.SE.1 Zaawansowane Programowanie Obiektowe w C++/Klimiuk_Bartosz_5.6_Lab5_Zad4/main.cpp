#include <iostream>
#include <utility>
#include "Dictionary.h"

using namespace std;

int main()
{
    Dictionary slownik;
    map<string, string> wyrazy = {
        {"Zegar", "Clock"},
        {"Adam", "Adam"},
        {"Wyraz", "Word"},
        {"Slownik", "Dictionary"},
        {"Jablko", "Apple"},
        {"Najlepszy", "Linux"}
    };

    slownik.addWord(make_pair("Alfabet", "Alphabet"));
    for(auto i=wyrazy.begin(); i!=wyrazy.end(); i++)
        slownik.addWord(make_pair(i->first, i->second));

    slownik.show();

    slownik.showTranslation("Zegar");
    slownik.showTranslation("Najgorszy");

    slownik.removeWord("Wyraz");

    slownik.show();

    return 0;
}
