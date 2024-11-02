#ifndef OFFICE_H
#define OFFICE_H
#include "Commercial.h"
class Office : public Commercial {


public:
	void taxBuilding();
	Office();
	void setIcon() override;
};

#endif