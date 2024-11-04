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
