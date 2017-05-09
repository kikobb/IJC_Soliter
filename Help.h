/**
 * @file Help.h.
 *
 * @author xuhlia03
 * 
 * Declares the help class.
 */

#ifndef IJC_SOLITER_HELP_H
#define IJC_SOLITER_HELP_H

#include "Game.h"


/** A help data. */
struct helpData{
    boardElements location_1;
    int index_1;
    boardElements location_2;
    int index_2;
    Card *payloadHead = nullptr;
};

/** A help. */
class Help {

public:
    Help(Game *);
    //vracia pointer na vysledok helpu, ak nieje mozny tah, vracia nullptr
    helpData* help();
    void resetHelp();

private:
    helpData res;
    int achvdPssbHlp = 0;
    Game *game;

    void fill(helpData &r, boardElements l1, int i1, boardElements l2, int i2, Card* c = nullptr);
};


#endif //IJC_SOLITER_HELP_H
