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
