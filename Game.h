/**
 * @file C:\Users\jaime\Desktop\IJC_Soliter-master\Game.h.
 *
 * @author xbarna02
 * 
 * Declares the game class.
 */

#ifndef IJC_SOLITER_GAME_H
#define IJC_SOLITER_GAME_H


#include "CardDeck.h"
#include "TargetStack.h"
#include "WorkingPack.h"

/** Values that represent board elements. */
enum boardElements{
    pullStackT,
    swapStackT,
    workingPackT,
    targetStackT,
    gameBoard
};

/** forward declaration. */
class History;
class Help;
struct helpData;

/** A game. */
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

    helpData* helper();
    void resetHelp();

};


#endif //IJC_SOLITER_GAME_H
