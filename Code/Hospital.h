/**
* @class Hospital
* @brief Class for the Hospital service
* @ingroup Factory
* @implements Service
*
* The Hospital class is a concrete service participant of the Factory design pattern. It is used to create a hospital service.
*/
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Service.h"
class Hospital : public Service {
    public:
    Hospital();
    void setIcon();
    Cell* clone();
};

#endif