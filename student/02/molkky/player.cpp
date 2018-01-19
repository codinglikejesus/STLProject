#include "player.hh"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, int points):
    _name(name), _points(points){
}

const string Player::get_name(){
    return _name;
}

int Player::get_points(){
    return _points;
}

void Player::add_points(int pts){
    _points += pts;
    if(_points > 50){
        _points = 25;
        cout << get_name() << " gets penalty points!";
    }
}

bool Player::has_won(){
    if(_points == 50){
        return true;
    }
    else
        return false;

}
