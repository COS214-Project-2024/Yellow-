#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H

#include "SystemState.h"
#include "Save.h"
#include "Saves.h"
#include "HistoryNode.h"


class SaveAndLoad {

private:
	SystemState* currentSave;
	HistoryNode* currHN; //currentHistoryNode - centralized history node
	// FOR TESTING
	static int dummyInt;

public:
	Save* createSave();

	// void SaveSystem(Save *save);
	void saveSystem(Saves *saves);
	void loadSystem(int saveNum, Saves *saves);
	SystemState* getCurrentSystemState();
	// FOR TESTING
	SaveAndLoad();
	void printCurrentSave();
};

#endif

/*Visual Paradigm Changes:
	+ saveSystem(Saves* saves) : void
	+ loadSystem(saveNum : int, Saves *saves) : void
*/