#ifndef SNAKE_H
#define SNAKE_H
#include "Pet.h"

class Snake : public Pet{
public:
    Snake();
    Snake(string name, string type);
    void cuteAction();
    ~Snake();
};

#endif //SNAKE_H
