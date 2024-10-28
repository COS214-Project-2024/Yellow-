#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "People.h"
#include "Budget.h"
#include "Disatisfaction.h"
#include "Strategy.h"
#include "Green.h"

#include <iostream>
#include <typeinfo>
using namespace std;

class Government {

    private:
        People* peopleState;
        Budget* budgetState;
        Disatisfaction* disatisfactionState;
        Strategy* strategy;
        static Government* uniqueInstanceGov;

    protected:
        Government(){};

    public:
        ~Government(){
            delete peopleState;
            delete budgetState;
            delete disatisfactionState;
            delete strategy;
            uniqueInstanceGov = nullptr;
        };

        //Strategy methods
        string implementPolicy(string stateType, Severity* state);
        string implementPolicyPeople();
        string implementPolicyBudget();
        string implementPolicyMorale();
        void setStrategy(Strategy* newStrategy);


        //Singleton method
        static Government& onlyInstance();

        //State methods
        void handlePeople(bool upOrDown);
        void handleBudget(bool upOrDown);
        void handleMorale(bool upOrDown);
        Severity* getBudgetState();
        Severity* getPeopleState();
        Severity* getMoraleState();
        void setPeopleState(People* people);
        void setBudgetState(Budget* budget);
        void setMoraleState(Disatisfaction* morale);
};

#endif
