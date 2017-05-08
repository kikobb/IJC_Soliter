/**
 * @file History.cpp.
 *
 * @author xbarna02
 * 		   
 * Implements the history class.
 */

#include "History.h"

/**
 * Record move.
 *
 * @param src		 Source of the elemet(s).
 * @param srcIndex   Zero-based index of the source.
 * @param dest		 Destination for the elemet(s).
 * @param lastFaceUp True to last face up.
 */

void History::recordMove(boardElements src, int srcIndex, boardElements dest,
                         bool lastFaceUp) {
    if (position == size() - 1){
        addMove(src, srcIndex, dest, 0, nullptr, lastFaceUp);
        position++;
    } else{
        while (position != size() - 1)
            removeMove();
        recordMove(src, srcIndex, dest, lastFaceUp);
    }
}

/**
 * Record move.
 *
 * @param src		 Source for the elemet(s).
 * @param srcIndex   Zero-based index of the source.
 * @param dest		 Destination for the elemet(s).
 * @param destIndex  Zero-based index of the destination.
 * @param lastFaceUp True to last face up.
 */

void History::recordMove(boardElements src, int srcIndex, boardElements dest,
                         int destIndex, bool lastFaceUp) {
    if (position == size() - 1){
        addMove(src, srcIndex, dest, destIndex, nullptr, lastFaceUp);
        position++;
    } else{
        while (position != size() -1 )
            removeMove();
        recordMove(src, srcIndex, dest, destIndex, lastFaceUp);
    }
}

/**
 * Record move.
 *
 * @param 		   src		   Source for the elemet(s).
 * @param 		   srcIndex    Zero-based index of the source.
 * @param 		   dest		   Destination for the elemet(s).
 * @param 		   destIndex   Zero-based index of the destination.
 * @param [in,out] payloadHead If non-null, the payload head.
 * @param 		   lastFaceUp  True to last face up.
 */

void History::recordMove(boardElements src, int srcIndex, boardElements dest,
                         int destIndex, Card *payloadHead, bool lastFaceUp) {
    if (position == size() - 1){
        addMove(src, srcIndex, dest, destIndex, payloadHead, lastFaceUp);
        position++;
    } else{
        while (position != size() -1 )
            removeMove();
        recordMove(src, srcIndex, dest, destIndex, payloadHead, lastFaceUp);
    }
}

/**
 * Roll back.
 *
 * @return Null if it fails, else a pointer to a histElement.
 */

histElement* History::rollBack() {
    if (position == -1)
        return nullptr;
    return getMove(position--);
}

/**
 * Roll forward.
 *
 * @return Null if it fails, else a pointer to a histElement.
 */

histElement* History::rollForward() {
    if (position == size() -1)
        return nullptr;
    return getMove(++position);
}

/**
 * Gets the size of history stack.
 *
 * @return An int equals to size.
 */

int History::size() { return (int)gameHistElement.size();}

/**
 * Adds a move.
 *
 * @param 		   src		 Source for the.
 * @param 		   srcIndex  Zero-based index of the source.
 * @param 		   dest		 Destination for the.
 * @param 		   destIndex Zero-based index of the destination.
 * @param [in,out] paylHd    If non-null, the payl HD.
 * @param 		   lastFceUp True to last fce up.
 */

void History::addMove(boardElements src, int srcIndex, boardElements dest,
                      int destIndex, Card *paylHd, bool lastFceUp) {
    histElement tmp = {src, srcIndex, dest, destIndex, paylHd, lastFceUp};
    gameHistElement.push_back(tmp);
}

/** Remove move from stack. */
void History::removeMove() {gameHistElement.pop_back();}

/**
 * Gets a move.
 *
 * @param i Zero-based index of the game history element.
 *
 * @return Null if it fails, else the move.
 */

histElement* History::getMove(int i) { return &gameHistElement[i];}