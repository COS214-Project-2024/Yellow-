/**
* @class Budget
* @brief Class that represents the budget of the city
* @ingroup State
* @implements Severity
*
* The Budget class is a concrete state participant of the State design pattern. It is used to represent the budget of the city.
*/
#include "Budget.h"

void Budget::setSeverity(Severity *sev) {

    delete this->severity;
    this->severity = sev;

}

void Budget::handleSeverity(bool upOrDown) {

    cout << "Budget: ";
    Severity* newSev = this->severity->handle(upOrDown);
    this->setSeverity(newSev);

}

Severity *Budget::getState() {
    return this->severity;
}

Budget::~Budget() {

    delete severity;

}
