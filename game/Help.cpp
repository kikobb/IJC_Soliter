//
// Created by k on 6.5.2017.
//

#include "Help.h"
#include "Game.h"

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
                res.index_1 = swapStackT;
                res.index_2 = targetStackT;
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
                //res = {swapStackT, 0, workingPackT, i};
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
                    //res = {workingPackT, i, targetStackT, j};
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
                        //res = {workingPackT, i, workingPackT, j, game->getWorkingPack(j)->pop()};
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
