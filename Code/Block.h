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
