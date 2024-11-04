/**
 * @file Yellow.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef YELLOW_H
#define YELLOW_H

#include "Severity.h"
#include "Green.h"
#include "Red.h"

class Yellow : public Severity {
    public:
        string getSeverity() override;
        Severity *handle(bool increment) override;

};

#endif
