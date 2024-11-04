#include "Section.h"

Section::Section(string cellType) : Cell(cellType) {}

vector<Section *> Section::getChildren()
{
    vector<Section*> emptyChild;
    return emptyChild;
}

void Section::setIcon()
{
}

Cell *Section::clone()
{
    return nullptr;
}

float Section::getMoney()
{
    return 0.0f;
}

void Section::setMoney(float newAmount)
{
}
