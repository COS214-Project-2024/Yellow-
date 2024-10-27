#include "City.h"

City& City::instanceCity() {
	static City onlyInstance;
 	return onlyInstance;
}
