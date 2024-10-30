#ifndef HAPPYOBSERVER_H
#define HAPPYOBSERVER_H
#include "Observer.h"

class HappyObserver : public Observer {
public:
	int totalHappiness;
	HappyObserver();
	HappyObserver(vector<Citizen*> subj);
	void update();
};

#endif
