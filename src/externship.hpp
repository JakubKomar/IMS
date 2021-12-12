/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  externship.hpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef EXTERNSHIP_HPP
#define EXTERNSHIP_HPP

#include "main.hpp"
#include "baseship.hpp"

/**
 * Class for extern ships (tankers) that use US terminals
 */
class externShip : public baseShip {
public:
    /**
     * Extern ship behavior - contains ship processes
     */
    void Behavior();

    externShip();

private:
    static int externShipCounter; //!< total counter of initialized extern ships
    int externShipNumber; //!< extern ship index for debugging purposes
};

#endif