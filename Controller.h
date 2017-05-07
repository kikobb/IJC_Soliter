/**
 * @file Controller.h.
 *
 * @author xbarna02
 * 
 * Declares the controller class.
 */

#ifndef IJC_SOLITER_CONTROLLER_H
#define IJC_SOLITER_CONTROLLER_H

#ifdef LINUX
#include <unistd.h>
#define SLEEP(t) usleep(t * 1000);
#elif WINDOWS
#include <windows.h>
#define SLEEP(t) Sleep(t);
#else
#include <unistd.h>
#define SLEEP(t) usleep(t * 1000);
#endif

#include "Game.h"
#include "string"
#include "ViewAbstractClass.h"
#include "History.h"
#include "Help.h"

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
