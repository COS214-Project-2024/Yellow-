#ifndef POPULATION_H
#define POPULATION_H

#include "Observer.h"
#include "Visitor.h"
class Citizen;
#include <string>
#include <vector>

using namespace std;
class Population {

private:
	Observer* observerList;
	vector<Citizen*> listOfCitizens;

public:
	void attach(Observer* obs);

	void detach(Observer* obs);

	void notify();

	void allProcreate();

	void acceptVisitor(Visitor* v);
};

#endif
