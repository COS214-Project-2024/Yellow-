/**
* @class People
* @brief Class that the state of the population
* @ingroup State
* @implements Severity
*
* The People class is a concrete state participant of the State design pattern. It is used to represent the state of the population.
*/
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
