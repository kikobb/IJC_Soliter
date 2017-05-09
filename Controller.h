/**
 * @file Controller.h.
 *
 * @author xbarna02
 * 
 * Declares the controller class.
 */

#ifndef IJC_SOLITER_CONTROLLER_H
#define IJC_SOLITER_CONTROLLER_H

#ifndef CLRSCR_MACRO
#define CLRSCR_MACRO

#define CLRSCR "\033[2J\033[1;1H"

#endif

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

#include "ViewAbstractClass.h"
#include "Game.h"
#include <string>
#include "History.h"
#include "Help.h"
#include "ControllerAbstractClass.h"

class Controller : ControllerAbstractClass{
public:
    Controller(Game *, ViewAbstractClass*);
    void rollBack();
    void rollForward();
    bool move(boardElements src, int srcIndex, boardElements dest,
              int destIndex, Card *payloadHead = nullptr, bool histBlock = false);
    void help();
    void initGame();
    bool save(std::string);
    void load(std::string);

private:
    Game *game;
    ViewAbstractClass *view;

    void timeTravel(histElement *);
    void checkForEnd();
    void gameWon();



};


#endif //IJC_SOLITER_CONTROLLER_H
