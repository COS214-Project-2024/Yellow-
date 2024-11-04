#include "HistoryNode.h"
#include "HistoryBranch.h"

HistoryNode::HistoryNode() {
    this->name = "";
    this->next = nullptr;
    this->previous = nullptr;
    this->cityData = nullptr;
}

HistoryNode::HistoryNode(string name, Save* cityData) {
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

void HistoryNode::setData (Save* cityData) {
    this->cityData = cityData;
}

Save* HistoryNode::getData() {
    return this->cityData;
}