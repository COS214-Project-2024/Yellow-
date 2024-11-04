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

////////////// Constructors ///////////////

/// Default Constructor
Population::Population(){
    if (listOfCitizens.empty()) {
        std::cout << "A new Population of people has joined the city." << std::endl;
    }
}

////////////// Observers ///////////////

/// Add observers
void Population::attach(Observer* obs) {
    if (obs == nullptr) {
        std::cout << "Invalid Observer pointer." << std::endl;
        return;
    }

    for (Observer* existingObserver : observerList) {                   // Check if observer is already in the list
        if (existingObserver == obs) {
            std::cout << "This Observer is already attached." << std::endl;
            return;
        }
    }

    observerList.push_back(obs);
    std::cout << "An Observer has been hired to monitor the Population's " << obs->getObservationType() << "." << std::endl;
}

/// Remove observer
void Population::detach(Observer* obs) {
    if (obs == nullptr) {
        std::cout << "Invalid Observer pointer." << std::endl;
        return;
    }

    for (auto it = observerList.begin(); it != observerList.end(); ++it) {
        if (*it == obs) {
            observerList.erase(it);
            std::cout << "The " << obs->getObservationType() << " Observer has been removed." << std::endl;
            return;
        }
    }

    std::cout << "This " << obs->getObservationType() << " Observer was not found in list." << std::endl;
}

/// Get Observers
vector<Observer*> Population::getObservers() {
    return observerList;
}

/// Notify Observers
void Population::notify() {
    for (Observer* obs : observerList) {
        if (obs) {  // Check for nullptr
            obs->update();
        }
    }
    std::cout << "All observers have been notified." << std::endl;
}

////////////// Population control ///////////////

/// Add new Citizen
void Population::addCitizen(Citizen* citizen) {
    listOfCitizens.push_back(citizen);
    std::cout << "A new Citizen has joined the Population." << std::endl;
}

/// Make Citizens procreate
void Population::allProcreate() {
    std::vector<Citizen*> newCitizens;

    for (Citizen* citizen : listOfCitizens) {
        if (citizen) {                                      // Check for null
            Citizen* newCitizen = citizen->procreate();
            newCitizens.push_back(newCitizen);              // Store the new citizen
        }
    }

    // Add new citizens to the population
    listOfCitizens.insert(listOfCitizens.end(), newCitizens.begin(), newCitizens.end());

    std::cout << "All citizens have procreated." << std::endl;
}

/// Get Citizens
vector<Citizen*> Population::getCitizens() {
    return listOfCitizens;
}

////////////// Visitor ///////////////

/// Accept Visitor
void Population::acceptVisitor(Visitor* v) {
	for (Citizen* cit : listOfCitizens){
		v->visitCitizens(cit);
	}
}


// void Citizen::setSelfObserver(Observer* obs) {
//     obs->setSubject(this);
// }