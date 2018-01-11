#include <iostream>

using namespace std;
int main()

{
    cout << "How many numbers would you like to have? ";
    int luku = 0;
    cin >>luku;
    int i= 1;
    while( luku >= i){
        if( i % 3 == 0){
            if( i % 7 == 0){
                cout << "zip boing" << endl;
            }
            else{
                cout << "zip" << endl;
            }
            i++;

        }
        else if( i % 7 == 0){
            if(i % 3 == 0){
                cout << "zip boing" << endl;
            }
            else{
                cout << "boing" << endl;
            }
            i++;
        }

        else{
            cout << i << endl;
            i++;
        }

    }
}
