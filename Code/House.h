#ifndef HOUSE_H
#define HOUSE_H

#include "Residential.h"

class House : public Residential {


public:
	House();
	void setIcon() override;
    Cell* clone() override;
};

#endif
