#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i=0, j, n, m, p;

    do{
        cout<<"Podaj stopien wielomianu:  ";
        cin>>n;
    } while(n<0);
    n++;

    int wspolczynniki[n+1][n];

    cout<<"Podaj punkt:  ";
    cin>>p;

    for(i=0; i<n; i++)
    {
        cout<<"Podaj wspolczynnik "<<n-i-1<<":  ";
        cin>>wspolczynniki[0][i];
    }

    m=n;
    for(i=1; i<n+1; i++)
    {
        j=0;
        wspolczynniki[i][j] = wspolczynniki[i-1][j];
        j++;
        while(j<m)
        {
            wspolczynniki[i][j] = wspolczynniki[i][j-1]*p + wspolczynniki[i-1][j];
            j++;
        }
        m--;
    }

    m=n;
    for(i=0; i<n+1; i++)
    {
        cout<<p<<"|";
        for(j=0; j<m; j++)
        {
            cout<<setw(4)<<wspolczynniki[i][j]<<"|";
        }
        if(i==0) {}
        else
        {
            m--;
            while(j<n)
            {
                cout<<setw(5)<<"x|";
                j++;
            }
        }

        cout<<endl;
    }

    return 0;
}
