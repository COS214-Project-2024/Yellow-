#include "HappyObserver.h"
#include <iostream>

#include "Population.h"

HappyObserver::HappyObserver() {
	observationType = "happiness";
}

HappyObserver::HappyObserver(Population* subj) {
	this->subject = subj;
	observationType = "happiness";
}

void HappyObserver::update() {
	if (subject->listOfCitizens.empty()) {
		std::cout << "There are no citizens to observe." << std::endl;
		return;
	}

	int citizenCount = 0;
	float totalHappiness = 0;

	for (Citizen* cit : subject->listOfCitizens) {
		if (cit) {
			totalHappiness += cit->getHappiness();
			citizenCount++;
		}
	}

	if (citizenCount > 0) {
		averageHappiness = totalHappiness / citizenCount;
		City::instanceCity().stuff.res->setMorale(averageHappiness);
	} else {
		std::cout << "Observer: No valid citizens found for happiness calculation." << std::endl;
	}
}
