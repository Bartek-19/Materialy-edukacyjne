#ifndef TDATA_H
#define TDATA_H


class Tdata
{
    public:
        Tdata();
        Tdata(int &dd, int &mm, int &rr):d(dd), m(mm), r(rr) {};
        void wczytaj();
        void wyswietl();
        int getR();
        virtual ~Tdata();
    private:
        int d, m, r;
};

#endif // TDATA_H
