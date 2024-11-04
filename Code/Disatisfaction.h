/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
#ifndef DISATISFACTION_H
#define DISATISFACTION_H

#include "Severity.h"

class Severity;

class Disatisfaction {

    private:
        Severity* severity;

    public:
        //State methods
        Disatisfaction(Severity* sev) : severity(sev) {}
        ~Disatisfaction();
        void setSeverity(Severity* sev);
        Severity* getState();
        void handleSeverity(bool upOrDown);

};

#endif
