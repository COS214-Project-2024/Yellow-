#ifndef INCOMEOBSERVER_H
#define INCOMEOBSERVER_H
#include "Observer.h"

class IncomeObserver : public Observer {
public:
    float averageIncome;
    IncomeObserver();
    IncomeObserver(vector<Citizen*> subj);
    void update();
};



#endif //INCOMEOBSERVER_H