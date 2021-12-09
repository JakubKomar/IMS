/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  externship.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef EXTERNSHIP_HPP
#define EXTERNSHIP_HPP

#include "main.hpp"

/**
 * Class for extern ships (tankers) that use US terminals
 */
class externShip : public Process {
public:
    /**
     * Extern ship behavior - contains ship processes
     */
    void Behavior();

    externShip();
    ~externShip();
private:
    static int externShipCounter; /*!< total counter of initialized extern ships */
};

#endif