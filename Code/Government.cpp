/**
* @class Government
* @brief Class that represents the government of the city
* @ingroup State, Strategy, Command, Chain of Responsibility
* @implements Department
*
* The Government class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the policies of the city.
*/
#include "Government.h"

Policies* Government::implementPolicy(string stateType, string prevState, string currState) {

    Policies* policy = strategy->implementPolicy(stateType, prevState, currState);

    return policy;
}

Policies* Government::implementPolicyPeople(string prevState) {
    return this->implementPolicy("People", prevState, this->peopleState->getState()->getSeverity());
}

Policies* Government::implementPolicyBudget(string prevState) {
    return this->implementPolicy("Budget", prevState, this->budgetState->getState()->getSeverity());
}

Policies* Government::implementPolicyMorale(string prevState) {
    return this->implementPolicy("Disatisfaction", prevState, this->disatisfactionState->getState()->getSeverity());

}

void Government::setStrategy(Strategy* newStrategy) {
    delete this->strategy;
    this->strategy = newStrategy;
}

Government* Government :: uniqueInstanceGov = nullptr;

Government& Government::onlyInstance() {
    static Government uniqueInstanceGov;
    cout << "\033[38;5;39mYour city's Government has been created. If you want to create another, first delete this one! \033[0m" << endl;

    return uniqueInstanceGov;
}

MaterialOrder* Government::handlePeople(bool upOrDown) {

    string prevSev = this->peopleState->getState()->getSeverity();

    this->peopleState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyPeople(prevSev);

    if(newPolicy != nullptr){
        return this->department->handle(newPolicy);
    }


    return nullptr;

}

MaterialOrder* Government::handleBudget(bool upOrDown) {
    string prevSev = this->budgetState->getState()->getSeverity();

    this->budgetState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyBudget(prevSev);

    if(newPolicy != nullptr){
        return this->department->handle(newPolicy);
    }


    return nullptr;
}

MaterialOrder* Government::handleMorale(bool upOrDown) {
    string prevSev = this->disatisfactionState->getState()->getSeverity();

    this->disatisfactionState->handleSeverity(upOrDown);

    Policies* newPolicy = implementPolicyMorale(prevSev);

    if(newPolicy != nullptr){
        return this->department->handle(newPolicy);
    }


    return nullptr;
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

Government::Government() {
//    peopleState = new People(new Green());
//    budgetState = new Budget(new Green());
//    disatisfactionState = new Disatisfaction(new Green());
//    strategy = new AddPublicTransport();
//    Department* newDepartment = new Transport();
//    Department* newAmen = new Amenities();
//    Department* newLabour = new Labour();
//    Department* newFinances = new Finances();
//    newDepartment->setSuccessor(newAmen);
//    newAmen->setSuccessor(newLabour);
//    newLabour->setSuccessor(newFinances);
//    department = newDepartment;
}
