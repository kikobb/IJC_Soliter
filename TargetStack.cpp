//
// Created by martin on 6.5.2017.
//

#include "TargetStack.h"

TargetStack::TargetStack(Color color) {packColor = color;}

bool TargetStack::put(Card *card) {

    if (this->isEmpty()){
        if (card->color() == packColor) {
            if (card->value() == 1) {
                this->put(card);
                return true;
            }
        }
    }
    else
    if ((card->value() - this->get()->value()) == 1) {
        if (card->color() == packColor) {
            this->put(card);
            return true;
        }
    }
    return false;
}

//bool TargetStack::put(CardStack * stack) {  }

Color TargetStack::getPackColor() { return packColor;}