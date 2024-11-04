/**
 * @file Citizen.h
 * @author Rorisang Manamela
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CITIZEN_H
#define CITIZEN_H
#include "Observer.h"
#include <string>
class Buildings;
class Residential;
using namespace std;

class Citizen{
protected:
	int happiness;						// How happy is the citizen? (Out of 100)
	Residential* accommodation;			// Where does the citizen live?
	string employment;					// What is the citizen's job?
private:
	float money;						// What is the citizen's bank balance?
	Buildings* businessAddress;				// Where does the citizen work?
public:
    Citizen();
    Citizen(int happy, Residential* acc, string job, float cash, Buildings* addr);
    Citizen(const Citizen& other);
    int getHappiness() const;
    void setHappiness(int value);
    Residential* getAccommodation() const;
    void setAccommodation(Residential* acc);
    string getEmployment() const;
    void setEmployment(string job);
    float getMoney() const;
    void setMoney(float cash);
    Buildings* getBusinessAddress();
    void setBusinessAddress(Buildings* address);
	Citizen* procreate();

};

#endif
