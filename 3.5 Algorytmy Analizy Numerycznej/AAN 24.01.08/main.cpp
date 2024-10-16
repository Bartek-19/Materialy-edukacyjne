#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return (pow(x, 4) + 5*pow(x, 2) - 3*x - 15);
}

int main()
{
    double epsilon;

    cout<<"> Zadanie 13.1"<<endl;
    cout<<"Wyznaczanie najmniejszego dodatniego pierwiastka funkcji x^4 + 5*x^2 - 3*x - 15"<<endl;
    cout<<"Zakres wartosci = [0;2]"<<endl;
    do{
        cout<<"Podaj epsilon (>0):  ";
        cin>>epsilon;
    } while(epsilon <= 0);

    return 0;
}
