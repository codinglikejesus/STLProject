#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// TODO: Toteuta split-funktio tänne
// Älä tee mitään muutoksia main-funktioon

vector<string> split(string merkkijono, char erotinmerkki, bool ohitus = false)
{
    vector<string> tulos;
    while(merkkijono.size() != 0){
        string::size_type indeksi = merkkijono.find(erotinmerkki);
        if(indeksi != string::npos){
            if(merkkijono.at(0) == erotinmerkki and merkkijono.size() == 1){
                tulos.push_back(merkkijono.substr(0, indeksi ));
                tulos.push_back(merkkijono.substr(0, indeksi ));
            }
            tulos.push_back(merkkijono.substr(0, indeksi ));
            merkkijono.erase(0, indeksi +1);
        }
        else{
            tulos.push_back(merkkijono.substr(0));
            merkkijono.erase(0);
        }
    }
    if(ohitus == false){
        return tulos;
    }
    else{
        int i = 0;
        tulos.erase(std::remove(tulos.begin(), tulos.end(), ""), tulos.end());

    }
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto o : parts ) {
        std::cout << o << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto o : parts_no_empty ) {
        std::cout << o << std::endl;
    }
}
