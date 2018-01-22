#ifndef RUUTU_HH
#define RUUTU_HH

#include <vector>
#include <iostream>
class Ruutu;

using Lauta = std::vector< std::vector< Ruutu > >;

class Ruutu
{
public:
    Ruutu(int x, int y, int arvo, Lauta*);
    void tulosta(std::ostream&);
    void uusi_ruutu(int x, int y, bool onko_miinaa, Lauta*);
    void laskeViereiset();
    bool onkoValmis();
    bool onkoLippu();
    void poistaLippu();
    void lisaaLippu();
    bool avaa();

};

#endif // RUUTU_HH
