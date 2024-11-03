#ifndef MALL_H
#define MALL_H
#include "Commercial.h"
class Mall : public Commercial {


public:
	Mall();
	void setIcon() override;
    Cell* clone() override;
};

#endif