//
// Created by k on 7.5.2017.
//

#ifndef IJC_SOLITER_CONSOLEVIEW_H
#define IJC_SOLITER_CONSOLEVIEW_H

#include "ViewAbstractClass.h"
#include <iostream>

class ConsoleView: ViewAbstractClass {

public:
    void refresh(WorkingPack *, int);
    void refresh(TargetStack *, int);
    void refresh(CardDeck *);
    void refresh();

private:
    std::string board[]{
      "\n",
      //toascii(186) + " Deck   SwapDeck         |  Target  |  Target  |  Target  |  Target | " + toascii(186),
      "                          |  Target  |  Target  |  Target  |  Target  |",
      " Deck   SwapDeck          |  CLUBS   | DIAMONDS |  HEARTS  |  SPADES  |",
      "\n"
      " FULL     K(S)            |   K(S)   |   K(S)   |   K(S)   |   K(S)   |",
      "\n", "\n",
      "| Stack_1 | Stack_2 | Stack_3 | Stack_4 | Stack_5 | Stack_6 | Stack_7 |",
      "| hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "|  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |",
      "\n"


    };
};


#endif //IJC_SOLITER_CONSOLEVIEW_H
