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
    this->shipNumber= shipCounter;
    shipCounter++; // increase number of created Ship instances
    Print("new ship number %d at time: %g \n", shipNumber, Time);
}

void Ship::Malfunction()
{
    bool fatalMallfunction=true;
    bool repairebleMallfucntion=true;
    double fatalMallfunctionPropability=0.005;
    double  repairebleMallfunctionPropability=0.02;
    //------do mainu-------//
    if(true)
    {
        double rand=Random();
        if((rand<=fatalMallfunctionPropability)&&fatalMallfunction)//fatal/critikal Malfunction 
        {
            cerr<<"\u001b[31m Ship has been destroyed \u001b[0m\n";
            Ship * replacement=new Ship; 
            replacement->Activate(Time + Exponential(21*DAY));    //náhrada
            this->Cancel();
        }
        else if(((rand>fatalMallfunctionPropability)&&(rand<=repairebleMallfunctionPropability))&&repairebleMallfucntion)//repaireble Malfunction
        {
            cerr<<"\u001b[33m Ship repaired on see \u001b[0m\n";
            Wait(Exponential(11*DAY));  //repair on sea
        }
        
    } 
}

void Ship::fueling(char* Harbor)
{
    Print("Ship no. %d: fueling start in %s at time %g\n", shipNumber,Harbor ,Time);
    fueling();
    Print("Ship no. %d: fueling end %s at time %g\n", shipNumber,Harbor ,Time);
}

void Ship::fueling()
{
    Wait(Exponential(22));
}

void Ship::sailing(char* Harbor)
{
    Print("Ship no. %d: sail to%s at time %g\n", shipNumber,Harbor, Time);
    sailing();
}

void Ship::sailing()
{
    Malfunction();
    Wait(Uniform(10 * DAY, 12 * DAY)); 
}

void Ship::load()
{
    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);
    Print("Ship no. %d: Picked %d USA terminal front at time %g\n", shipNumber, shortestIndex, Time);

    Seize(TerminalUS[shortestIndex]);
    Wait(Uniform(20, 30)); // loading cargo TODO consult Uniform - exponential is in petri net
    Release(TerminalUS[shortestIndex]);

    Print("Ship no. %d: Release USA terminal at time %g\n", shipNumber, Time);
}

void Ship::store()
{
    int shortestIndex = findShortestQueue(GEterminalC, TerminalGE);

    Print("Ship no. %d: Picked %d GE terminal front at time %g\n", shipNumber, shortestIndex, Time);

    Seize(TerminalGE[shortestIndex]);
    Wait(Exponential(20)); // expounding cargo TODO consult exponential by petri

    if (Time > 365*DAY) importedLng += 174000;
    Release(TerminalGE[shortestIndex]);

    Print("Ship no. %d: Release GE terminal at time %g\n", shipNumber, Time);
}

void Ship::Behavior() {

    Print("Ship no. %d: Start at time %g\n", shipNumber, Time);

	while(true)
    {
        journeyStart = Time; // register journey start time

        sailing("USA");
        
        load();

        fueling("USA");

        sailing("GE");

        store();

        // TODO add maintenance here - if branch 

        fueling("GE");

        Print("\n\n --- Ship no. %d: repeat journey (no. of journeys: %d) at time: %g --- \n\n", shipNumber, ++journeyCounter, Time);

        journeyTime(Time - journeyStart); // register journey end time

    }
}

Ship::~Ship() 
{ 
    Print("delete ship number %d at time: %g \n", shipNumber,  Time); 
}    



