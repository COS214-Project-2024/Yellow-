#ifndef SAVES_H
#define SAVES_H

#include <vector>
#include "HistoryBranch.h"

class Saves
{
private:
    string currentBranchPath; //example "M.1_a.2_c.9_f"
    HistoryBranch* historyTree;
    HistoryNode* cursor;

public:
    Saves();
    ~Saves();
    void save();
    HistoryBranch *getSaves(); //exposes the tree for visualisation
    Save *loadAtCursor();//returns the save at cursor;
    Save* loadSave(string path); //loads a save at a specific path; example "M.1_a.2_c.9_f.3", where the last number is the number/name of the node on that branch
    HistoryNode* getCursor();
    void moveForward();
    void moveBack();
    void moveIntoBranch(string branchAlpha); //examples: "a", "b", "ab", "cb"; "a" moves to the 1st branch, "ab" moves to the 27th branch
    string getCurrentBranchPath();
    void loadBranch(string path);
    void deleteBranch(string path);
    void deleteSave(string path);

};

#endif // SAVES_H