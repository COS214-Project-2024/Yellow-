#include "Finances.h"

MaterialOrder *Finances::handle(Policies *policy) {
    if(policy->getPolicy() == "IncreaseTaxes"){

        MaterialOrder* materialOrder = new MaterialOrder();

        //TAX TYPE

        int min = 0;
        int max = 100;

        int val = this->randomVal->randomVal(min, max);

        string material;

        if(val >= 0 && val < 20){
            material = "PropertyTax";
        }
        else if(val >= 20 && val < 70){
            material = "IncomeTax";
        }
        else{
            material = "BusinessTax";
        }

        //INCREASE AMOUNT
        min = 0;
        max = 15;
        val = this->randomVal->randomVal(min, max);

        float amount = val / 100;

        materialOrder->addMaterial(material, amount);

        return materialOrder;

    }
    else{
        return nullptr;
    }
}
