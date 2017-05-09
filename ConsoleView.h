/**
 * @file ConsoleView.h.
 *
 * @author xbarna02
 * 	
 * Declares the console view class.
 */

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
#ifndef CLRSCR_MACRO
#define CLRSCR_MACRO

#define CLRSCR "\033[2J\033[1;1H"

#endif

#ifndef IJC_SOLITER_CONSOLEVIEW_H
#define IJC_SOLITER_CONSOLEVIEW_H

#include "ViewAbstractClass.h"
#include "ControllerAbstractClass.h"
#include <iostream>
#include <vector>

class ConsoleView: ViewAbstractClass {

public:
    ConsoleView();
    void setGameController(ControllerAbstractClass *);
    void refresh(WorkingPack *, int);
    void refresh(TargetStack *, int);
    void refresh(CardDeck *);
    void refresh();
    void initClosure();
    void print();
    void gameWon();

    void playGame();
    bool translateCommand(std::string from, std::string to, std::string strngCard);
    void badCommand();
    void badMoove();

    ControllerAbstractClass *controller;
private:
    std::vector<std::string> board;
    bool deckFull;
    bool init;



   // void print();

};


#endif //IJC_SOLITER_CONSOLEVIEW_H
