/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  argparser.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

#include "main.hpp"

void argparse(int argc, char** argv, int *malfunction, int *tankerC, int *USterminalC, int *GEterminalC, int *maintenanceInterval, int *fuelInterval);

#endif