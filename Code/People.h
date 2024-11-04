#ifndef PEOPLE_H
#define PEOPLE_H

#include "Severity.h"

class Severity;

class People {

    private:
        Severity* severity;

    public:
        //State pattern methods
        People(Severity* sev) : severity(sev) {}
        ~People();
        void setSeverity(Severity* sev);
        void handleSeverity(bool upOrDown);
        Severity* getState();

};

#endif
