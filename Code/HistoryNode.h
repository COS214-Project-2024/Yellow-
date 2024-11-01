#include <vector>
#include <string>
#include <iostream>
#include "City.h"

using namespace std;

class HistoryNode {
    private:
        HistoryNode* previous;
        vector <HistoryNode*> next;
        Varibals* cityData;
        string name;

    public:
        void setName(string name);
        string getName();
        void setPrevious(HistoryNode* previous);
        HistoryNode* getPrevious();
        void addNext(HistoryNode* next);
        vector <HistoryNode*> getNext();
        void setData (Varibals* cityData);
        Varibals* getData();

    
};