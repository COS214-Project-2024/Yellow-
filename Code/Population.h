#ifndef POPULATION_H
#define POPULATION_H
#include "Observer.h"
#include "Visitor.h"
// #include "Citizen.h"
#include <string>
#include <vector>
using namespace std;

class Population {
private:
    vector<Observer*> observerList;
	vector<Citizen*> listOfCitizens;
public:
    Population();
	void attach(Observer* obs);
	void detach(Observer* obs);
	vector<Observer*> getObservers();
	void notify();
    void addCitizen(Citizen* citizen);
	void allProcreate();
	vector<Citizen*> getCitizens();
	void acceptVisitor(Visitor* v);
};

#endif
