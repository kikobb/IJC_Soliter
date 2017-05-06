//
// Created by martin on 6.5.2017.
//

#ifndef IJC_SOLITER_TARGETPACK_H
#define IJC_SOLITER_TARGETPACK_H

#include "Color.h"
#include "Card.h"
#include "CardDeck.h"

class TargetStack : public CardDeck{
    public:
        bool put(Card*);
        Color getPackColor();
    protected:
        Color packColor;
};


#endif //IJC_SOLITER_TARGETPACK_H
