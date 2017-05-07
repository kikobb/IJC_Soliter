//
// Created by xuhlia03
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
    //virtual void highlight(helpData)=0;
};


#endif //IJC_SOLITER_VIEWABSTRACTCLASS_H
