/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  generators.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef GENERATORS_HPP
#define GENERATORS_HPP

#include "main.hpp"

/**
 * Class for generating German ships (tankers)
 */
class shipGenerator : public Event {
public:
    /**
     * Generates German ships (tankers)
     */
    void Behavior();

private:
    static int generatedCounter; /*!< total counter of generated German ships */
};

/**
 * Class for generating extern ships (tankers)
 */
class externShipGenerator : public Event {
public:
    /**
     * Generates extern ships (tankers)
     */
    void Behavior();
};

/**
 * Class for generating terminal defect
 */
class terminalDefectGenerator : public Event {
public:
    int terminalNumber;
    myFacility *terminal;
    /**
     * Generates terminal defect
     */
    void Behavior();
    terminalDefectGenerator(int termNum, myFacility *facility);
};

#endif