/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  ship.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef LOGER_HPP
#define LOGER_HPP

#include "main.hpp"
/**
 * Class for German ships (tankers)
 */
class Loger : public Event {
public:
    void Behavior();
 

private: 
    unsigned long prevVal=0;
};

class LogerM : public Event {
public:
    void Behavior();  

private: 
    unsigned long prevVal=0;
};


#endif