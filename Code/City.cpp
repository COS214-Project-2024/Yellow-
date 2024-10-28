#include "City.h"

struct Varibals
{
	Resources* res;
	Taxes* tax;
};

City& City::instanceCity() {
	static City onlyInstance;
 	return onlyInstance;
}
