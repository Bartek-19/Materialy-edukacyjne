#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

using namespace std;

int main()
{
    int liczba, liczbaGracza;
    srand(time(NULL));
    liczba = rand()%11;

    do{
        try {
            cout<<"Odgadnij liczbe od 0 do 10: ";
            fflush(stdin);
            cin>>liczbaGracza;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Podano niepoprawny typ danych.");
            }

            if(liczbaGracza!=liczba)
                throw -1;
            else
                cout<<"Gratulacje! Odgadles liczbe!"<<endl;
        } catch(invalid_argument &E) {
            cout<<E.what()<<endl;
        } catch(int w) {
            cout<<"Nie odgadles, sprobuj ponownie."<<endl;
        } catch(...) {
            cout<<"Niezdefinowany blad"<<endl;
        }
    }while(liczbaGracza!=liczba);

    return 0;
}
