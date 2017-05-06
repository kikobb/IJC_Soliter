//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_HELP_H
#define IJC_SOLITER_HELP_H

#include "Game.h"

struct helpData{
    boardElements location_1;
    int index_1;
    boardElements location_2;
    int index_2;
    Card *payloadHead = nullptr;
};


//class Game;

class Help {

public:
    Help(Game *);
    bool help();
    void resetHelp();
    helpData getResult();

private:
    helpData res;
    int achvdPssbHlp = 0;
    Game *game;
};


#endif //IJC_SOLITER_HELP_H
