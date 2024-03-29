/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  generators.hpp
 *
 * @authors Jakub Komarek (xkomar33)
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
    static int generatedCounter; //!< total counter of generated German ships
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
    int terminalNumber; //!< number of terminal for which the defect was generated
    myFacility *terminal; //!< terminal pointer array for which the defect was generated
    
    /**
     * Generates terminal defect
     */
    void Behavior();
    terminalDefectGenerator(int termNum, myFacility *facility);
};

#endif