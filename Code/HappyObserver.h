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
	int averageHappiness;
	HappyObserver();
	HappyObserver(Population* subj);
	void update();
};

#endif
