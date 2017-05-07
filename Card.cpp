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
    faceDirection = false;
    highlight = false;
}

void Card::turnFaceUp() {faceDirection = true;}

void Card::turnFaceDown() {faceDirection = false;}

int Card::compareValue(Card c) {
    if (cardValue == c.value())
        return 0;
    else
        return std::abs(cardValue - c.value());
}

void Card::turnOnCard() {highlight = true;}

void Card::turnOffCard() {highlight = false;}

//getters
Color Card::color() { return cardColor;}

int Card::value() {return cardValue;}

bool Card::isTurnedFaceUp() {return faceDirection;}

bool Card::isHighlighted() { return highlight; }

std::string Card::toString() {
    std::string output;

    switch (this->value()){
        case 13: output + "K"; break;
        case 12: output + "Q"; break;
        case 11: output + "J"; break;
        case 1: output + "A"; break;
        default: output + (char)('0' + this->value()); break;
    }
    output + " ";
    switch (this->color()){
        case SPADES: output + "(S)"; break;
        case CLUBS: output + "(C)"; break;
        case DIAMONDS: output + "(D)"; break;
        case HEARTS: output + "(H)"; break;
    }

    return output;
}

bool Card::operator==(Card *c){
    return (this->value() == c->value() && this->color() == c->color());
}


