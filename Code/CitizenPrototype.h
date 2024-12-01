#ifndef CITIZENPROTOTYPE_H
#define CITIZENPROTOTYPE_H
#include <vector>
#include <string>

class CitizenPrototype {
protected:
    // Basic citizen stuff
    static int identityNumbers;							// Counter for assigning ID numbers

public:
    // Prototype
    virtual CitizenPrototype* procreate() = 0;				// Prototype

};

int CitizenPrototype::identityNumbers = 0;			// Initalise ID numbers, to increase with each new object


#endif //CITIZENPROTOTYPE_H
