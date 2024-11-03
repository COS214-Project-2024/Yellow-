#include "HappyObserver.h"
#include <iostream>

HappyObserver::HappyObserver() {
	observationType = "happiness";
}

HappyObserver::HappyObserver(vector<Citizen*> subj) {
	listOfSubjects = subj;
	observationType = "happiness";
}

void HappyObserver::update() {
	if (listOfSubjects.empty()) {
		std::cout << "There are no citizens to observe." << std::endl;
		return;
	}

	int citizenCount = 0;
	float totalHappiness = 0;

	for (Citizen* cit : listOfSubjects) {
		if (cit) {
			totalHappiness += cit->getHappiness();
			citizenCount++;
		}
	}

	if (citizenCount > 0) {
		averageHappiness = totalHappiness / citizenCount;
		City::instanceCity().stuff.res->setMorale(averageHappiness);
		// std::cout << "Observer: Average happiness of citizens: " << averageHappiness << "!" << std::endl;
	} else {
		std::cout << "Observer: No valid citizens found for happiness calculation." << std::endl;
	}
}
