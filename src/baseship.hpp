/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  baseship.hpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef BASESHIP_HPP
#define BASESHIP_HPP

#include "main.hpp"

/**
 * Base class for extern and intern ships (tankers)
 */
class baseShip : public Process {
public:
    double inputTime; //!< store time of entrance into terminal (Facility)
    double generatedWait; //!< store generated wait for terminal
	bool interrupted; //!< tells if process was interrupted while in terminal queue
    
    /**
     * Base ship behavior
     */
    void Behavior();
    baseShip();

};

#endif