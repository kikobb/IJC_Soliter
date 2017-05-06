//
// Created by k on 6.5.2017.
//

#include "History.h"

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

void History::recordMove(boardElements src, int srcIndex, boardElements dest,
                         int destIndex, Card payloadHead, bool lastFaceUp) {
    if (position == size() - 1){
        addMove(src, srcIndex, dest, destIndex, payloadHead, lastFaceUp);
        position++;
    } else{
        while (position != size() -1 )
            removeMove();
        recordMove(src, srcIndex, dest, destIndex, payloadHead, lastFaceUp);
    }
}

histElement History::rollBack() {
    if (position == -1)
        return nullptr;
    return getMove(position--);
}

histElement History::rollForward() {
    if (position == size())
        return nullptr;
    return getMove(++position);
}

int History::size() { return (int)gameHistElement.size();}

void History::addMove(boardElements src, int srcIndex, boardElements dest,
                      int destIndex, Card paylHd, bool lastFceUp) {
    histElement tmp = {src, srcIndex, dest, destIndex, paylHd, lastFceUp};
    gameHistElement.push_back(tmp);
}

void History::removeMove() {gameHistElement.pop_back();}

histElement History::getMove(int i) { return gameHistElement[i];}