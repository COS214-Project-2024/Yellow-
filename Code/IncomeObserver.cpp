#include "IncomeObserver.h"
#include <iostream>

IncomeObserver::IncomeObserver() {
    observationType = "income";
}

IncomeObserver::IncomeObserver(Population* subj) {
    this->subject = subj;
    observationType = "income";
}

void IncomeObserver::update() {
    if (subject->listOfCitizens.empty()) {
        std::cout << "No citizens to observe." << std::endl;
        return;
    }

    float totalIncome = 0;
    int citizenCount = 0;

    for (Citizen* cit : subject->listOfCitizens) {
        if (cit) {
            totalIncome += cit->getMoney();
            citizenCount++;
        }
    }

    if (citizenCount > 0) {
        averageIncome = totalIncome / citizenCount;
        City::instanceCity().stuff.res->setBudget(City::instanceCity().stuff.res->getBudget() + averageIncome);
    } else {
        std::cout << "Observer: No valid citizens found for income calculation." << std::endl;
    }
}


