#ifndef HAPPYOBSERVER_H
#define HAPPYOBSERVER_H
#include "Observer.h"

class HappyObserver : public Observer {
public:
	int averageHappiness;
	HappyObserver();
	HappyObserver(Population* subj);
	void update();
};

#endif
