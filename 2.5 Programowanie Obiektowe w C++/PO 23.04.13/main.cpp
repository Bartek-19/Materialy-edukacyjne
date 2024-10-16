#include <iostream>
#include "Ifigura.h"
#include "Tkolo2.h"
#include "Tkwadrat2.h"
#include "Tprostokat2.h"

using namespace std;

int main()
{
    Ifigura *wskObjekt1, *wskObjekt2, *wskObjekt3;

    wskObjekt1 = new Tkolo2;
    wskObjekt2 = new Tkwadrat2;
    wskObjekt3 = new Tprostokat2;

    cout<<endl;
    wskObjekt1->wyswietl();
    cout<<endl;
    wskObjekt2->wyswietl();
    cout<<endl;
    wskObjekt3->wyswietl();
    cout<<endl;

    delete wskObjekt1;
    delete wskObjekt2;
    delete wskObjekt3;

    return 0;
}
