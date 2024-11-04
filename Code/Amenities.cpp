/**
 * @class Amenities
 * @brief Concrete handler participant of the Chain of Responsibility design pattern
 * @ingroup Chain of responsibility
 * @implements Department
 *
 * The Amenities class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the ExpandCity policy.
 * 
 */
#include "Amenities.h"

MaterialOrder* Amenities::handle(Policies* policy) {
    if(policy->getPolicy() == "ExpandCity"){
        MaterialOrder* materialOrder = new MaterialOrder();

        //TYPES OF BUILDING

        int min = 0;
        int max = 100;

        int val = this->randomVal->randomVal(min, max);

        string material;

        if(val >= 0 && val < 30){
            //RESIDENTIAL
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 40){
                material = "House";
            }
            else if(val >= 40 && val < 70){
                material = "Apartment";
            }
            else{
                material = "Complex";
            }
        }
        else if(val >= 30 && val < 50){
            //UTILITIES
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 50){
                material = "PowerPlant";
            }
            else if(val >= 50 && val < 80){
                material = "WaterPlant";
            }
            else{
                material = "WasteManagement";
            }
        }
        else if(val >= 50 && val < 70){
            //INDUSTRIAL
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 40){
                material = "ConcreteFactory";
            }
            else if(val >= 40 && val < 70){
                material = "SteelFactory";
            }
            else{
                material = "Forestry";
            }
        }
        else if(val >= 70 && val < 80){
            //SERVICES
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 40){
                material = "School";
            }
            else if(val >= 40 && val < 70){
                material = "Hospital";
            }
            else{
                material = "PoliceStation";
            }
        }
        else if(val >= 80 && val < 95){
            //COMMERCIAL
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 40){
                material = "Mall";
            }
            else if(val >= 40 && val < 70){
                material = "Office";
            }
            else{
                material = "Shop";
            }
        }
        else{
            //LANDMARKS
            val = this->randomVal->randomVal(min, max);
            if(val >= 0 && val < 50){
                material = "Museum";
            }
            else{
                material = "Park";
            }
        }

        materialOrder->addMaterial(material, 1);

        material = "MoraleIncrease";

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
