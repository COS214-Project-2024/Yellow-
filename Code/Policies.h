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
#ifndef CODE_POLICIES_H
#define CODE_POLICIES_H

#include <iostream>
using namespace std;

class Policies {
    private:
        string policyName;
    public:
        Policies(string policyName);
        void setPolicy(string newPolicyName);
        string getPolicy();
};


#endif //CODE_POLICIES_H
