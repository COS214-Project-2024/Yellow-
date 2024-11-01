#include "HistoryNode.h"

void HistoryNode::setName(string name)
{
    this->name = name;
}

string HistoryNode::getName()
{
    return this->name;
}

void HistoryNode::setPrevious(HistoryNode* previous)
{
    this->previous = previous;
}

HistoryNode* HistoryNode::getPrevious()
{
    return this->previous;
}

void HistoryNode::addNext(HistoryNode* next)
{
    this->next.push_back(next);
}

vector <HistoryNode*> HistoryNode::getNext()
{
    return this->next;
}

void HistoryNode::setData (Varibals* cityData)
{
    this->cityData = cityData;
}

Varibals* HistoryNode::getData()
{
    return this->cityData;
}