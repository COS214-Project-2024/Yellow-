/**
* @class OpenField
* @brief Concrete factory participant of the Factory design pattern
* @ingroup Factory
* @implements Cell
*
* The OpenField class is a concrete factory participant of the Factory design pattern. It is used to create an open field.
*/
#include "OpenField.h"
OpenField::OpenField() : Cell("Field") {
    setCellType("Field");
}

void OpenField::setIcon() {
    this->icon = 'F';
}

Cell *OpenField::clone() {
    //Cell* newField = new OpenField();
    //return newField;
}

void OpenField::createBuildingResource()
{
}

float OpenField::getMoney()
{
    return 0.0f;
}
