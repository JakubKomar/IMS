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
 * Class for terminal defect process
 */
class myFacility : public Facility{
public:
    int get2Length();
    Entity* getfrst();
};

#endif
