#include "Saves.h"
#include <iostream>

using namespace std;

Saves::Saves()
{
    this->currentBranchPath = "M";
    this->historyTree = new HistoryBranch();
    this->cursor = this->historyTree->getHead();
}

Saves::~Saves()
{
    delete this->historyTree;
}

