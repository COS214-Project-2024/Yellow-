/**
* @class People
* @brief Class that the state of the population
* @ingroup State
* @implements Severity
*
* The People class is a concrete state participant of the State design pattern. It is used to represent the state of the population.
*/
#include "Policies.h"

Policies::Policies(string policyName) {
    this->policyName = policyName;
}

void Policies::setPolicy(string newPolicyName) {
    this->policyName = newPolicyName;

}

string Policies::getPolicy() {
    return this->policyName;
}
