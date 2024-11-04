#include "Dog.h"
#include <iostream>

Dog::Dog() {
    this->animalType = "dog";
}

Dog::Dog(Citizen* owner) : Pet(owner) {
    this->animalType = "dog";
}

void Dog::cuteAction() {
    std::cout << "Woof! :)" << std::endl;
}
Dog::~Dog() = default;