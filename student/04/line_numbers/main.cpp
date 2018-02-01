#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string input_nimi = "";
    string output_nimi = "";
    vector <string> rivilista;
    cout << "Input file: ";
    getline(cin, input_nimi);
    cout << "Output file: ";
    getline(cin, output_nimi);

    ifstream input_olio(input_nimi);
    if ( not input_olio) {
        cout << "Error! The file " << input_nimi << " cannot be opened.";
        return EXIT_FAILURE;
    }
    else{
        string rivi;
        while ( getline(input_olio, rivi)){
            rivilista.push_back(rivi);
        }
        input_olio.close();
    }
    ofstream output_olio(output_nimi);
    if ( not output_olio) {
        cout << "Error! The file " << output_nimi << " cannot be opened.";
    }
    else{
        string rivi;
        for ( int i = 0; i < rivilista.size(); ++i){
            output_olio << i + 1 << " " << rivilista.at(i) << endl;
        }
    }
    output_olio.close();
}
