/**
* @class MaterialOrder
* @brief MaterialOrder class
* @ingroup Factory
* @implements MaterialOrder
*
* The MaterialOrder class is a concrete factory participant of the Factory design pattern. It is used to create a material order.
*/
#include "MaterialOrder.h"

void MaterialOrder::addMaterial(string newMaterial, float newQuantity) {

    this->materials.push_back(newMaterial);
    this->materialQuantities.push_back(newQuantity);

}
