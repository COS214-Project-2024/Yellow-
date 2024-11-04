/**
* @class MaterialOrder
* @brief MaterialOrder class
* @ingroup Factory
* @implements MaterialOrder
*
* The MaterialOrder class is a concrete factory participant of the Factory design pattern. It is used to create a material order.
*/
#ifndef CODE_MATERIALORDER_H
#define CODE_MATERIALORDER_H

#include <iostream>
#include <vector>
using namespace std;

class MaterialOrder {
public:
    vector<pair<string, float>>  materials;

    void addMaterial(string newMaterial, float newQuantity);
};


#endif //CODE_MATERIALORDER_H