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

vector<Section *> Section::getChildren()
{
    vector<Section*> emptyChild;
    return emptyChild;
}