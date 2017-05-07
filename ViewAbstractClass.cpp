/**
 * @file ViewAbstractClass.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the view abstract class class.
 */

#include "ViewAbstractClass.h"

/**
 * Refreshes the view of working packs.
 *
 * @param [in,out] pack If non-null, the pack to refresh.
 * @param 		   i    Zero-based index of the pack.
 */

void ViewAbstractClass::refresh(WorkingPack * pack, int i){

}

/**
 * Refreshes.
 *
 * @param [in,out] stack If non-null, the stack.
 * @param 		   i	 Zero-based index of the target stack.
 */

void ViewAbstractClass::refresh(TargetStack * stack, int i){}

/**
 * Refreshes the given deck.
 *
 * @param [in,out] deck If non-null, the deck to refresh.
 */

void ViewAbstractClass::refresh(CardDeck * deck){}

/** Refreshes this object. */
void ViewAbstractClass::refresh(){}

/**
 * Highlights the cards to move.
 *
 * @param elements1 The source elements.
 * @param i		    Zero-based index of the.
 * @param elements  The location to put.
 * @param b		    An int to process.
 */

//void ViewAbstractClass::highlight(boardElements elements1, int i, boardElements elements, int b){}



