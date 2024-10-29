#ifndef SECTION_H
#define SECTION_H

#include "Visitor.h"
#include <vector>
class Block;

class Section {

public:
	virtual void addSection(Section* section) = 0;

	virtual void removeSection(int idx) = 0;

	virtual Section* getSection(int idx) = 0;

	virtual void acceptVisitor(Visitor* v) = 0;

	virtual vector<Section*> getChildren();

	virtual ~Section();
};

#endif
