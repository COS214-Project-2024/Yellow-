#include "Dog.h"
#include <iostream>

Dog::Dog() {
    this->animalType = "dog";
}

Dog::Dog(string name, string type) : Pet(name, type){}

void Dog::cuteAction() {
    std::cout << "Woof! :)" << std::endl;
}
Dog::~Dog() = default;