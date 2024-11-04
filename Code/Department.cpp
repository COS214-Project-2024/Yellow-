/**
* @class Complex
* @brief Class that represents a Complex building
* @ingroup Factory
* @implements Residential factory
*
* The Complex class is a concrete factory participant of the Factory design pattern. It is used to create a complex building.
*/
#include "Department.h"

void Department::setSuccessor(Department *newSuccessor) {
    this->successor = newSuccessor;
}
