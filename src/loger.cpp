/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  loger.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */


#include "loger.hpp"

void Loger::Behavior() {

    logerPerYear.push_back(importedLng-this->prevVal); // log new value
    statPerYear(importedLng-this->prevVal); // log new statistics value
    this->prevVal=importedLng; // remember value for next run

    Activate(Time +DAY*365); // activate after one year
}
void LogerM::Behavior() {
    logerPerMonth.push_back(importedLng- this->prevVal); // log new value
    statPerMonth(importedLng- this->prevVal); // log new statistics value
    this->prevVal=importedLng; // remember value for next run
    
    Activate(Time +DAY*30); // activate after one month
}