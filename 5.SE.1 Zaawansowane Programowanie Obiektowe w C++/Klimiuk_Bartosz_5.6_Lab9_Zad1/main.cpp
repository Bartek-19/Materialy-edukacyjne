#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream file;
    string line;
    size_t n;
    try {
        //komentarz
        file.open("main.cpp");
        while(getline(file,line)) {
            n=line.find("//");
            if(n!=string::npos) {
                line=line.substr(0, n);
            }
            cout<<line<<endl;
        }
        file.close();
    } catch(exception &e) {
        cout<<"Nie mozna otworzyc pliku, "<<e.what()<<endl;
    }

    return 0;
}
