#include "Cat.h"
#include <iostream>

Cat::Cat() {
    this->animalType = "cat";
}

Cat::Cat(Citizen* owner) : Pet(owner) {
    this->animalType = "cat";
}

void Cat::cuteAction() {
    std::cout << "Meow! :3" << std::endl;
}
Cat::~Cat() = default;