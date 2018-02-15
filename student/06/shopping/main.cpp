#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Product {
    string product_name;
    string price;
};

void add_chain(string chain, map<string, map<string, vector<Product>>> store_container){
    if (store_container.find(chain) == store_container.end())
    {
        map<string, vector<Product>> location;
        store_container[chain] = location;
    }
}


void add_product(string tuote, string price, Product product, string store, map <string, vector<Product>> location, map<string, map<string, vector<Product>>> store_container, vector <Product> product_list){
    product.product_name = tuote;
    product.price = price;
    for ( auto a : product_list){
        if ( a.product_name == tuote){
            a.price = price;
            break;
        }
    }
    product_list.push_back(product);
}

void add_location(map<string, map<string, vector<Product>>> store_container, string chain, string location)
{
    map<string, map<string, vector<Product>>>::iterator it = store_container.find(chain);

    // Jos kauppaketjua ei löydy
    if (it == store_container.end())
    {
        return;
    }

    if ((*it).second.find(location) == (*it).second.end())
    {
        map<string, vector<Product>> product_list;
        (*it).second.insert({kauppa, product_list});
    }

}

void chains(std::vector<string> command){
cout << "toimii"<< endl;
}
void stores(std::vector<string> command){
cout << "toimii"<< endl;
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

std::vector<std::string> split(const std::string& s){
    const char* delimiter = ";";
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not new_part.empty())
        {
            result.push_back(new_part);
        }
    }
    if(not tmp.empty())
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
            line_split = split(line);
            map <string, vector<Product>> location;
            vector<Product> product_list;
            Product product;
            string store = line_split.at(0);
            string kauppa = line_split.at(1);
            string tuote = line_split.at(2);
            string price = line_split.at(3);

            add_chain(store, store_container, location);
            add_location(store_container, location, kauppa, product_list);
            add_product(tuote, price, product, store, location, store_container, product_list);
        }

    }while(true){
        string input;
        cout << "> "; cin >> input;
        std::vector<string> command = split(input);
        if(command.at(0) == "chains"){
            chains(command);
        }else if(command.at(0) == "stores"){
            stores(command);
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
