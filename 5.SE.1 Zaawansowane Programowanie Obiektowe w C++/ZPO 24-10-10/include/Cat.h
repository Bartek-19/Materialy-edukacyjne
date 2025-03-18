#ifndef CAT_H
#define CAT_H

#include <Animal.h>


class Cat : public Animal
{
    public:
        Cat();
        Cat(int limbs, string theName, bool protection);
        ~Cat();

        void initMice(int mysze[5]);
        void initCat(int limbs, string theName, bool protection, int hunter, int mysze[5]);
        void setLevelOfMouseHunting(int value);

        int getLevelOfMouseHunting();
        int getMice(int index);

        void giveVoice();
        void info();

    private:
        int levelOfMouseHunting;
        int mice[5];
};

#endif // CAT_H
