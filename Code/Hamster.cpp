#include "Hamster.h"
#include <iostream>

Hamster::Hamster() {
    this->animalType = "hamster";
}

Hamster::Hamster(string name, string type) : Pet(name, type){}

void Hamster::cuteAction() {
    std::cout << "Squeak! :o" << std::endl;
}
Hamster::~Hamster() = default;