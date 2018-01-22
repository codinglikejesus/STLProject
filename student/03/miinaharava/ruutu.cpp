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
    if(x_!=0 and y_ != 0){
        if(lauta_->at(x_-1).at(y_-1).arvo_ == 1){
            ++arvo_;
        }
    }
    if(x_>0 and y_ != 0){
        if(lauta_->at(x_).at(y_-1).arvo_ == 1){
            ++arvo_;
        }
        if(lauta_->at(x_+1).at(y_ -1).arvo_ == 1){
            ++arvo_;
        }

    }
    if(x_!=0 and y_>0){
        if(lauta_->at(x_-1).at(y_+1).arvo_ == 1){
            ++arvo_;
        }
        if(lauta_->at(x_-1).at(y_).arvo_ == 1){
            ++arvo_;
        }

    }


    if(lauta_->at(x_+1).at(y_).arvo_ == 1){
        ++arvo_;
    }

    if(lauta_->at(x_).at(y_+1).arvo_ == 1){
        ++arvo_;
    }
    if(lauta_->at(x_+1).at(y_+1).arvo_ == 1){
        ++arvo_;
    }

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
