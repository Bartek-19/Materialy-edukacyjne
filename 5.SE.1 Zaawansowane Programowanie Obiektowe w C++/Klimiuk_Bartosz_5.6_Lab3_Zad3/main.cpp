#include <iostream>

using namespace std;

template <typename T>
class Array
{
    public:
        Array()
        {
            initTab(10);
        }
        Array(int n)
        {
            initTab(n);
        }
        ~Array()
        {
            delete [] tab;
        }
        void sorting()
        {
            int iMin;
            for(int i=0; i<index; i++)
            {
                iMin=i;
                for(int j=i+1; j<index; j++)
                {
                    if(tab[j]<tab[iMin])
                        iMin = j;
                }
                swap(tab[i], tab[iMin]);
            }
        }
        T maximal()
        {
            T result = tab[0];
            for(int i=1; i<index; i++)
                result = (result<tab[i]) ? tab[i] : result;
            return result;
        }
        void show()
        {
            for(int i=0; i<index; i++)
                cout<<tab[i]<<" ";
            cout<<endl;
        }
        void add(T value)
        {
            if(index < maxSize)
            {
                tab[index] = value;
                index++;
            }

        }
        T returnElement(int i)
        {
            if(i>=0 && i<index)
                return tab[i];
            else
                return maximal();
        }

    private:
        T *tab;
        int maxSize;
        int index;
        void initTab(int n)
        {
            if(n>0)
            {
                tab = new T[n];
                index = 0;
                maxSize = n;
            }
        }
};

template<> void Array<string>::sorting()
{
    int iMin;
    for(int i=0; i<index; i++)
    {
        iMin=i;
        for(int j=i+1; j<index; j++)
        {
            if(tab[j].length()<tab[iMin].length())
                iMin = j;
        }
        swap(tab[i], tab[iMin]);
    }
}
template<> string Array<string>::maximal()
{
    string result = tab[0];
    for(int i=1; i<index; i++)
        result = (result.length()<tab[i].length()) ? tab[i] : result;
    return result;
}

int main()
{
    Array<double> t1;
    t1.add(4.27);
    t1.add(3.14159);
    t1.add(3.141589);
    t1.add(2.7321);
    t1.add(1.978);
    t1.add(7.69);
    t1.show();
    cout<<t1.maximal()<<endl;
    t1.sorting();
    t1.show();
    cout<<endl;

    Array<int> *t2 = new Array<int>(7);
    t2->add(4);
    t2->add(3);
    t2->add(3);
    t2->add(2);
    t2->add(1);
    t2->add(7);
    t2->add(0);
    t2->add(88);
    t2->show();
    cout<<t2->maximal()<<endl;
    t2->sorting();
    t2->show();
    cout<<endl;
    delete t2;

    Array<char> t3(5);
    t3.add('b');
    t3.add('x');
    t3.add('X');
    t3.add(68);
    t3.add(102);
    t3.show();
    cout<<t3.maximal()<<endl;
    t3.sorting();
    t3.show();
    cout<<endl;

    Array<string> *t4 = new Array<string>();
    t4->add("Taki");
    t4->add("ze");
    t4->add("mnie");
    t4->add("Maksi");
    t4->add("Kaz");
    t4->show();
    cout<<t4->maximal()<<endl;
    t4->sorting();
    t4->show();
    cout<<endl;
    delete t4;

    return 0;
}
