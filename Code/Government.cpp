#include "Government.h"

string Government::implementPolicy(string stateType, Severity* state) {
    string stateColour = "";
    if(typeid(*state) == typeid(Green)){
        stateColour = "Green";
    }
    else if(typeid(*state) == typeid(Yellow)){
        stateColour = "Yellow";
    }
    else if(typeid(*state) == typeid(Red)){
        stateColour = "Red";
    }


    string policy = strategy->implementPolicy(stateType, stateColour);

    return policy;
}

string Government::implementPolicyPeople() {
    return this->implementPolicy("People", this->peopleState->getState());
}

string Government::implementPolicyBudget() {
    return this->implementPolicy("Budget", this->budgetState->getState());
}

string Government::implementPolicyMorale() {
    return this->implementPolicy("Disatisfaction", this->disatisfactionState->getState());

}

void Government::setStrategy(Strategy* newStrategy) {
    this->strategy = newStrategy;
}

Government* Government :: uniqueInstanceGov = nullptr;

Government& Government::onlyInstance() {
//    if( uniqueInstanceGov == nullptr){
//        uniqueInstanceGov = new Government ();
//        cout << "\033[38;5;39mYour city's Government has been created. \033[0m" << endl;
//    }
//    else{
//        cout << "\033[38;5;196mThere already exists a government. Check the city books in the library to be educated on the ruling of this city \033[0m" << endl;
//    }

    static Government uniqueInstanceGov;
    cout << "\033[38;5;39mYour city's Government has been created. If you want to create another, first delete this one! \033[0m" << endl;

    return uniqueInstanceGov;
}

void Government::handlePeople(bool upOrDown) {
    //TODO: this will have to be more advanced to change the state with the fully fledged game
    this->peopleState->handleSeverity(upOrDown);

}

void Government::handleBudget(bool upOrDown) {
    //TODO: this will have to be more advanced to change the state with the fully fledged game
    this->disatisfactionState->handleSeverity(upOrDown);
}

void Government::handleMorale(bool upOrDown) {
    //TODO: this will have to be more advanced to change the state with the fully fledged game
    this->budgetState->handleSeverity(upOrDown);
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
