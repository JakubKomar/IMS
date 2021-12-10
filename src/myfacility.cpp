/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  myfacility.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "myfacility.hpp"

using namespace std;

int myFacility::get2Length() {
    return Q2->Length();
}
Entity* myFacility::getfrst() {
    return Q2->GetFirst();
}