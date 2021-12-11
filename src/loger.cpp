/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  loger.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */


#include "loger.hpp"

void Loger::Behavior()
{

    logerPerYear.push_back(importedLng-this->prevVal);
    statPerYear(importedLng-this->prevVal);
    this->prevVal=importedLng;

    Activate(Time +DAY*365);
}
void LogerM::Behavior()
{
    logerPerMonth.push_back(importedLng- this->prevVal);
    statPerMonth(importedLng- this->prevVal);
    this->prevVal=importedLng;
    
    Activate(Time +DAY*30);
}