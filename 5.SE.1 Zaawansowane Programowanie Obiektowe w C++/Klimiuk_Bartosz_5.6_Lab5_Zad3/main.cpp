#include <iostream>
#include <map>
#include <string>

using namespace std;

char dodatkowyZnak(const string& str1, const string& str2) {
    map<char, int> charCount;
    for (char c : str1)
        charCount[c]++;
    for (char c : str2)
        charCount[c]--;
    for (const auto& entry : charCount)
        if (entry.second < 0)
            return entry.first;

    return '\0';
}

int main() {
    string str1 = "abcde", str2 = "dceabf";
    char wynik = dodatkowyZnak(str1, str2);

    (wynik != '\0') ? cout<<"Dodatkowy znak: "<<wynik<<endl : cout<<"Nie znaleziono dodatkowego znaku."<<endl;

    return 0;
}
