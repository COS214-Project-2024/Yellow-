/**
 * @class AddPublicTransport
 * @brief  AddPublicTransport is a concrete strategy participant of the Strategy design pattern.
 * @ingroup Strategy
 * @implements Strategy
 * @see Strategy
 * 
 * AddPublicTransport is a concrete strategy participant of the Strategy design pattern. It is used to implement a policy that adds public transport to the city.
 * 
 */
#include "AddPublicTransport.h"
 Policies* AddPublicTransport::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "Budget" && currStateColour == "Green" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mThings have been looking good. We are upgrading the public transport \033[0m" << endl;
        return new Policies("AddPublicTransport");
    }
    return nullptr;
}

