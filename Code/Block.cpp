#include "Block.h"

Block::~Block()
{
	
}

void Block::addSection(Section *section)
{
	children.push_back(section);
}

void Block::removeSection(Section* section){
	int idx = 0;
	for (Section* sec : children)
	{
		if(sec == section)
		{
			children.erase(children.begin() + idx);
		}
	}
}

Section* Block::getSection(int idx){
	cout << "idx = " << idx << endl;
	
	if (idx < 0 || children.size()-1 <= 0)
	{
		return nullptr;
	}
	else if (idx >= children.size()-1)
	{
		cout << "Going down" << endl;
		return children.back()->getSection(idx - (children.size()-1));
	}
	else
	{
		return children.at(idx);
	}
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