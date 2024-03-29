/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  myfacility.cpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "myfacility.hpp"

using namespace std;

int myFacility::get2Length() {
    return Q2->Length(); // call Facility protected method
}
Entity* myFacility::getfrst() {
    return Q2->GetFirst(); // call Facility protected method
}