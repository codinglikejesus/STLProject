#ifndef RUUTU_HH
#define RUUTU_HH

#include <vector>
#include <iostream>
class Ruutu;

using Lauta = std::vector< std::vector< Ruutu > >;

class Ruutu
{
public:
    Ruutu(int x, int y, bool onkoMiinaa, Lauta*, int arvo = 0);
    void tulostaDebug(std::ostream&);
    void tulosta(std::ostream&);
    void laskeViereiset();
    bool onkoValmis();
    bool onkoLippu();
    void poistaLippu();
    void lisaaLippu();
    bool avaa();
    int x_;
    int y_;
    int arvo_;
    Lauta* lauta_;
    bool onkoMiinaa_;
private:


};

#endif // RUUTU_HH
