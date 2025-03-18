#include <iostream>
#include <memory>

using namespace std;

struct Elem {
    shared_ptr<Elem> prev;
    shared_ptr<Elem> next;
    int val;
};

class Lista {
    private:
        shared_ptr<Elem> first;
    public:
        Lista() {
            //first.reset();
        }

        void show() {
            if(first.get()!=0) {
                shared_ptr<Elem> t(first);
                do {
                    cout<<t->val<<endl;
                    t = t->next;
                } while(t.get()!=first.get());
            } else {
                cout<<"Lista jest pusta"<<endl;
            }
        }

        bool isEmpty() {
            return ((first.get()==0) ? true : false);
        }

        void addFirst(int value) {
            if(first.get()==0) {
                first = make_shared();
                first->val = value;
                first->prev = first;
                first->next = first;
            } else {
                shared_ptr<Elem> t;
                t->prev = first->prev;
                t->next = first;
                t->val = value;
                first->prev = t;
                first = t;
            }
        }

        void addLast(int value) {
            if(first.get()==0) {
                first->val = value;
                first->prev = first;
                first->next = first;
            } else {
                shared_ptr<Elem> t;
                t->prev = first->prev;
                t->next = first;
                t->val = value;
                first->prev = t;
            }
        }

        ~Lista() {
            first->next.reset();
            first->prev.reset();
            first.reset();
        }
};

int main()
{

    return 0;
}
