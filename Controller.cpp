/**
 * @file Controller.cpp.
 * 
 * @author xbarna02
 * 
 * Implements the controller class.
 */

#include "Controller.h"

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

void Controller::moove(boardElements src, int srcIndex, boardElements dest,
                       int destIndex, Card *payloadHead) {

    //flag pre historiu
    bool lastTurnUp = false;
    bool mooveSuccesfull = false;

    //pullSatck klik (prehodi odkaldaci balicek)
    if (src == pullStackT && dest == pullStackT){
        game->turnPullStack();
        view->refresh(game->getSwapStack());
        if (game->isPullStackEmpty())
            view->refresh();
        mooveSuccesfull = true;
    }

    // swap to tergetStack
    if (src == swapStackT && dest == targetStackT){
        //ak sa to uspesne presunie
        if (game->getTargetStack(destIndex)->put(game->getSwapStack()->get())){
            game->getSwapStack()->pop();
            view->refresh(game->getTargetStack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getSwapStack());
    }

    //swap to workingPack
    if (src == swapStackT && dest == workingPackT){
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
        //uspesne presunutie (iba jedna karta (ta co je navrchu) a je to validne)
        //todo skontroluj overload
        if (game->getWorkingPack(srcIndex)->get() == payloadHead &&
            game->getTargetStack(destIndex)->put(game->getWorkingPack(srcIndex)->get())){
            game->getWorkingPack(srcIndex)->pop();
            view->refresh(game->getTargetStack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getWorkingPack(srcIndex), srcIndex);
    }

    //workingPack to workingPack
    if (src == workingPackT && dest == workingPackT){
        //uspesne presunutir
        //otocenia kary
        if (game->getWorkingPack(destIndex)->put(game->getWorkingPack(srcIndex)->get(payloadHead))){
            game->getWorkingPack(srcIndex)->pop(payloadHead);
            //flag pre historiu
            lastTurnUp = !game->getWorkingPack(srcIndex)->get()->isTurnedFaceUp();
            game->getWorkingPack(srcIndex)->get()->turnFaceUp();
            view->refresh(game->getWorkingPack(destIndex), destIndex);
            mooveSuccesfull = true;
        }
        view->refresh(game->getWorkingPack(srcIndex), srcIndex);
    }

    //ulozenie historie
    if (mooveSuccesfull) {
        game->getHistory()->recordMove(src, srcIndex, dest, destIndex, payloadHead, lastTurnUp);
        game->resetHelp();
    }
}

/** Roll back. */
void Controller::rollBack() {
    histElement* move = game->getHistory()->rollBack();
    if (move == nullptr)
        return;
    timeTravel(move);

}

/** Roll forward. */
void Controller::rollForward() {
    histElement* move = game->getHistory()->rollForward();
    if (move == nullptr)
        return;
    timeTravel(move);
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
