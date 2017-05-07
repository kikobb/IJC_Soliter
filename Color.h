/**
 * @file Color.h.
 *
 * @author xbarna02
 * 	
 * Declares the color class.
 */

#ifndef IJC_SOLITER_COLOR_H
#define IJC_SOLITER_COLOR_H

enum Color{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

//return true ak su karty rovnakej farby
#define ARE_SIMILAR(a, b) (\
                            (((a) == DIAMONDS || (a) == HEARTS) && ((b) == DIAMONDS || (b) == HEARTS)) ||\
                            (((a) == SPADES || (a) == CLUBS) && ((b) == SPADES || (b) == CLUBS))\
                            )
#define GET_FIRST CLUBS

#define GET_LAST SPADES

#endif //IJC_SOLITER_COLOR_H
