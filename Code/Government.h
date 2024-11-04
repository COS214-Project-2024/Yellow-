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
#include "AddPublicTransport.h"
#include "Transport.h"
#include "Labour.h"
#include "Amenities.h"
#include "Finances.h"

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
        Department* department;

    protected:

    public:
        Government();
        ~Government(){

//            delete budgetState;
//            delete peopleState;
//            delete disatisfactionState;
//            delete strategy;
//            uniqueInstanceGov = nullptr;
        };
        friend class City;

        //Strategy methods
        Policies* implementPolicy(string stateType, string prevState, string currState);
        Policies* implementPolicyPeople(string prevState);
        Policies* implementPolicyBudget(string prevState);
        Policies* implementPolicyMorale(string prevState);
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
