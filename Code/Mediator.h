/**
* @class Mediator
* @brief Class that represents a Mediator
* @ingroup Mediator
* @implements Mediator
*
* The Mediator class is a concrete mediator participant of the Mediator design pattern. It is used to notify the system of changes.
*/
#ifndef MEDIATOR_H
#define MEDIATOR_H

class Mediator {


public:
	virtual void notify() = 0;
};

#endif
