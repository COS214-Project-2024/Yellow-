/**
* @class People
* @brief Class that the state of the population
* @ingroup State
* @implements Severity
*
* The People class is a concrete state participant of the State design pattern. It is used to represent the state of the population.
*/
#include "People.h"

void People::setSeverity(Severity *sev) {
    delete this->severity;
    this->severity = sev;

}

void People::handleSeverity(bool upOrDown) {

    cout << "People: ";
    Severity* newSev = this->severity->handle(upOrDown);
    this->setSeverity(newSev);

}

People::~People() {

    delete severity;

}

Severity *People::getState() {
    return this->severity;
}
