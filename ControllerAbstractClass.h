//
// Created by k on 9.5.2017.
//

#ifndef IJC_SOLITER_CONTROLLERABSTRACTCLASS_H_H
#define IJC_SOLITER_CONTROLLERABSTRACTCLASS_H_H

#include "Game.h"

class ControllerAbstractClass{

public:
    virtual void rollBack()=0;
    virtual void rollForward()=0;
    virtual bool move(boardElements src, int srcIndex, boardElements dest,
               int destIndex, Card *payloadHead = nullptr, bool histBlock = false)=0;
    virtual void initGame()=0;
    //virtual void help()=0;
    //virtual bool save(std::string)=0;
    //virtual void load(std::string)=0;
};

#endif //IJC_SOLITER_CONTROLLERABSTRACTCLASS_H_H
