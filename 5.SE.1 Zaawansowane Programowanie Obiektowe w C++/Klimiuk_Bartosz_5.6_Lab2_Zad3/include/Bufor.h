#ifndef BUFOR_H
#define BUFOR_H


class Bufor
{
    public:
        Bufor();
        Bufor(int N);
        virtual ~Bufor();
        virtual void add(int value);
        virtual double calculate()=0;
        int getIndex();
        int getSize();
        int getTab(int i);
        int getFirst();
        void setTab(int N);
        void setFirst(int value);
        void setTab(int pos, int value);
        void show();

    private:
        int* tab;
        int n;
        int index;
};

#endif // BUFOR_H
