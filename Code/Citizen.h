#ifndef CITIZEN_H
#define CITIZEN_H
#include "Residential.h"
#include "Observer.h"
#include <string>
using namespace std;

class Citizen{
protected:
	int happiness;						// How happy is the citizen? (Out of 100)
	Residential* accommodation;			// Where does the citizen live?
	string employment;					// What is the citizen's job?
private:
	float money;						// What is the citizen's bank balance?
	string businessAddress;				// Where does the citizen work?
public:
    Citizen();
    Citizen(int happy, Residential* acc, string job, float cash, string addr);
    Citizen(const Citizen& other);
    int getHappiness() const;
    void setHappiness(int value);
    Residential* getAccommodation() const;
    void setAccommodation(Residential* acc);
    string getEmployment() const;
    void setEmployment(string job);
    float getMoney() const;
    void setMoney(float cash);
    string getBusinessAddress();
    void setBusinessAddress(string address);
	Citizen* procreate();

};

#endif
