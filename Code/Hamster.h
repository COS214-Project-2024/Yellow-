#ifndef HAMSTER_H
#define HAMSTER_H
#include "Pet.h"

class Hamster : public Pet{
public:
    Hamster();
    Hamster(Citizen* owner);
    void cuteAction();
    ~Hamster();
};

#endif //HAMSTER_H
