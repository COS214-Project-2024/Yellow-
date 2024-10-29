#ifndef WATERPLANT_H
#define WATERPLANT_H
#include "Utilities.h"
class WaterPlant : public Utilities {
    public:
    WaterPlant();
    void createResource() override;
};

#endif
