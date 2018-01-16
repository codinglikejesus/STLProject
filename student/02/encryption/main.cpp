#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;
string encrypter(string password, string text){
    int i = 0;
    string encrypted_text;
    string original_text;
    original_text = text;
    string:: size_type pituus=0;
    pituus = text.length();
    char letter;
    letter = password.at(i);
    for(int j = 0; j < pituus; j++){
        i = 0;
        for(char kirjain = 'a'; kirjain < 'z'; kirjain ++){
            if(text.string::at(j) == kirjain){
                encrypted_text += password.string::at(i);
            }
            i++;

        }

    }
    return encrypted_text;

}

int main()
{
    string text;
    string password;
    cout << "Enter the encryption key: ";
    cin >> password;
    if(password.length() != 26){
        cout << "Error! The encryption key must contain 26 characters.";
        EXIT_FAILURE;
    }
    for(int i = 0; i < 26; i++){
        if(islower(password.at(i))){

        }
        else{
            cout << "Error! The encryption key must contain only lower case characters.";
            EXIT_FAILURE;
        }

    }
    for( char kirjain = 'a'; kirjain < 'z'; ++kirjain){
        if( password.find(kirjain) == string::npos){
            cout << "Error! The encryption key must contain all alphabets a-z";
            EXIT_FAILURE;
        }
    }
    cout << "Enter the text to be encrypted: ";
    cin >> text;
    for(int i = 0; i < text.length(); i++){
        if(islower(text.at(i))){

        }
        else{
            cout << "Error! The encryption key must contain only lower case characters.";
            EXIT_FAILURE;
        }
    }
    string encrypted_text = encrypter(password, text);
    cout << "Encrypted text: " << encrypted_text;
}

