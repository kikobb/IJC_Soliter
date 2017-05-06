//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_GAME_H
#define IJC_SOLITER_GAME_H


#include "../model/CardDeck.h"
#include "../model/TargetStack.h"
#include "History.h"
#include "Help.h"
#include "../model/WorkingPack.h"

enum boardElements{
    pullStackT,
    swapStackT,
    workingPackT,
    targetStackT,
    gameBoard
};

class Game {

protected:
    CardDeck *pullStack;
    CardDeck *swapStack;
    TargetStack *targetStacks[4];
    WorkingPack *workingPacks[7];

    History *history;
    Help *help;

public:
    Game(); //konstruktor
    bool turnPullStack();
    bool reverseTurnPullStack();
    //getters
    WorkingPack* getWorkingPack(int);
    TargetStack* getTargetStack(int);
    CardDeck* getSwapStack();

private:
    void fillWorkingPacks(CardDeck *deck);
    void initTargetStacks();
};


#endif //IJC_SOLITER_GAME_H
