#include <iostream>
#include <exception>
using namespace std;

class Error {
public:
    virtual void error() = 0;
    virtual ~Error() {}
};

class Over21 : public Error {
public:
    void error() {
        cout << "Suma przekroczyla wartosc 21" << endl;
    }
};

int add(int sum) {
    int liczba;
    if(!(cin >> liczba)) {
        cin.clear();
        cin.ignore();
        throw exception();
    } else if(liczba<0) {
        throw underflow_error("Podano liczbe ujemna");
    } else if(sum+liczba>21) {
        throw Over21();
    } else {
        return liczba;
    }
}

void oczko() {
    int liczba;
    int suma=0;
    int lProb=0;
    int lProbU=0;

    do {
        try {
            cout << "Podaj liczbe: ";
            lProb++;
            liczba = add(suma);
            suma+=liczba;
            lProbU++;
        } catch (const underflow_error& p) {
            cout<<p.what()<<endl;
        } catch (exception p) {
            cout<<p.what()<<endl;
        } catch (Over21 p) {
            p.error();
        }
    } while (suma != 21);
    cout<<endl<<"Gratulacje"<<endl;
    cout<<"Liczba wszystkich prob: "<<lProb<<endl;
    cout<<"Liczba udanych prob: "<<lProbU<<endl;
    cout<<"Liczba nieudanych prob: "<<lProb-lProbU<<endl;
}

int main()
{
    oczko();
    return 0;
}
