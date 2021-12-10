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
#include "baseship.hpp"
#include "string"

/**
 * Class for German ships (tankers)
 */
class Ship : public baseShip {
public:
    /**
     * Ship behavior - contains ship processes
     */
    void Behavior();
    void Malfunction();
    void fueling(char const* harbor);
    void fueling();
    void sailing(char const* Harbor);
    void sailing();
    void load();
    void store();
    Ship();
    ~Ship();   

private: 
    double journeyStart;
    int journeyCounter = 0;
    int shipNumber=-1;
};

#endif