#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal
{
    public:
        Animal();
        Animal(int limbNr, string name, bool isProtected);
        ~Animal();

        string getName();
        int getLimbNr();
        bool getProtected();

        void setName(string newName);
        void setLimbNr(int newLimbNr);
        void setProtected(bool isProtected);

        void giveVoice();
        void info();

    private:
        int limbNr;
        string name;
        bool protectedAnimal;
};

#endif // ANIMAL_H
