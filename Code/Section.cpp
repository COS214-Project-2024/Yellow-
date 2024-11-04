#include "Section.h"

Section::Section(string cellType) : Cell(cellType) {}

vector<Section *> Section::getChildren()
{
    vector<Section*> emptyChild;
    return emptyChild;
}

Section::~Section()
{
    
}