#ifndef TSASIAD_H
#define TSASIAD_H
#include <string>
#include "Tdomownik.h"

using namespace std;

class Tsasiad
{
    public:
        Tsasiad(Tdomownik &D);
        void info(Tdomownik &D);
        virtual ~Tsasiad();

    protected:
        string nazwa;
};

#endif // TSASIAD_H
