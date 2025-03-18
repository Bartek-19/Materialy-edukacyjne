#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<string, float, float, float, float, float, int, string> planeta;

void show() {
    vector<planeta> planety;
    planety.push_back(make_tuple("Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"));
    planety.push_back(make_tuple("Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"));
    planety.push_back(make_tuple("Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"));
    planety.push_back(make_tuple("Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"));
    planety.push_back(make_tuple("Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"));
    planety.push_back(make_tuple("Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"));
    planety.push_back(make_tuple("Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"));
    planety.push_back(make_tuple("Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"));
    /*  { {"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
         {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
         {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
         {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
         {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
         {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
         {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
         {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"} };*/
    cout << "Przed sortowaniem wzgledem srednicy:" << endl;
    cout << "nazwa " << "srednica " << "masa " << "odleglosc od slonca " << " czas obrotu w okol wlasnej osi " << "liczba ksiezycow " << "rodzaj planety" << endl;
    for_each(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string> element) {
        cout << get<0>(element) << " " << get<1>(element) << " " << get<2>(element) << " " << get<3>(element) << " " << get<4>(element) << " " << get<5>(element) << " " << get<6>(element) << " " << get<7>(element) << endl;
    });
    cout << endl << "Po sortowaniu wzgledem srednicy: " << endl;
    sort(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string> a, tuple<string, float, float, float, float, float, int, string> b) {
        return get<1>(a) < get<1>(b);
    });
    cout << "nazwa " << "srednica " << "masa " << "odleglosc od slonca " << " czas obrotu w okol wlasnej osi " << "liczba ksiezycow " << "rodzaj planety" << endl;
    for_each(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string> element) {
        cout << get<0>(element) << " " << get<1>(element) << " " << get<2>(element) << " " << get<3>(element) << " " << get<4>(element) << " " << get<5>(element) << " " << get<6>(element) << " " << get<7>(element) << endl;
    });
}

int main()
{
    show();
    return 0;
}
