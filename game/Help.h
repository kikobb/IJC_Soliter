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
};

class Help {

public:
    helpData help(Game *);
    void resetHelp();

private:
    int achvdPssbHlp = 0;
};


#endif //IJC_SOLITER_HELP_H
