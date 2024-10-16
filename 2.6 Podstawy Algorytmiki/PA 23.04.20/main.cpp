#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int make_hash(char s, int exp, int p, int off)
{
    return ( ((int)s - off) * pow(p, exp) );
}

int update_hash(int o_hash, char s_prev, char s_next, int off, int p, int exp)
{
    int u_hash = o_hash - ((int)s_prev - off) * pow(p, exp);
    u_hash = u_hash * p;
    u_hash += ((int)s_next - off);

    return u_hash;
}

void KarpRabin(char *pattern, char *text, int lenP, int lenT, int p, int off)
{
    int hashP=0, hashT=0, i=0, j=0, k, l;

    while(i < lenP)
    {
        hashP += make_hash(pattern[i], off, p, lenP-1-i);
        hashT += make_hash(text[i], off, p, lenP-1-i);
        i++;
    }

    i=lenP;

    while(i <= lenT)
    {
        if(hashP == hashT)
        {
            k = 0;
            while(k < lenT - lenP)
            {
                l = 0;
                while(l < lenP && pattern[l]==text[k+l])
                    l++;
                if(l==lenP)
                    cout<<k<<endl;
                k++;
            }
        }

        if(i < lenT)
            hashT = update_hash(hashT, text[j], text[i], off, p, lenP-1);

        i++;
        j++;
    }
}

int main()
{
    string linia, sciezka="tekst.txt";
    int dlugoscTekstu, dlugoscWzorca, n=2;
    char *tekst, *wzorzec;
    ifstream plik;

    plik.open(sciezka);

    getline(plik, linia);

    dlugoscWzorca = linia.length();

    wzorzec = new char[dlugoscWzorca];

    strcpy(wzorzec, linia.c_str());


    while(linia)
    {
        getline(plik, linia);
        dlugoscTekstu = linia.length();
        tekst = new char[dlugoscTekstu];
        strcpy(tekst, linia.c_str());
        cout<<"Indeksy w linii "<<n<<":"<<endl;
        n++;
        KarpRabin(wzorzec, tekst, dlugoscWzorca, dlugoscTekstu, 2, (int)wzorzec[0]);
        cout<<endl;
        delete [] tekst;
    }

    return 0;
}
