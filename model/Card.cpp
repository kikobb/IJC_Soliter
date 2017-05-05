//
// Created by k on 5.5.2017.
//

#include <cstdlib>
#include "Card.h"

class Card {

public:
    Card(int val, Color c); //konstruktor
    Color color();
    int value();
    void turnFaceUp();
    void turnFaceDown();
    bool isTurnedFaceUp();
    int compareValue(Card c);

private:
    int cardValue;
    Color cardColor;
    bool faceDirection;
};
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

