/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  terminaldefect.hpp
 *
 * @authors Jakub Komárek (xkomar33)
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
	int terminalNumber;
    myFacility *terminal;

    /**
     * Extern ship behavior - contains ship processes
     */
    void Behavior();

    terminalDefect(int termNum, myFacility *facility);
};

#endif
