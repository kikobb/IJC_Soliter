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

    Game *game = new Game;
    ConsoleView *view = new ConsoleView();
    ControllerAbstractClass *c = (ControllerAbstractClass *) new Controller(game, (ViewAbstractClass *) view);
    view->setGameController(c);
    view->controller->initGame();
    view->playGame();


}


