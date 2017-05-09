/**
 * @file Help.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the help class.
 */

#include "Help.h"

/**
 * Constructor.
 *
 * @param [in,out] g If non-null, a Game to process.
 */

Help::Help(Game *g) {game = g;}

/**
 * Gets the help.
 *
 * @return Null if it fails, else a pointer to a helpData.
 */

helpData* Help::help() {
    int possibHelpNmbr = 0;
    //prehladanie moznosti s kartou na swapStack
    if (!game->getSwapStack()->isEmpty()) {
        //targetStack
        for (int i = 0; i < 4; i++) {
            if (!game->getTargetStack(i)->isEmpty()) {
                if (game->getTargetStack(i)->put(game->getSwapStack()->get())) {
                    game->getTargetStack(i)->pop();
                    if (possibHelpNmbr++ == achvdPssbHlp) {
                        achvdPssbHlp++;
                        fill(res, swapStackT, 0, targetStackT, i);
                        return &res;
                    }
                }
            }
        }
        //workingPack
        for (int i = 0; i < 7; i++) {
            if (!game->getTargetStack(i)->isEmpty()) {
                if (game->getWorkingPack(i)->put(game->getSwapStack()->get())) {
                    game->getWorkingPack(i)->pop();
                    if (possibHelpNmbr++ == achvdPssbHlp) {
                        achvdPssbHlp++;
                        fill(res, swapStackT, 0, workingPackT, i);
                        return &res;
                    }
                }
            }
        }
    }
    //prehladanie moznosti pre karty na workingPacku
    //targetStack
    for (int i = 0; i < 7; i++){
        if (!game->getWorkingPack(i)->isEmpty()) {
            for (int j = 0; j < 4; j++) {
                if(!game->getTargetStack(j)->isEmpty()) {
                    if (game->getTargetStack(j)->put(game->getWorkingPack(j)->get())) {
                        game->getTargetStack(j)->pop();
                        if (possibHelpNmbr++ == achvdPssbHlp) {
                            achvdPssbHlp++;
                            fill(res, workingPackT, i, targetStackT, j);
                            return &res;
                        }
                    }
                }
            }
        }
    }
    //workingPack
    for (int i = 0; i < 7; i++){
        if (!game->getWorkingPack(i)->isEmpty()) {
            for (int j = 0; j < 7; j++) {
                if (i == j)
                    continue;
                if (!game->getWorkingPack(i)->isEmpty()) {
                    for (int k = game->getWorkingPack(i)->size() - 1; k >= 0; --k) {
                        if (game->getWorkingPack(i)->get(k)->isTurnedFaceUp() &&
                                game->getWorkingPack(j)->put(game->getWorkingPack(i)->get(k))) {
                            game->getWorkingPack(j)->pop();
                            if (possibHelpNmbr++ == achvdPssbHlp) {
                                //aby navrhoval presunutie krala na prazdne policko len ak kral nieco zakriva
                                if(game->getWorkingPack(i)->get(k)->value() != 13 ||
                                        game->getWorkingPack(i)->countHidden() != 0){
                                    achvdPssbHlp++;
                                    fill(res, workingPackT, i, workingPackT, j, game->getWorkingPack(i)->get(k));
                                    return &res;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (possibHelpNmbr != 0) {
        resetHelp();
        return help();
    }
    else
        return nullptr;
}

/** Resets the help. */
void Help::resetHelp() {achvdPssbHlp = 0;}

/**
 * Fills.
 *
 * @param [in,out] r  A helpData to process.
 * @param 		   l1 The first boardElements.
 * @param 		   i1 Zero-based index of the 1.
 * @param 		   l2 The second boardElements.
 * @param 		   i2 Zero-based index of the 2.
 * @param [in,out] c  If non-null, a Card to process.
 */

void Help::fill(helpData &r, boardElements l1, int i1, boardElements l2, int i2, Card* c) {
    r.location_1 = l1;
    r.index_1 = i1;
    r.location_2 = l2;
    r.index_2 = i2;
    if (c != nullptr)
        r.payloadHead = c;
}