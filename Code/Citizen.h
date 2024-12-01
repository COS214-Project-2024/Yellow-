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
class Buildings;
class Residential;
#include "Pet.h"
#include "RandomUtil.h"
#include "CitizenPrototype.h"

class Citizen : public CitizenPrototype{
private:
	// Basic citizen data
	float money;										// What is the citizen's bank balance?
	Residential* accommodation;							// Where does the citizen live?					// Cell pointers
	Buildings* businessAddress;							// Where does the citizen work?					// Cell pointers
	Pet* pet;											// Does the citizen have a pet?
	RandomUtil generator;								// [For random generation]
	void petChanceCalculator();							// [For deciding who gets a pet]

	// States for Observers to observe
	int happiness;										// How happy is the citizen? (Out of 100)
	std::string employment;								// What is the citizen's job?

public:
	int identityNum;
	// Basic citizen functions
    Citizen();



    Citizen(int happy, string job, float cash,  Pet* pet, Residential* acc,  Buildings* addr);

    Citizen(const Citizen& other);
    int getHappiness() const;
    void setHappiness(int value);
    string getEmployment() const;
    void setEmployment(string job);
    float getMoney() const;
    void setMoney(float cash);
	Residential* getAccommodation() const;
	void setAccommodation(Residential* acc);
	Buildings* getBusinessAddress() const;
	void setBusinessAddress(Buildings* address);
	Pet* getPet() const;
	void setPet(Pet* pet);

	// Prototype stuff
	CitizenPrototype* procreate();


};

#endif
