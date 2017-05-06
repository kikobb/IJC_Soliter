//
// Created by k on 5.5.2017.
//

#ifndef IJC_SOLITER_CARD_H
#define IJC_SOLITER_CARD_H

#include "Color.h"

//todo daj to do common header

class Card {

public:
    Card(int val, Color c); //konstruktor
    Color color();
    int value();
    void turnFaceUp();
    void turnFaceDown();
    bool isTurnedFaceUp();
    int compareValue(Card c);
    //overload
    bool operator==(Card *c);


private:
    int cardValue;
    Color cardColor;
    bool faceDirection;
};

#endif //IJC_SOLITER_CARD_H
