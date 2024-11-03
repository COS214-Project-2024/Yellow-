#include "IncomeObserver.h"
#include <iostream>

IncomeObserver::IncomeObserver() {
    observationType = "income";
}

IncomeObserver::IncomeObserver(vector<Citizen*> subj) {
    listOfSubjects = subj;
    observationType = "income";
}

void IncomeObserver::update() {
    if (listOfSubjects.empty()) {
        std::cout << "No citizens to observe." << std::endl;
        return;
    }

    float totalIncome = 0;
    int citizenCount = 0;

    for (Citizen* cit : listOfSubjects) {
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


