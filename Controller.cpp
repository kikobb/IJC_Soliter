//
// Created by k on 6.5.2017.
//

#include "Controller.h"
#include "History.h"
#include "ViewAbstractClass.h"

Controller::Controller(Game *g, ViewAbstractClass* v) {game = g; view = v;}

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

void Controller::rollBack() {
    histElement* move = game->getHistory()->rollBack();
    if (move == nullptr)
        return;
    timeTravel(move);

}

void Controller::rollForward() {
    histElement* move = game->getHistory()->rollForward();
    if (move == nullptr)
        return;
    timeTravel(move);
}

void Controller::help() {
    helpData* result = nullptr;
    if (!game->helper(result))
        return;
    //view->highlight()
}