/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  baseship.hpp
 *
 * @authors Jakub Komárek (xkomar33)
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
    double inputTime;
    double generatedWait;
	bool interrupted; /*!< tells if process was interrupted while in terminal queue */
    bool recordInputTime;
    /**
     * Base ship behavior
     */
    void Behavior();
    baseShip();

};

#endif