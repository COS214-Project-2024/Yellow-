#ifndef COMPLEX_H
#define COMPLEX_H
#include "Residential.h"
class Complex : public Residential {


public:
	Complex();
    Cell* clone() override;
    void setIcon() override;
};

#endif