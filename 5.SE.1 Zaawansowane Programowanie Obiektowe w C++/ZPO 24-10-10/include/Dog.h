#ifndef DOG_H
#define DOG_H

#include <Animal.h>
#include <iostream>

using namespace std;

class Dog : public Animal
{
    public:
        Dog();
        Dog(int limbs, string theName, bool protection);
        Dog(int limbs, string theName, bool protection, string breedName, int guider, int tracker);
        ~Dog();

        string getBreed();
        int getSkillLevel(int type);

        void setBreed(string breedName);
        void setSkillLevel(int type, int value);

        void giveVoice();
        void info();

    private:
        string breed;
        int levelOfGuideSkills;
        int levelOfTrackerSkills;
};

#endif // DOG_H
