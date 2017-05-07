/**
 * @file main.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the main class.
 */

/**
*@mainpage
* This project implements simple game named Klondike (Solitaire).
* Klondike is played with a standard 52-card deck, without Jokers.
* After shuffling, seven piles of cards are laid from left to right.
* Each pile begins with one upturned card.
* From left to right, each pile contains one more card than the last.
* The first and left-most pile contains a single upturned card, the second pile contains two cards (one downturned, one upturned), the third contains three (two downturned, one upturned), and so on, until the seventh pile which contains seven cards (six downturned, one upturned).
* The piles should look like the figure to the right at the beginning of every game.
* The four foundations (light rectangles in the upper right of the figure) are built up by suit from Ace (low in this game) to King, and the tableau piles can be built down by alternate colors, and partial or complete piles can be moved if they are built down by alternate colors also.
* Any empty piles can be filled with a King or a pile of cards with a King. The aim of the game is to build up a stack of cards starting with two and ending with King, all of the same suit.
* Once this is accomplished, the goal is to move this to a foundation, where the player has previously placed the Ace of that suit.
* Once the player has done this, they will have "finished" that suit, the goal being to finish all suits, at which time the player would have won.
* There are different ways of dealing the remainder of the deck:
* \n Turning only one card at a time, but placing no limit on passes through the deck.
* \n Turning three cards at once to the waste with no limit on passes through the deck, but allowing the player to switch once to a single pass through the deck one card at a time; after that single pass, however, the player cannot go back to turning three cards at a time and can turn over no more cards from the waste.
*/

#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

/**
 * Main entry-point for this application.
 *
 * @param argc The number of command-line arguments provided.
 * @param argv An array of command-line argument strings.
 *
 * @return Exit-code for the process - 0 for success, else an error code.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    scene->addItem(rect);

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
