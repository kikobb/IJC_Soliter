//
// Created by k on 5.5.2017.
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

CardStack CardStack::pop(Card *card) {
    return takeFrom(card);
}

void CardStack::flush() {
    for (int i = this->size(); i > 0; i--){
        this->pop();
    }
}

CardStack* CardStack::takeFrom(Card *card) {
    int pos = deckStack.
}
