/**
 * @file Block.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BLOCK_H
#define BLOCK_H

#include "Visitor.h"
#include "Section.h"
#include "Buildings.h"
#include <vector>
#include <typeinfo>

class Block : public Section {

private:
    vector<Cell*> children;

	Buildings* building;

public:
	Block();
	~Block();

	void addSection(Cell* section);

	void removeSection(int idx);

	Cell* getSection(int idx);

	void acceptVisitor(Visitor* v);

	vector<Cell*> getChildren();
	
	virtual Cell* clone();
	
	void createBuildingResource() override;

	virtual void setProductionRate(int newRate){}
	virtual void taxBuilding(){}
	virtual void payEmployees(){}
};

#endif
