/**
 * @file Red.h
 * @author Saskia Steyn
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RED_H
#define RED_H

#include "Severity.h"
#include "Yellow.h"

class Red : public Severity {
    public:
        string getSeverity() override;
        Severity *handle(bool increment) override;
};

#endif
