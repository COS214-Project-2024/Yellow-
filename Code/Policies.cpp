/**
* @class Policies
* @brief Class that represents a policy
* @ingroup Policies
* @implements Policies
*
* A class used by the government to pass policies between patterns. It is used to pass policies between patterns.
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
