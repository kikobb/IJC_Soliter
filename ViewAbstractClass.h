//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_VIEWABSTRACTCLASS_H
#define IJC_SOLITER_VIEWABSTRACTCLASS_H

#include "WorkingPack.h"
#include "TargetStack.h"
#include "Game.h"

class ViewAbstractClass {

public:
    virtual void refresh(WorkingPack *, int);
    virtual void refresh(TargetStack *, int);
    virtual void refresh(CardDeck *);
    virtual void refresh();
    virtual void highlight(boardElements, int, boardElements, int);
};


#endif //IJC_SOLITER_VIEWABSTRACTCLASS_H
