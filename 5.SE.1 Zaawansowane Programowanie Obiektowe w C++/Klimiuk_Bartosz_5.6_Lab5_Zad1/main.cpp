#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> duplikat(vector<int> v)
{
    pair<int, int> result;
    int i,n;
    vector<int>::iterator it;

    for(it=v.begin(); it!=v.end(); it++)
    {
        i = *it;
        int n = count_if(v.begin(), v.end(), [i](int x) { return x == i; });
        result = {i, n};
        if(n!=1)
            return result;
    }
    return result;
}

int main()
{
    vector<int> zbior = {1, 3, 5, 7, 9, 11, 11, 13, 15};
    pair<int, int> p = duplikat(zbior);

    cout<<p.first<<", "<<p.second<<endl;

    return 0;
}
