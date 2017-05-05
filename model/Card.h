//
// Created by k on 5.5.2017.
//

#ifndef IJC_SOLITER_CARD_H
#define IJC_SOLITER_CARD_H

//todo daj to do common header

enum Color{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

//return true ak su karty rovnakej farby
#define similarColors(a, b) (\
                            (((a) == DIAMONDS || (a) == HEARTS) && ((b) == DIAMONDS || (b) == HEARTS)) ||\
                            (((a) == SPADES || (a) == CLUBS) && ((b) == SPADES || (b) == CLUBS))\
                            )


#endif //IJC_SOLITER_CARD_H
