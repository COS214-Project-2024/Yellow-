/**
* @class Green
* @brief Class that represents a Green severity
* @ingroup State
* @implements Severity
*
* The Green class is a concrete state participant of the State design pattern. It is used to represent a green severity.
*/
#include "Green.h"

string Green::getSeverity() {
    return "Green";
}

Severity *Green::handle(bool increment) {
    if(increment){
        cout << "\033[38;5;76m Well done, your city is doing really well! State staying green \033[0m" << endl;
        return new Green();
    }
    else{
        cout << "\033[38;5;226m Things aren't that bad yet, but keep an eye on your city. State changing to yellow\033[0m" << endl;
        return new Yellow();
    }
}
