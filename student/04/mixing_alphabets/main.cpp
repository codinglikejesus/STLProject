#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    // Tämä on random-numerogeneraattori, joka pitää antaa parametrina sille
    // algorithm-kirjaston funktiolle, joka sekoittaa kirjaimet
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;


    while (std::cin >> word)
    {
        std::vector <char> lista;

        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        for( char a : word){
            lista.push_back(a);

        }
        // TODO: toteuta ratkaisusi tähän
        if(lista.size() > 3){
            shuffle(++(lista.begin()) ,--(lista.end()), generator );
        }
        word = "";
        for (auto letter : lista){
            word += letter;

        }
        std::cout << word << std::endl;
        lista.clear();
    }
}
