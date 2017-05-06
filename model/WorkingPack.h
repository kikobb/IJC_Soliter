//
// Created by martin on 6.5.2017.
//

#ifndef IJC_SOLITER_WORKINGPACK_H
#define IJC_SOLITER_WORKINGPACK_H

#include "CardDeck.h"
#include "CardStack.h"

class WorkingPack : public CardStack{
    public:
        WorkingPack(CardStack *initStack);
        bool put(Card*);
};

#endif //IJC_SOLITER_WORKINGPACK_H
