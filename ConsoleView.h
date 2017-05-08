/**
 * @file ConsoleView.h.
 *
 * @author xbarna02
 * 	
 * Declares the console view class.
 */

#ifndef IJC_SOLITER_CONSOLEVIEW_H
#define IJC_SOLITER_CONSOLEVIEW_H

#include "ViewAbstractClass.h"
#include <iostream>
#include <vector>

#define CLRSCR "\033[2J\033[1;1H"

class ConsoleView: ViewAbstractClass {

public:
    ConsoleView();
    void refresh(WorkingPack *, int);
    void refresh(TargetStack *, int);
    void refresh(CardDeck *);
    void refresh();

private:
    std::vector<std::string> board;
    bool deckFull;

    void print();
};


#endif //IJC_SOLITER_CONSOLEVIEW_H
