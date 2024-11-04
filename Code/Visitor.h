/**
 * @file Visitor.h
 * @author Stefan Muller
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef VISITOR_H
#define VISITOR_H

class Citizen;
class Section;
class Visitor {


public:
	virtual void visitCitizens(Citizen* ele) = 0;

	//virtual void visitTransport(Vehicle* ele) = 0;

	virtual void visitBuilding(Section* ele) = 0;
};

#endif
