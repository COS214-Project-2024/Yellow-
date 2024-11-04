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