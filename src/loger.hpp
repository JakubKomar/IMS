/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  loger.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef LOGER_HPP
#define LOGER_HPP

#include "main.hpp"
/**
 * generating report every year
 */
class Loger : public Event {
public:
    void Behavior();

private: 
    unsigned long prevVal=0;
};
/**
 * generating report every month
 */
class LogerM : public Event {
public:
    void Behavior();  

private: 
    unsigned long prevVal=0;
};


#endif