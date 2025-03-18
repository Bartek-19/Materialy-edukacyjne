#include <iostream>

using namespace std;

template <typename T>
T minimal(T* tab, int n)
{
    cout<<"Dla tego typu nie liczymy minimum"<<endl;
    return *tab;
}

template<>
double minimal<double>(double* tab, int n)
{
    double result = tab[0];
    for(int i=1; i<n; i++)
    {
        result = (result>tab[i]) ? tab[i] : result;
    }
    return result;
}

template<>
int minimal<int>(int* tab, int n)
{
    int result = tab[0];
    for(int i=1; i<n; i++)
    {
        result = (result>tab[i]) ? tab[i] : result;
    }
    return result;
}

template<>
float minimal<float>(float* tab, int n)
{
    float result = tab[0];
    for(int i=1; i<n; i++)
    {
        result = (result>tab[i]) ? tab[i] : result;
    }
    return result;
}

int main()
{
    int tab1[10] = {2, 6, 7, 19, 0, -8, -68, 90, -67, 10};
    int minimum1 = minimal<int>(tab1, 10);
    cout<<minimum1<<endl;

    float tab2[5] = {1.001, 1.002, 1.000, 0.999, 0.9991};
    float minimum2 = minimal<float>(tab2, 5);
    cout<<minimum2<<endl;

    double tab3[4] = {-0.0000001, -0.00000001, -0.000000001, -0.0000000001};
    double minimum3 = minimal<double>(tab3, 4);
    cout<<minimum3<<endl;

    return 0;
}

