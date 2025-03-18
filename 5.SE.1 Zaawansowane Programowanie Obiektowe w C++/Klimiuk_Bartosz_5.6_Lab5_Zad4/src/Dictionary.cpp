#include "Dictionary.h"
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

Dictionary::Dictionary()
{
    //ctor
}

void Dictionary::addWord(pair<string, string> word)
{
    words.insert(word);
    sortAlphabetically();
}

void Dictionary::removeWord(string word)
{
    map<string, string>::iterator wordExists = words.find(word);
    if(wordExists!=words.end())
    {
        words.erase(word);
        cout<<"Usunieto ze slownika \""<<word<<"\""<<endl;
    }
    else
        cout<<"Slowo \""<<word<<"\" nie wystepuje w slowniku"<<endl;
    cout<<endl;
}

void Dictionary::show()
{
    cout<<"Zawartosc slownika:"<<endl;
    map<string, string>::iterator w;
    for(w=words.begin(); w!=words.end(); w++)
        cout<<w->first<<" - "<<w->second<<endl;
    cout<<endl;
}

void Dictionary::showTranslation(string word)
{
    map<string, string>::iterator wordExists = words.find(word);
    if(wordExists!=words.end())
        cout<<word<<" - "<<wordExists->second<<endl;
    else
        cout<<"Slowa \""<<word<<"\" nie ma w slowniku"<<endl;
    cout<<endl;
}

void Dictionary::sortAlphabetically()
{
    //Funkcja niepotrzebna
    //Sortowanie alfabetyczne odbywa sie automatycznie w kontenerze map<string, ... >
}

Dictionary::~Dictionary()
{
    //dtor
}
