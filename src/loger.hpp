/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  loger.hpp
 *
 * @authors Jakub Komarek (xkomar33)
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
    /**
     * Loger behavior - log year statistics
     */
    void Behavior();

private: 
    unsigned long prevVal=0;
};
/**
 * generating report every month
 */
class LogerM : public Event {
public:
    /**
     * LogerM behavior - log month statistics
     */
    void Behavior();  

private: 
    unsigned long prevVal=0; //!< for remembering previous value of import
};


#endif