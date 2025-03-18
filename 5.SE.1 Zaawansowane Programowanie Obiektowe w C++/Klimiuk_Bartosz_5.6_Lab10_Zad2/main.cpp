#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex reg("([0-1]?[0-9]|2[0-3]){1}(:[0-5][0-9]){1,2}");
    string czas1 = "11:01:21";
    string czas2 = "9:01:18";
    string czas3 = "21:12";
    string czas4 = "0:32";

    if(regex_match(czas1, reg))
        cout<<"Zgdony format czasu hh:mm:ss"<<endl;
    else
        cout<<"Niezgdony format czasu hh:mm:ss"<<endl;

    if(regex_match(czas2, reg))
        cout<<"Zgdony format czasu hh:mm"<<endl;
    else
        cout<<"Niezgdony format czasu hh:mm"<<endl;

    return 0;
}
