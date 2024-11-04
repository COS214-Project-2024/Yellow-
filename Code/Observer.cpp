/**
* @class Observer
* @brief Class that represents an Observer
* @ingroup Observer
* @implements Observer
*
* The Observer class is a concrete observer participant of the Observer design pattern. It is used to observe the state of the city.
*/
#include "Observer.h"

Observer::Observer() {}

Observer::Observer(vector<Citizen*> subj) {
    listOfSubjects = subj;
}

string Observer::getObservationType() {
    return observationType;
}

void Observer::setSubject(vector<Citizen*> subj) {
    listOfSubjects = subj;
}

vector<Citizen*> Observer::getSubject() const{
    return listOfSubjects;
}

// void Observer::update() {
// 	// Implement Observer::update in derived classes
// }