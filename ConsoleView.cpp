/**
 * @file ConsoleView.cpp.
 *
 * @author xbarna02
 *
 * Implements the console view class.
 */

#include <iostream>
#include "ConsoleView.h"

using namespace std;

ConsoleView::ConsoleView() {
    board.push_back(" -----------------------------------------------------------------------");
    board.push_back("|                          | Target_1 | Target_2 | Target_3 | Target_4 ||");
    board.push_back("|  Deck      SwapDeck      |  CLUBS   | DIAMONDS |  HEARTS  |  SPADES  ||");
    board.push_back("|  FULL        K(S)        |  ------    --------    ------     ------  ||");
    board.push_back("|                          |   K(S)   |   K(S)   |   K(S)   |   K(S)   ||");
    board.push_back("| --------------------------------------------------------------------- |");
    board.push_back("|| Stack_1 | Stack_2 | Stack_3 | Stack_4 | Stack_5 | Stack_6 | Stack_7 ||");
    board.push_back("|| hid.: 2 | hid.: 3 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("||  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   |  K(S)   ||");
    board.push_back("| --------------------------------------------------------------------- |");
    board.push_back(" -----------------------------------------------------------------------");

    deckFull = true;
    init = false;

}

void ConsoleView::refresh() {
    if (deckFull) {
        deckFull = false;
        board[3].replace(3, 4, "FULL");
    }
    else {
        deckFull = true;
        board[3].replace(3, 4, "NULL");
    }
    if(!init)
        print();
}

void ConsoleView::refresh(CardDeck * swap) {
    if (swap->size() == 0)
        board[3].replace(15, 4, "NULL");
    else
        board[3].replace(15, swap->get()->toString().size(), swap->get()->toString());

    if(!init)
        print();
}

void ConsoleView::refresh(WorkingPack * wp, int i) {
    int boardCounter = 0;
    board[7].replace((unsigned)9+(i*10), 1, to_string(wp->countHidden()));

    for (int j = 0; j < wp->size(); ++j) {
        if(wp->get(j)->isTurnedFaceUp())
            board[8 + boardCounter++].replace((unsigned)4+(i*10), wp->get(j)->toString().size(), wp->get(j)->toString());
    }
    for (int j = boardCounter; j < 13 ; ++j) {
        board[8 + j].replace((unsigned)4+(i*10), 5, "     ");
    }

    if(!init)
        print();
}

void ConsoleView::refresh(TargetStack *ts, int i) {
    if (ts->size() == 0)
        board[4].replace((unsigned)31+(i*11), 5, "     ");
    else
        board[4].replace((unsigned)31+(i*11), ts->get()->toString().size(), ts->get()->toString());
    if(!init)
        print();
}

void ConsoleView::print() {
    cout << CLRSCR;
    for (int i = 0; i < board.size() ; ++i) {
        cout << board[i] << endl;
    }
}

void ConsoleView::initClosure() { init = !init;}