/**
 * @file HappyObserver.h
 * @author Rorisang Manamela
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HAPPYOBSERVER_H
#define HAPPYOBSERVER_H
#include "Observer.h"

class HappyObserver : public Observer {
public:
	int totalHappiness;
	HappyObserver();
	HappyObserver(vector<Citizen*> subj);
	void update();
};

#endif
