/**
 * @file ViewAbstractClass.h.
 * 
 * @author xuhlia03
 * 		   
 * Declares the view abstract class class.
 */

#ifndef IJC_SOLITER_VIEWABSTRACTCLASS_H
#define IJC_SOLITER_VIEWABSTRACTCLASS_H

#include "WorkingPack.h"
#include "TargetStack.h"
#include "ControllerAbstractClass.h"

/** A view abstract class. */
class ViewAbstractClass {

public:
    virtual void setGameController(ControllerAbstractClass *)=0;
    virtual void refresh(WorkingPack *, int)=0;
    virtual void refresh(TargetStack *, int)=0;
    virtual void refresh(CardDeck *)=0;
    virtual void refresh()=0;
    virtual void initClosure()=0;
    virtual void print()=0;
    virtual void gameWon()=0;
};


#endif //IJC_SOLITER_VIEWABSTRACTCLASS_H
