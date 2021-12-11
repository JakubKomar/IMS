/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  myfacility.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef MYFACILITY_HPP
#define MYFACILITY_HPP

#include <simlib.h>

/**
 * Class for Facility class inherit
 */
class myFacility : public Facility{
public:
    /**
     * getter for lenght of Q2 queue from Facility protected methods
     * @return Q2 length
     */
    int get2Length();

    /**
     * getter for first member in Q2 queue from Facility protected methods
     * @return pointer to member
     */
    Entity* getfrst();
};

#endif
