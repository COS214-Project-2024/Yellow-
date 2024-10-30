#include "MaterialOrder.h"

void MaterialOrder::addMaterial(string newMaterial, float newQuantity) {

    this->materials.push_back(newMaterial);
    this->materialQuantities.push_back(newQuantity);

}
