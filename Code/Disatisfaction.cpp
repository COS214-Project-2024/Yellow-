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

void Disatisfaction::lowerTaxes() {
	// TODO - implement Disatisfaction::lowerTaxes
	throw "Not yet implemented";
}

Severity *Disatisfaction::getState() {
    return this->severity;
}

Disatisfaction::~Disatisfaction() {

    delete this->severity;

}
