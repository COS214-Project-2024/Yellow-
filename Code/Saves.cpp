#include "Saves.h"
#include <iostream>
#include <sstream>

using namespace std;

Saves::Saves()
{
    this->currentBranchPath = "M_0";
    this->historyTree = new HistoryBranch();
    this->cursor = this->historyTree->getHead();
}

Saves::~Saves()
{
    delete this->historyTree;
}

void Saves::save(Save *save, bool overwrite)
{
    if (this->historyTree->getHead() == nullptr || this->cursor == this->historyTree->getTail())
    {
        this->historyTree->addNode(save, this->cursor);
        this->cursor = this->historyTree->getTail();
    }
    else if (this->cursor->getNext() == nullptr)
    {
        this->historyTree->addNode(save, this->cursor);
    }
    else
    {
        if (overwrite)
        {
            this->historyTree->addNode(save, this->cursor);
        }
        else
        {
            this->historyTree->startAltHistory(save, this->cursor);
        }
    }
}

HistoryBranch *Saves::getSaves() const
{
    return this->historyTree;
}

Save *Saves::loadAtCursor()
{
    return this->cursor->getData();
}

HistoryNode *Saves::goToNode(string path) // path example: "M_0.1_a.2_c.9_f.3"
{
    HistoryBranch *branch = loadBranch(path);
    HistoryNode *current = branch->getHead();
    string name = path.substr(path.find_last_of(".") + 1);
    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

Save *Saves::viewSave(string path) // path example: "M_0.1_a.2_c.9_f.3"
{
    HistoryNode *node = this->goToNode(path);
    if (node == nullptr)
    {
        cout << "Node not found\n";
        return nullptr;
    }
    return node->getData();
}

Save *Saves::loadSave(string path) // path example: "M_0.1_a.2_c.9_f.3"
{
    HistoryNode *node = this->goToNode(path);
    if (node == nullptr)
    {
        cout << "Node not found\n";
        return nullptr;
    }
    this->cursor = node;
    return node->getData();
}

HistoryNode *Saves::getCursor()
{
    return this->cursor;
}

void Saves::moveForward()
{
    if (this->cursor->getNext() != nullptr)
    {
        cursor = cursor->getNext();
    }
}

void Saves::moveBack()
{
    if (this->cursor->getPrevious() != nullptr)
    {
        cursor = cursor->getPrevious();
    }
}

void Saves::moveIntoBranch(string branchAlpha)
{
    if (this->cursor->getAlternatives().size() == 0)
    {
        // no alternatives
        cout << "No alternatives branches to move into\n";
        return;
    }
    // iterate over all the branches and find the one with the correct name
    string name = this->cursor->getName() + "_" + branchAlpha;

    for (HistoryBranch *branch : this->cursor->getAlternatives())
    {
        if (branch->getBranchID() == name)
        {
            this->cursor = branch->getHead();
            this->currentBranchPath += "." + branchAlpha;
            this->historyTree = branch;
            return;
        }
    }
}

void Saves::moveOutOfBranch()
{
    if (this->historyTree->getParentBranch() == nullptr)
    {
        cout << "Cannot move out of the main branch\n";
        return;
    }
    this->currentBranchPath = this->currentBranchPath.substr(0, this->currentBranchPath.find_last_of("."));
    this->historyTree = this->historyTree->getParentBranch();
}

string Saves::getCurrentBranchPath()
{
    return this->currentBranchPath;
}

HistoryBranch *Saves::loadBranch(string path)
{
    resetToMainBranch();
    vector<string> branchNames;
    string traversalPath = path;
    size_t pos = 0;

    // Handle the main branch prefix "M"
    if (traversalPath == "M")
    {
        // If the path is only "M", return the main branch
        return this->historyTree;
    }
    else if (traversalPath.substr(0, 3) == "M_0")
    {
        // Check if there are any more branches after "M_0"
        pos = traversalPath.find(".");
        if (pos == 3 || pos == string::npos)
        {
            // If no more branches, return the main branch
            return this->historyTree;
        }
        else
        {
            // Remove the "M_0." prefix
            traversalPath.erase(0, pos + 1);
        }
    }

    while ((pos = traversalPath.find(".")) != string::npos)
    {
        branchNames.push_back(traversalPath.substr(0, pos));
        traversalPath.erase(0, pos + 1);
    }
    if (!traversalPath.empty())
    {
        branchNames.push_back(traversalPath);
    }

    HistoryBranch *branch = loadBranchHelper(branchNames, this->historyTree);
    if (branch == nullptr)
    {
        cout << "Branch not found\n";
    }
    return branch;
}

HistoryBranch *Saves::loadBranchHelper(vector<string> branchNames, HistoryBranch *currentBranch)
{
    if (branchNames.empty())
    {
        return currentBranch;
    }

    string name = branchNames[0];
    if (name == "M_0")
    {
        // Handle the main branch case
        return loadBranchHelper(vector<string>(branchNames.begin() + 1, branchNames.end()), currentBranch);
    }

    string nodeName = name.substr(0, name.find("_"));
    for (HistoryNode *node : currentBranch->getAllBranchPoints())
    {
        if (node->getName() == nodeName)
        {
            for (HistoryBranch *branch : node->getAlternatives())
            {
                if (branch->getBranchID() == name)
                {
                    // Create a copy of the vector without the first element
                    vector<string> remainingBranchNames(branchNames.begin() + 1, branchNames.end());
                    return loadBranchHelper(remainingBranchNames, branch);
                }
            }
        }
    }
    return nullptr;
}

void Saves::setBranch(string path)
{
    HistoryBranch *branch = loadBranch(path);
    if (branch == nullptr)
    {
        cout << "Branch not found\n";
        return;
    }
    this->historyTree = branch;
    this->cursor = branch->getHead();
    this->currentBranchPath = path;
}

void Saves::resetToMainBranch()
{
    while (this->historyTree->getParentBranch() != nullptr)
    {
        moveOutOfBranch();
    }
}

void Saves::resetCursor(bool toMainBranch, bool toHead)
{
    if (toMainBranch)
    {
        resetToMainBranch();
    }
    if (toHead)
    {
        this->cursor = this->historyTree->getHead();
    }
}

void Saves::printTree()
{
    string result = "";
    result += this->historyTree->printBranch();
    cout << result;
}

void Saves::printCursor()
{
    cout << "Cursor: " << this->cursor->getName() << endl;
}

void Saves::deleteSave(string path)
{
    HistoryNode *node = goToNode(path);
    if (node == nullptr)
    {
        cout << "Node not found\n";
        return;
    }
    this->historyTree->removeNode(node);
}

void Saves::deleteBranch(string path)
{
    string alpha = path.substr(path.find_last_of(".") + 1);
    string branchPath = path.substr(0, path.find_last_of("."));
    HistoryBranch *branch = loadBranch(branchPath);
    if (branch == nullptr)
    {
        cout << "Branch not found\n";
        return;
    }
    branch->removeBranch(alpha, this->cursor);
}