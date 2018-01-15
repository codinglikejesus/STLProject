#include <iostream>
#include <cctype>

using namespace std;
string encrypter(){
    for(char kirjain = 'a'; kirjain < 'z'; kirjain ++)

}

int main()
{
    string encrypted_text;
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
    cin >> encrypted_text;
    for(int i = 0; i < encrypted_text.length(); i++){
        if(islower(password.at(i))){

        }
        else{
            cout << "Error! The encryption key must contain only lower case characters.";
            EXIT_FAILURE;
        }
    }
}

