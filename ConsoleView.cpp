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
#include "Controller.h"

bool translateCommand(Controller *controlGame, std::string from, std::string to, std::string card);
void terminateGame();
void saveGame();
void loadGame();
void newGame();
void badCommand();

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
        board[3].replace(15, 5, "NULL ");
    else
        if (swap->get()->toString().size() == 4)
            board[3].replace(15, 5, swap->get()->toString() + " ");
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

int main(int argc, char *argv[]) {
    if (argc > 1) {
        fprintf(stderr, "Prilis vela agrumentov");
        return -1;
    }

    if(argc == 1){
        if (argv[1] == "--help"){
            std::cout << "help" <<std::endl;
        }
    }

    Game *game = new Game;
    ConsoleView *view = new ConsoleView;
    Controller *controlGame = new Controller(game, (ViewAbstractClass *) view);
    controlGame->initGame();

    Card *tmp = new Card(13, HEARTS);
    tmp->turnFaceUp();
    game->getWorkingPack(0)->forcePut(tmp);
    view->refresh(game->getWorkingPack(0), 0);
    tmp = new Card(12, SPADES);
    tmp->turnFaceUp();
    game->getWorkingPack(0)->forcePut(tmp);
    view->refresh(game->getWorkingPack(0), 0);
    tmp = new Card(11, HEARTS);
    tmp->turnFaceUp();
    game->getWorkingPack(0)->forcePut(tmp);
    view->refresh(game->getWorkingPack(0), 0);

    tmp = new Card(13, HEARTS);
    tmp->turnFaceUp();
    game->getWorkingPack(1)->forcePut(tmp);
    view->refresh(game->getWorkingPack(1), 1);


    bool jedeme = true;
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

        if(!translateCommand(controlGame, from, to, card)) {
            badCommand();
            SLEEP(2000);
            controlGame->moove(gameBoard, 0, gameBoard, 0);
        }

    }
}

bool translateCommand(Controller *controlGame, std::string from, std::string to, std::string strngCard) {
    if (from.size() == 0) {
        controlGame->moove(gameBoard, 0, gameBoard, 0);
        return true;
    }

    int pomFilledArgs = 1;
    if (to.size() != 0)
        pomFilledArgs++;
    if (strngCard.size() != 0)
        pomFilledArgs++;

    if (from == "exit") {
//        terminateGame();
    }
    if (from == "save") {
        if (to == "exit") {
//            saveGame();
//            terminateGame();
        }
//    saveGame();
    }
    if (from == "load") {
//        loadGame();
    }
    if (from == "new" || (from == "new" && to == "game")) {
//        newGame();
    }

    if (from == "back" || from == "rollback" || from == "b") {
        controlGame->rollBack();
        return true;
    }

    if (from == "forward" || from == "rollforward" || from == "next" || from == "n" || from == "f") {
        controlGame->rollForward();
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
    if (pomFilledArgs == 3)
        controlGame->moove(src, srcIndex, dest, destIndex, card);
    else
        controlGame->moove(src, srcIndex, dest, destIndex);

    return true;
}

void badCommand(){
    std::cout<< "zli command" << endl;
}