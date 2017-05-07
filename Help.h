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

class Help {

public:
    Help(Game *);
    //vracia pointer na vysledok helpu, ak nieje mozny tah, vracia nullptr
    helpData* help();
    void resetHelp();

private:
    void fill(helpData &r, boardElements l1, int i1, boardElements l2, int i2, Card* c = nullptr);
    helpData res;
    int achvdPssbHlp = 0;
    Game *game;
};


#endif //IJC_SOLITER_HELP_H
