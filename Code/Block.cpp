/**
* @class Block
* @brief A class that represents a block of buildings.
* @ingroup Composite
* @implements Section
*
* The Block class is a composite participant of the Composite design pattern. It is used to represent a block of buildings.
*/
#include "Block.h"

Block::Block() : Section("Block") //review
{
}

Block::~Block()
{
	
}

void Block::addSection(Section *section)
{
	 if (Block* blockSection = dynamic_cast<Block*>(section)) {
        const auto& blockChildren = section->getChildren();
        for (Section* child : blockChildren)
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

Section* Block::getSection(int idx){	
	if (idx < 0 || idx >= children.size()) {
        return nullptr;
    }
	return children.at(idx);
}

void Block::acceptVisitor(Visitor* v) {
	for (Section* sec : children)
	{
		v->visitBuilding(sec);
	}
}

vector<Section*> Block::getChildren()
{
	return children;
}