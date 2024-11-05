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

void Saves::goToNode(string path) // path example: "M_0.1_a.2_c.9_f.3"
{
    HistoryBranch *branch = loadBranch(path);
    if (branch == nullptr)
    {
        cout << "Branch not found\n";
        return;
    }

    cout << "Branch id" << branch->getBranchID() << endl;

    HistoryNode *current = branch->getHead();
    string name = path.substr(path.find_last_of(".") + 1);
    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            this->cursor = current;
            cout << "================================================" << endl;
            cout << this->historyTree->printBranch();
            cout << branch->printBranch();

            this->historyTree = branch;
            this->currentBranchPath = path.substr(0, path.find_last_of("."));
            return;
        }
        current = current->getNext();
    }

    resetCursor(true, true);
    return;
}

Save *Saves::viewSave(string path) // path example: "M_0.1_a.2_c.9_f.3"
{
    HistoryBranch *branch = loadBranch(path);
    if (branch == nullptr)
    {
        cout << "Branch not found\n";
        return nullptr;
    }
    HistoryNode *current = branch->getHead();
    string name = path.substr(path.find_last_of(".") + 1);
    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            return current->getData(); // Return the data without changing the cursor
        }
        current = current->getNext();
    }

    cout << "Node not found\n";
    return nullptr;
}

Save *Saves::loadSave() // Load the data at the cursor
{
    if (this->cursor == nullptr)
    {
        cout << "Cursor is not pointing to any node\n";
        return nullptr;
    }
    return this->cursor->getData();
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
    // Check if the path is just the main branch
    if (path == "M_0")
    {
        return this->historyTree;
    }

    // Remove any trailing ".x" where x is a number
    size_t dotPos = path.find_last_of(".");
    if (dotPos != string::npos && isdigit(path[dotPos + 1]))
    {
        path = path.substr(0, dotPos);
    }

    // Split the path into sections
    vector<string> sections;
    stringstream ss(path);
    string section;
    while (getline(ss, section, '.'))
    {
        sections.push_back(section);
    }

    // Start with the main branch
    HistoryBranch *currentBranch = this->historyTree;

    // Traverse the path sections
    for (size_t i = 1; i < sections.size(); ++i)
    {
        string nodeName = sections[i].substr(0, sections[i].find('_'));
        string branchID = sections[i];

        // Find the node in allBranchPoints
        HistoryNode *currentNode = nullptr;
        for (HistoryNode *node : currentBranch->getAllBranchPoints())
        {
            if (node->getName() == nodeName)
            {
                currentNode = node;
                break;
            }
        }

        if (currentNode == nullptr)
        {
            return nullptr; // Node not found
        }

        // Find the branch in alternatives
        currentBranch = nullptr;
        for (HistoryBranch *branch : currentNode->getAlternatives())
        {
            if (branch->getBranchID() == branchID)
            {
                currentBranch = branch;
                break;
            }
        }

        if (currentBranch == nullptr)
        {
            return nullptr; // Branch not found
        }
    }

    return currentBranch;
}

HistoryBranch *Saves::loadBranchHelper(vector<string> branchNames, HistoryBranch *currentBranch)
{

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

    this->cursor = this->historyTree->getHead();
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

void Saves::printFullPathToCursor()
{
    cout << "Path to cursor: " << this->currentBranchPath + "." + this->cursor->getName() << endl;
}

void Saves::deleteSave()
{
    if (this->cursor == nullptr)
    {
        cout << "Cursor is not pointing to any node\n";
        return;
    }
    this->historyTree->removeNode(this->cursor);
    this->cursor = nullptr; // Optionally, reset the cursor after deletion
}

void Saves::deleteBranch(string alpha)
{
    if (this->cursor == nullptr)
    {
        cout << "Cursor is not pointing to any node\n";
        return;
    }

    // Create the branch ID by adding the alpha to the current node's name
    string branchID = this->cursor->getName() + "_" + alpha;

    // Find the branch in the alternatives of the current node
    vector<HistoryBranch *> &alternatives = this->cursor->getAlternativesByRef();
    bool branchFound = false;
    cout <<"=--=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    for (auto it = alternatives.begin(); it != alternatives.end(); ++it)
    {

        cout << ((*it)->getBranchID() == branchID) << endl ;
        if ((*it)->getBranchID() == branchID)
        {
            // Branch found, delete it
            HistoryBranch *branchToDelete = *it;
            alternatives.erase(it);
            delete branchToDelete;
            branchFound = true;
            break;
        }
    }

    if (branchFound)
    {
        // If this was the last branch, remove the current node from allBranchPoints
        if (alternatives.empty())
        {
            this->historyTree->removeFromAllBranchPoints(this->cursor);
        }
    }
    else
    {
        cout << "Branch not found\n";
    }
}