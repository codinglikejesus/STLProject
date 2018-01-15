#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string password;
    cout << "Enter the encryption key: ";
    cin >> password;
    if(password.length() != 26){
        cout << "Error! The encryption key must contain 26 characters.";
        return 0;
    }
    for(int i = 0; i < 26; i++){
        if(islower(password.at(i))){

        }
        else{
            cout << "Error! The encryption key must contain only lower case characters.";
        }

    }
}
