#ifndef HAPPYOBSERVER_H
#define HAPPYOBSERVER_H
#include "Observer.h"
#include "City.h"

class HappyObserver : public Observer {
public:
	int averageHappiness;
	HappyObserver();
	HappyObserver(vector<Citizen*> subj);
	void update();
};

#endif
