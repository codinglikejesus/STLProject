//Authors:
//Luukas Lusetti, 255162,  luukas.lusetti@student.tut.fi
//Matti Tuomela, 267013, matti.tuomela@student.tut.fi

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


//Tuote struct
struct Product {
    string product_name;
    string price;

};


//Tarkistaa, onko vektorin alkioissa tyhjia merkkijonoja.
//Palauttaa true jos on, muuten false.
bool empty_line(vector<string> line_split){
    for ( auto line : line_split){
        if ( line == "")
            return true;
        else
            return false;
    }
    return true;
}


//Ottaa parametrina vektorin joka sisaltaa tiedostosta otetun rivin jaettuna osiin.
//Palauttaa arvon true, jos rivi on oikeanlainen, muuten false.
bool is_line_correct(vector<string> line_split){
    if ( line_split.size() != 4 or empty_line(line_split)){
        cout << "Error: the file has an erroneous line" << endl;
        return false;
    }
    return true;
}


//Tarkistaa onko parametreja oikea maara, ja palauttaa tarkastelun mukaisen arvon
bool number_of_params(vector<string> command, unsigned int number){
    if(command.size() != number){
        cout << "Error: error in command " << command.at(0) << endl;
        return false;
    }
    else
        return true;
}


//Lisaa store_container rakenteeseen uuden ketjun
void add_chain(string chain, map<string, map<string, vector<Product>>> &store_container){

    //Tarkistaa loytyyko kyseinen ketju jo rakenteesta, ja lisaa uuden
    //jos ei loydy
    if (store_container.find(chain) == store_container.end()){
        map<string, vector<Product>> location;
        store_container[chain] = location;
    }
}


//Lisaa tuotteen ketju/sijainti rakenteeseen.
void add_product(string product_name, string price, Product &product, string chain, map<string, map<string, vector<Product>>> &store_container, string location_name){
    bool flag = true;

    //Antaa structi-oliolle nimen ja hinnan.
    product.product_name = product_name;
    product.price = price;

    //Kay jokaisen tuotteen listasta lapi, ja tarkistaa etta loytyyko
    //listasta jo lisattava tuote.
    for ( auto a : store_container[chain][location_name]){

        //Jos loytyy, muuttaa listasta loytyvan tuotteen hinnan uudella hinnalla.
        if ( a.product_name == product_name){
            a.price = price;
            flag = false;
            break;
        }
    }

    //Lisaa uuden tuotteen listaan jos sita ei loytynyt entuudestaan.
    if (flag != false)
        store_container[chain][location_name].push_back(product);
}


//Lisaa sijainnin kauppaketjulle
void add_location(map<string, map<string, vector<Product>>> &store_container, string location_name, string chain){
    vector<Product> product_list;

    //Tarkistaa loytyyko sijaintia kyseiselle kaupaketjulle, ja jos ei loydy, luo
    //uuden sijainnin.
    if ( store_container[chain].find(location_name) == store_container[chain].end())
        store_container[chain].insert({location_name, product_list});
}


//Kay jokaisen kauppaketjun lapi ja tulostaa ne erillisille riville.
void chains(map<string, map<string, vector<Product>>> &store_container){
    for(auto i : store_container){
        cout << i.first << endl;
    }
}


//Ottaa jonkin kauppaketjun parametrina ja tulostaa kyseisen ketjun jokaisen
//sijainnin.
void stores(map<string, map<string, vector<Product>>> &store_container, string store_name){
    if ( store_container.find(store_name) == store_container.end()){
        cout << "Error: an unknown chain" << endl;
        return;
    }

    else{
        for(auto i : store_container[store_name]){
            cout << i.first << endl;
        }
    }
}

//Ottaa parametreinaan ketjun ja sijainnin, ja tulostaa kyseisen kaupan tuotteiden nimet ja
//hinnat aakkosjarjestyksessa.
void selection(std::vector<string> command, map<string, map<string, vector<Product>>> &store_container){

    set <string> product_set;
    string store_name = command.at(1);
    string store_location = command.at(2);

    //Tarkistaa, loytyyko parametrina valitettya ketjua tietorakenteesta.
    if ( store_container.find(store_name) == store_container.end()){
        cout << "Error: unknown chain" << endl;
        return;
    }

    //Tarkistaa, loytyyko parametrina valitettya sijaintia tietorakenteesta
    else if (store_container[store_name].find(store_location) == store_container[store_name].end()){
        cout << "Error: unknown store" << endl;
        return;
    }

    else{

        //Sijoittaa product_set:iin tuotteen nimen ja joko "out of stock" tai hinnan.
        for ( auto product : store_container[store_name][store_location]){
            if ( product.price == "out-of-stock")
                product_set.insert(product.product_name + " out of stock");
            else
                product_set.insert(product.product_name + " " + product.price);
        }
    }

    //Tulostaa product_set:sta alkiot.
    for( auto product : product_set)
        cout << product << endl;
}

//Ottaa parametreina tuoteen jonka hintaa tarkastellaan ja tietorakenteen. Tulostaa tuotteen
//halvimman loydetyn hinnan, tai ilmoituksen, jos tuote on loppu tai sita ei ole olemassa. Lisaksi
//tulostaa sijainnit, josta tuotteet saa halvimmalla hinnalla.
void cheapest(vector <string> command, map<string, map<string, vector<Product>>> &store_container){
    bool in_stock = false;
    string current_price = "0";
    set <string> available_stores;
    string current_product = command.at(1);

    //Iteroi lapi jokaisen ketjun
    for ( auto store : store_container){

        //Kay lapi jokaisen sijainnin ketjulle
        for ( auto location : store.second){

            //Kay lapi jokaisen tuotteen kyseiselle kaupalle
            for ( auto product : location.second){

                //Tarkistaa onko tuote jota tarkastellaan sama kuin parametrina saatu merkkijono.
                if ( current_product == product.product_name){

                    in_stock = true;

                    //Jos tuotetta on saatavilla, ja current_price:lle on asetettu hinta,
                    //vertaillaan merkkijonoja double:na ja jos uusi arvo on suurempi kuin aiempi
                    //korvataan vanha uudella.
                    if(product.price != "out-of-stock" ){
                        if(current_price == "0"){
                            current_price = product.price;
                        }

                        //Jos tuote loytyy halvemmalla hinnalla, available_stores alustetaan ja uusi
                        //kaupan sijainti lisataan listaan. Muuten vain uusi kaupan sijainti lisataan
                        //listaan.
                        else{
                            if(stod(current_price) > stod(product.price)){
                                available_stores.clear();
                                available_stores.insert(store.first + " " + location.first);
                                current_price = product.price;
                            }
                            else if(stod(current_price) == stod(product.price))
                                available_stores.insert(store.first + " " + location.first);
                        }
                    }
                }
            }
        }
    }

    //Tulostaa virheilmoituksen, tai hinnan ja alkiot available_stores:sta.
    if (in_stock == false)
            cout << "Product is not part of product selection." << endl;

    else if ( current_price == "0")
        cout << "The product is temporarily out of stock everywhere." << endl;

    else{
        cout << current_price << " euros" << endl;
        for (auto str : available_stores){
            cout << str << endl;
        }
    }
}


//Käy for looppilla läpi jokaikisen tuotteen, ja jos tuote ei ole vielä products_alphabetical vectorissa,
//lisää sen vectoriin. Kun kaikki tuotteet on käyty läpi, järjestää vectorin aakkosjärjestykseen ja tulostaa sen.
void products(map<string, map<string, vector<Product>>> &store_container){
    vector<string> products_alphabetical;

    for(auto chain : store_container){
        for(auto store_location : chain.second){
            for(auto products : store_location.second){

                //Tarkistaa loytyyko tuote listasta products_alphabetical.
                if((find(products_alphabetical.begin(), products_alphabetical.end(), products.product_name) == products_alphabetical.end()))
                    products_alphabetical.push_back(products.product_name);
                }
            }
        }

        //Lajittelee tuoteet aakkosjärjestykseen vektorissa.
        sort(products_alphabetical.begin(), products_alphabetical.end());

        //Tulostaa tuoteet vektorista.
        for(auto it : products_alphabetical){
            cout << it << endl;
        }
}


//Ottaa parametrina jaettavan merkkijonon ja merkkijonon jakajan. Palauttaa vektorin
//joka sisaltaa merkkijonon osat.
std::vector<std::string> split(const std::string& s, const char delimiter){

    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos){
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());

        if(not (new_part.empty())){
            result.push_back(new_part);
        }
    }

    if(not (tmp.empty())){
        result.push_back(tmp);
    }

    return result;
}


int main()
{
    map<string, map<string, vector<Product>>>::iterator it;

    //Varsinaisen tietorakenteen alustus.
    map<string, map<string, vector<Product>>> store_container;
    string file_name;

    //Pyytaa luettavan tiedoston nimea ja luo tiedosto-olion
    cout << "Input file: ";
    getline(cin, file_name);
    ifstream file(file_name);
    if (!file.is_open()){
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }

    //Tiedosto saadaan avattua
    else{
        string line;
        while ( getline(file, line)){

            //Jaetaan rivi osiin ja sijoitetaan vektoriin line_split, sijoitetaan osat store_container
            //mappiin.
            vector <string> line_split;
            line_split = split(line, ';');

            if(not is_line_correct(line_split)){
                return EXIT_FAILURE;
            }

            Product product;
            string chain = line_split.at(0);
            string location_name = line_split.at(1);
            string product_name = line_split.at(2);
            string price = line_split.at(3);

            //Sijoitetaan tieto tietorakenteeseen erillisilla funktioilla
            add_chain(chain, store_container);
            add_location(store_container, location_name, chain);
            add_product(product_name, price, product, chain, store_container, location_name);    
        }
        file.close();

    }while(true){
        //Ohjelma pyytaa kayttajalta komentoa
        string input;
        cout << "> "; getline(cin, input);
        char delimiter = ' ';

        //Jakaa komennon osiin ja tallentaa sen vektoriin command
        vector<string> command = split(input, delimiter);

        //Kutsuu komentoa vastaavaa funktiota
        if(command.at(0) == "chains"){
            if(number_of_params(command, 1))
                chains(store_container);
        }
        else if(command.at(0) == "stores"){
            if(number_of_params(command, 2))
                stores(store_container, command.at(1));
        }

        else if(command.at(0) == "selection"){
            if(number_of_params(command, 3))
                selection(command, store_container);
        }
        else if(command.at(0) == "cheapest"){
            if(number_of_params(command, 2))
                cheapest(command, store_container);
        }

        else if(command.at(0) == "quit")
            return EXIT_SUCCESS;

        else if(command.at(0) == "products"){
            if(number_of_params(command, 1))
                products(store_container);
        }
        else
            std::cout << "Error: unknown command" << std::endl;
    }
}
