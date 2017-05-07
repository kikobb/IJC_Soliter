//
// Created by k on 6.5.2017.
//

#ifndef IJC_SOLITER_VIEWABSTRACTCLASS_H
#define IJC_SOLITER_VIEWABSTRACTCLASS_H

#include "WorkingPack.h"
#include "TargetStack.h"

class ViewAbstractClass {

public:
    virtual void refresh(WorkingPack *, int)=0;
    virtual void refresh(TargetStack *, int)=0;
    virtual void refresh(CardDeck *)=0;
    virtual void refresh()=0;
    virtual void highlight(boardElements, int, boardElements, int);
};


#endif //IJC_SOLITER_VIEWABSTRACTCLASS_H
