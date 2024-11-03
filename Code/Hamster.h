#ifndef HAMSTER_H
#define HAMSTER_H
#include "Pet.h"

class Hamster : public Pet{
public:
    Hamster();
    Hamster(string name, string type);
    void cuteAction();
    ~Hamster();
};

#endif //HAMSTER_H
