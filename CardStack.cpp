/**
 * @file CardStack.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the card stack class.
 */

#include "CardStack.h"

/**
 * Puts the given stack.
 *
 * @param [in,out] stack If non-null, the stack to put.
 *
 * @return True if it succeeds, false if it fails.
 */

bool CardStack::put(CardStack * stack) {
    if (stack == nullptr)
        return false;
    if (stack->isEmpty())
        return true;

    //get nieje pop tj. karta tam ostane
    for (int i = 0; i < stack->size(); i++){
        deckStack.push_back(stack->pop());
    }
    return true;
}

/**
 * Removes and returns the top-of-stack card.
 *
 * @param [in,out] card If non-null, the card to pop.
 *
 * @return if Card == null pop top, else the previous top-of-stack object.
 */

CardStack* CardStack::pop(Card *card) {
    if (card == nullptr) {
        CardStack *tmp = new CardStack();
        tmp->put(this->pop());
        return tmp;
    }
    return takeFrom(card);
}

/** Flushes this object. */
void CardStack::flush() {
    for (int i = this->size(); i > 0; i--){
        this->pop();
    }
}

/**
 * Take from this stack the given card.
 *
 * @param [in,out] card If non-null, the card.
 *
 * @return Null if it fails, else a pointer to a CardStack.
 */

CardStack* CardStack::takeFrom(Card *card) {
    int pos = -1;
    for (int i = 0; i < deckStack.size(); ++i) {
        if (deckStack[i]->value() == card->value() &&
                deckStack[i]->color() == card->color()){
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return nullptr;
    CardStack *retStack = new CardStack;
    for (int i = (int)this->size() - pos; i < deckStack.size(); ++i) {
        retStack->put(this->get(i));
    }

    /** Size of the temporary old */
    int tmpOldSize = this->size();

    for (int i = pos; i < tmpOldSize; ++i) {
        this->pop();
    }

    return retStack;

}
