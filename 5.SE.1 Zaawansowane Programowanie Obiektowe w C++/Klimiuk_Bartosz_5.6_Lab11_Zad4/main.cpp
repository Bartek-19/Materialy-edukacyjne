#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> iadr(new int(3));
    iadr[0] = 2;
    iadr[1] = 4;
    iadr[2] = 6;
    iadr[3] = 8;

    return 0;
}
