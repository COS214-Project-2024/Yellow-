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

void Budget::increaseTaxes() {
	// TODO - implement Budget::increaseTaxes
	throw "Not yet implemented";
}

Severity *Budget::getState() {
    return this->severity;
}

Budget::~Budget() {

    delete severity;

}
