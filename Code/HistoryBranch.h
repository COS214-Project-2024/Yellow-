#ifndef HISTORYBRANCH_H
#define HISTORYBRANCH_H

#include <vector>
#include <string>
#include "Save.h"

class HistoryNode; // Forward declaration

using namespace std;

class HistoryBranch{

    private:
        HistoryNode* head;
        // HistoryNode* current;
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
        void addNode(Save *cityData, HistoryNode *cursor);
        void startAltHistory(Save *cityData, HistoryNode *cursor);
        void removeBranch(string letter, HistoryNode *cursor);
        string getBranchAlpha();
        string generateAltBranchID(HistoryNode* branchPointNode);
        void addToAllBranchPoints(HistoryNode *branchPoint);
        vector <HistoryNode*> getAllBranchPoints() const;
        void removeFromAllBranchPoints(HistoryNode *branchPoint);
        string generateAlternativeName(const string &branchRootName, int count);
        string incrementName(const string &name);
        void removeNode(HistoryNode *cursor);
        void moveBack(HistoryNode *cursor);
        void moveForward(HistoryNode *cursor);
  
        // FOR TESTING
        string printBranch();
};

#endif
