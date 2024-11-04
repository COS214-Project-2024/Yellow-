#ifndef SAVE_H
#define SAVE_H

#include "SystemState.h"
#include "City.h"
#include "Map.h"

class Save {

private:
    Map* map;
	Varibals* systemState;

public:

    Save(Map* map, Varibals* systemState);
    ~Save();

	Varibals* getSystemState();
	void setSystemState(Varibals *sState);

    Map* getMap();
    void setMap(Map *map);
};

#endif
