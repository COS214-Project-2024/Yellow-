#ifndef OBSERVER_H
#define OBSERVER_H
#include "Citizen.h"
#include "City.h"
#include <string>
#include <vector> 
class Population;
using namespace std;

class Observer {
protected:
	Population* subject;
public:
	Observer();
	Observer(Population* subj);
	string observationType;
	string getObservationType();
	void setSubject(Population* subj);
	Population* getSubject() const;
	virtual void update() = 0;
};

#endif
