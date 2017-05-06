//
// Created by martin on 6.5.2017.
//

#ifndef IJC_SOLITER_WORKINGPACK_H
#define IJC_SOLITER_WORKINGPACK_H

#include "CardDeck.h"

class WorkingPack : public CardDeck{
    public:
        bool put(Card*);
};

#endif //IJC_SOLITER_WORKINGPACK_H
