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


#define DAY 24 /*!< define 1 day - 24 hours */

extern int malfunction; /*!< German ship malfunction interval */
extern int tankerC; /*!< number of German tankers */
extern int USterminalC; /*!< number of USA terminals */
extern int GEterminalC; /*!< number of German terminals */
extern int maintenanceInterval; /*!< German ship maintenance interval */
extern int fuelInterval; /*!< German ship fueling interval */
extern unsigned long importedLng; /*!< Number of imported LNG units */

extern Facility *TerminalUS; /*!< US terminals Facility pointer */
extern Facility *TerminalGE; /*!< GE terminals Facility pointer */
extern Histogram journeyTime;

extern int shipCounter; /*!< Counter of ship */
/**
 * set all terminal names in array of facilities
 * @param terminalCount number of terminals
 * @param terminalText  generic terminal text
 * @param terminal      array of terminals
 */
void setTerminalNames(int terminalCount, const char *terminalText, Facility *terminal);

/**
 * print all terminal statistics in array of facilities
 * @param terminalCount number of terminals
 * @param terminal      array of terminals
 */
void printTerminalOutput(int terminalCount, Facility *terminal);

/**
 * Finds facility with shortest queue
 * @param  facilityCount   number of facilities
 * @param  facilityPointer pointer fo Facility array that will be searched
 * @return                 index of facility array
 */
int findShortestQueue(int facilityCount, Facility *facilityPointer);


#endif