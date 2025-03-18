#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
void showConvertingFromGrams(int divider, T value)
{
    cout<<"Dla podanego typu brak specjalizacji"<<endl;
}

template<>
void showConvertingFromGrams<int>(int divider, int value)
{
    cout<<value<<"g = "<<value/divider;
    if(divider==10)
        cout<<"dag"<<endl;
    else if(divider==1000)
        cout<<"kg"<<endl;
    else
        cout<<"Jakiejs jednostki masy"<<endl;
}

template<>
void showConvertingFromGrams<float>(int divider, float value)
{
    cout<<value<<"g = "<<setprecision(3)<<value/divider;
    if(divider==10)
        cout<<"dag"<<endl;
    else if(divider==1000)
        cout<<"kg"<<endl;
    else
        cout<<" Jakiejs jednostki masy"<<endl;
}

int main()
{
    float m1 = 102.34;
    float m2 = 198.01;

    showConvertingFromGrams(10, m1);
    showConvertingFromGrams(1000, 56);
    showConvertingFromGrams(12, m2);
    showConvertingFromGrams(1234, "abcd");

    return 0;
}
