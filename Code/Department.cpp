/**
* @class Department
* @brief A class that represents a department
* @ingroup Chain of responsibility
* @implements Department
*
* The Department class is a handler participant of the Chain of Responsibility design pattern. It is used to handle the policies that are passed to it.
*/
#include "Department.h"

void Department::setSuccessor(Department *newSuccessor) {
    this->successor = newSuccessor;
}
