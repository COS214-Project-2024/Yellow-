#ifndef OBSERVER_H
#define OBSERVER_H
#include "Citizen.h"
#include <string>
class Citizen;
using namespace std;

class Observer {
protected:
	vector<Citizen*> listOfSubjects;
public:
	Observer();
	Observer(vector<Citizen*> subj);
	string observationType;
	string getObservationType();
	void setSubject(vector<Citizen*> subj);
	vector<Citizen*> getSubject() const;
	virtual void update() = 0;
};

#endif
