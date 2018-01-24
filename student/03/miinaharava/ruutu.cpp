#include "ruutu.hh"

Ruutu::Ruutu(int x, int y, bool onkoMiinaa, Lauta* lauta, int arvo, bool onkoAvattu, bool onkoLippua):x_(x), y_(y), onkoMiinaa_(onkoMiinaa), lauta_(lauta), arvo_(arvo), onkoAvattu_(onkoAvattu), onkoLippua_(onkoLippua)
{

}
void Ruutu::tulostaDebug(std::ostream& virta)
{
    if(onkoMiinaa_ == true){
        virta << "x";
        }
    else{
        virta << arvo_;
    }

}

void Ruutu::tulosta(std::ostream& virta)
{
    if(onkoAvattu_ == false){
        if(onkoLippua_ == true){
            virta << "P";
        }
        else{
            virta << ".";
        }
    }
    else{
        if(onkoMiinaa_ == true){
            virta << "*";
        }
        else{
            virta << arvo_;
        }


    }


}

void Ruutu::laskeViereiset()
{
    {

    if(x_!=0 and y_ != 0){
        if(lauta_->at(y_-1).at(x_-1).onkoMiinaa_ == true){
            ++arvo_;
        }
    }
    if(y_ != 0){
        if(lauta_->at(y_-1).at(x_).onkoMiinaa_ == true){
            ++arvo_;
        }
        if(x_ < lauta_->size()-1){
            if(lauta_->at(y_ -1).at(x_+1).onkoMiinaa_ == true){
                ++arvo_;
            }
        }


    }
    if(x_!=0){
        if(y_ < lauta_->at(x_).size()-1){
            if(lauta_->at(y_+1).at(x_-1).onkoMiinaa_ == true){
                ++arvo_;
            }
        }

        if(lauta_->at(y_).at(x_-1).onkoMiinaa_ == true){
           ++arvo_;
        }

    }

    if(x_ < lauta_->size()-1){
        if(lauta_->at(y_).at(x_+1).onkoMiinaa_ == true){
        ++arvo_;
    }
    }
    if(y_ < lauta_->at(x_).size()-1){

        if(lauta_->at(y_+1).at(x_).onkoMiinaa_ == true){
            ++arvo_;
        }
        if(x_ < lauta_->at(x_).size()-1){
            if(lauta_->at(y_+1).at(x_+1).onkoMiinaa_ == true){
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
    else if(onkoMiinaa_ == false and onkoLippua_ == false){

    }
    else{
        return false;
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
    if(onkoLippua_ == true){
        onkoLippua_= false;
    }
}

bool Ruutu::avaa()
{
    onkoAvattu_ = true;
    if(onkoMiinaa_ == true){

        return false;
    }
    else if(arvo_ == 0){
        if(x_!=0 and y_ != 0){
            if(lauta_->at(y_-1).at(x_-1).onkoMiinaa_ == false and lauta_->at(y_-1).at(x_-1).onkoAvattu_ == false){
                lauta_->at(y_-1).at(x_-1).avaa();
            }
        }
        if(y_ != 0){
            if(lauta_->at(y_-1).at(x_).onkoMiinaa_ == false and lauta_->at(y_-1).at(x_).onkoAvattu_ == false){
                lauta_->at(y_-1).at(x_).avaa();
            }
            if(x_ < lauta_->size()-1){
                if(lauta_->at(y_ -1).at(x_+1).onkoMiinaa_ == false and lauta_->at(y_ -1).at(x_+1).onkoAvattu_ == false){
                    lauta_->at(y_ -1).at(x_+1).avaa();
                }
            }


        }
        if(x_!=0){
            if(y_ < lauta_->at(x_).size()-1){
                if(lauta_->at(y_+1).at(x_-1).onkoMiinaa_ == false and lauta_->at(y_+1).at(x_-1).onkoAvattu_ == false){
                    lauta_->at(y_+1).at(x_-1).avaa();
                }
            }

            if(lauta_->at(y_).at(x_-1).onkoMiinaa_ == false and lauta_->at(y_).at(x_-1).onkoAvattu_ == false){
               lauta_->at(y_).at(x_-1).avaa();
            }

        }

        if(x_ < lauta_->size()-1){
            if(lauta_->at(y_).at(x_+1).onkoMiinaa_ == false and lauta_->at(y_).at(x_+1).onkoAvattu_ == false){
                lauta_->at(y_).at(x_+1).avaa();
        }
        }
        if(y_ < lauta_->at(x_).size()-1){

            if(lauta_->at(y_+1).at(x_).onkoMiinaa_ == false and lauta_->at(y_+1).at(x_).onkoAvattu_ == false){
                lauta_->at(y_+1).at(x_).avaa();
            }
            if(x_ < lauta_->at(x_).size()-1){
                if(lauta_->at(y_+1).at(x_+1).onkoMiinaa_ == false and lauta_->at(y_+1).at(x_+1).onkoAvattu_ == false){
               lauta_->at(y_+1).at(x_+1).avaa();
                }
            }
        }
        return true;
        }



    else{
        return true;
}

}
