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


#define DAY 24 // 1 day is 24 hours

int findShortestQueue(int facilityCount, Facility *facilityPointer);

class Ship : public Process {
public:
    void Behavior();
    Ship();
    ~Ship();   

private: 
    static int shipCounter;
};

class externShip : public Process {
public:
    void Behavior();
    externShip();
    ~externShip();
private:
    static int externShipCounter;
};


#endif