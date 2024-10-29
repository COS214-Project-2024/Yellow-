#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
using namespace std;

class Observer {
public:
	string observationType;
	string getObservationType();
	virtual void update() = 0;
};

#endif
