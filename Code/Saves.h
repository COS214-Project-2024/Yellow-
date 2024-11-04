/**
 * @file Saves.h
 * @author Daniel Lukyanov
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SAVES_H
#define SAVES_H

#include <vector>
#include "HistoryBranch.h"
#include "HistoryNode.h"

class Saves
{
private:
    string currentBranchPath; //example "M.1_a.2_c.9_f"
    HistoryBranch* historyTree;
    HistoryNode* cursor;

public:
    Saves();
    ~Saves();
    void save(Save* save, bool overwrite = false);//saves at cursor
    HistoryBranch *getSaves() const; //exposes the tree for visualisation. Set to const, to make sure it the tree does not get mutilated by the caller
    Save *loadAtCursor();//returns the save at cursor;
    HistoryNode* goToNode(string path);
    Save* viewSave(string path); //loads a save at a specific path; example "M.1_a.2_c.9_f.3", where the last number is the number/name of the node on that branch
    Save* loadSave(string path); //loads a save at a specific path; example "M.1_a.2_c.9_f.3", where the last number is the number/name of the node on that branch
    void deleteSave(string path); //deletes a save at a specific path; example "M.1_a.2_c.9_f.3", where the last number is the number/name of the node on that branch
    void deleteBranch(string path);
    HistoryNode* getCursor();
    void moveForward();
    void moveBack();
    void moveIntoBranch(string branchAlpha); //examples: "a", "b", "ab", "cb"; "a" moves to the 1st branch, "ab" moves to the 27th branch
    void moveOutOfBranch(); //moves out of the current branch to the parent branch. Must set cursor to current of branch we just moved into
    string getCurrentBranchPath();
    HistoryBranch* loadBranch(string path);
    void resetToMainBranch();
    void resetCursor(bool toMainBranch = true, bool toHead = true);

};

#endif // SAVES_H