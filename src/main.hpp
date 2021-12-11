/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  main.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <simlib.h>
#include <getopt.h>
#include <iomanip>

#include "myfacility.hpp"

#define DAY 24 //!< define 1 day - 24 hours
using namespace std;

extern int malfunction; //!< German ship malfunction interval
extern int tankerC; //!< number of German tankers
extern int USterminalC; //!< number of USA terminals
extern int GEterminalC; //!< number of German terminals
extern int maintenanceInterval; //!< German ship maintenance interval
extern unsigned long importedLng; //!< Number of imported LNG units

extern myFacility *TerminalUS; //!< US terminals Facility pointer
extern myFacility *TerminalGE; //!< GE terminals Facility pointer
extern Histogram journeyTime; //!< Histogram for needed journey time - from Germany to USA and back

extern vector<unsigned int> logerPerMonth; //!< for storing number of imported gas per month
extern vector<unsigned int> logerPerYear; //!< for storing number of imported gas per year

extern Stat statPerMonth; //!< statistics for imported gas per month
extern Stat statPerYear; //!< statistics for imported gas per year

extern int shipCounter; //!< counter of German ships
extern int tankerCapacity; //!< number of total number of German ships requested on init

extern bool fatalMallfunction; //!< fatal malfunction switch
extern bool repairebleMallfucntion; //!< repairable malfunction switch
extern double fatalMallfunctionPropability; //!< fatal malfunction probability
extern double  repairebleMallfunctionPropability; //!< repairable malfunction probability
extern bool malfuctionGeneralSwich; //!< malfunction switch
extern unsigned int duration; //!< simulation duration in years
extern int repairebleLog; //!< log for number of repairable malfunction
extern int fatalLog; //!< log for number of fatal malfunction
/**
 * set all terminal names in array of facilities
 * @param terminalCount number of terminals
 * @param terminalText  generic terminal text
 * @param terminal      array of terminals
 */
void setTerminalNames(int terminalCount, const char *terminalText, myFacility *terminal);

/**
 * create instances of terminal defect generators 
 * @param terminalCount number of terminals
 * @param terminal      array of terminals
 */
void instantiateTerminalDefect(int terminalCount, myFacility *terminal);

/**
 * print all terminal statistics in array of facilities
 * @param terminalCount number of terminals
 * @param terminal      array of terminals
 */
void printTerminalOutput(int terminalCount, myFacility *terminal);

/**
 * Finds facility with shortest queue
 * @param  facilityCount   number of facilities
 * @param  facilityPointer pointer fo Facility array that will be searched
 * @return                 index of facility array
 */
int findShortestQueue(int facilityCount, myFacility *facilityPointer);

/**
 * print gathered statistics
 */
void printStats();
#endif