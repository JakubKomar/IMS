/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  ship.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef SHIP_HPP
#define SHIP_HPP

#include "main.hpp"

/**
 * Class for German ships (tankers)
 */
class Ship : public Process {
public:
    /**
     * Ship behavior - contains ship processes
     */
    void Behavior();

    Ship();
    ~Ship();   

private: 
    static int shipCounter; /*!< total counter of initialized ships */
    double journeyStart;
};

#endif