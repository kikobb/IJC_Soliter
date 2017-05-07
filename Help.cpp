//
// Created by k on 6.5.2017.
//

#include "Help.h"

Help::Help(Game *g) {game = g;}

bool Help::help() {
    int possibHelpNmbr = 0;
    //prehladanie moznosti s kartou na swapStack
    //targetStack
    for (int i = 0; i < 4; i++){
        if (game->getTargetStack(i)->put(game->getSwapStack()->get())){
            game->getTargetStack(i)->pop();
            if (possibHelpNmbr++ == achvdPssbHlp){
                achvdPssbHlp++;
                fill(res ,swapStackT, 0, targetStackT, i);
                return true;
            }
        }
    }
    //workingPack
    for (int i = 0; i < 7; i++){
        if (game->getWorkingPack(i)->put(game->getSwapStack()->get())) {
            game->getWorkingPack(i)->pop();
            if (possibHelpNmbr++ == achvdPssbHlp){
                achvdPssbHlp++;
                fill(res ,swapStackT, 0, workingPackT, i);
                return true;
            }
        }
    }
    //prehladanie moznosti pre karty na workingPacku
    //targetStack
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 4; j++){
            if (game->getTargetStack(j)->put(game->getWorkingPack(j)->get())){
                game->getTargetStack(j)->pop();
                if (possibHelpNmbr++ == achvdPssbHlp) {
                    achvdPssbHlp++;
                    fill(res, workingPackT, i, targetStackT, j);
                    return true;
                }
            }
        }
    }
    //workingPack
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            if (i == j)
                continue;
            for (int k = game->getWorkingPack(i)->size() -1; k >= 0; ++k) {
                if (game->getWorkingPack(j)->put(game->getWorkingPack(i)->get(k))){
                    game->getWorkingPack(j)->pop();
                    if (possibHelpNmbr++ == achvdPssbHlp) {
                        achvdPssbHlp++;
                        fill(res, workingPackT, i, workingPackT, j, game->getWorkingPack(i)->get(k));
                        return true;
                    }
                }
            }
        }
    }
    resetHelp();
    return false;
}

void Help::resetHelp() {achvdPssbHlp = 0;}

helpData Help::getResult() { return res;}

void Help::fill(helpData &r, boardElements l1, int i1, boardElements l2, int i2, Card* c) {
    r.location_1 = l1;
    r.index_1 = i1;
    r.location_2 = l2;
    r.index_2 = i2;
    if (c != nullptr)
        r.payloadHead = c;
}