/**
 * @file TargetStack.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the target stack class.
 */

#include "TargetStack.h"

/**
 * Constructor.
 *
 * @param color The color of the target stack.
 */

TargetStack::TargetStack(Color color) {packColor = color;}

/**
 * Puts the given card.
 *
 * @param [in,out] card If non-null, the card to put.
 *
 * @return True if it succeeds, false if it fails.
 */

bool TargetStack::put(Card *card) {

    if (this->isEmpty()){
        if (card->color() == packColor) {
            if (card->value() == 1) {
                deckStack.push_back(card);
                return true;
            }
        }
    }
    else
    if ((card->value() - this->get()->value()) == 1) {
        if (card->color() == packColor) {
            this->put(card);
            return true;
        }
    }
    return false;
}

//bool TargetStack::put(CardStack * stack) {  }

/**
 * Gets pack color.
 *
 * @return The pack color.
 */

Color TargetStack::getPackColor() { return packColor;}