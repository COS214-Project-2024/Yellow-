#ifndef HISTORYBRANCH_H
#define HISTORYBRANCH_H

#include <vector>
#include <string>
#include "City.h"

class HistoryNode; // Forward declaration

using namespace std;

class HistoryBranch{

    private:
        HistoryNode* head;
        HistoryNode* current;
        HistoryNode* tail;
        HistoryBranch* parentBranch;
        vector <HistoryNode*> allBranchPoints;
        string branchID;
        int size;
    
    public:
        HistoryBranch();
        ~HistoryBranch();
        HistoryNode* getHead();
        HistoryNode* getCurrent();
        HistoryNode* getTail();
        HistoryBranch* getParentBranch();
        void setParentBranch(HistoryBranch* parentBranch);
        string getBranchID();
        void setBranchID(string branchID);
        void setCurrent(string path);
        void addNode(Varibals *cityData);
        void startAltHistory(Varibals *cityData);
        void addToAllBranchPoints(HistoryNode* branchPoint);
        vector <HistoryNode*> getAllBranchPoints() const;
        void removeFromAllBranchPoints(HistoryNode *branchPoint);
        string generateAlternativeName(const string &branchRootName, int count);
        string incrementName(const string &name);
        void removeNode();
        void moveBack();
        void moveForward();
  
        // FOR TESTING
        string printBranch();
        void printBranchHelper(HistoryBranch *branch, string &result, int indentLevel, bool isMainBranch);
        // void printCurrent();
        // void printRoot();
};

#endif
