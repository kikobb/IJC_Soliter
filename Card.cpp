/**
 * @file Card.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the card class.
 */

#include <cstdlib>
#include "Card.h"
#include "Color.h"

/**
 * Constructor.
 *
 * @param val The value.
 * @param c   A Color to process.
 */

Card::Card(int val, Color c){
    cardValue = val;
    cardColor = c;
    faceDirection = false;
    highlight = false;
}

/** Turn card face up. */
void Card::turnFaceUp() {faceDirection = true;}

/** Turn card face down. */
void Card::turnFaceDown() {faceDirection = false;}

/**
 * Compare this card to another.
 *
 * @param c A Card to compare.
 *
 * @return An difference between cards values
 */

int Card::compareValue(Card c) {
    if (cardValue == c.value())
        return 0;
    else
        return std::abs(cardValue - c.value());
}

/** Turn on card. */
void Card::turnOnCard() {highlight = true;}

/** Turn off card. */
void Card::turnOffCard() {highlight = false;}

/**
 * Gets the color.
 *
 * @return A Color.
 */

Color Card::color() { return cardColor;}

/**
 * Gets the value.
 *
 * @return An int.
 */

int Card::value() {return cardValue;}

/**
 * Query if this object is turned face up.
 *
 * @return True if turned face up, false if not.
 */

bool Card::isTurnedFaceUp() {return faceDirection;}

/**
 * Query if this object is highlighted.
 *
 * @return True if highlighted, false if not.
 */

bool Card::isHighlighted() { return highlight; }

/**
 * Convert this object into a string representation.
 *
 * @return A std::string that represents this object.
 */

std::string Card::toString() {
    /** The output */
    std::string output;

    switch (this->value()){
        case 13: output.append("K"); break;
        case 12: output.append("Q"); break;
        case 11: output.append("J"); break;
        case 1: output.append("A"); break;
        default: output.append(std::to_string(this->value())); break;
    }
    output + " ";

    switch (this->color()){
        case SPADES: output.append("(S)"); break;
        case CLUBS: output.append("(C)"); break;
        case DIAMONDS: output.append("(D)"); break;
        case HEARTS: output.append("(H)"); break;
    }

    return output;
}

/**
 * Equality operator. Find out if this card is the same as card from param.
 *
 * @param [in,out] c If non-null, a Card to process.
 *
 * @return True if the parameters are considered equivalent.
 */

bool Card::operator==(Card *c){
    return (this->value() == c->value() && this->color() == c->color());
}


