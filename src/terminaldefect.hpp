/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  terminaldefect.hpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef TERMINALDEFECT_HPP
#define TERMINALDEFECT_HPP

#include "main.hpp"

/**
 * Class for terminal defect process
 */
class terminalDefect : public Process {
public:
	int terminalNumber; //!< number of terminal for which the defect was generated
    myFacility *terminal; //!< terminal pointer array for which the defect was generated

    /**
     * Terminal defect behavior - contains defect processes
     */
    void Behavior();

    terminalDefect(int termNum, myFacility *facility);
};

#endif
