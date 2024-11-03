#include "Snake.h"
#include <iostream>

Snake::Snake() {
    this->animalType = "snake";
}

Snake::Snake(string name, string type) : Pet(name, type){}

void Snake::cuteAction() {
    std::cout << "Hiss! :>" << std::endl;
}
Snake::~Snake() = default;