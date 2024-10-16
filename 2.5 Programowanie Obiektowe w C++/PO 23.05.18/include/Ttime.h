#ifndef TTIME_H
#define TTIME_H
#include "iostream"

using namespace std;

class Ttime
{
    public:
        Ttime(int g, int m);
        virtual ~Ttime();
        Ttime operator+(Ttime T);
        Ttime operator-(Ttime T);
        friend ostream & operator<<(ostream & O, const Ttime &Czas);
        int getHours();
        int getMinutes();
        void changeTime(int H, int M);

    protected:
        int godziny, minuty;
};

#endif // TTIME_H
