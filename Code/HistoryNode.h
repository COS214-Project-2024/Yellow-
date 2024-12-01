#ifndef HISTORYNODE_H
#define HISTORYNODE_H

#include <vector>
#include <string>
#include "Save.h"

class HistoryBranch; // Forward declaration

using namespace std;

class HistoryNode {
    private:
        HistoryNode* previous;
        HistoryNode* next;
        vector <HistoryBranch*> alternatives;
        Save* cityData;
        string name;

    public:
        HistoryNode(); //default constructor
        HistoryNode(string name, Save *cityData); //constructor
        HistoryNode(HistoryNode* other); //copy constructor
        ~HistoryNode();
        void setName(string name);
        string getName();
        void setPrevious(HistoryNode* previous);
        HistoryNode* getPrevious();
        void startAltHistory(HistoryBranch *branch);
        void addAltHistory(HistoryBranch* branch);
        HistoryNode *getNext();
        void setNext(HistoryNode* next);
        vector <HistoryBranch*> getAlternatives();
        std::vector<HistoryBranch *> &getAlternativesByRef();
        void setAlternatives(vector<HistoryBranch *> newAlternatives);
        void setData(Save *cityData);
        Save* getData();

    
};

#endif