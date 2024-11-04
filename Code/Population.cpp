/**
 * @file Policies.h
 * @author Saskia Steyn
 * @brief A class used by the government to pass policies between patterns
 * @version 0.1
 * @date 2024-10-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Population.h"
#include "Citizen.h"
#include <iostream>

//////////////////////// Constructors /////////////////////////
Population::Population() {}

//////////////////////// Observers ////////////////////////

void Population::attach(Observer* obs) {
    // Null check
    if (obs == nullptr) {
        std::cout << "Invalid Observer pointer." << std::endl;
        return;
    }

    // Check if observer is already in the list
    for (Observer* existingObserver : observerList) {
        if (existingObserver == obs) {
            std::cout << "This Observer is already attached." << std::endl;
            return;
        }
    }

    observerList.push_back(obs);
    obs->setSubject(this);
    std::cout << "An Observer has been hired to monitor the Population's " << obs->getObservationType() << "." << std::endl;
}

void Population::detach(Observer* obs) {
    // Null check
    if (obs == nullptr) {
        std::cout << "Invalid Observer pointer." << std::endl;
        return;
    }

    // Remove it
    for (auto it = observerList.begin(); it != observerList.end(); ++it) {
        if (*it == obs) {
            observerList.erase(it);
            std::cout << "The " << obs->getObservationType() << " Observer has been removed." << std::endl;
            return;
        }
    }

    std::cout << "This " << obs->getObservationType() << " Observer was not found in list." << std::endl;
}

void Population::notify() {
    if(observerList.empty()) {
        std::cout << "There are no Observers watching the population." << std::endl;
    }
    else {
        for (Observer* obs : observerList) {
            if (obs) {  // Check for nullptr
                obs->update();
            }
        }
        std::cout << "All observers have been notified." << std::endl;
    }
}

vector<Observer*> Population::getObservers() {
    return observerList;
}