/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  ship.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "ship.hpp"

using namespace std;

////// SHIP CLASS METHODS ///////
Ship::Ship() 
{
    Priority = 0; // set process priority to 0
    this->shipNumber= shipCounter;
    shipCounter++; // increase number of created Ship instances
    // fprintf(stderr,"new ship number %d at time: %g \n", shipNumber, Time);
}

void Ship::Malfunction()
{
    if(malfuctionGeneralSwich)
    {
        double rand=Random();
        if((rand<=fatalMallfunctionPropability)&&fatalMallfunction)//fatal/critical Malfunction 
        {
            fatalLog++;
            // cerr<<"\u001b[31m Ship has been destroyed \u001b[0m\n";
            Ship * replacement=new Ship; 
            replacement->Activate(Time + Exponential(30*DAY));    //náhrada
            this->Cancel();
        }
        else if((rand<=repairebleMallfunctionPropability+fatalMallfunctionPropability)&&repairebleMallfucntion)//repaireble Malfunction
        {
            repairebleLog++;
            // cerr<<"\u001b[33m Ship repaired on see \u001b[0m\n";
            Wait(Exponential(20*DAY));  //repair on sea
        }    
    } 
}

void Ship::fueling(char const* Harbor)
{
    // fprintf(stderr,"Ship no. %d: fueling start in %s at time %g\n", shipNumber,Harbor ,Time);
    fueling();
    // fprintf(stderr,"Ship no. %d: fueling end %s at time %g\n", shipNumber,Harbor ,Time);
}

void Ship::fueling()
{
    Wait(Exponential(22));
}

void Ship::sailing(char const* Harbor)
{
    // fprintf(stderr,"Ship no. %d: sail to%s at time %g\n", shipNumber,Harbor, Time);
    sailing();
}

void Ship::sailing()
{
    Malfunction();
    Wait(Uniform(10 * DAY, 12 * DAY)); 
}

void Ship::load()
{
    generatedWait = Uniform(20,30); // store generated wait for Terminal
    int shortestIndex = findShortestQueue(USterminalC, TerminalUS); 
    // fprintf(stderr,"Ship no. %d: Picked %d USA terminal front at time %g with generated wait: %g\n", shipNumber, shortestIndex, Time, generatedWait);

    repeatUSASeize:
    interrupted = false;
    Seize(TerminalUS[shortestIndex]);
    inputTime = Time;
    // fprintf(stderr, "Ship no. %d: inputTime:%g\n\n\n", shipNumber, inputTime);
    Wait(generatedWait); // loading cargo TODO consult Uniform - exponential is in petri net
    
    if (interrupted) {
        //generatedWait -= (Time - inputTime); // calculate remaining time
        // fprintf(stderr,"Ship no. %d: INTERUPTEEEED at time %g in USA terminal number %d, calculated new time = %g\n", shipNumber, Time, shortestIndex, generatedWait);
        goto repeatUSASeize;
        
    }

    Release(TerminalUS[shortestIndex]);
    Priority = 0; // reset process priority to 0
    recordInputTime = true;

    // fprintf(stderr,"Ship no. %d: Release USA terminal at time %g\n", shipNumber, Time);
}

void Ship::store()
{
    generatedWait = Uniform(20,30); // store generated wait for terminal
    int shortestIndex = findShortestQueue(GEterminalC, TerminalGE);

    // fprintf(stderr,"Ship no. %d: Picked %d GE terminal front at time %g with generated wait: %g\n", shipNumber, shortestIndex, Time, generatedWait);

    repeatGESeize:
    interrupted = false;
    Seize(TerminalGE[shortestIndex]);
    inputTime = Time;
    // fprintf(stderr, "Ship no. %d: inputTime:%g\n\n\n", shipNumber, inputTime);
    Wait(generatedWait); // expounding cargo TODO consult exponential by petri
    
    if (interrupted) {
        //generatedWait = Time - generatedWait; // calculate remaining time
        // fprintf(stderr,"Ship no. %d: INTERUPTEEEED at time %g in GE terminal number %d, calculated new time = %g\n", shipNumber,Time, shortestIndex, generatedWait);
        goto repeatGESeize;
    }

    importedLng += tankerCapacity; // raise imported LNG counter

    Release(TerminalGE[shortestIndex]);
    Priority = 0; // reset process priority to 0
    recordInputTime = true;

    // fprintf(stderr,"Ship no. %d: Release GE terminal at time %g\n", shipNumber, Time);
}

void Ship::Behavior() {

    // fprintf(stderr,"Ship no. %d: Start at time %g\n", shipNumber, Time);

	while(true)
    {
        journeyStart = Time; // register journey start time

        sailing("USA");
        
        load();

        fueling("USA");

        sailing("GE");

        store();

        fueling("GE");

        // fprintf(stderr,"\n\n --- Ship no. %d: repeat journey (no. of journeys: %d) at time: %g --- \n\n", shipNumber, ++journeyCounter, Time);

        journeyTime(Time - journeyStart); // register journey end time

    }
}

Ship::~Ship() 
{ 
    // fprintf(stderr,"delete ship number %d at time: %g \n", shipNumber,  Time); 
}    



