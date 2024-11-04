/**
 * @class AddPublicTransport
 * @brief  AddPublicTransport is a concrete strategy participant of the Strategy design pattern.
 * @ingroup Strategy
 * @implements Strategy
 * @see Strategy
 * 
 * AddPublicTransport is a concrete strategy participant of the Strategy design pattern. It is used to implement a policy that adds public transport to the city.
 * 
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
