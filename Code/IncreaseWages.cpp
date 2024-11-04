/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#include "IncreaseWages.h"

Policies* IncreaseWages::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if((stateType == "Disatisfaction" || stateType == "Dissatisfaction") && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mThe economy are in shambles, we are giving you more money \033[0m" << endl;
        return new Policies("IncreaseWages");
    }
    return nullptr;
}
