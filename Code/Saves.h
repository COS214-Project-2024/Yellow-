#ifndef SAVES_H
#define SAVES_H

#include <vector>
#include "iostream"
#include "Save.h"
#include "HistoryBranch.h"

using namespace std;

class Saves {
friend class SaveAndLoad;    
    //attributes
    private:
        vector <Save*> saves;
        // HistoryBranch* saves;
        
    public:
        //methods
        Saves() {};
        ~Saves() {}; //must delete all saves first

        void storeSave(Save* save);
        Save* getSave(int index);

        // FOR TESTING
        void printAllSaves();

};

#endif


/*
    Visual Paradigm changes:
    Vector of Save objects
*/