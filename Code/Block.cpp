#include "Block.h"

Block::Block() : Section("Block") //review
{
}

Block::~Block()
{
	children.clear();
}

void Block::addSection(Cell *section)
{
	 if (typeid(Block*) == typeid(section)) {
        const auto& blockChildren = section->getChildren();
        for (Cell* child : blockChildren)
		{
			this->addSection(child);
		}
    } 
	else 
	{
        children.push_back(section);
    }
}

void Block::removeSection(int idx){
	children.erase(children.begin() + idx);
}

Cell* Block::getSection(int idx){	
	if (idx < 0 || idx >= children.size()) {
        return nullptr;
    }
	return children.at(idx);
}

void Block::acceptVisitor(Visitor* v) {
	for (Cell* sec : children)
	{
		//v->visitBuilding(sec);
	}
}

vector<Cell*> Block::getChildren()
{
	return children;
}

Cell *Block::clone()
{
    return nullptr;
}

void Block::createBuildingResource()
{
}
