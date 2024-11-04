/**
 * @file Save.h
 * @author Daniel Lukyanov
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SAVE_H
#define SAVE_H

#include "SystemState.h"

class Save {

private:
	SystemState systemState;

	SystemState* getSave();

	void setSave(SystemState* sState);
};

#endif
