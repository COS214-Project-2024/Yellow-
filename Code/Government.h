#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "People.h"
#include "Budget.h"
#include "Disatisfaction.h"
#include "Strategy.h"
#include "Green.h"
#include "MaterialOrder.h"
#include "Policies.h"
#include "Department.h"

#include <iostream>
#include <typeinfo>
using namespace std;
class City;
class Government {

    private:
        People* peopleState;
        Budget* budgetState;
        Disatisfaction* disatisfactionState;
        Strategy* strategy;
        static Government* uniqueInstanceGov;
        Department* department;

    protected:
        Government(){};

    public:
        friend class City;
        ~Government(){
            delete peopleState;
            delete budgetState;
            delete disatisfactionState;
            delete strategy;
            uniqueInstanceGov = nullptr;
        };

        //Strategy methods
        Policies* implementPolicy(string stateType, Severity* prevState, Severity* currState);
        Policies* implementPolicyPeople(Severity* prevState);
        Policies* implementPolicyBudget(Severity* prevState);
        Policies* implementPolicyMorale(Severity* prevState);
        void setStrategy(Strategy* newStrategy);


        //Singleton method
        static Government& onlyInstance();

        //State methods
        MaterialOrder* handlePeople(bool upOrDown);
        MaterialOrder* handleBudget(bool upOrDown);
        MaterialOrder* handleMorale(bool upOrDown);
        Severity* getBudgetState();
        Severity* getPeopleState();
        Severity* getMoraleState();
        void setPeopleState(People* people);
        void setBudgetState(Budget* budget);
        void setMoraleState(Disatisfaction* morale);
};

#endif
