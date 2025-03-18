#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void wyswietl(int &L)
{
    cout<<L<<" ";
}

int main()
{
    vector<int> lista;
    int n, a, x=30;
    srand(time(NULL));

    cout<<"Tworzenie listy"<<endl;
    n = rand()%5 + x;
    for(int i=0; i<n; i++)
    {
        a = rand()%201 - 100;
        if(a>=0)
            lista.insert(lista.begin(), a);
        else
            lista.push_back(a);
    }

    cout<<"Wyswietlanie:"<<endl;
    vector<int>::iterator it;
    for(it=lista.begin(); it!=lista.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    for_each(lista.begin(), lista.end(), wyswietl);
    cout<<endl;

    for(auto i=lista.begin(); i!=lista.end(); i++)
        cout<<*i<<" ";
    cout<<endl;

    return 0;
}
