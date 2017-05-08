/**
 * @file CardDeck.h.
 *
 * @author xbarna02
 * 		   
 * Declares the card deck class.
 */

#ifndef IJC_SOLITER_CARDDECK_H
#define IJC_SOLITER_CARDDECK_H

#include <vector>
#include "Card.h"


/** A card deck. */
class CardDeck {

public:
    static CardDeck * createStandardDeck();
    int size();
    void put(Card *);
    virtual Card* pop();
    Card* get();
    Card* get(int);
    bool isEmpty();

protected:
    std::vector<Card*> deckStack;
};


#endif //IJC_SOLITER_CARDDECK_H
