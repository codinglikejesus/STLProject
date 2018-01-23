#include "ruutu.hh"

Ruutu::Ruutu(int x, int y, bool onkoMiinaa, Lauta* lauta, int arvo, bool onkoAvattu, bool onkoLippua):x_(x), y_(y), onkoMiinaa_(onkoMiinaa), lauta_(lauta), arvo_(arvo), onkoAvattu_(onkoAvattu), onkoLippua_(onkoLippua)
{

}
void Ruutu::tulostaDebug(std::ostream& virta)
{

    virta << onkoMiinaa_;

}

void Ruutu::tulosta(std::ostream& virta)
{
    if(onkoAvattu_ == false){
        virta << ".";
    }
    else if(onkoLippua_ == true){
        virta << "P";
    }
    else{
        virta << arvo_;
    }
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
    if(onkoMiinaa_ == true and onkoLippua_ == true){
        return true;
    }
}

bool Ruutu::onkoLippu()
{
    return onkoLippua_;
}

void Ruutu::lisaaLippu()
{
    if(onkoLippua_ == false){
        onkoLippua_ = true;
    }
}

void Ruutu::poistaLippu()
{

}

bool Ruutu::avaa()
{
    onkoAvattu_ = true;
    if(onkoMiinaa_ == true){

        return false;
    }
    else{
        return true;

    }

}
