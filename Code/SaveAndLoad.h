/**
 * @file SaveAndLoad.h
 * @author Daniel Lukyanov
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H

#include "SystemState.h"
#include "Save.h"

class SaveAndLoad {

private:
	SystemState* currentSave;

public:
	Save* createSave();

	void LoadSystem(Save* save);
};

#endif
