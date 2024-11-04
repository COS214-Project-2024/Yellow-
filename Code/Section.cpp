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
