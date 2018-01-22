#include "ruutu.hh"

Ruutu::Ruutu(int x, int y, int arvo, Lauta* lauta):x_(x), y_(y), arvo_(arvo), lauta_(lauta)
{

}
void Ruutu::tulostaDebug(std::ostream& virta)
{
    virta << arvo_;
}

void Ruutu::tulosta(std::ostream& virta)
{
    virta << ".";
}

void Ruutu::laskeViereiset()
{

}


bool Ruutu::onkoValmis()
{

}

bool Ruutu::onkoLippu()
{

}

void Ruutu::lisaaLippu()
{

}

void Ruutu::poistaLippu()
{

}

bool Ruutu::avaa()
{

}
