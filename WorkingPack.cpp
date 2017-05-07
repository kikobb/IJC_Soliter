/**
 * @file WorkingPack.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the working pack class.
 */

#include "WorkingPack.h"

/**
 * Constructor.
 *
 * @param [in,out] initStack If non-null, stack of initializes.
 */

WorkingPack::WorkingPack(CardStack *initStack) {
    for (int i = 0; i < initStack->size() ; ++i) {
        deckStack.push_back(initStack->get(i));
    }
}

/**
 * Puts the given card to working pack.
 *
 * @param [in,out] card If non-null, the card to put.
 *
 * @return True if it succeeds, false if it fails.
 */

bool WorkingPack::put(Card *card) {
    //podmienka na prazdny stack berie len krala (13)
    if (this->isEmpty()){
        if (card->value() == 13){
            this->put(card);
            return true;
        }
        else
            return false;
    }
    else
    if ((card->value() - this->get()->value()) == -1) {
        if (!ARE_SIMILAR(this->get()->color(), card->color())) {
            this->put(card);
            return true;
        } else
            return false;
    } else
        return false;
}

/**
 * Puts the given stack to working pack.
 *
 * @param [in,out] stack If non-null, the stack to put.
 *
 * @return True if it succeeds, false if it fails.
 */

bool WorkingPack::put(CardStack * stack) {
    if (stack == nullptr)
        return false;
    //osetrenie na krala
    if(this->isEmpty()){
        if (stack->get()->value() == 13){
            for (int i = 0; i < stack->size(); ++i) {
                this->put(stack->get(i));
            }
            return true;
        } else
            return false;
    } else if ((stack->get()->value() - this->get()->value()) == -1){
        if (!ARE_SIMILAR(stack->get()->color(), this->get()->color())){
            for (int i = 0; i < stack->size(); ++i) {
                this->put(stack->get(i));
            }
            return true;
        } else
            return false;
    } else
        return false;
}

/**
 * Gets a card stack* using the given card.
 *
 * @param [in,out] card If non-null, the card to get.
 *
 * @return Null if it fails, else a pointer to a CardStack.
 */

CardStack* WorkingPack::get(Card * card) { return takeFrom(card);}

/**
 * Force put one card
 *
 * @param [in,out] card If non-null, the card.
 */

void WorkingPack::forcePut(Card *card) {
    deckStack.push_back(card);
}

/**
 * Force put whole stack.
 *
 * @param [in,out] stack If non-null, the stack.
 */

void WorkingPack::forcePut(CardStack *stack) {
    for (int i = 0; i < stack->size(); ++i) {
        deckStack.push_back(stack->get(i));
    }
}

/**
 * Take from working pack.
 *
 * @param [in,out] card If non-null, the card.
 *
 * @return Null if it fails, else a pointer to a CardStack.
 */

CardStack* WorkingPack::takeFrom(Card * card) {
    int pos = -1;
    for (int i = 0; i < this->size(); ++i) {
        if (this->get(i)->value() == card->value() &&
            this->get(i)->color() == card->value()){
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return nullptr;
    CardStack *retStack = new CardStack;
    for (int i = this->size() - pos; i < this->size(); ++i) {
        retStack->put(this->get(i));
    }
    return retStack;
}