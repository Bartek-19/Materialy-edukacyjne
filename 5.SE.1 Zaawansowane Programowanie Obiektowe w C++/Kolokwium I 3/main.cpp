#include <iostream>
#include <boost/fusion/container.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/fusion/algorithm.hpp>
#include <vector>

typedef boost::fusion::vector<std::string, float, float, float, float, float, int, std::string> Planeta;

void show(Planeta& P)
{
    std::cout << boost::fusion::at_c<0>(P)
         << "\tsrednica: " << boost::fusion::at_c<1>(P)
         << "\tmasa: " << boost::fusion::at_c<2>(P)
         << "\todleglosc od slonca: " << boost::fusion::at_c<3>(P)
         << "\tczas obiegu [lata]: " << boost::fusion::at_c<4>(P)
         << "\tczas obrotu [dni]: " << boost::fusion::at_c<5>(P)
         << "\tliczba ksiezycow: " << boost::fusion::at_c<6>(P)
         << "\trodzaj: " << boost::fusion::at_c<7>(P) << std::endl;
}

bool sortowanie(Planeta& P1, Planeta& P2)
{
    if( boost::fusion::at_c<3>(P1) > boost::fusion::at_c<3>(P2) )
        return true;
    else
        return false;
}

int main()
{
    std::vector<Planeta> planety = {
        Planeta("Merkury", 0.3825f, 0.552f, 0.3871f, 0.2408f, 58.64306f, 0, "skalista"),
        Planeta("Wenus", 0.9489f, 0.8149f, 0.7233f, 0.6152f, 243.01875f, 0, "skalista"),
        Planeta("Ziemia", 1.0f, 1.0f, 1.0f, 1.0f, 0.99727f, 1, "skalista"),
        Planeta("Mars", 0.5335f, 0.1074f, 1.5237f, 1.8808f, 1.02596f, 2, "skalista"),
        Planeta("Jowisz", 11.2092f, 317.8f, 5.2034f, 11.8637f, 0.41354f, 79, "gazowa"),
        Planeta("Saturn", 9.494f, 95.1620f, 9.5371f, 29.4484f, 0.44400f, 82, "gazowa"),
        Planeta("Uran", 4.0074f, 14.5360f, 19.1913f, 84.0711f, 0.71833f, 27, "gazowo-lodowa"),
        Planeta("Neptun", 3.8827f, 17.1470f, 30.0690f, 164.8799f, 0.67125f, 14, "gazowo-lodowa")
    };

    return 0;
}
