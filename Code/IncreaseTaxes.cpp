/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#include "IncreaseTaxes.h"

Policies* IncreaseTaxes::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "Budget" && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mNew policy implemented. Taxes will be raised by 20% \033[0m" << endl;
        return new Policies("IncreaseTaxes");
    }
    return nullptr;
}
