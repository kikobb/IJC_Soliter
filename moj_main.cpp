/**
 * @file moj_main.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the moj main class.
 */

#include <iostream>
#include "ConsoleView.h"

int main(int argc, char *argv[]) {
    //std::cout << "hello world !!!" <<std::endl;

    ConsoleView *pom = new ConsoleView();

    pom->refresh();
    pom->refresh();
    pom->refresh(new CardDeck);
    CardStack *tmp = new CardStack;
    tmp->put(new Card(3, SPADES));
    tmp->get()->turnFaceUp();
    tmp->put(new Card(4, HEARTS));
    tmp->get()->turnFaceUp();
    WorkingPack *tmpWp = new WorkingPack(tmp);
    pom->refresh(tmpWp, 4);
    TargetStack *tmpTs = new TargetStack(SPADES);
    tmpTs->put(new Card(1, SPADES));
    pom->refresh(tmpTs, 3);

}
