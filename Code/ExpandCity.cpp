#include "ExpandCity.h"

Policies* ExpandCity::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "People" && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mApparantly we have a city of rabbits, we are expanding it to make space for all the new babies \033[0m" << endl;
        return new Policies("ExpandCity");
    }

    return nullptr;

}
