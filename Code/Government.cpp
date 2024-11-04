/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#include "Government.h"

Policies* Government::implementPolicy(string stateType, Severity* prevState, Severity* currState) {
    string currStateColour = "";
    if(typeid(*currState) == typeid(Green)){
        currStateColour = "Green";
    }
    else if(typeid(*currState) == typeid(Yellow)){
        currStateColour = "Yellow";
    }
    else if(typeid(*currState) == typeid(Red)){
        currStateColour = "Red";
    }

    string prevStateColour = "";
    if(typeid(*prevState) == typeid(Green)){
        prevStateColour = "Green";
    }
    else if(typeid(*prevState) == typeid(Yellow)){
        prevStateColour = "Yellow";
    }
    else if(typeid(*prevState) == typeid(Red)){
        prevStateColour = "Red";
    }

    Policies* policy = strategy->implementPolicy(stateType, prevStateColour, currStateColour);

    return policy;
}

Policies* Government::implementPolicyPeople(Severity* prevState) {
    return this->implementPolicy("People", prevState, this->peopleState->getState());
}

Policies* Government::implementPolicyBudget(Severity* prevState) {
    return this->implementPolicy("Budget", prevState, this->budgetState->getState());
}

Policies* Government::implementPolicyMorale(Severity* prevState) {
    return this->implementPolicy("Disatisfaction", prevState, this->disatisfactionState->getState());

}

void Government::setStrategy(Strategy* newStrategy) {
    this->strategy = newStrategy;
}

Government* Government :: uniqueInstanceGov = nullptr;

Government& Government::onlyInstance() {
    static Government uniqueInstanceGov;
    cout << "\033[38;5;39mYour city's Government has been created. If you want to create another, first delete this one! \033[0m" << endl;

    return uniqueInstanceGov;
}

MaterialOrder* Government::handlePeople(bool upOrDown) {

    Severity* prevSev = this->peopleState->getState();

    this->peopleState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyPeople(prevSev);

    return this->department->handle(newPolicy);

}

MaterialOrder* Government::handleBudget(bool upOrDown) {
    Severity* prevSev = this->peopleState->getState();

    this->disatisfactionState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyBudget(prevSev);

    return this->department->handle(newPolicy);
}

MaterialOrder* Government::handleMorale(bool upOrDown) {
    Severity* prevSev = this->peopleState->getState();

    this->budgetState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyMorale(prevSev);

    return this->department->handle(newPolicy);
}

Severity *Government::getBudgetState() {
    return this->budgetState->getState();
}

Severity *Government::getPeopleState() {
    return this->peopleState->getState();
}

Severity *Government::getMoraleState() {
    return this->disatisfactionState->getState();
}

void Government::setPeopleState(People *people) {
    this->peopleState = people;

}

void Government::setBudgetState(Budget *budget) {
    this->budgetState = budget;

}

void Government::setMoraleState(Disatisfaction *morale) {
    this->disatisfactionState = morale;

}
