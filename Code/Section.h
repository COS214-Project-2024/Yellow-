#ifndef SECTION_H
#define SECTION_H

#include "Visitor.h"
#include <vector>
#include "Cell.h"
class Block;

class Section : public Cell {

public:
	Section(string cellType);

	virtual void addSection(Cell* section) = 0;

	virtual void removeSection(int idx) = 0;

	virtual Cell* getSection(int idx) = 0;

	virtual void acceptVisitor(Visitor* v) = 0;

	virtual vector<Cell*> getChildren();
	
	virtual void setIcon();

	virtual Cell* clone() = 0;
	
	virtual void createBuildingResource() = 0;

	virtual float getMoney();
	virtual void setMoney(float newAmount);
};

#endif
