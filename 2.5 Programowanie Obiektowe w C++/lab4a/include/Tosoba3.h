#ifndef TOSOBA3_H
#define TOSOBA3_H
#include <iostream>

using namespace std;

class Tosoba3
{
    public:
        Tosoba3();
        virtual ~Tosoba3();
        //Tosoba3(string naz);
        //Tosoba3(string *naz);
        Tosoba3(string &naz);
        //Tosoba3(const string &naz);
        string getNazwisko();
    private:
        string nazwisko;
};

#endif // TOSOBA3_H
