/**
* @class IncreaseTaxes
* @brief IncreaseTaxes is a concrete strategy participant of the Strategy design pattern.
* @ingroup Strategy
* @implements Strategy
*
* IncreaseTaxes is a concrete strategy participant of the Strategy design pattern. It is used to implement a policy that increases taxes in the city.
*/
#include "IncreaseTaxes.h"

Policies* IncreaseTaxes::implementPolicy(string stateType, string prevStateColour, string currStateColour) {
    if(stateType == "Budget" && currStateColour == "Red" && prevStateColour == "Yellow"){
        cout << "\033[38;5;48mNew policy implemented. Taxes will be raised by 20% \033[0m" << endl;
        return new Policies("IncreaseTaxes");
    }
    return nullptr;
}
