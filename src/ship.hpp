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

    /**
     * @brief module for mallfuction on road over sea
     */
    void Malfunction();

    /**
     * @brief fueling fuction whith debug report
     */
    void fueling(char const* harbor);

    /**
     * @brief module for simulating fueling process
     */
    void fueling();

    /**
     * @brief module for simulating sailing between terminals whith debug
     */
    void sailing(char const* Harbor);

    /**
     * @brief module for simulating sailing between terminals 
    */
    void sailing();

    /**
     * @brief module for simulation of loading lng gass
     */
    void load();

    /**
     * @brief module for simulation of unloading lng gass
     */
    void store();
    Ship();
    ~Ship();   

private: 
    double journeyStart; //!< for recording journey start time
    int journeyCounter = 0; //!< store number of journeys for each ship
    int shipNumber=-1;  //!< ship identifier for debugging purposes
};

#endif