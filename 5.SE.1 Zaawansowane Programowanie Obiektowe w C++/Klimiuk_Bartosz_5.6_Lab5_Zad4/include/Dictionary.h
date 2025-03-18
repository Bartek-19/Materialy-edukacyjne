#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <utility>

using namespace std;

class Dictionary
{
    public:
        Dictionary();
        ~Dictionary();

        void addWord(pair<string, string> word);
        void removeWord(string word);
        void show();
        void showTranslation(string word);
        void sortAlphabetically();

    private:
        map<string, string> words;

};

#endif // DICTIONARY_H
