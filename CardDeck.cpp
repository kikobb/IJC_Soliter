/**
 * @file CardDeck.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the card deck class.
 */

#include <algorithm>
#include "CardDeck.h"

/**
 * Creates standard deck.
 *
 * @return Null if it fails, else the new standard deck.
 */

CardDeck * CardDeck::createStandardDeck() {
    CardDeck *retDeck = new CardDeck;
    std::vector<Card *> pom;
    for (int i = GET_FIRST; i <= GET_LAST; ++i) {
        for (int j = 1; j < 14; ++j) {
            pom.push_back(new Card(j, (Color)i));
        }
    }

    std::random_shuffle(pom.begin(), pom.end());

    for (int k = 0; k < pom.size() ; ++k) {
        retDeck->put(pom[k]);
    }
    return retDeck;
}

/**
 * Gets the size of this deck.
 *
 * @return A size of this deck.
 */

int CardDeck::size() { return (int)deckStack.size();}

/**
 * Puts the given card.
 *
 * @param [in,out] c If non-null, the card to put.
 */

void CardDeck::put(Card * c) {deckStack.push_back(c);}

/**
 * Removes and returns the top-of-stack.
 *
 * @return Null if it fails, else the previous top-of-stack card.
 */

Card * CardDeck::pop() {
    Card * ret = deckStack[deckStack.size() - 1];
    deckStack.pop_back();
    return ret;
}

/**
 * Gets the card from top.
 *
 * @return Null if it fails, else a pointer to a Card.
 */

Card* CardDeck::get() { return deckStack[deckStack.size() - 1];}

/**
 * Gets a card* using the given index.
 *
 * @param i The iindex to get.
 *
 * @return Null if it fails, else a pointer to a Card.
 */

Card* CardDeck::get(int i) { return deckStack[i];}

/**
 * Query if this deck is empty.
 *
 * @return True if empty, false if not.
 */

bool CardDeck::isEmpty() { return deckStack.empty();}