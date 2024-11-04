/**
 * @file People.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
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

        void increaseDisatidfaction();

};

#endif
