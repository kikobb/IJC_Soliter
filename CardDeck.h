//
// Created by xbarna02
//

#ifndef IJC_SOLITER_CARDDECK_H
#define IJC_SOLITER_CARDDECK_H

#include <vector>
#include "Card.h"


class CardDeck {

public:
    static CardDeck * createStandardDeck();
    int size();
    void put(Card *);
    Card* pop();
    Card* get();
    Card* get(int);
    bool isEmpty();

protected:
    std::vector<Card*> deckStack;
};


#endif //IJC_SOLITER_CARDDECK_H
