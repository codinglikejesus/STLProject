#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
   map<string, int> piste_hakemisto;
   string input_tiedosto;
   cout << "Input file: ";
   cin >> input_tiedosto;
   ifstream tiedosto_olio(input_tiedosto);
   if (not tiedosto_olio){
       cout << "Error! The file " << input_tiedosto << " cannot be opened.";
       return EXIT_FAILURE;
   }
   string nimi;
   int pisteet;
   string rivi;
   while( getline(tiedosto_olio, rivi)){
       int erotin_indeksi = rivi.find(":");
       nimi = rivi.substr(0, erotin_indeksi);
       pisteet = stoi(rivi.substr((++erotin_indeksi)));
       if(piste_hakemisto.find(nimi) != piste_hakemisto.end()){
           piste_hakemisto.at(nimi) += pisteet;
       }
       else{
            piste_hakemisto.insert(make_pair(nimi, pisteet));

       }

   }
   tiedosto_olio.close();
   cout << "Final scores:" << endl;
   for ( auto alkio: piste_hakemisto){
        cout << alkio.first << ": " << alkio.second << endl;


   }

}
