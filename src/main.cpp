/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  main.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "main.hpp"
#include "argparser.hpp"
#include "baseship.hpp"
#include "ship.hpp"
#include "externship.hpp"
#include "generators.hpp"
#include "loger.hpp"
#include "terminaldefect.hpp"

using namespace std;

//setup config
   
    int fuelInterval = 1 * DAY; // each day TODO calculate if given day interval corresponds to number of trips

    //us harbor config
        int USterminalC = 6; 
    //ge harbor config
        int GEterminalC = 2;
    //tanker config
        int tankerC = 10;   //tanker count
        int tankerCapacity=174000;  //capacity of one tanker in m3
//end setup config

//simulation config
    unsigned int duration=5;//duration of simulation in years
    int maintenanceInterval = 7 * DAY; // each week
//end simulation config 

//mallfunctions
    int malfunction = 0;

    //tanker mallfuctions
    bool fatalMallfunction=true;
    bool repairebleMallfucntion=true;
    double fatalMallfunctionPropability=0.002;      //probability that tanker on way get fatal mallfunction
    double  repairebleMallfunctionPropability=0.02; //probability that tanker on way get repaireble mallfunction
//end mallfunctions 

//log vars
    unsigned long importedLng = 0;  
    Histogram journeyTime("Time needed for journey to USA and back", 20 * DAY, 10, 30);

    Stat statPerMonth;
    Stat statPerYear;

    vector<unsigned int> logerPerMonth;
    vector<unsigned int> logerPerYear;
    int shipCounter=0;
//end log vars


myFacility *TerminalUS; /*!< US terminals Facility pointer */
myFacility *TerminalGE; /*!< GE terminals Facility pointer */


int main(int argc, char** argv)
{
    argparse(argc, argv, &malfunction, &tankerC, &USterminalC, &GEterminalC, &maintenanceInterval, &fuelInterval);

    // create local facilities according to input parameters and assign them to global pointer
    myFacility TerminalUSTemp[USterminalC]; 
    TerminalUS = TerminalUSTemp;
    
    myFacility TerminalGETemp[GEterminalC];
    TerminalGE = TerminalGETemp;

    // set name for each terminal
    setTerminalNames(USterminalC, "US terminal number ", TerminalUS);
    setTerminalNames(GEterminalC, "GE terminal number ", TerminalGE);

    RandomSeed(time(NULL));

    Init(0, duration*365*DAY); //TODO change end time
    
    (new externShipGenerator)->Activate(Time + 50); //TODO change generation time
    (new shipGenerator)->Activate(); //TODO change generation time

    instantiateTerminalDefect(USterminalC, TerminalUS);
    instantiateTerminalDefect(GEterminalC, TerminalGE);

    (new Loger)->Activate(Time+362*DAY);
    (new LogerM)->Activate(Time+30*DAY);

    Run();

    printStats();

    return 0;
}

void setTerminalNames(int terminalCount, const char *terminalText, myFacility *terminal) {
    for (int i = 0; i < terminalCount; i++) {
        string termName = terminalText + to_string(i + 1); // add number to generic text
        cout << termName << endl;

        terminal[i].SetName(termName.c_str()); // set i-th terminal name
    }
}

void instantiateTerminalDefect(int terminalCount, myFacility *terminal) {
    for (int i = 0; i < terminalCount; i++) {
        (new terminalDefectGenerator(i, terminal))->Activate(Time + 700);
    }
}

void printTerminalOutput(int terminalCount, myFacility *terminal) {
    for (int i = 0; i < terminalCount; i++){
        terminal[i].Output();
    }
}

int findShortestQueue(int facilityCount, myFacility *facilityPointer) {
    int shortesti = 0; // index of terminal with shortest queue

    // finding index of shortest queue
    for (int i = 1; i < facilityCount; i++) {
        if (facilityPointer[i].QueueLen() < facilityPointer[shortesti].QueueLen()) {
            shortesti = i;
        }
    }
    return shortesti;
}

void printStats()
{
    printTerminalOutput(USterminalC, TerminalUS);
    printTerminalOutput(GEterminalC, TerminalGE);
    journeyTime.Output();



    cout<<"imported gas per month:\n";
    statPerMonth.Output();
    int j=1;
    for (auto i : logerPerMonth)
    {
        cout <<setw(3)<< j <<":"<< i << '\n';
        if(!(j%12))
            cout<<"--------------------\n";
        j++;
    }
    cout<<"\n";


    cout<<"imported gas per year:\n";
    statPerYear.Output();
    j=1;
    for (auto i : logerPerYear)
    {
        cout <<setw(3)<<j <<":"<< i << '\n';
        j++;
    }
    cout<<"\n";

    cout <<"total transported:"<< importedLng << endl;
}