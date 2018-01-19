#include <string>
#ifndef PLAYER_HH
#define PLAYER_HH

using namespace std;

class Player
{
public:
    Player(string name, int points = 0);
    const string get_name();
    int get_points();
    void add_points(int pts);
    bool has_won();
    int _points;
private:
    string _name;


};

#endif // PLAYER_HH
