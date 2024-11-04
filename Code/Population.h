#ifndef POPULATION_H
#define POPULATION_H
#include "Observer.h"
#include "Visitor.h"
#include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

class Observer;

class Population {
private:
	int averageHappiness;
    vector<Observer*> observerList;
	vector<Citizen*> listOfCitizens;
public:
    Population();
	void attach(Observer* obs);
	void detach(Observer* obs);
	vector<Observer*> getObservers();
	void notify();
	// void setSelfObserver(Observer* obs);
    void addCitizen(Citizen* citizen);
	void allProcreate();
	vector<Citizen*> getCitizens();
	void acceptVisitor(Visitor* v);
};

#endif
