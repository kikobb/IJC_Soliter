//
// Created by martin on 6.5.2017.
//

#ifndef IJC_SOLITER_TARGETPACK_H
#define IJC_SOLITER_TARGETPACK_H

#include "Color.h"
#include "../../../../../usr/include/jmorecfg.h"
#include "Card.h"
#include "CardDeck.h"

class TargetStack : public CardDeck{
    public:
        bool put(Card*);
    protected:
        Color packColor;
};


#endif //IJC_SOLITER_TARGETPACK_H
