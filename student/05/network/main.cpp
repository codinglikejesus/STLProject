#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


int iterator = 0;
const std::string HELP_TEXT = "S = store id1 i2\n P = print id\n"
                              "C = count id\n D = depth id";

void print(std::map<std::string, std::vector <std::string>> network, std::string name){
    if ( iterator == 0)
        std::cout << name << std::endl;

    if (network.find(name) != network.end()){

        for( auto nimi : network.at(name)){
            if ( network.at(name).size() != 0){
                std::string commas = "..";
                for ( int i = 0; i < iterator; i++)
                    commas += "..";
                std::cout << commas << nimi << std::endl;
                iterator++;
                print(network, nimi);
            }
            else return;
        }

    }
    iterator--;
}

std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}



int main()
{
    // TODO: Implement the datastructure here
    std::map <std::string, std::vector<std::string>> verkosto;

    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);
            std::vector<std::string> toinen;
            if ( verkosto.find(id1) != verkosto.end()){
                verkosto[id1].push_back(id2);
            }
            else{
                toinen.push_back(id2);
                verkosto.insert(std::pair<std::string, std::vector<std::string>>(id1, toinen));


            }
        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            iterator = 0;
            print(verkosto, id);



        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
