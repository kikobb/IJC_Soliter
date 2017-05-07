//
// Created by k on 5.5.2017.
//

#ifndef IJC_SOLITER_CARD_H
#define IJC_SOLITER_CARD_H

#include <string>
#include "Color.h"


class Card {

public:
    Card(int val, Color c); //konstruktor
    Color color();
    int value();
    void turnFaceUp();
    void turnFaceDown();
    void turnOnCard();
    void turnOffCard();
    bool isTurnedFaceUp();
    bool isHighlighted();
    int compareValue(Card c);
    //overload
    bool operator==(Card *c);

    std::string toString();


private:
    int cardValue;
    Color cardColor;
    bool faceDirection;
    bool highlight;
};

#endif //IJC_SOLITER_CARD_H
