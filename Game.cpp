//
// Created by xbarna02
//

#include "Game.h"
#include "History.h"
#include "Help.h"

//constructor
Game::Game() {
    pullStack = CardDeck::createStandardDeck();
    initTargetStacks();
    fillWorkingPacks(pullStack);
    swapStack = new CardDeck();
    history = new History;
    help = new Help(this);
    achvdHeplNmbr = 0;
}

void Game::fillWorkingPacks(CardDeck *deck) {
    CardStack *tmpStack = new CardStack;

    for (int i = 0; i < 7; ++i) {
        tmpStack->flush();
        for (int j = 0; j < i; ++j) {
            tmpStack->put(deck->pop());
        }
        workingPacks[i] = new WorkingPack(tmpStack);
        workingPacks[i]->get()->turnFaceUp();
    }
}

void Game::initTargetStacks() {
    for (int i = GET_FIRST; i <= GET_LAST ; ++i) {
        targetStacks[i] = new TargetStack((Color)i);
    }
}

bool Game::turnPullStack() {
    if (!pullStack->isEmpty()) {
        swapStack->put(pullStack->pop());
        swapStack->get()->turnFaceUp();
    }
    else
        if (!swapStack->isEmpty())
            for (int i = swapStack->size(); i > 0 ; --i) {
                pullStack->put(swapStack->pop());
                pullStack->get()->turnFaceDown();
            }
        else
            return false;
    return true;
}

bool Game::reverseTurnPullStack() {
    if (!swapStack->isEmpty()) {
        pullStack->put(swapStack->pop());
        pullStack->get()->turnFaceDown();
    }
    else
        if (!pullStack->isEmpty())
            for (int i = pullStack->size(); i > 0; --i) {
                swapStack->put(pullStack->pop());
                swapStack->get()->turnFaceUp();
            }
        else
            return false;
    return true;
}

//getters
WorkingPack* Game::getWorkingPack(int i) { return workingPacks[i];}

TargetStack* Game::getTargetStack(int i) { return targetStacks[i];}

CardDeck* Game::getSwapStack() { return swapStack;}

History* Game::getHistory() { return history;}

helpData* Game::helper() {
    return help->help();
}


bool Game::isPullStackEmpty() { return pullStack->isEmpty();}

//setter
void Game::resetHelp(){help->resetHelp();}


