#ifndef CAT_H
#define CAT_H
#include "Pet.h"

class Cat : public Pet{
public:
    Cat();
    Cat(Citizen* owner);
    void cuteAction();
    ~Cat();
};

#endif //CAT_H
