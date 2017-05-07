/**
 * @file TargetStack.h.
 *
 * @author xuhlia03
 * 
 * Declares the target stack class.
 */

#ifndef IJC_SOLITER_TARGETPACK_H
#define IJC_SOLITER_TARGETPACK_H


#include "CardStack.h"

class TargetStack : public CardDeck{
public:
    TargetStack(Color);
    bool put(Card *);
    //bool put(CardStack *);
    Color getPackColor();

protected:
    Color packColor;
};


#endif //IJC_SOLITER_TARGETPACK_H
