//
// Created by xbarna02
//

#ifndef IJC_SOLITER_CARDSTACK_H
#define IJC_SOLITER_CARDSTACK_H


#include "CardDeck.h"

class CardStack : public CardDeck{

public:
    bool put(CardStack * stack);
    using CardDeck::put;
    CardStack* pop(Card * card);
    using CardDeck::pop;
    void flush();

private:
    CardStack* takeFrom(Card *card);

};


#endif //IJC_SOLITER_CARDSTACK_H
