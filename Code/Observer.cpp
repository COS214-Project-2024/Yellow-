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