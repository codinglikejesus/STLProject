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


//void add_product(string tuote, string price, Product &product, string store, map <string, vector<Product>> location, map<string, map<string, vector<Product>>> &store_container, vector <Product> &product_list){
  //  product.product_name = tuote;
    //product.price = price;
    //for ( auto a : product_list){
      //  if ( a.product_name == tuote){
        //    a.price = price;
          //  break;
        //}
    //}
    //product_list.push_back(product);
//}

void add_location(map<string, map<string, vector<Product>>> &store_container, string store, map <string, vector<Product>> &location, string chain){
    vector<Product> product_list;
    store_container[chain].insert({store, product_list});}

void chains(map<string, map<string, vector<Product>>> &store_container){
    for(auto i : store_container){
                cout << i.first << endl;}
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
            line_split = split(line);

            Product product;
            string chain = line_split.at(0);
            string store = line_split.at(1);
            string tuote = line_split.at(2);
            string price = line_split.at(3);

            add_chain(chain, store_container, location);
            add_location(store_container, store, location, chain);
            //add_product(tuote, price, product, chain, location, store_container, product_list);
        }for(auto i : store_container){
            cout << i.first << endl;
        }


    }while(true){
        string input;
        cout << "> "; cin >> input;
        std::vector<string> command = split(input);
        if(command.at(0) == "chains"){
            chains(store_container);
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
