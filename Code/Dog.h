#ifndef DOG_H
#define DOG_H
#include "Pet.h"

class Dog : public Pet{
public:
    Dog();
    Dog(Citizen* owner);
    void cuteAction();
    ~Dog();
};

#endif //DOG_H
