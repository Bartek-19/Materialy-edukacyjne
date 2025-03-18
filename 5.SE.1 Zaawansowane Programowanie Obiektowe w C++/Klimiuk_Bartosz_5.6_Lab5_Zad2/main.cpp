#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> exor(set<int> s1, set<int> s2)
{
    set<int> result, temp1, temp2;
    set_difference( s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(temp1, temp1.end()) );
    set_difference( s2.begin(),s2.end(),s1.begin(),s1.end(), inserter(temp2, temp2.end()) );
    set_union( temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(result, result.end()) );
    return result;
}

void wyswietl(const int &L)
{
    cout<<L<<" ";
}

int main()
{
    set<int> set1 = {1, 2, 3, 4, 5, 6, 7, 8}, set2 = {5, 6, 7, 8, 9, 10, 11};
    set<int> zbiorXOR = exor(set1, set2);
    for_each(zbiorXOR.begin(), zbiorXOR.end(), wyswietl);

    return 0;
}
