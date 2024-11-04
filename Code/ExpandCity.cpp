/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
#include "ExpandCity.h"

Policies* ExpandCity::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "People" && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mApparantly we have a city of rabbits, we are expanding it to make space for all the new babies \033[0m" << endl;
        return new Policies("ExpandCity");
    }
    if(stateType == "People" && currStateColour == "Red" && prevStateColour == "Red"){
        cout << "\033[38;5;48mApparantly we have a city of rabbits, we are expanding it to make space for all the new babies \033[0m" << endl;
        return new Policies("ExpandCity");
    }

    return nullptr;

}
