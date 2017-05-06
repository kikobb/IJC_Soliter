//
// Created by k on 6.5.2017.
//

#include "Help.h"
#include "Game.h"

helpData Help::help(Game *game) {
    int possibHelpNmbr = 0;
    //prehladanie moznosti s kartou na swapStack
    //targetStack
    for (int i = 0; i < 4; i++){
        if (game->getTargetStack(i)->put(game->getSwapStack()->get())){
            game->getTargetStack(i)->pop();
            if (possibHelpNmbr++ == achvdPssbHlp){
                achvdPssbHlp++;
                helpData tmp = {swapStackT, 0, targetStackT, i};
                return tmp;
            }
        }
    }
    //workingPack
    for (int i = 0; i < 7; i++){
        if (game->getWorkingPack(i)->put(game->getSwapStack()->get())) {
            game->getWorkingPack(i)->pop();
            if (possibHelpNmbr++ == achvdPssbHlp){
                achvdPssbHlp++;
                helpData tmp = {swapStackT, 0, workingPackT, i};
                return tmp;
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
                    helpData tmp = {workingPackT, i, targetStackT, j};
                    return tmp;
                }
            }
        }
    }
    //workingPack
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            if (i == j)
                continue;
            if (game->getWorkingPack(j)->put(game->getWorkingPack(j)->get())){
                game->getWorkingPack(j)->pop();
                if (possibHelpNmbr++ == achvdPssbHlp) {
                    achvdPssbHlp++;
                    helpData tmp = {workingPackT, i, workingPackT, j};
                return tmp;
                }
            }
        }
    }
    resetHelp();
    return nullptr;
}

void Help::resetHelp() {Help::achvdPssbHlp = 0;}