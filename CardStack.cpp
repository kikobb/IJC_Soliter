//
// Created by xbarna02
//


#include "CardStack.h"

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

CardStack* CardStack::pop(Card *card) {
    return takeFrom(card);
}

void CardStack::flush() {
    for (int i = this->size(); i > 0; i--){
        this->pop();
    }
}

CardStack* CardStack::takeFrom(Card *card) {
    int pos = -1;
    for (int i = 0; i < deckStack.size(); ++i) {
        if (deckStack[i]->value() == card->value() &&
                deckStack[i]->color() == card->value()){
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

    int tmpOldSize = this->size();

    for (int i = this->size(); i < tmpOldSize; ++i) {
        this->pop();
    }

    return retStack;

}
