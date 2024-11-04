/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
#include "Disatisfaction.h"

void Disatisfaction::setSeverity(Severity *sev) {
    delete this->severity;
    this->severity = sev;

}

void Disatisfaction::handleSeverity(bool upOrDown) {

    cout << "Morale: ";
    Severity* newSev = this->severity->handle(upOrDown);
    this->setSeverity(newSev);

}


Severity *Disatisfaction::getState() {
    return this->severity;
}

Disatisfaction::~Disatisfaction() {

    delete this->severity;

}
