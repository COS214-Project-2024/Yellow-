/**
 * @file Office.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef OFFICE_H
#define OFFICE_H
#include "Commercial.h"
class Office : public Commercial {


public:
	Office();
	void setIcon() override;
    Cell* clone() override;
};

#endif