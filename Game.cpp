/**
 * @file Game.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the game class.
 */

#include "Game.h"
#include "History.h"
#include "Help.h"

/** Default constructor. */
Game::Game() {
    pullStack = CardDeck::createStandardDeck();
    initTargetStacks();
    fillWorkingPacks(pullStack);
    swapStack = new CardDeck();
    history = new History;
    help = new Help(this);
    achvdHeplNmbr = 0;
}

Game::Game(CardDeck *pull, CardDeck *swap, TargetStack *target[4], WorkingPack *working[7]) {
    pullStack = pull;
    swapStack = swap;
    for (int i = 0; i < 4; ++i) {
        targetStacks[i] = target[i];
    }
    for (int i = 0; i < 7; ++i) {
        workingPacks[i] = working[i];
    }
}


/**
 * Fill working packs.
 *
 * @param [in,out] deck If non-null, the deck.
 */

void Game::fillWorkingPacks(CardDeck *deck) {
    CardStack *tmpStack = new CardStack;

    for (int i = 0; i < 7; ++i) {
        tmpStack->flush();
        for (int j = 0; j <= i; ++j) {
            tmpStack->put(deck->pop());
        }
        workingPacks[i] = new WorkingPack(tmpStack);
        workingPacks[i]->get()->turnFaceUp();
    }
}

/** Initializes the target stacks. */
void Game::initTargetStacks() {
    for (int i = GET_FIRST; i <= GET_LAST ; ++i) {
        targetStacks[i] = new TargetStack((Color)i);
    }
}

/**
 * Determines if we can turn pull stack.
 *
 * @return True if it succeeds, false if it fails.
 */

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

/**
 * Determines if we can reverse turn pull stack.
 *
 * @return True if it succeeds, false if it fails.
 */

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

/**
 * Gets working pack.
 *
 * @param i Zero-based index of the working packs.
 *
 * @return Null if it fails, else the working pack.
 */

WorkingPack* Game::getWorkingPack(int i) { return workingPacks[i];}

/**
 * Gets target stack.
 *
 * @param i Zero-based index of the  target stacks.
 *
 * @return Null if it fails, else the target stack.
 */

TargetStack* Game::getTargetStack(int i) { return targetStacks[i];}

/**
 * Gets swap stack.
 *
 * @return Null if it fails, else the swap stack.
 */

CardDeck* Game::getSwapStack() { return swapStack;}

CardDeck* Game::getPullStack() { return pullStack;}

/**
 * Gets the history.
 *
 * @return Null if it fails, else the history.
 */

History* Game::getHistory() { return history;}

/**
 * Gets the helper.
 *
 * @return Null if it fails, else a pointer to a helpData.
 */

helpData* Game::helper() {
    return help->help();
}

/**
 * Queries if the pull stack is empty.
 *
 * @return True if the pull stack is empty, false if not.
 */

bool Game::isPullStackEmpty() { return pullStack->isEmpty();}

/** Resets the help. */
void Game::resetHelp(){help->resetHelp();}


