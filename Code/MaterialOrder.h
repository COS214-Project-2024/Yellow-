#ifndef CODE_MATERIALORDER_H
#define CODE_MATERIALORDER_H

#include <iostream>
#include <vector>
using namespace std;

class MaterialOrder {

    //TODO: implement changes and chat to Stefan on how each policy will affect the city
    //TODO: implement the randomised function
public:
    vector<string>  materials;
    vector<float> materialQuantities;

    void addMaterial(string newMaterial, float newQuantity);
};


#endif //CODE_MATERIALORDER_H
