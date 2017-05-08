/**
 * @file Card.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the card class.
 */

#include <cstdlib>
#include <exception>
#include <string>
#include <locale>
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

/**
 * Alternative Constructor.
 *
 * @param input The value and Color to process.
 */
Card::Card(std::string *input){
    int pomVal = 0;
    Color pomColor;

    if (input->size() != 4 || input->substr(1, 1) != "(" || input->substr(3, 1) != ")")
        throw -1;

    //val
    if (atoi(input->substr(0, 1).c_str()) > 1 && atoi(input->substr(0, 1).c_str()) < 11)
        pomVal = atoi(input->substr(0, 1).c_str());
    else if (input->substr(0, 1) == "A" || input->substr(0, 1) == "a")
            pomVal = 1;
        else if (input->substr(0, 1) == "K" || input->substr(0, 1) == "k")
                pomVal = 13;
            else if (input->substr(0, 1) == "Q" || input->substr(0, 1) == "q")
                    pomVal = 12;
                else if (input->substr(0, 1) == "J" || input->substr(0, 1) == "j")
                        pomVal = 11;
                    else
                        throw -1;

    //color
    if (input->substr(2, 1) == "C" || input->substr(0, 1) == "c")
        pomColor = CLUBS;
    else if (input->substr(2, 1) == "D" || input->substr(0, 1) == "d")
            pomColor = DIAMONDS;
        else if (input->substr(2, 1) == "H" || input->substr(0, 1) == "h")
                pomColor = HEARTS;
            else if (input->substr(2, 1) == "S" || input->substr(0, 1) == "s")
                    pomColor = SPADES;
                else
                    throw -1;

    cardValue = pomVal;
    cardColor = pomColor;
    faceDirection = false;
    highlight = false;
}

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
 * Equality operator. Find out if this card is the same as card from param.
 *
 * @param [in,out] c If non-null, a Card to process.
 *
 * @return True if the parameters are considered equivalent.
 */

bool Card::operator==(const Card *c){
    return (this->value() == c->cardValue && this->color() == c->cardColor);
}


