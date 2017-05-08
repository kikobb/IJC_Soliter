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
    board.push_back("|                          |  Target  |  Target  |  Target  |  Target  ||");
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

}

void ConsoleView::refresh() {
    if (deckFull) {
        deckFull = false;
        board[3].replace(3, 4, "NULL");
    }
    else {
        deckFull = true;
        board[3].replace(3, 4, "FULL");
    }
    print();
}

void ConsoleView::refresh(CardDeck * swap) {
    if (swap->size() == 0)
        board[3].replace(15, 4, "NULL");
    else
        board[3].replace(15, 4, swap->get()->toString());
    print();
}

void ConsoleView::refresh(WorkingPack * wp, int i) {
    int boardCounter = 0;
    board[7].replace((unsigned)9+(i*10), 1, to_string(wp->countHidden()));

    for (int j = 0; j < wp->size(); ++j) {
        if(wp->get(j)->isTurnedFaceUp())
            cerr << wp->get(j)->toString() <<endl;
            board[8 + boardCounter++].replace((unsigned)4+(i*10), 4, wp->get(j)->toString());
    }
    for (int j = boardCounter; j < 13 ; ++j) {
        board[8 + j].replace((unsigned)4+(i*10), 4, "    ");
    }

    print();
}

void ConsoleView::refresh(TargetStack *ts, int i) {
    board[4].replace((unsigned)31+(i*11), 4, ts->get()->toString());
    print();
}

void ConsoleView::print() {
    cout << CLRSCR;
    for (int i = 0; i < board.size() ; ++i) {
        cout << board[i] << endl;
    }
}