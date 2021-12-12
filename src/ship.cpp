/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  ship.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "ship.hpp"

using namespace std;

////// SHIP CLASS METHODS ///////
Ship::Ship()  {
    Priority = 0; // set process priority to 0
    this->shipNumber= shipCounter;
    shipCounter++; // increase number of created Ship instances
}

void Ship::Malfunction() {
    if(malfuctionGeneralSwich) {
        double rand=Random();
        if((rand<=fatalMallfunctionPropability)&&fatalMallfunction) { //fatal/critical Malfunction 
            fatalLog++;
            Ship * replacement=new Ship; 
            replacement->Activate(Time + Exponential(30*DAY));    //náhrada
            this->Cancel();
        }
        else if((rand<=repairebleMallfunctionPropability+fatalMallfunctionPropability)&&repairebleMallfucntion) { //repaireble Malfunction
            repairebleLog++;
            Wait(Exponential(20*DAY));  //repair on sea
        }    
    } 
}

void Ship::fueling(char const* Harbor) {
    fueling();
}

void Ship::fueling() {
    Wait(Exponential(22));
}

void Ship::sailing(char const* Harbor) {
    sailing();
}

void Ship::sailing() {
    Malfunction();
    Wait(Uniform(10 * DAY, 12 * DAY)); 
}

void Ship::load() {
    generatedWait = Uniform(20,30); // store generated wait for Terminal
    int shortestIndex = findShortestQueue(USterminalC, TerminalUS); 

    repeatUSASeize:
    interrupted = false;

    Seize(TerminalUS[shortestIndex]);
    inputTime = Time;
    Wait(generatedWait); // loading cargo TODO consult Uniform - exponential is in petri net
    
    if (interrupted) {
        goto repeatUSASeize;
    }

    Release(TerminalUS[shortestIndex]);
    Priority = 0; // reset process priority to 0
}

void Ship::store() {
    generatedWait = Uniform(20,30); // store generated wait for terminal
    int shortestIndex = findShortestQueue(GEterminalC, TerminalGE);

    repeatGESeize:
    interrupted = false;
    
    Seize(TerminalGE[shortestIndex]);
    inputTime = Time;
    Wait(generatedWait); // expounding cargo TODO consult exponential by petri
    
    if (interrupted) {
        goto repeatGESeize;
    }

    importedLng += tankerCapacity; // raise imported LNG counter

    Release(TerminalGE[shortestIndex]);
    Priority = 0; // reset process priority to 0
}

void Ship::Behavior() {
	while(true) {
        journeyStart = Time; // register journey start time

        sailing("USA");
        
        load();

        fueling("USA");

        sailing("GE");

        store();

        fueling("GE");

        journeyTime(Time - journeyStart); // register journey end time
    }
}


