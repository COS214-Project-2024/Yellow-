#include "Cat.h"
#include <iostream>

Cat::Cat() {
    this->animalType = "cat";
}

Cat::Cat(string name, string type) : Pet(name, type){}

void Cat::cuteAction() {
    std::cout << "Meow! :3" << std::endl;
}
Cat::~Cat() = default;