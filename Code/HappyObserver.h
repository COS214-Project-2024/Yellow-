#ifndef HAPPYOBSERVER_H
#define HAPPYOBSERVER_H
#include "Observer.h"
#include "Citizen.h"

class HappyObserver : public Observer {
public:
	HappyObserver();
	HappyObserver(Citizen* subj);
	Citizen* subject;
	void update();
};

#endif
