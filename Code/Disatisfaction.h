/**
 * @file Disatisfaction.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
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


        void lowerTaxes();
};

#endif
