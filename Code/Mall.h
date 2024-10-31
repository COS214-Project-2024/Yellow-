#ifndef MALL_H
#define MALL_H
#include "Commercial.h"
class Mall : public Commercial {


public:
	Mall();
	void taxBuilding() override;
	void setIcon() override;
};

#endif