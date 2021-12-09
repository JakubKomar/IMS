/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  main.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "main.hpp"
#include "argparser.hpp"

using namespace std;

int malfunction=0;
int tankerC = 10;
int USterminalC = 6;
int GEterminalC = 2;
int maintenanceInterval = 7 * DAY; // each week
int fuelInterval = 1 * DAY; // each day TODO calculate if given day interval corresponds to number of trips

Facility *TerminalUS; // US terminals pointer

int Ship::shipCounter = 0; //set number of Ship instances to 0
int externShip::externShipCounter = 0; //set number of externShip instances to 0

//Uniform(0,100); -- rovnomerne rozlozeni

int findShortestQueue(int facilityCount, Facility *facilityPointer) {
    int shortesti = 0; // index of terminal with shortest queue

    // finding index of shortest queue
    for (int i = 1; i < facilityCount; i++) {
        if (facilityPointer[i].QueueLen() < facilityPointer[shortesti].QueueLen()) {
            shortesti = i;
        }
    }
    return shortesti;
}

////// SHIP CLASS METHODS ///////
Ship::Ship() {
    shipCounter++; // increase number of created Ship instances
    Print("new ship number %d at time: %g \n", shipCounter, Time);
}

void Ship::Behavior() {
    Print("Ship no. %d: Start at time %g\n", shipCounter, Time);

    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    Print("Ship no. %d: Picked %d front at time %g\n", shipCounter, shortestIndex, Time);

    Seize(TerminalUS[shortestIndex]);
    Wait(200); //TODO add interval
    Release(TerminalUS[shortestIndex]);

    Print("Ship no. %d: Release terminal at time %g\n", shipCounter, Time);
}
Ship::~Ship() { Print("delete ship number %d at time: %g \n", shipCounter,  Time); }    

////// EXTERN SHIP CLASS METHODS ///////
externShip::externShip() {
    externShipCounter++;
    Print("new extern ship number %d at time: %g \n", externShipCounter, Time);
}

void externShip::Behavior() {
    Print("Extern ship no. %d: Start at time %g\n", externShipCounter, Time);

    int shortestIndex = findShortestQueue(USterminalC, TerminalUS);

    Print("Extern ship no. %d: Picked %d front at time %g\n", externShipCounter, shortestIndex, Time);

    Seize(TerminalUS[shortestIndex]);
    Wait(200); //TODO add interval
    Release(TerminalUS[shortestIndex]);


    Print("Extern ship no. %d: End at time %g\n", externShipCounter,Time);
}
externShip::~externShip() {
    Print("delete extern ship number %d at time: %g \n", externShipCounter, Time);
}    


////// US HARBOR CLASS METHODS ///////
class HarborUS : public Process{
    void Behavior()
    {

    }
};

////// GE HARBOR CLASS METHODS ///////
class HarborGE : public Process{
    void Behavior()
    {

    }
};

class externShipGenerator : public Event {
    void Behavior() {
        (new externShip)->Activate();
        Activate(Time + 50); //TODO change generation time
    }
};

class shipGenerator : public Event {
    void Behavior() {
        (new Ship)->Activate();
        Activate(Time + 50); //TODO change generation time
    }
};


int main(int argc, char** argv)
{
    

    argparse(argc, argv, &malfunction, &tankerC, &USterminalC, &GEterminalC, &maintenanceInterval, &fuelInterval);

    Facility TerminalUStemp[USterminalC];
    TerminalUS = TerminalUStemp;

    for (int i = 0; i < USterminalC; i++) {
        string termName = "US terminal number " + to_string(i+1);
        cout << termName << endl;
        TerminalUS[i].SetName(termName.c_str());
    }

    Print("\n===== BEGIN =====\n");
    
    Print("\n===== Init =====\n");
    Init(0, 600); //TODO change end time
    
    //(new externShipGenerator)->Activate(Time + 50); //TODO change generation time
    (new shipGenerator)->Activate(Time + 50); //TODO change generation time
    
    Print("\n===== Run =====\n");
    Run();


    for (int i = 0; i < USterminalC; i++)
    {
        TerminalUS[i].Output();
    }

    return 0;
}
