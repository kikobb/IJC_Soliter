/**
 * @file Card.h.
 *
 * @author xbarna02
 * 		   
 * Declares the card class.
 */

#ifndef IJC_SOLITER_CARD_H
#define IJC_SOLITER_CARD_H

#include <string>
#include "Color.h"


/** A card. */
class Card {

public:

    /**
     * Constructor.
     *
     * @param val The value.
     * @param c   A Color to process.
     */

    Card(int val, Color c); //konstruktor
    Card(std::string *);//alternativny konstruktor
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
    bool operator==(const Card *c);

    std::string toString();


private:
    int cardValue;
    Color cardColor;
    bool faceDirection;
    bool highlight;
};

#endif //IJC_SOLITER_CARD_H
