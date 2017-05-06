//
// Created by martin on 6.5.2017.
//

#import "WorkingPack.h"

bool WorkingPack::put(Card *card) {
;
    //podmienka na prazdny stack berie len krala (13)
    if (this->isEmpty()){
        if (card->value() == 13){
            this->put(card);
            return true;
        }
        else
            return false;
    }
    else
    if ((card->value() - this->get()->value()) == -1) {
        if (!ARE_SIMILAR(this->get()->color(), card->color())) {
            this->put(card);
            return true;
        } else
            return false;
    } else
        return false;
}