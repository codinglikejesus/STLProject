#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string product_name;
    double price;
};

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
    bool flag;
    //Pyytaa luettavan tiedoston nimea ja luo tiedosto-olion
    cout << "Input file: " << endl;
    getline(cin, file_name);
    ifstream file(file_name);
    if ( not file){
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
            vector <Product> product_list;
            Product product;


            //Tarkistaa onko ketju jo store_container:ssa
            if ( store_container.find( line_split.at(0)) == store_container.end()){
                product.product_name = line_split.at(2);
                product.price = stoi(line_split.at(3));
                product_list.push_back(product);
                store_container.insert({line_split.at(0), location});
            }
            else{
                //Kay iteraattorilla lapi jokaisen avaimen, ja tarkistaa loytyyko sijainti.
                //Jos ei loydy, sjoittaa uuden sijainnin
                for ( it=store_container.begin(); it != store_container.end(); it++){
                    if (it->second == location){
                        location.insert({line_split.at(1), product_list});
                        flag = true;
                    }
                if ( flag == true){
                    if ( find(store_container[line_split.at(0)][line_split.at(1)].begin(), store_container[line_split.at(0)][line_split.at(1)].end(), line_split.at(2)) != store_container[line_split.at(0)][line_split.at(1)].end()){
                        if ( product.price < store_container[line_split.at(0)][line_split.at(1)].at(product.price)){

                        }
                    }
                }
                }
            }
        }
    }


}
