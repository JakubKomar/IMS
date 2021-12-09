/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  main.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "main.hpp"
#include "argparser.hpp"
#include "ship.hpp"
#include "externship.hpp"
#include "generators.hpp"

using namespace std;

//global variables - defined in main.hpp with description
int malfunction = 0;
int tankerC = 10;
int USterminalC = 6;
int GEterminalC = 2;
int maintenanceInterval = 7 * DAY; // each week
int fuelInterval = 1 * DAY; // each day TODO calculate if given day interval corresponds to number of trips
unsigned long importedLng = 0;


Facility *TerminalUS; /*!< US terminals Facility pointer */
Facility *TerminalGE; /*!< GE terminals Facility pointer */
Histogram journeyTime("Time needed for journey to USA and back", 20 * DAY, 10, 30);

int shipCounter=0;
//Uniform(0,100); -- rovnomerne rozlozeni

void setTerminalNames(int terminalCount, const char *terminalText, Facility *terminal) {
    for (int i = 0; i < terminalCount; i++) {
        string termName = terminalText + to_string(i + 1); // add number to generic text
        cout << termName << endl;

        terminal[i].SetName(termName.c_str()); // set i-th terminal name
    }
}

void printTerminalOutput(int terminalCount, Facility *terminal) {
    for (int i = 0; i < terminalCount; i++)
    {
        terminal[i].Output();
    }
}

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

int main(int argc, char** argv)
{
    argparse(argc, argv, &malfunction, &tankerC, &USterminalC, &GEterminalC, &maintenanceInterval, &fuelInterval);

    // create local facilities according to input parameters and assign them to global pointer
    Facility TerminalUSTemp[USterminalC]; 
    TerminalUS = TerminalUSTemp;
    
    Facility TerminalGETemp[GEterminalC];
    TerminalGE = TerminalGETemp;

    // set name for each terminal
    setTerminalNames(USterminalC, "US terminal number ", TerminalUS);
    setTerminalNames(GEterminalC, "GE terminal number ", TerminalGE);

    RandomSeed(time(NULL));

    Print("\n===== BEGIN =====\n");
    
    Print("\n===== Init =====\n");
    Init(0, 2*365*DAY); //TODO change end time
    
    (new externShipGenerator)->Activate(Time + 50); //TODO change generation time
    (new shipGenerator)->Activate(); //TODO change generation time

    
    Print("\n===== Run =====\n");
    Run();

    // print statistics
    printTerminalOutput(USterminalC, TerminalUS);
    printTerminalOutput(GEterminalC, TerminalGE);
    journeyTime.Output();

    cout << importedLng << endl;

    return 0;
}
