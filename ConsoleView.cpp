/**
 * @file ConsoleView.cpp.
 *
 * @author xbarna02
 *
 * Implements the console view class.
 */

#include <iostream>
#include <algorithm>
#include "ConsoleView.h"

void terminateGame();
void loadGame();
void newGame();


using namespace std;

ConsoleView::ConsoleView() {
    board.push_back(" -----------------------------------------------------------------------");
    board.push_back("|                          | Target_1 | Target_2 | Target_3 | Target_4 ||");
    board.push_back("|  Deck      SwapDeck      |  CLUBS   | DIAMONDS |  HEARTS  |  SPADES  ||");
    board.push_back("|  FULL        K(S)        |  ------    --------    ------     ------  ||");
    board.push_back("|                          |   K(S)   |   K(S)   |   K(S)   |   K(S)   ||");
    board.push_back("| --------------------------------------------------------------------- |");
    board.push_back("|| Stack_1 | Stack_2 | Stack_3 | Stack_4 | Stack_5 | Stack_6 | Stack_7 ||");
    board.push_back("|| hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 | hid.: 0 ||");
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
    if (swap->isEmpty())
        board[3].replace(15, 5, "NULL ");
    else {
        if (swap->get()->toString().size() == 4)
            board[3].replace(15, 5, swap->get()->toString() + " ");
        else
            board[3].replace(15, swap->get()->toString().size(), swap->get()->toString());

        if (swap->get()->isHighlighted())
            board[3].replace(14, 1, ">");
        else
            board[3].replace(14, 1, " ");
    }
    if(!init)
        print();
}

void ConsoleView::refresh(WorkingPack * wp, int i, int helpFlag) {
    int boardCounter = 0;
    board[7].replace((unsigned)9+(i*10), 1, to_string(wp->countHidden()));

    //kripad helpu kral sa presunie
    if (wp->isEmpty() && helpFlag != 0)
        if (helpFlag == 1)
            board[8 + boardCounter].replace((unsigned) 3 + (i * 10), 1, ">");
        else
            board[8 + boardCounter].replace((unsigned) 3 + (i * 10), 1, " ");

    //prejde vsetky wp (ak null wp->size == 0)
    for (int j = 0; j < wp->size(); ++j) {
        if(wp->get(j)->isTurnedFaceUp()) {
            //help
            if (wp->get(j)->isHighlighted())
                board[8 + boardCounter].replace((unsigned) 3 + (i * 10), 1, ">");
            else
                board[8 + boardCounter].replace((unsigned) 3 + (i * 10), 1, " ");

            //prekreslenie karty
            if (wp->get()->toString().size() == 4)
                board[8 + boardCounter++].replace((unsigned) 4 + (i * 10), 5, wp->get(j)->toString() + " ");
            else
                board[8 + boardCounter++].replace((unsigned) 4 + (i * 10), wp->get(j)->toString().size(),
                                                  wp->get(j)->toString());
        }
    }
    for (int j = boardCounter; j < 13 ; ++j) {
        board[8 + j].replace((unsigned)4+(i*10), 5, "     ");
    }

    if(!init)
        print();
}

void ConsoleView::refresh(TargetStack *ts, int i) {
    if (ts->isEmpty())
        board[4].replace((unsigned)31+(i*11), 5, "     ");
    else {
        if (ts->get()->toString().size() == 4)
            board[4].replace((unsigned) 31 + (i * 11), 5, ts->get()->toString() + " ");
        else
            board[4].replace((unsigned) 31 + (i * 11), ts->get()->toString().size(), ts->get()->toString());

        if (ts->get()->isHighlighted())
            board[4].replace((unsigned) 30 + (i * 11), 1, ">");
        else
            board[4].replace((unsigned) 30 + (i * 11), 1, " ");
    }

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

void ConsoleView::gameWon() {
    std::vector<std::string> endGame;

    endGame.push_back(" -----------------------------------------------------------------------");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                         CONGRATULATION                                |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                            YOU WON                                    |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back("|                                                                       |");
    endGame.push_back(" -----------------------------------------------------------------------");

    board = endGame;
    print();
}

void ConsoleView::setGameController(ControllerAbstractClass * c) { controller = c;}

Game* ConsoleView::playGame() {
    bool jedeme = true;
    Game *newGame = nullptr;
    std::string command, from, to, card;
    while (jedeme){
        command = "";
        from = "";
        to = "";
        card = "";
        getline(std::cin, command);
        from = command.substr(0, command.find(" ", 0));
        if (command.size() > from.size() + 1)
            to = command.substr(from.size() + 1, command.find(" ", from.size() + 1) - (from.size() + 1));
        if (command.size() >  from.size() + to.size() + 2)
            card = command.substr(from.size() + to.size() + 2, command.find(" ", from.size() + to.size() + 2) - (from.size() + to.size() + 2));

        if(!translateCommand(from, to, card)) {
            badCommand();
            SLEEP(800);
            controller->move(gameBoard, 0, gameBoard, 0);
        }
    }
}

bool ConsoleView::translateCommand(std::string from, std::string to, std::string strngCard) {
    if (from.size() == 0) {
        controller->move(gameBoard, 0, gameBoard, 0);
        return true;
    }

    int pomFilledArgs = 1;
    if (to.size() != 0)
        pomFilledArgs++;
    if (strngCard.size() != 0)
        pomFilledArgs++;

    if (from == "help" || from == "h") {
        controller->help();
        return true;
    }

    if (from == "exit") {
       // terminateGame();
    }

    if (from == "save") {
        saveGame(to);
        if (strngCard == "exit") {
            //terminateGame();
        }
        return  true;
    }
    if (from == "load" && pomFilledArgs == 2) {
        return loadGame(to);
    }
    if (from == "new" || (from == "new" && to == "game")) {
//        newGame();
    }

    if (from == "back" || from == "rollback" || from == "b") {
        controller->rollBack();
        return true;
    }

    if (from == "forward" || from == "rollforward" || from == "next" || from == "n" || from == "f") {
        controller->rollForward();
        return true;
    }

    boardElements src = gameBoard, dest = gameBoard;
    int srcIndex = -1, destIndex = -1;
    Card *card = nullptr;

    //src + index
    if(from == "deck" || from == "d"){
        src = pullStackT;
        srcIndex = 0;
        //swap
    }else if (from == "swap" || from == "s") {
        src = swapStackT;
        srcIndex = 0;
        //workingPack
    }else if (from.substr(0, from.size() - 1) == "stack" || from.substr(0, from.size() - 1) == "s") {
        if (atoi(from.substr(from.size() - 1, 1).c_str()) > 0 && atoi(from.substr(from.size() - 1, 1).c_str()) < 8) {
            src = workingPackT;
            srcIndex = atoi(from.substr(from.size() - 1, 1).c_str()) -1;
        }
        //targetStack
    } else if (from.substr(0, from.size() - 1) == "target" || from.substr(0, from.size() - 1) == "t") {
        if (atoi(from.substr(from.size() - 1, 1).c_str()) > 0 && atoi(from.substr(from.size() - 1, 1).c_str()) < 5) {
            src = targetStackT;
            srcIndex = atoi(from.substr(from.size() - 1, 1).c_str()) -1;
        }
    }

    //dest + destIndex
    if (pomFilledArgs > 1){
        //workingPack
        if (to.substr(0, to.size() - 1) == "stack" || to.substr(0, to.size() - 1) == "s") {
            if (atoi(to.substr(to.size() - 1, 1).c_str()) > 0 && atoi(to.substr(to.size() - 1, 1).c_str()) < 8) {
                dest = workingPackT;
                destIndex = atoi(to.substr(to.size() - 1, 1).c_str()) -1;
            }
            //targetStack
        } else if (to.substr(0, to.size() - 1) == "target" || to.substr(0, to.size() - 1) == "t") {
            if (atoi(to.substr(to.size() - 1, 1).c_str()) > 0 && atoi(to.substr(to.size() - 1, 1).c_str()) < 5) {
                dest = targetStackT;
                destIndex = atoi(to.substr(to.size() - 1, 1).c_str()) -1;
            }
        }
    }else if(src == pullStackT) {
        dest = pullStackT;
        destIndex = 0;
    }

    if (pomFilledArgs == 3){
        try {
            card = new Card(&strngCard);
        }catch (int &e){
            if (e == -1)
                return false;
        }
    }

    //validacia
    switch (pomFilledArgs){
        case 3:
        case 2: if (dest == gameBoard || (dest == targetStackT && destIndex > 3) || (dest == workingPackT && destIndex > 6)) {
                return false;
            }
        case 1: if (src == gameBoard || (src == targetStackT && srcIndex > 3) || (src == workingPackT && srcIndex > 6)) {
                return false;
            }
        default:
            break;
    }

    //volanie controllera
    if (pomFilledArgs == 3) {
        if(!controller->move(src, srcIndex, dest, destIndex, card)) {
            badMoove();
            SLEEP(800);
            controller->move(gameBoard, 0, gameBoard, 0);
        }
        return true;
    }
    else {
        if(!controller->move(src, srcIndex, dest, destIndex)) {
            badMoove();
            SLEEP(800);
            controller->move(gameBoard, 0, gameBoard, 0);
        }
        return true;
    }
}

//private
void ConsoleView::badCommand(){
    std::cout<< "zli command" << endl;
}

void ConsoleView::badMoove(){
    std::cout<< "Neplatny tah" << endl;
}

void ConsoleView::saveGame(std::string name) {
    if(!controller->save(name)){
        std::cout << "Game was not saved !!!! Press any key . . . ." << std::endl;
        getchar();
        refresh();
        refresh();
        return;
    } else{
        std::cout << "Game was saved Press any key. . . ." << std::endl;
        getchar();
        refresh();
        refresh();
        return;
    }
}

bool ConsoleView::loadGame(std::string meno) {
    if(!controller->load(meno)){
        std::cout << "Game not found !!!! Press any key . . . ." << std::endl;
        getchar();
        refresh();
        refresh();
        return false;
    }
    return true;

}



void terminateGame(){}

