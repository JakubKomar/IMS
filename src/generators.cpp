/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  generators.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "generators.hpp"
#include "ship.hpp"
#include "externship.hpp"

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
	Activate(Time + 9); //TODO change generation time
}
