/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  externship.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "externship.hpp"

using namespace std;

int externShip::externShipCounter = 0; //set number of externShip instances to 0

////// EXTERN SHIP CLASS METHODS ///////
externShip::externShip() {
    Priority = 0; //set process priority to 0
    externShipNumber = externShipCounter++;
}

void externShip::Behavior() {
    generatedWait = Uniform(20,30); // store generated wait for terminal
    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    repeatSeize:
    interrupted = false;

    Seize(TerminalUS[shortestIndex]);
    inputTime = Time;
    Wait(generatedWait); // loading cargo TODO consult Uniform - exponential is in petri net
    
    if (interrupted) {
        goto repeatSeize;
    }

    Release(TerminalUS[shortestIndex]);
    Priority = 0; // reset process priority to 0
} 
