/**
 * @file History.h.
 *
 * @author xbarna02
 * 
 * Declares the history class.
 */

#ifndef IJC_SOLITER_HISTORY_H
#define IJC_SOLITER_HISTORY_H

#include "Game.h"

/** A hist element. */
struct histElement{
    boardElements src;
    int srcIndex;
    boardElements dest;
    int destIndex;
    Card* payloadHead;
    bool lastaFaceUp;
};

/** A history. */
class History {

public:
    void recordMove(boardElements src, int srcIndex, boardElements dest,
                    bool lastFaceUp);
    void recordMove(boardElements src, int srcIndex, boardElements dest,
                    int destIndex, bool lastFaceUp);
    void recordMove(boardElements src, int srcIndex, boardElements dest,
                    int destIndex, Card *payloadHead, bool lastFaceUp);
    histElement* rollBack();
    histElement* rollForward();

private:
    std::vector<struct histElement> gameHistElement;
    int position = -1;

    int size();
    void addMove(boardElements src, int srcIndex, boardElements dest,
                        int destIndex, Card *paylHd, bool lastFceUp);
    void removeMove();
    histElement* getMove(int);

};


#endif //IJC_SOLITER_HISTORY_H
