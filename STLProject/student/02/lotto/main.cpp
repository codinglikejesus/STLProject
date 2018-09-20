#include <iostream>
#include <string>
#include <sstream>

using namespace std;

unsigned long int factorial(unsigned long int number){
    unsigned long int result = 1;
    for(int i = 1; i <= number; ++i){
        result *= i;
    }
    return result;
}

unsigned long int odds_of_winning(int drawn_balls, int ball_amount){
    unsigned long int odds = 0;
    unsigned long int osoittaja = 0;
    unsigned long int nimittaja = 0;
    osoittaja = factorial(ball_amount);
    nimittaja = factorial(ball_amount - drawn_balls) * factorial(drawn_balls) ;
    odds = osoittaja / nimittaja;
    return odds;

}

bool error_check(int drawn_balls, int ball_amount){
    if(ball_amount < 0){
        cout << "The number of balls must be a positive number." << endl;
        return 1;
    }
    else if(drawn_balls > ball_amount){
        cout << "At most the total number of balls can be drawn." << endl;
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int ball_amount;
    int drawn_balls;
    cout << "Enter the total number of lottery balls: ";
    cin >> ball_amount;
    cout << "Enter the number of the drawn balls: ";
    cin >> drawn_balls;
    if(error_check(drawn_balls, ball_amount) == 0){
        cout << "The probability of guessing all " << drawn_balls
             << " balls correctly is 1/" << odds_of_winning(drawn_balls, ball_amount);


    }
return 0;
}
