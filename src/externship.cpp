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
    Priority = 0; //set process priority to 0
    externShipNumber = externShipCounter++;
    // fprintf(stderr,"new extern ship number %d at time: %g \n", externShipNumber, Time);
}

void externShip::Behavior() {
    // fprintf(stderr,"Extern ship no. %d: Start at time %g\n", externShipNumber, Time);

    generatedWait = Uniform(20,30); // store generated wait for terminal
    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    // fprintf(stderr,"Extern ship no. %d: Picked %d front at time %g with generated wait: %g\n", externShipNumber, shortestIndex, Time, generatedWait);

    repeatSeize:
    interrupted = false;
    Seize(TerminalUS[shortestIndex]);
    inputTime = Time;
    // fprintf(stderr, "Extern ship no. %d: inputTime:%g\n\n\n", externShipNumber, inputTime);
    Wait(generatedWait); // loading cargo TODO consult Uniform - exponential is in petri net
    if (interrupted) {
        //generatedWait -= (Time - inputTime); // calculate remaining time
        // fprintf(stderr,"Extern ship no. %d: INTERUPTEEEED at time %g in USA terminal number %d, calculated new time = %g\n", externShipNumber, Time, shortestIndex, generatedWait);
        goto repeatSeize;
    }

    Release(TerminalUS[shortestIndex]);
    Priority = 0; // reset process priority to 0

    // fprintf(stderr,"Extern ship no. %d: Release USA terminal at time %g\n", externShipNumber, Time);


    // fprintf(stderr,"Extern ship no. %d: End at time %g\n", externShipNumber,Time);
}
externShip::~externShip() {
    // fprintf(stderr,"delete extern ship number %d at time: %g \n", externShipNumber, Time);
}    
