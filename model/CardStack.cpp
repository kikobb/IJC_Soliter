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
        deckStack.push_back(stack->pop(()8));
        deckStack;
        deckStack.push_back();
    }
    return true;
}
