/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  terminaldefect.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "terminaldefect.hpp"
#include "baseship.hpp"
#include "generators.hpp"

using namespace std;

////// TERMINAL DEFECT METHODS ///////
terminalDefect::terminalDefect(int termNum, myFacility *facility) {
    terminalNumber = termNum;
    terminal = facility;
}

void terminalDefect::Behavior() {
    Seize(terminal[terminalNumber], 1); // seize with service priority

    if (terminal[terminalNumber].get2Length() > 0) { // if another process was interrupted
    	baseShip *ship = (baseShip *)terminal[terminalNumber].getfrst(); // get the process

    	ship->interrupted = true; // set interrupted flag
    	ship->Priority = 1; // set process priority to 1
    	ship->generatedWait -= (Time - ship->inputTime); // recalculate remaining facility usage time
      
    	ship->Activate(); // activate interrupted process
    }

    Wait(Exponential(5*DAY)); // repairing defect
    Release(terminal[terminalNumber]);

    (new terminalDefectGenerator(terminalNumber, terminal))->Activate(Time+ Exponential(5*30*DAY)); // generate new terminal defect generator for given terminal number
}