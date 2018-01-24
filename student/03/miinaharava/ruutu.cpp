#include "ruutu.hh"

//Uuden ruudun alustus
Ruutu::Ruutu(int x, int y, bool onkoMiinaa, Lauta* lauta, int arvo, bool onkoAvattu, bool onkoLippua):x_(x), y_(y), onkoMiinaa_(onkoMiinaa), lauta_(lauta), arvo_(arvo), onkoAvattu_(onkoAvattu), onkoLippua_(onkoLippua)
{

}

//Palauttaa virralle arvon
void Ruutu::tulosta(std::ostream& virta)
{
    //Tarkistaa onko ruutu avattu ja palauttaa P jos siinä on lippu
    if(onkoAvattu_ == false){
        if(onkoLippua_ == true){
            virta << "P";
        }
        else{
            virta << ".";
        }
    }
    else{
        //Tarkistaa onko miinaa
        if(onkoMiinaa_ == true){
            virta << "*";
        }
        //Palauttaa viereisten miinojen lukumaaran
        else{
            virta << arvo_;
        }


    }


}

//Kay jokaisen ruudun ymparilla olevan ruudun ja lisaa +1 _arvo:oon jos on. Lisaksi,
//tarkistetaan etta ruutu ei sijaitse laudan reunoilla indeksivirheiden valttamiseksi
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
//Palauttaa true jos ruudussa on merkitty miina tai jos ruudussa ei ole miinaa eika vaaraa lippua.
bool Ruutu::onkoValmis()
{
    if(onkoMiinaa_ == true and onkoLippua_ == true){
        return true;
    }
    else if(onkoMiinaa_ == false and onkoLippua_ == false){
        return true;

    }
    else{
        return false;
    }
}
//Palauttaa kutsutun ruudun onkoLippua_ arvon
bool Ruutu::onkoLippu()
{
    return onkoLippua_;
}
//Muuttaa kutsutun ruudun onkoLippua_ arvon
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
//Aluksi metodi muuttaa ruudun onkoAvattu_ arvon todeksi. Jos Ruudussa on miina palauttaa false ja peli loppuu. Muuten
//tarkistaa onko avatun ruudun arvo == 0, jolloin avataan viereiset ruudut jotka eivat ole avattuja ja eivat ole miinoja, samalla tavalla
//kuin laskeViereiset(). Avatut ruudut avataan uudestaan Ruutu::avaa() metodin avulla. Lopulta metodi palauttaa arvon true ja peli jatkuu.
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
