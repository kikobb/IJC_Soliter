//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_GAME_H
#define IJC_SOLITER_GAME_H


#include "../model/CardDeck.h"
#include "../model/TargetStack.h"
#include "../model/WorkingPack.h"
//#include "History.h"
//#include "Help.h"

enum boardElements{
    pullStackT,
    swapStackT,
    workingPackT,
    targetStackT,
    gameBoard
};

//forward declaration
class History;
class Help;

class Game {

private:
    CardDeck *pullStack;
    CardDeck *swapStack;
    TargetStack *targetStacks[4];
    WorkingPack *workingPacks[7];

    History *history;
    Help *help;

    void fillWorkingPacks(CardDeck *deck);
    void initTargetStacks();

public:
    int achvdHeplNmbr;
    Game(); //konstruktor
    bool turnPullStack();
    bool reverseTurnPullStack();
    //getters
    WorkingPack* getWorkingPack(int);
    TargetStack* getTargetStack(int);
    CardDeck* getSwapStack();
    bool isPullStackEmpty();
    History* getHistory();

    //bool Help();
    void resetHelp();

};


#endif //IJC_SOLITER_GAME_H
