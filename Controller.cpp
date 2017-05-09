/**
 * @file Controller.cpp.
 * 
 * @author xbarna02
 * 
 * Implements the controller class.
 */

#include <iostream>
#include "Controller.h"
#include "Card.h"


/**
 * Constructor.
 *
 * @param [in,out] g If non-null, a Game to process.
 * @param [in,out] v If non-null, the ViewAbstractClass to process.
 */

Controller::Controller(Game *g, ViewAbstractClass* v) {game = g; view = v;}

/**
 * Mooves card or cards from source to destination.
 *
 * @param 		   src		   Source of the card.
 * @param 		   srcIndex    Zero-based index of the source card.
 * @param 		   dest		   Destination for the card(s).
 * @param 		   destIndex   Zero-based index for the destination.
 * @param [in,out] payloadHead If non-null, the payload head.
 */

bool Controller::move(boardElements src, int srcIndex, boardElements dest,
                      int destIndex, Card *payloadHead, bool histBlock) {

    //flag pre historiu
    bool lastTurnUp = false;
    bool mooveSuccesfull = false;

    //pullSatck klik (prehodi odkaldaci balicek)
    if (src == pullStackT && dest == pullStackT){
        game->turnPullStack();
        view->refresh(game->getSwapStack());
        if (game->isPullStackEmpty() || game->getSwapStack()->isEmpty())
            view->refresh();
        mooveSuccesfull = true;
    }

    // swap to tergetStack
    if (src == swapStackT && dest == targetStackT){
        if (game->getSwapStack()->isEmpty())
            return false;
        //ak sa to uspesne presunie
        if (game->getTargetStack(destIndex)->put(game->getSwapStack()->get())){
            game->getSwapStack()->pop();
            view->refresh(game->getTargetStack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getSwapStack());

        if (mooveSuccesfull)
            checkForEnd();
    }

    //swap to workingPack
    if (src == swapStackT && dest == workingPackT){
        if (game->getSwapStack()->isEmpty())
            return false;
        //uspesne presunutie
        if (game->getWorkingPack(destIndex)->put(game->getSwapStack()->get())){
            game->getSwapStack()->pop();
            view->refresh(game->getWorkingPack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getSwapStack());
    }

    //targetStack to workingPack
    if (src == targetStackT && dest == workingPackT){
        if (game->getTargetStack(srcIndex)->isEmpty())
            return false;
        //uspesne presunutie
        if (game->getWorkingPack(destIndex)->put(game->getTargetStack(srcIndex)->get())){
            game->getTargetStack(srcIndex)->pop();
            view->refresh(game->getWorkingPack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getTargetStack(srcIndex), srcIndex);
    }

    //workingPack to targetStack
    if (src == workingPackT && dest == targetStackT){
        //ak je prazdny
        if (game->getWorkingPack(srcIndex)->isEmpty())
            return false;
        //kvoli moznosti null v payloadHead
        bool test;
        if (payloadHead == nullptr)
            test = true;
        else
            test = *game->getWorkingPack(srcIndex)->get() == payloadHead;
        //uspesne presunutie (iba jedna karta (ta co je navrchu) a je to validne)
        if ((payloadHead == nullptr || test) &&
                game->getTargetStack(destIndex)->put(game->getWorkingPack(srcIndex)->get())
                ){
            game->getWorkingPack(srcIndex)->pop();
            //flag pre historiu
            //pozri vi to nebola posledna karta (tac o sa popla)
            if (game->getWorkingPack(srcIndex)->size() != 0) {
                lastTurnUp = !game->getWorkingPack(srcIndex)->get()->isTurnedFaceUp();
                game->getWorkingPack(srcIndex)->get()->turnFaceUp();
            }
            view->refresh(game->getTargetStack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getWorkingPack(srcIndex), srcIndex);

        if (mooveSuccesfull)
            checkForEnd();
    }

    //workingPack to workingPack
    if (src == workingPackT && dest == workingPackT){
        //uspesne presunutir
        //otocenia kary
        if (game->getWorkingPack(destIndex)->put(game->getWorkingPack(srcIndex)->get(payloadHead))) {
            game->getWorkingPack(srcIndex)->pop(payloadHead);
            //flag pre historiu
            //pozri vi to nebola posledna karta (tac o sa popla)
            if (game->getWorkingPack(srcIndex)->size() != 0) {
                lastTurnUp = !game->getWorkingPack(srcIndex)->get()->isTurnedFaceUp();
                game->getWorkingPack(srcIndex)->get()->turnFaceUp();
            }
            view->refresh(game->getWorkingPack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getWorkingPack(srcIndex), srcIndex);
    }

    if (src == gameBoard && dest == gameBoard){
        view->refresh();
        view->refresh();
    }

    //ulozenie historie
    if (mooveSuccesfull) {
        game->resetHelp();
        if (!histBlock)
            game->getHistory()->recordMove(src, srcIndex, dest, destIndex, payloadHead, lastTurnUp);
        return true;
    }

    return false;
}

/** Roll back. */
void Controller::rollBack() {
    histElement* histPoint = game->getHistory()->rollBack();
    if (histPoint == nullptr) {
        move(gameBoard, 0, gameBoard, 0);
        return;
    }
    timeTravel(histPoint);

}

/** Roll forward. */
void Controller::rollForward() {
    histElement* histPoint = game->getHistory()->rollForward();
    if (histPoint == nullptr){
        move(gameBoard, 0, gameBoard, 0);
        return;
    }
    move(histPoint->src, histPoint->srcIndex, histPoint->dest, histPoint->destIndex, histPoint->payloadHead, true);
}

/** Help is used for giving the possible move to user */
void Controller::help() {
    helpData* result = game->helper();

    if (result == nullptr)
        return;

    if (result->location_1 == swapStackT){
        if(result->location_2 == targetStackT){
            //nastavenie highlightu ON
            game->getSwapStack()->get()->turnOnCard();
            game->getTargetStack(result->index_2)->get()->turnOnCard();
            //prekreslenie vo view
            view->refresh(game->getSwapStack());
            view->refresh(game->getTargetStack(result->index_2), result->index_2);
            //wait
            SLEEP(2000);
            //nastavenie highlightu OFF
            game->getSwapStack()->get()->turnOffCard();
            game->getTargetStack(result->index_2)->get()->turnOffCard();
            //prekreslenie vo view
            view->refresh(game->getSwapStack());
            view->refresh(game->getTargetStack(result->index_2), result->index_2);
        } else{
            //workingPack
            //nastavenie highlightu ON
            game->getSwapStack()->get()->turnOnCard();
            game->getWorkingPack(result->index_2)->get()->turnOnCard();
            //prekreslenie vo view
            view->refresh(game->getSwapStack());
            view->refresh(game->getWorkingPack(result->index_2), result->index_2);
            //wait
            SLEEP(2000);
            //nastavenie highlightu OFF
            game->getSwapStack()->get()->turnOffCard();
            game->getWorkingPack(result->index_2)->get()->turnOffCard();
            //prekreslenie vo view
            view->refresh(game->getSwapStack());
            view->refresh(game->getWorkingPack(result->index_2), result->index_2);
        }
    } else {
        //pre wokingPack
        if (result->location_2 == targetStackT){
            //nastavenie highlightu ON
            game->getWorkingPack(result->index_1)->get()->turnOnCard();
            game->getTargetStack(result->index_2)->get()->turnOnCard();
            //prekreslenie vo view
            view->refresh(game->getWorkingPack(result->index_1), result->index_1);
            view->refresh(game->getTargetStack(result->index_2), result->index_2);
            //wait
            SLEEP(2000);
            //nastavenie highlightu OFF
            game->getWorkingPack(result->index_1)->get()->turnOffCard();
            game->getTargetStack(result->index_2)->get()->turnOffCard();
            //prekreslenie vo view
            view->refresh(game->getWorkingPack(result->index_1), result->index_1);
            view->refresh(game->getTargetStack(result->index_2), result->index_2);
        } else{
            //pre workingPack
            //nastavenie highlightu ON
            CardStack* pomStack = game->getWorkingPack(result->index_1)->get(result->payloadHead);
            for (int i = 0; i < pomStack->size(); ++i) {
                pomStack->get(i)->turnOnCard();
            }
            game->getWorkingPack(result->index_2)->get()->turnOnCard();
            //prekreslenie vo view
            view->refresh(game->getWorkingPack(result->index_1), result->index_1);
            view->refresh(game->getWorkingPack(result->index_2), result->index_2);
            //wait
            SLEEP(2000);
            //nastavenie highlightu OFF
            for (int i = 0; i < pomStack->size(); ++i) {
                pomStack->get(i)->turnOffCard();
            }
            game->getWorkingPack(result->index_2)->get()->turnOffCard();
            //prekreslenie vo view
            view->refresh(game->getWorkingPack(result->index_1), result->index_1);
            view->refresh(game->getWorkingPack(result->index_2), result->index_2);
        }

    }
}

/**
 * Time travel moves card or cards from destination to source.
 *
 * @param [in,out] travelCoord If non-null, the travel coordinate.
 */

void Controller::timeTravel(histElement * travelCoord) {
    //timetravel dava z destination veci do source

    //pullSatck klik (prehodi odkaldaci naspet balicek)
    if (travelCoord->dest == pullStackT && travelCoord->src == pullStackT){
        game->reverseTurnPullStack();
        view->refresh(game->getSwapStack());
        if (game->isPullStackEmpty())
            view->refresh();
    }

    //tergetStack to swap
    if (travelCoord->src == swapStackT && travelCoord->dest == targetStackT){
        game->getSwapStack()->put(game->getTargetStack(travelCoord->destIndex)->pop());
        view->refresh(game->getTargetStack(travelCoord->destIndex), travelCoord->destIndex);
        view->refresh(game->getSwapStack());
    }

    //workingPack to swap
    if (travelCoord->src == swapStackT && travelCoord->dest == workingPackT){
        game->getSwapStack()->put(game->getWorkingPack(travelCoord->destIndex)->pop());
        view->refresh(game->getWorkingPack(travelCoord->destIndex), travelCoord->destIndex);
        view->refresh(game->getSwapStack());
    }

    //workingPack to targetStack
    if (travelCoord->src == targetStackT && travelCoord->dest == workingPackT){
        game->getTargetStack(travelCoord->srcIndex)->put(game->getWorkingPack(travelCoord->destIndex)->pop());
        view->refresh(game->getTargetStack(travelCoord->srcIndex), travelCoord->srcIndex);
        view->refresh(game->getWorkingPack(travelCoord->destIndex), travelCoord->destIndex);
    }

    //targetStack to workingPack
    if (travelCoord->src == workingPackT && travelCoord->dest == targetStackT){
        //nastavenie spravneho otocenia karty na ktoru sa to uklada
        if (travelCoord->lastaFaceUp) {
            game->getWorkingPack(travelCoord->srcIndex)->get()->turnFaceDown();
        }
        game->getWorkingPack(travelCoord->srcIndex)->forcePut(game->getTargetStack(travelCoord->destIndex)->pop());
        view->refresh(game->getWorkingPack(travelCoord->srcIndex), travelCoord->srcIndex);
        view->refresh(game->getTargetStack(travelCoord->destIndex), travelCoord->destIndex);
    }

    //workingPack to workingPack
    if (travelCoord->src == workingPackT && travelCoord->dest == workingPackT){
        if (travelCoord->lastaFaceUp) {
            game->getWorkingPack(travelCoord->srcIndex)->get()->turnFaceDown();
        }
        game->getWorkingPack(travelCoord->srcIndex)->forcePut(game->getWorkingPack(travelCoord->destIndex)->pop(travelCoord->payloadHead));
        view->refresh(game->getWorkingPack(travelCoord->destIndex), travelCoord->destIndex);
        view->refresh(game->getWorkingPack(travelCoord->srcIndex), travelCoord->srcIndex);
    }

}

/** Initialize game view */
void Controller::initGame() {
    view->initClosure();
    view->refresh();
    view->refresh(game->getSwapStack());
    for (int i = 0; i < 4; ++i) {
        view->refresh(game->getTargetStack(i), i);
    }
    for (int i = 0; i < 7; ++i) {
        view->refresh(game->getWorkingPack(i), i);
    }
    view->initClosure();
    view->print();
}

void Controller::gameWon() {
    view->gameWon();
    SLEEP(3000);
    std::cout << CLRSCR;
    exit(0);
}

void Controller::checkForEnd() {
    bool flag = true;
    for (int i = 0; i < 4; ++i) {
        if (game->getTargetStack(i)->isEmpty() || game->getTargetStack(i)->get()->value() != 13){
            flag = false;
            break;
        }
    }
    if (flag)
        gameWon();
}


