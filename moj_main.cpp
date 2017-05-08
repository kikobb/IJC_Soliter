/**
 * @file moj_main.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the moj main class.
 */

#include <iostream>
#include "ConsoleView.h"
#include "Controller.h"

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


//    ConsoleView *pom = new ConsoleView();
//
//    pom->refresh();
//    pom->refresh();
//    pom->refresh(new CardDeck);
//    CardStack *tmp = new CardStack;
//    tmp->put(new Card(3, SPADES));
//    tmp->get()->turnFaceUp();
//    tmp->put(new Card(4, HEARTS));
//    tmp->get()->turnFaceUp();
//    WorkingPack *tmpWp = new WorkingPack(tmp);
//    pom->refresh(tmpWp, 4);
//    TargetStack *tmpTs = new TargetStack(SPADES);
//    pom->refresh(tmpTs, 2);
//    tmpTs->put(new Card(1, SPADES));
//    pom->refresh(tmpTs, 3);

    Game *game = new Game;
    ConsoleView *view = new ConsoleView;
    Controller *controlGame = new Controller(game, (ViewAbstractClass *) view);
    controlGame->initGame();

    bool jedeme = true;
    std::string from, to, card;
    while (jedeme){
        std::cin >> from >> to >> card;
        if (from == "s1")
            if (to == "t3")
                if (card == "A(H)") {
                    controlGame->moove(workingPackT, 0, targetStackT, 2);
                    jedeme = false;
                }
    }
}
