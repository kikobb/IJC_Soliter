//
// Created by xuhlia03
//

#include "WorkingPack.h"

WorkingPack::WorkingPack(CardStack *initStack) {
    for (int i = 0; i < initStack->size() ; ++i) {
        deckStack.push_back(initStack->get(i));
    }
}

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

CardStack* WorkingPack::get(Card * card) { return takeFrom(card);}

void WorkingPack::forcePut(Card *card) {
    deckStack.push_back(card);
}

void WorkingPack::forcePut(CardStack *stack) {
    for (int i = 0; i < stack->size(); ++i) {
        deckStack.push_back(stack->get(i));
    }
}

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