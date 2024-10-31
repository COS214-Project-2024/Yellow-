#include "MaterialOrder.h"

void MaterialOrder::addMaterial(string newMaterial, float newQuantity) {

    this->materials.push_back({newMaterial, newQuantity});

}
