/**
 * @file Observer.h
 * @author Rorisang Manamela
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef OBSERVER_H
#define OBSERVER_H
#include "Citizen.h"
#include "City.h"
#include <string>
#include <vector> 
class Population;
using namespace std;

class Observer {
protected:
	Population* subject;
public:
	Observer();
	Observer(Population* subj);
	string observationType;
	string getObservationType();
	void setSubject(Population* subj);
	Population* getSubject() const;
	virtual void update() = 0;
};

#endif
