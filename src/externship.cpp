/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  externship.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "externship.hpp"

using namespace std;

int externShip::externShipCounter = 0; //set number of externShip instances to 0

////// EXTERN SHIP CLASS METHODS ///////
externShip::externShip() {
    externShipCounter++;
    fprintf(stderr,"new extern ship number %d at time: %g \n", externShipCounter, Time);
}

void externShip::Behavior() {
    fprintf(stderr,"Extern ship no. %d: Start at time %g\n", externShipCounter, Time);

    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    fprintf(stderr,"Extern ship no. %d: Picked %d front at time %g\n", externShipCounter, shortestIndex, Time);

    Seize(TerminalUS[shortestIndex]);
    Wait(Uniform(20, 30)); // loading cargo TODO consult Uniform - exponential is in petri net
    Release(TerminalUS[shortestIndex]);

    fprintf(stderr,"Extern ship no. %d: Release USA terminal at time %g\n", externShipCounter, Time);


    fprintf(stderr,"Extern ship no. %d: End at time %g\n", externShipCounter,Time);
}
externShip::~externShip() {
    fprintf(stderr,"delete extern ship number %d at time: %g \n", externShipCounter, Time);
}    
