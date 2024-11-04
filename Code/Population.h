#ifndef POPULATION_H
#define POPULATION_H
#include "Observer.h"
#include "Visitor.h"
#include <string>
#include <vector>
class Observer;
using namespace std;

class Population {
protected:
    vector<Observer*> observerList;						// The Observer list
public:
	// Observer stuff
	static vector<Citizen*> listOfCitizens;			// State (All citizens)

	// General Population stuff
    Population();										// Default constructor - does nothing

	// Observer stuff
	void attach(Observer* obs);
	void detach(Observer* obs);
	void notify();
	vector<Observer*> getObservers();

	virtual vector<Citizen*> getCitizens() = 0;			// getState (Observer's access to the list of citizens)
	virtual void setCitizens(Citizen*) = 0;             // setState
};



#endif
