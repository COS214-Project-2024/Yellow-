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
    vector<Section*> children;

	Buildings* building;

public:
	Block();
	~Block();

	void addSection(Section* section);

	void removeSection(int idx);

	Section* getSection(int idx);

	void acceptVisitor(Visitor* v);

	vector<Section*> getChildren();
};

#endif
