//
// Created by sjvr0 on 2024/11/01.
//

#include "OpenField.h"
OpenField::OpenField() {
    setCellType("Field");
}

void OpenField::setIcon() {
    this->icon = "F";
}

Cell *OpenField::clone() {
    Cell* newField = OpenField();
    return newField;
}
