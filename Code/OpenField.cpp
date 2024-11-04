//
// Created by sjvr0 on 2024/11/01.
//

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
