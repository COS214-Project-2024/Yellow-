#ifndef TOWNHALL_H
#define TOWNHALL_H
#include "Service.h"
class TownHall : public Service {
public:
    TownHall();
    Cell* clone() override;
};

#endif
