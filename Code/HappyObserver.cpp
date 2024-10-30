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
		std::cout << "No citizens to observe." << std::endl;
		return;
	}

	float totalHappiness = 0;
	int citizenCount = 0;

	// Calculate the total happiness
	for (Citizen* cit : listOfSubjects) {
		if (cit) {  // Ensure the pointer is valid
			totalHappiness += cit->getHappiness();
			citizenCount++;
		}
	}

	// Calculate and print the average happiness
	if (citizenCount > 0) {
		float averageHappiness = totalHappiness / citizenCount;
		std::cout << "Observer: Average happiness of citizens: " << averageHappiness << "!" << std::endl;
	} else {
		std::cout << "Observer: No valid citizens found for happiness calculation." << std::endl;
	}
}


