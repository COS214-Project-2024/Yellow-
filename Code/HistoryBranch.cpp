#include "HistoryBranch.h"
#include "HistoryNode.h"

HistoryBranch::HistoryBranch()
{
    this->head = nullptr;
    this->current = this->head;
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

HistoryNode* HistoryBranch::getCurrent()
{
    return this->current;
}

// void HistoryBranch::setCurrent(string path)
// {
//     this->current = current;
// }

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

void HistoryBranch::startAltHistory(Varibals *cityData)
{
    if (this->current != nullptr)
    {
        // Create new branch
        HistoryBranch *newBranch = new HistoryBranch();
        // Create a new node and insert it in the new historyBranch
        newBranch->addNode(cityData);
        // Insert the new historyBranch into the alternatives vector of the node
        this->current->getAlternativesByRef().push_back(newBranch);
        // Connect the new node.previous to the branchpoint (the node, into which we added a new branch)
        newBranch->getHead()->setPrevious(this->current);

        // Set the ID of the branch to numberOfBranchPointNode.alternatives.size() + 1
        newBranch->setBranchID(this->current->generateAltBranchID());

        // Set the ID of the new node to branchID.1.
        newBranch->getHead()->setName("1");

        // Set parent branch
        
        newBranch->setParentBranch(this);

        addToAllBranchPoints(this->current);

        // FOR TESTING
        // Iterate over all the branches inside the current node's alternatives and print the parentBranch branchID
        for (HistoryBranch *branch : this->current->getAlternatives())
        {
            std::cout << "Parent branch ID: " << branch->getParentBranch()->getBranchID() << std::endl;
        }
    }
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

void HistoryBranch::addNode(Varibals *cityData)
{
    string name = "";
    if (this->head == nullptr)
    {
        // Create the first node
        name = "1";
        HistoryNode *newNode = new HistoryNode(name, cityData);
        this->head = newNode;
        this->current = this->head;
        this->tail = this->head;
        this->size++;
    }
    else if (this->current == this->tail)
    {
        // Add the new node at the end
        name = incrementName(this->tail->getName());
        HistoryNode *newNode = new HistoryNode(name, cityData);
        this->tail->setNext(newNode);
        newNode->setPrevious(this->tail);
        this->current = newNode;
        this->tail = newNode;
        this->size++;
    }
    else
    {
        // Add the new node after the current node and delete all data after the current node
        name = incrementName(this->current->getName());
        HistoryNode *newNode = new HistoryNode(name, cityData);
        HistoryNode *nextNode = this->current->getNext();

        // Set the new node in the correct position
        this->current->setNext(newNode);
        newNode->setPrevious(this->current);
        this->current = newNode;
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

void HistoryBranch::removeNode()
{
    if (this->current == nullptr)
    {
        return;
    }

    bool hasBranches = !this->current->getAlternatives().empty();
    HistoryNode *previous = this->current->getPrevious();
    HistoryNode *next = this->current->getNext();

    if (hasBranches)
    {
        if (previous != nullptr)
        {
            // Move all the alternatives to the previous node
            for (HistoryBranch *branch : this->current->getAlternatives())
            {
                previous->addAltHistory(branch);
                branch->getHead()->setPrevious(previous);
            }

            // Debugging: Print alternatives before clearing
            cout << "Alternatives before clearing: " << this->current->getAlternatives().size() << endl;

            // Clear the alternatives vector
            this->current->getAlternativesByRef().clear();

            // Debugging: Print alternatives after clearing
            cout << "Alternatives after clearing: " << this->current->getAlternatives().size() << endl;

            // Add the previous node to allBranchPoints
            addToAllBranchPoints(previous);
        }
        else
        {
            // Delete the branches
            for (HistoryBranch *branch : this->current->getAlternatives())
            {
                delete branch;
            }

            // Debugging: Print alternatives before clearing
            cout << "Alternatives before clearing: " << this->current->getAlternatives().size() << endl;

            // Clear the alternatives vector
            this->current->getAlternativesByRef().clear();

            // Debugging: Print alternatives after clearing
            cout << "Alternatives after clearing: " << this->current->getAlternatives().size() << endl;
        }

        // Remove the current node from allBranchPoints
        removeFromAllBranchPoints(this->current);
    }

    // Connect previous to the next node if current is not the head
    if (this->current != this->head)
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
    if (this->current == this->head && this->head != nullptr)
    {
        HistoryNode *childHeadNext = this->head->getNext();
        if (childHeadNext != nullptr)
        {
            childHeadNext->setPrevious(this->head->getPrevious());
        }
    }

    // Delete the current node and update the current pointer
    HistoryNode *temp = this->current;

    if (next != nullptr)
    {
        this->current = next;
    } else if (previous != nullptr) {
        this->current = previous;
    } else {
        this->current = nullptr;
    }

        delete temp;
    }

void HistoryBranch::moveBack()
{
    if (this->current != nullptr && this->current != this->head)
    {
        this->current = this->current->getPrevious();
    }
}

void HistoryBranch::moveForward()
{
    if (this->current != nullptr && this->current != this->tail)
    {
        this->current = this->current->getNext();
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