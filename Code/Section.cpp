/**
* @class Section
* @brief A class that represents a section of the city
* @ingroup Section
* @implements Cell
*
* The Section class is a concrete participant of the Section design pattern. It is used to represent a section of the city.
*/
#include "Section.h"

Section::Section(string cellType) : Cell(cellType) {}

vector<Cell *> Section::getChildren()
{
    vector<Cell*> emptyChild;
    return emptyChild;
}

void Section::setIcon()
{
}

float Section::getMoney()
{
    return 0.0f;
}

void Section::setMoney(float newAmount)
{
    
}
