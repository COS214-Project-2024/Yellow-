#include "HistoryBranch.h"
#include "HistoryNode.h"

HistoryBranch::HistoryBranch()
{
    this->head = nullptr;
    this->tail = this->head;
    this->branchID = "M";
    this->size = 0;
    this->parentBranch = nullptr;
}

HistoryBranch::~HistoryBranch()
{
    HistoryNode *temp = this->head;
    while (temp != nullptr)
    {
        HistoryNode *next = temp->getNext();

        // Check if the node's alternatives are not empty
        if (!temp->getAlternatives().empty())
        {
            // Iterate over each alternative branch and delete it
            for (HistoryBranch *alternativeBranch : temp->getAlternatives())
            {
                delete alternativeBranch;
            }
        }

        delete temp;
        temp = next;
    }
}

HistoryNode* HistoryBranch::getHead() {
    return this->head;
}

HistoryNode* HistoryBranch::getTail()
{
    return this->tail;
}

HistoryBranch* HistoryBranch::getParentBranch()
{
    return this->parentBranch;
}

void HistoryBranch::setParentBranch(HistoryBranch *parentBranch)
{
    this->parentBranch = parentBranch;
}

string HistoryBranch::getBranchID()
{
    return this->branchID;
}

void HistoryBranch::setBranchID(string branchID)
{

    this->branchID = branchID;
}

void HistoryBranch::startAltHistory(Save *cityData, HistoryNode *cursor)
{
    if (cursor != nullptr)
    {
        // Create new branch
        HistoryBranch *newBranch = new HistoryBranch();
        // Create a new node and insert it in the new historyBranch
        newBranch->addNode(cityData, cursor);
        // Insert the new historyBranch into the alternatives vector of the node
        cursor->getAlternativesByRef().push_back(newBranch);
        // Connect the new node.previous to the branchpoint (the node, into which we added a new branch)
        newBranch->getHead()->setPrevious(cursor);

        // Set the ID of the branch to numberOfBranchPointNode.alternatives.size() + 1
        newBranch->setBranchID(generateAltBranchID(cursor));

        // Set the ID of the new node to branchID.1.
        newBranch->getHead()->setName("1");

        // Set parent branch
        
        newBranch->setParentBranch(this);

        addToAllBranchPoints(cursor);

        // FOR TESTING
        // Iterate over all the branches inside the current node's alternatives and print the parentBranch branchID
        for (HistoryBranch *branch : cursor->getAlternatives())
        {
            std::cout << "Parent branch ID: " << branch->getParentBranch()->getBranchID() << std::endl;
        }
    }
}

void HistoryBranch::removeBranch(string letter, HistoryNode *cursor)
{
    // Check if the current node has alternatives
    if (cursor->getAlternatives().empty())
    {
        return;
    }

    // Find the branch to remove
    HistoryBranch *branchToRemove = nullptr;
    for (HistoryBranch *branch : cursor->getAlternatives())
    {
        if (branch->getBranchAlpha() == letter)
        {
            branchToRemove = branch;
            break;
        }
    }

    // Check if the branch was found
    if (branchToRemove == nullptr)
    {
        return;
    }

    // Remove the branch from the alternatives vector
    for (auto it = cursor->getAlternativesByRef().begin(); it != cursor->getAlternativesByRef().end(); ++it)
    {
        if (*it == branchToRemove)
        {
            cursor->getAlternativesByRef().erase(it);
            break;
        }
    }

    // Delete the branch
    delete branchToRemove;
}

string HistoryBranch::getBranchAlpha(){
    string branchNumber = "";
    branchNumber = this->branchID.substr(this->branchID.find("_"), this->branchID.size());
    return branchNumber;
}

string HistoryBranch::generateAltBranchID(HistoryNode* branchPointNode)
{
    int count = branchPointNode->getAlternatives().size() - 1;
    string altIdentifier;

    while (count >= 0)
    {
        altIdentifier.insert(altIdentifier.begin(), 'a' + (count % 26));
        count = count / 26 - 1; // Decrement count correctly to handle the next character
    }

    return branchPointNode->getName() + "_" + altIdentifier;
}

void HistoryBranch::addToAllBranchPoints(HistoryNode *branchPoint)
{
    // Check if the branchPoint already exists in allBranchPoints
    for (const auto &existingBranchPoint : this->allBranchPoints)
    {
        if (existingBranchPoint == branchPoint)
        {
            // Branch point already exists, do nothing
            return;
        }
    }
    // If it doesn't exist, add it to allBranchPoints
    this->allBranchPoints.push_back(branchPoint);
}

void HistoryBranch::removeFromAllBranchPoints(HistoryNode *branchPoint)
{
    // Find and remove the branchPoint from allBranchPoints
    for (auto it = this->allBranchPoints.begin(); it != this->allBranchPoints.end(); ++it)
    {
        if (*it == branchPoint)
        {
            this->allBranchPoints.erase(it);
            return; // Exit after removing the branchPoint
        }
    }
}

vector<HistoryNode *> HistoryBranch::getAllBranchPoints() const
{
    return this->allBranchPoints;
}

void HistoryBranch::addNode(Save *cityData, HistoryNode* cursor)
{
    string name = "";
    if (this->head == nullptr)
    {
        // Create the first node
        name = "1";
        HistoryNode *newNode = new HistoryNode(name, cityData);
        this->head = newNode;
        cursor = this->head;
        this->tail = this->head;
        this->size++;
    }
    else if (cursor == this->tail)
    {
        // Add the new node at the end
        name = incrementName(this->tail->getName());
        HistoryNode *newNode = new HistoryNode(name, cityData);
        this->tail->setNext(newNode);
        newNode->setPrevious(this->tail);
        cursor = newNode;
        this->tail = newNode;
        this->size++;
    }
    else
    {
        // Add the new node after the current node and delete all data after the current node
        name = incrementName(cursor->getName());
        HistoryNode *newNode = new HistoryNode(name, cityData);
        HistoryNode *nextNode = cursor->getNext();

        // Set the new node in the correct position
        cursor->setNext(newNode);
        newNode->setPrevious(cursor);
        cursor = newNode;
        this->tail = newNode;
        this->size++;

        // Delete all nodes after the current node
        while (nextNode != nullptr)
        {
            HistoryNode *temp = nextNode;
            nextNode = nextNode->getNext();
            delete temp;
            this->size--;
        }
    }
}

string HistoryBranch::incrementName(const string &name)
{
    if (name.empty())
    {
        return name;
    }

    size_t pos = name.find_last_of('.');
    if (pos == string::npos)
    {
        // No '.' found, increment the first number if it exists
        string numberStr;
        size_t i = 0;
        while (i < name.size() && isdigit(name[i]))
        {
            numberStr += name[i];
            i++;
        }

        if (!numberStr.empty())
        {
            int number = stoi(numberStr);
            number++;
            return to_string(number) + name.substr(i);
        }
        else
        {
            // No number found, return the original name
            return name;
        }
    }

    string baseName = name.substr(0, pos + 1);
    string numberStr = name.substr(pos + 1);
    int number = stoi(numberStr);
    number++;

    return baseName + to_string(number);
}

void HistoryBranch::removeNode(HistoryNode* cursor)
{
    if (cursor == nullptr)
    {
        return;
    }

    bool hasBranches = !cursor->getAlternatives().empty();
    HistoryNode *previous = cursor->getPrevious();
    HistoryNode *next = cursor->getNext();

    if (hasBranches)
    {
        if (previous != nullptr)
        {
            // Move all the alternatives to the previous node
            for (HistoryBranch *branch : cursor->getAlternatives())
            {
                previous->addAltHistory(branch);
                branch->getHead()->setPrevious(previous);
            }

            // Debugging: Print alternatives before clearing
            cout << "Alternatives before clearing: " << cursor->getAlternatives().size() << endl;

            // Clear the alternatives vector
            cursor->getAlternativesByRef().clear();

            // Debugging: Print alternatives after clearing
            cout << "Alternatives after clearing: " << cursor->getAlternatives().size() << endl;

            // Add the previous node to allBranchPoints
            addToAllBranchPoints(previous);
        }
        else
        {
            // Delete the branches
            for (HistoryBranch *branch : cursor->getAlternatives())
            {
                delete branch;
            }

            // Debugging: Print alternatives before clearing
            cout << "Alternatives before clearing: " << cursor->getAlternatives().size() << endl;

            // Clear the alternatives vector
            cursor->getAlternativesByRef().clear();

            // Debugging: Print alternatives after clearing
            cout << "Alternatives after clearing: " << cursor->getAlternatives().size() << endl;
        }

        // Remove the current node from allBranchPoints
        removeFromAllBranchPoints(cursor);
    }

    // Connect previous to the next node if current is not the head
    if (cursor != this->head)
    {
        if (previous != nullptr)
        {
            previous->setNext(next);
        }
        if (next != nullptr)
        {
            next->setPrevious(previous);
        }
    }
    else
    {
        // If current is the head, update the head pointer
        this->head = next;
        if (this->head != nullptr)
        {
            this->head->setPrevious(nullptr);
        }
    }

    // Handle the case where the head of a child branch is being removed
    if (cursor == this->head && this->head != nullptr)
    {
        HistoryNode *childHeadNext = this->head->getNext();
        if (childHeadNext != nullptr)
        {
            childHeadNext->setPrevious(this->head->getPrevious());
        }
    }

    // Delete the current node and update the current pointer
    HistoryNode *temp = cursor;

    if (next != nullptr)
    {
        cursor = next;
    } else if (previous != nullptr) {
        cursor = previous;
    } else {
        cursor = nullptr;
    }

        delete temp;
    }

void HistoryBranch::moveBack(HistoryNode* cursor)
{
    if (cursor != nullptr && cursor != this->head)
    {
        cursor = cursor->getPrevious();
    }
}

void HistoryBranch::moveForward(HistoryNode* cursor)
{
    if (cursor != nullptr && cursor != this->tail)
    {
        cursor = cursor->getNext();
    }
}

string HistoryBranch::printBranch()
{
    string output = "";
    HistoryNode *temp = this->head;

    // Print the main branch vertically
    while (temp != nullptr)
    {
        // Check if the current node is a branch point
        bool isBranchPoint = false;
        for (const auto &branchPoint : this->allBranchPoints)
        {
            if (branchPoint == temp)
            {
                isBranchPoint = true;
                break;
            }
        }

        if (isBranchPoint)
        {
            // Print the branch IDs
            output += " |" + string((temp->getName().length() + 1) * 2, ' ');
            for (const auto &altBranch : temp->getAlternatives())
            {
                output += "(" + altBranch->getBranchID() + ")   ";
            }
            output += "\n";

            // Print the main branch node
            output += "[" + temp->getName() + "]";
            for (const auto &altBranch : temp->getAlternatives())
            {
                HistoryNode *altTemp = altBranch->getHead();
                output += "----[" + altTemp->getName() + "]";
            }
            output += "\n";

            // Print the vertical pipes for the main branch
            output += " |";

            // Print the vertical pipes for the alternatives
            for (size_t i = 0; i < temp->getAlternatives().size(); ++i)
            {
                output += string((temp->getName().length() + 5), ' ') + "|";
            }
            output += "\n";

            // Print alternative branches vertically
            bool hasMoreNodes = true;
            size_t altBranchIndex = 0;
            while (hasMoreNodes)
            {
                hasMoreNodes = false;
                output += " | ";

                // For each alternative branch, print the node vertically
                for (const auto &altBranch : temp->getAlternatives())
                {
                    HistoryNode *altTemp = altBranch->getHead();

                    // Move to the node at the current index
                    for (size_t i = 0; i < altBranchIndex && altTemp != nullptr; ++i)
                    {
                        altTemp = altTemp->getNext();
                    }

                    // Check if there is a node to print
                    if (altTemp != nullptr)
                    {
                        hasMoreNodes = true;
                        output += string((temp->getName().length() + 3), ' ') + "[" + altTemp->getName() + "]";
                    }
                }
                // output += string((temp->getName().length() + 3), ' ') + " | "; // Maintain spacing if no node

                output += "\n";
                altBranchIndex++;
            }

            // // Print the vertical pipe after the alternative branches
            // output += " |\n";
        }
        else
        {
            // Print the current node in the main branch
            output += "[" + temp->getName() + "]\n";
            if (temp->getNext() != nullptr)
            {
                output += " |\n";
            }
        }

        temp = temp->getNext();
    }

    return output;
}