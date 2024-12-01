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

Observer::Observer(Population* subj) {
    this->subject = subj;
}

string Observer::getObservationType() {
    return observationType;
}

void Observer::setSubject(Population* subj) {
    this->subject = subj;
}

Population* Observer::getSubject() const{
    return subject;
}

// void Observer::update() {
// 	// Implement Observer::update in derived classes
// }