/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  generators.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "generators.hpp"
#include "ship.hpp"
#include "externship.hpp"
#include "terminaldefect.hpp"

using namespace std;

int shipGenerator::generatedCounter = 0; //set number of generated German ships to 0

////// SHIP GENERATOR ///////
void shipGenerator::Behavior() {
    if (generatedCounter < tankerC) {
        (new Ship)->Activate();
        generatedCounter++;
        Activate();
    }
}

////// EXTERN SHIP GENERATOR ///////
void externShipGenerator::Behavior() {
    (new externShip)->Activate();
	Activate(Time + 8);
}

////// TERMINAL DEFECT GENERATOR METHODS ///////
terminalDefectGenerator::terminalDefectGenerator(int termNum, myFacility *facility) {
    terminalNumber = termNum;
    terminal = facility;
}

void terminalDefectGenerator::Behavior() {
    (new terminalDefect(terminalNumber, terminal))->Activate();
}
