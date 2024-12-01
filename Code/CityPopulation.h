#ifndef CITYPOPULATION_H
#define CITYPOPULATION_H
#include "Observer.h"
#include <string>
#include "Population.h"

class CityPopulation : public Population{
public:
    // Basic citypopulation stuff
    CityPopulation();

    // Observer stuff
    vector<Citizen*> getCitizens();					// getState (Observer's access to the list of citizens)
    void setCitizens(Citizen* cit);                     // setState


    // Visitor stuff
    void acceptVisitor(Visitor* v);

    // For citizen registration
    static CityPopulation& instancePopulation();


    // Mini Prototype functionality
    // void allProcreate();
};



#endif //CITYPOPULATION_H
