/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  terminaldefect.cpp
 *
 * @authors Jakub Komárek (xkomar33)
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
    Seize(terminal[terminalNumber], 1);

    if (terminal[terminalNumber].get2Length() > 0) {

    	fprintf(stderr,"Terminal defect at time: %g \n", Time);
    	baseShip *ship = (baseShip *)terminal[terminalNumber].getfrst();

    	ship->interrupted = true;
    	ship->recordInputTime = false;
    	ship->Priority = 1; // set process priority to 1
    	ship->generatedWait -= (Time - ship->inputTime);
      
    	ship->Activate();	
    }

    Wait(Exponential(5*DAY));
    Release(terminal[terminalNumber]);



    (new terminalDefectGenerator(terminalNumber, terminal))->Activate(Time+ Exponential(5*30*DAY));
}