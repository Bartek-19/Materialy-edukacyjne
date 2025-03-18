#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Compare1 {
    public:
        bool operator( ) (int &a, int &b) { return a<b; }
};

class Compare2 {
    public:
        bool operator( ) (int &a, int &b) { return countDigits(a)<countDigits(b); }
    private:
        int countDigits(int n) {
            int result = 0;
            if(n<0) n *= -1;
            do { n/=10; result++; } while(n>0);
            return result;
        }
};

void wyswietl(int &L)
{
    cout<<L<<" ";
}

int countDigits(int n) {
    int result = 0;
    if(n<0) n *= -1;
    do { n/=10; result++; } while(n>0);
    return result;
}

int main()
{
    vector<int> lista;
    int n=15;
    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        lista.push_back(rand()%40001 - 20000);
    }

    cout<<"Lista: ";
    for_each(lista.begin(), lista.end(), wyswietl);
    cout<<endl<<"Lista po posortowaniu rosnaco: ";
    sort(lista.begin(), lista.end(), Compare1());
    for_each(lista.begin(), lista.end(), wyswietl);

    random_shuffle(lista.begin(), lista.end());

    cout<<endl<<endl<<"Lista: ";
    for_each(lista.begin(), lista.end(), wyswietl);
    cout<<endl<<"Lista po posortowaniu malejaco: ";
    for (size_t i = 0; i < lista.size(); i++) {
        for (size_t j = 0; j < lista.size() - i - 1; j++) {
            if (lista[j] < lista[j+1]) {
                swap(lista[j], lista[j + 1]);
            }
        }
    }
    for_each(lista.begin(), lista.end(), wyswietl);

    random_shuffle(lista.begin(), lista.end());

    cout<<endl<<endl<<"Lista: ";
    for_each(lista.begin(), lista.end(), wyswietl);
    cout<<endl<<"Lista po posortowaniu rosnaco wedlug liczby jej cyfr: ";
    Compare2 comp;
    for (unsigned int i = 0; i < lista.size(); i++) {
        for (unsigned int j = 0; j < lista.size() - i - 1; j++) {
            if (comp(lista[j+1], lista[j])) {
                swap(lista[j], lista[j+1]);
            }
        }
    }
    for_each(lista.begin(), lista.end(), wyswietl);

    random_shuffle(lista.begin(), lista.end());

    cout<<endl<<endl<<"Lista: ";
    for_each(lista.begin(), lista.end(), wyswietl);
    cout<<endl<<"Lista po posortowaniu malejaco wedlug liczby jej cyfr: ";
    sort(lista.begin(), lista.end(), [](int &L1, int &L2) {
        return countDigits(L1) > countDigits(L2);
    });
    for_each(lista.begin(), lista.end(), wyswietl);

    cout<<endl;
    return 0;
}
