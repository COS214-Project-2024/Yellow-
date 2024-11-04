/**
* @class Labour
* @brief Class that represents a Labour department
* @ingroup Chain of responsibility
* @implements Department
*
* The Labour class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the IncreaseWages policy.
*/
#include "Labour.h"

MaterialOrder *Labour::handle(Policies *policy) {
    if(policy->getPolicy() == "IncreaseWages"){

        MaterialOrder* materialOrder = new MaterialOrder();

        //DECREASE BUDGET
        int min = 0;
        int max = 100;

        int val = this->randomVal->randomVal(min, max);

        string material;

        material = "Budget";

        val *= -1;

        materialOrder->addMaterial(material, val);

        //INCREASE MORALE
        material = "Morale";

        materialOrder->addMaterial(material, 1);

        return materialOrder;




    }
    if(this->successor != nullptr){
        return this->successor->handle(policy);
    }
    else{
        return nullptr;
    }
}
