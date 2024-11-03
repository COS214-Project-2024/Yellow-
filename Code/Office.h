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