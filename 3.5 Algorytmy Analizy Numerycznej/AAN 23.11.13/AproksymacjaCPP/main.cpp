#include <iostream>

using namespace std;

int main()
{
    int wybor, n, i, a[2][3], W, Wa0, Wa1;
    double a0, a1;

    do{
        cout<<"Podaj ilosc wezlow:  ";
        cin>>n;
    }while(n<=0);

    int X[n], Y[n];

    do{
        cout<<"Wybierz rodzaj funkcji:"<<endl;
        cout<<"1. g(x) = ax + b"<<endl;
        cout<<"2. g(x) = a/x + b"<<endl;
        cout<<"3. g(x) = b * a^x"<<endl;
        cout<<" > > > ";
        cin>>wybor;
    }while(wybor<1 || wybor>3);

    switch(wybor)
    {
    case 1:
        for(i=0; i<n; i++)
        {
            cout<<"x["<<i<<"] = ";
            cin>>X[i];
        }
        for(i=0; i<n; i++)
        {
            cout<<"y["<<i<<"] = ";
            cin>>Y[i];
        }
        break;
    case 2:
        for(i=0; i<n; i++)
        {
            cout<<"x["<<i<<"] = 1/";
            cin>>X[i];
        }
        for(i=0; i<n; i++)
        {
            cout<<"y["<<i<<"] = ";
            cin>>Y[i];
        }
        break;
    case 3:
        for(i=0; i<n; i++)
        {
            cout<<"x["<<i<<"] = ";
            cin>>X[i];
        }
        for(i=0; i<n; i++)
        {
            cout<<"y["<<i<<"] = e^";
            cin>>Y[i];
        }
        break;
    default:
        cout<<"Cos poszlo nie tak"<<endl;
        exit(1);
    }

    a[0][0] = n;
    a[0][1] = 0;
    for(i=0; i<n; i++)
        a[0][1] += X[i];
    a[0][2] = 0;
    for(i=0; i<n; i++)
        a[0][2] += Y[i];
    a[1][0] = a[0][1];
    a[1][1] = 0;
    for(i=0; i<n; i++)
        a[1][1] += X[i]*X[i];
    a[1][2] = 0;
    for(i=0; i<n; i++)
        a[1][2] += X[i]*Y[i];

    W = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    Wa0 = a[0][2]*a[1][1] - a[1][2]*a[0][1];
    Wa1 = a[0][0]*a[1][2] - a[1][0]*a[0][2];

    if(W==0)
    {
        if(Wa0==0)
            cout<<"a0 ma nieskonczenien wiele rozwiazan"<<endl;
        else
            cout<<"a0 nie ma rozwiazan"<<endl;

        if(Wa1==0)
            cout<<"a1 ma nieskonczenien wiele rozwiazan"<<endl;
        else
            cout<<"a1 nie ma rozwiazan"<<endl;
    }
    else
    {
        a0 = Wa0/W;
        a1 = Wa1/W;

        cout<<"Wzor funkcji:  (";
        switch(wybor)
        {
        case 1:
            cout<<a0<<") + ("<<a1<<")X"<<endl;
            break;
        case 2:
            cout<<a0<<") + ("<<a1<<")X"<<endl;
            break;
        case 3:
            cout<<a0<<") * ("<<a1<<")^X"<<endl;
            break;
        default:
            cout<<endl<<"Cos poszlo nie tak"<<endl;
            exit(1);
        }
    }
    cout<<endl;

    system("PAUSE");
    return 0;
}
