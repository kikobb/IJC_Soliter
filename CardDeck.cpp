//
// Created by xbarna02
//

#include <algorithm>
#include "CardDeck.h"

CardDeck * CardDeck::createStandardDeck() {
    CardDeck *retDeck = new CardDeck;
    std::vector<Card *> pom;
    for (int i = GET_FIRST; i <= GET_LAST; ++i) {
        for (int j = 0; j < 14; ++j) {
            pom.push_back(new Card(j, (Color)i));
        }
    }

    std::random_shuffle(pom.begin(), pom.end());

    for (int k = 0; k < pom.size() ; ++k) {
        retDeck->put(pom[k]);
    }
    return retDeck;
}

int CardDeck::size() { return (int)deckStack.size();}

void CardDeck::put(Card * c) {deckStack.push_back(c);}

//todo skontroluj spravnost
Card * CardDeck::pop() {
    Card * ret = deckStack[deckStack.size() - 1];
    deckStack.pop_back();
    return ret;
}

Card* CardDeck::get() { return deckStack[deckStack.size() - 1];}

Card* CardDeck::get(int i) { return deckStack[i];}

//todo skontroluj spravnost
bool CardDeck::isEmpty() { return deckStack.empty();}