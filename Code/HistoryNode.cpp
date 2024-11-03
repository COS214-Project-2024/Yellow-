#include "HistoryNode.h"
#include "HistoryBranch.h"

HistoryNode::HistoryNode() {
    this->name = "";
    this->next = nullptr;
    this->previous = nullptr;
    this->cityData = nullptr;
}

HistoryNode::HistoryNode(string name, Varibals* cityData) {
    this->name = name;
    this->previous = nullptr;
    this->next = nullptr;
    this->cityData = cityData;
}

HistoryNode::HistoryNode(HistoryNode* other) {
    this->name = other->name;
    this->previous = other->previous;
    this->next = other->next;
    this->alternatives = other->alternatives;
    this->cityData = other->cityData;
}

HistoryNode::~HistoryNode()
{
    // Delete cityData
    if (this->cityData != nullptr){
        delete this->cityData;
    }

    this->cityData = nullptr;
    // Delete alternatives
    for (HistoryBranch *branch : this->alternatives)
    {
        cout << "Deleting branch" << endl;
        cout<< "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout<< branch->getHead()->getName() << endl;
        cout<< "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        delete branch;
    }
    this->alternatives.clear();

    // Set previous and next to nullptr
    this->previous = nullptr;
    this->next = nullptr;
}

void HistoryNode::setName(string name) {
    this->name = name;
}

string HistoryNode::getName() {
    return this->name;
}

void HistoryNode::setPrevious(HistoryNode* previous) {
    this->previous = previous;
}

HistoryNode* HistoryNode::getPrevious() {
    return this->previous;
}

void HistoryNode::addAltHistory(HistoryBranch* branch) {
    this->alternatives.push_back(branch);
    branch->getHead()->setPrevious(this);
}

string HistoryNode::generateAltBranchID()
{
    int count = this->alternatives.size()-1;
    string altIdentifier;

    while (count >= 0)
    {
        altIdentifier.insert(altIdentifier.begin(), 'a' + (count % 26));
        count = count / 26 - 1; // Decrement count correctly to handle the next character
    }

    return this->name + altIdentifier;
}

HistoryNode* HistoryNode::getNext() {
    return this->next;
}

void HistoryNode::setNext(HistoryNode* next) {
    this->next = next;
}

vector<HistoryBranch *> HistoryNode::getAlternatives() {
    return this->alternatives;
}

std::vector<HistoryBranch *> &HistoryNode::getAlternativesByRef()
{
    return this->alternatives;
}

void HistoryNode::setAlternatives(vector<HistoryBranch *> newAlternatives)
{
    alternatives = newAlternatives;
}

void HistoryNode::setData (Varibals* cityData) {
    this->cityData = cityData;
}

Varibals* HistoryNode::getData() {
    return this->cityData;
}