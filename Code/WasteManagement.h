#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H
#include "Utilities.h"
#include "City.h"
class WasteManagement : public Utilities {
public:
    WasteManagement();
    void createResource() override;
};

#endif