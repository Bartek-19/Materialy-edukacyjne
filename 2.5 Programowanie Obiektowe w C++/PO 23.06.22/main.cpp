#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
bool czyPalindrom(const T& t, int dlugosc)
{
    int i=0, j=dlugosc-1;

    while(t[i]==t[j] && i < j)
    {
        i++;
        j--;
    }
    if(i>=j)
        return true;
    else
        return false;
}

string tf(bool value)
{
    if(value)
        return "jest";
    else
        return "nie jest";
}

int main()
{
    char *tekst1 = "anilina";
    char tekst2[] = "Taki sobie napis";
    string tekst3("malajalam");
    int tab1[] = {1, 2, 3, 6, 3, 2, 1};
    int tab2[] = {1, 2, 3, 4, 4, 2, 1};
    char tab3[] = {'r', 'o', 't', 'a', 't', 'o', 'r'};

    cout<<"Zadanie 1"<<endl;
    cout<<"tekst 1: "<<tf( czyPalindrom(tekst1, strlen(tekst1)) )<<endl;
    cout<<"tekst 2: "<<tf( czyPalindrom(tekst2, strlen(tekst2)) )<<endl;
    cout<<"tekst 3: "<<tf( czyPalindrom(tekst3, tekst3.length()) )<<endl;
    cout<<"tab 1: "<<tf( czyPalindrom(tab1, sizeof(tab1)/sizeof(int)) )<<endl;
    cout<<"tab 2: "<<tf( czyPalindrom(tab2, sizeof(tab2)/sizeof(int)) )<<endl;
    cout<<"tab 3: "<<tf( czyPalindrom(tab3, sizeof(tab3)/sizeof(char)) )<<endl;

    return 0;
}
