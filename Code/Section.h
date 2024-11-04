#ifndef SECTION_H
#define SECTION_H

#include "Visitor.h"
#include <vector>
#include "Cell.h"
class Block;

class Section : public Cell {

public:
	Section(string cellType);

	virtual void addSection(Section* section) = 0;

	virtual void removeSection(int idx) = 0;

	virtual Section* getSection(int idx) = 0;

	virtual void acceptVisitor(Visitor* v) = 0;

	virtual vector<Section*> getChildren();
	
	virtual void setIcon();

	virtual Cell* clone();
	
	virtual void createBuildingResource() = 0;

	float getMoney() override;
	void setMoney(float newAmount) override;
};

#endif
