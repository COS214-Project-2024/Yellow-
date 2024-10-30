#include "IncreaseWages.h"

Policies* IncreaseWages::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if((stateType == "Disatisfaction" || stateType == "Dissatisfaction") && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mThe economy are in shambles, we are giving you more money \033[0m" << endl;
        return new Policies("IncreaseWages");
    }
    return nullptr;
}
