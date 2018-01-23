#include "ruutu.hh"

Ruutu::Ruutu(int x, int y, bool onkoMiinaa, Lauta* lauta, int arvo):x_(x), y_(y), onkoMiinaa_(onkoMiinaa), lauta_(lauta), arvo_(arvo)
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
    {

    if(x_!=0 and y_ != 0){
        if(lauta_->at(x_-1).at(y_-1).onkoMiinaa_ == true){
            ++arvo_;
        }
    }
    if(y_ != 0){
        if(lauta_->at(x_).at(y_-1).onkoMiinaa_ == true){
            ++arvo_;
        }
        if(x_ < lauta_->size()-1){
            if(lauta_->at(x_+1).at(y_ -1).onkoMiinaa_ == true){
                ++arvo_;
            }
        }


    }
    if(x_!=0){
        if(y_ < lauta_->at(x_).size()-1){
            if(lauta_->at(x_-1).at(y_+1).onkoMiinaa_ == true){
                ++arvo_;
            }
        }

        if(lauta_->at(x_-1).at(y_).onkoMiinaa_ == true){
           ++arvo_;
        }

    }

    if(x_ < lauta_->size()-1){
        if(lauta_->at(x_+1).at(y_).onkoMiinaa_ == true){
        ++arvo_;
    }
    }
    if(y_ < lauta_->at(x_).size()-1){

        if(lauta_->at(x_).at(y_+1).onkoMiinaa_ == true){
            ++arvo_;
        }
        if(x_ < lauta_->at(x_).size()-1){
            if(lauta_->at(x_+1).at(y_+1).onkoMiinaa_ == true){
            ++arvo_;
            }
        }
    }

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
