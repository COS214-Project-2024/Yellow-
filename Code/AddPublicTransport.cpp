#include "AddPublicTransport.h"
 Policies* AddPublicTransport::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "Budget" && currStateColour == "Green" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mThings have been looking good. We are upgrading the public transport \033[0m" << endl;
        return new Policies("AddPublicTransport");
    }
    return nullptr;
}

