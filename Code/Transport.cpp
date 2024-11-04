/**
* @class Transport
* @brief A class used to handle the addition of public transport to the city
* @ingroup Chain of responsibility
* @implements Department
*
* The Transport class is a concrete handler participant of the Chain of Responsibility design pattern. It is used to handle the AddPublicTransport policy.
*/
#include "Transport.h"

MaterialOrder* Transport::handle(Policies* policy) {
	if(policy->getPolicy() == "AddPublicTransport"){

        MaterialOrder* materialOrder = new MaterialOrder();

        //BUS STOP / TRAN STATION

        int min = 0;
        int max = 100;

        int val = this->randomVal->randomVal(min, max);

        string material;

        if(val < 50){
            material = "BusStop";
        }
        else{
            material = "TrainStation";
        }

        materialOrder->addMaterial(material, 1);

        //MORALE

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
