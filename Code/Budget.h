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
#ifndef BUDGET_H
#define BUDGET_H

#include "Severity.h"

class Budget {

    private:
        Severity* severity;

    public:
        //State methods
        Budget(Severity* sev) : severity(sev) {}
        ~Budget();
        void setSeverity(Severity* sev);
        void handleSeverity(bool upOrDown);
        Severity* getState();
};

#endif