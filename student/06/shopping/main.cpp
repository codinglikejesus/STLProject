//Authors:
//Luukas Lusetti, 255162,  luukas.lusetti@student.tut.fi
//Matti Tuomela, 267013, matti.tuomela@student.tut.fi

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string product_name;
    string price;
};

void add_chain(string chain, map<string, map<string, vector<Product>>> &store_container, map <string, vector<Product>> location){

    if (store_container.find(chain) == store_container.end())
    {
        map<string, vector<Product>> location;
        store_container[chain] = location;
    }
}


void add_product(string product_name, string price, Product &product, string chain, map<string, map<string, vector<Product>>> &store_container, string location_name){
    bool flag = true;
    product.product_name = product_name;
    product.price = price;
    for ( auto a : store_container[chain][location_name]){
        if ( a.product_name == product_name){
            a.price = price;
            flag = false;
            break;

        }
    }
    if (flag != false)
        store_container[chain][location_name].push_back(product);
}

void add_location(map<string, map<string, vector<Product>>> &store_container, string store, map <string, vector<Product>> &location, string chain){
    vector<Product> product_list;
    if ( store_container[chain].find(store) != store_container[chain].end())
        store_container[chain].insert({store, product_list});

}

void chains(map<string, map<string, vector<Product>>> &store_container){
    for(auto i : store_container){
                cout << i.first << endl;}
}
void stores(map<string, map<string, vector<Product>>> &store_container, string store_name){
    for(auto i : store_container[store_name]){
        cout << i.first << endl;
}
}
void selection(std::vector<string> command){
cout << "toimii"<< endl;
}
void cheapest(std::vector<string> command){
cout << "toimii"<< endl;
}
void products(std::vector<string> command){
cout << "toimii"<< endl;
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
    map<string, map<string, vector<Product>>>::iterator it;
    map<string, map<string, vector<Product>>> store_container;
    string file_name;
    map <string, vector<Product>> location;
    //Pyytaa luettavan tiedoston nimea ja luo tiedosto-olion
    cout << "Input file: " << endl;
    getline(cin, file_name);
    ifstream file(file_name);
    if (!file.is_open()){
        cout << "Error: the input file cannot be opened";
    }
    //Tiedosto saadaan avattua
    else{
        string line;

        while ( getline(file, line)){
            //Jaetaan rivi osiin ja sijoitetaan vektoriin line_split, sijoitetaan osat store_container
            //mappiin.
            vector <string> line_split;
            line_split = split(line, ';');

            Product product;
            string chain = line_split.at(0);
            string location_name = line_split.at(1);
            string product_name = line_split.at(2);
            string price = line_split.at(3);

            add_chain(chain, store_container, location);
            add_location(store_container, location_name, location, chain);
            add_product(product_name, price, product, chain, store_container, location_name);
        }for(auto i : store_container){
            cout << i.first << endl;
        }


    }while(true){
        string input;
        cout << "> "; getline(cin, input);
        char delimiter = ' ';
        vector<string> command = split(input, delimiter);
        if(command.at(0) == "chains"){
            chains(store_container);
        }else if(command.at(0) == "stores"){
            stores(store_container, command.at(1));
        }else if(command.at(0) == "selection"){
            selection(command);
        }else if(command.at(0) == "cheapest"){
            cheapest(command);
        }else if(command.at(0) == "products"){
            products(command);
        }else{
            std::cout << "Error: unknown command" << std::endl;
        }

    }


}
