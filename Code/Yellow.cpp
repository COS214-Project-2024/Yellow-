/**
* @class Yellow
* @brief A class used to indicate the state of the city
* @ingroup State
* @implements Severity
*
* The Yellow class is a concrete state participant of the State design pattern. It is used to indicate that the city is in a state of caution.
*/
#include "Yellow.h"

string Yellow::getSeverity() {
    return "Yellow";
}

Severity *Yellow::handle(bool increment) {
    if(increment){
        cout << "\033[38;5;76m Things are looking better! State changing to green \033[0m" << endl;
        return new Green();
    }
    else{
        cout << "\033[38;5;9m Oh oh... you need to pay attention! State changing to red \033[0m" << endl;
        return new Red();
    }
}
