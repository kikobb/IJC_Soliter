//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_CONTROLLER_H
#define IJC_SOLITER_CONTROLLER_H

#include "../game/Game.h"
#include "string"
#include "../view/ViewAbstractClass.h"
#include "../game/History.h"
#include "../game/Help.h"

class Controller {
public:
    Controller(Game *, ViewAbstractClass*);
    void rollBack();
    void rollForward();
    void moove(boardElements src, int srcIndex, boardElements dest,
               int destIndex, Card *payloadHead = nullptr);
    void help();
    bool save(std::string);
    void load(std::string);

private:
    Game *game;
    //todo pridat odkaz na view
    ViewAbstractClass *view;

    void timeTravel(histElement *);

};


#endif //IJC_SOLITER_CONTROLLER_H
