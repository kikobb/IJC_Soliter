//
// Created by k on 5.5.2017.
//

#include <cstdlib>
#include "Card.h"
#include "Color.h"

//konstruktor
Card::Card(int val, Color c){
    cardValue = val;
    cardColor = c;
}

void Card::turnFaceUp() {faceDirection = true;}

void Card::turnFaceDown() {faceDirection = false;}

int Card::compareValue(Card c) {
    if (cardValue == c.value())
        return 0;
    else
        return std::abs(cardValue - c.value());
}

//getters
Color Card::color() { return cardColor;}

int Card::value() {return cardValue;}

bool Card::isTurnedFaceUp() {return faceDirection;}

