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