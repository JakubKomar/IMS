/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  ship.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "ship.hpp"

using namespace std;

int Ship::shipCounter = 0; //set number of Ship instances to 0

////// SHIP CLASS METHODS ///////
Ship::Ship() {
    shipCounter++; // increase number of created Ship instances
    Print("new ship number %d at time: %g \n", shipCounter, Time);
}

void Ship::Behavior() {
    int shortestIndex = 0; /*!< stores index of shortest Facility queue */
    int journeyCounter = 0; /*!< stores number of ship journeys */

    Print("Ship no. %d: Start at time %g\n", shipCounter, Time);

	repeatJourney:
	journeyStart = Time; // register journey start time
    Print("Ship no. %d: sail to USA at time %g\n", shipCounter, Time);

    Wait(Uniform(10 * DAY, 12 * DAY)); // sail to USA

    shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    Print("Ship no. %d: Picked %d USA terminal front at time %g\n", shipCounter, shortestIndex, Time);

    Seize(TerminalUS[shortestIndex]);
    Wait(Uniform(20, 30)); // loading cargo TODO consult Uniform - exponential is in petri net
    Release(TerminalUS[shortestIndex]);

    Print("Ship no. %d: Release USA terminal at time %g\n", shipCounter, Time);

    Print("Ship no. %d: fueling in USA at time %g\n", shipCounter, Time);

    Wait(Exponential(22)); // fueling

    Print("Ship no. %d: sail to germany at time %g\n", shipCounter, Time);

    Wait(Uniform(10 * DAY, 12 * DAY)); // sail to Germany

    shortestIndex = findShortestQueue(GEterminalC, TerminalGE);

    Print("Ship no. %d: Picked %d GE terminal front at time %g\n", shipCounter, shortestIndex, Time);

    Seize(TerminalGE[shortestIndex]);
    Wait(Exponential(20)); // expounding cargo TODO consult exponential by petri
    if (Time > 365*DAY) importedLng += 174000;
    Release(TerminalGE[shortestIndex]);

    Print("Ship no. %d: Release GE terminal at time %g\n", shipCounter, Time);

    // TODO add maintenance here - if branch 

    Print("Ship no. %d: fueling in Germany at time %g\n", shipCounter, Time);
    
    Wait(Exponential(22)); // fueling

    Print("\n\n --- Ship no. %d: repeat journey (no. of journeys: %d) at time: %g --- \n\n", shipCounter, ++journeyCounter, Time);

    journeyTime(Time - journeyStart); // register journey end time

    goto repeatJourney;

}
Ship::~Ship() { Print("delete ship number %d at time: %g \n", shipCounter,  Time); }    



