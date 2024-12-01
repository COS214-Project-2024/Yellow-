#include "CityPopulation.h"

//////////////////////// Constructors ////////////////////////
CityPopulation::CityPopulation() {}

//
// CityPopulation& CityPopulation::instancePopulation(){
//     static CityPopulation mainPopulation;
//     return mainPopulation;
// }
//

//////////////////////// Observers ////////////////////////
// Get State
vector<Citizen*> CityPopulation::getCitizens() {
    return listOfCitizens;
}

// Set State
void CityPopulation::setCitizens(Citizen* cit) {
    listOfCitizens.push_back(cit);
}


////////////// Visitor ///////////////
/// Accept Visitor
void CityPopulation::acceptVisitor(Visitor* v) {
    for (Citizen* cit : listOfCitizens){
        v->visitCitizens(cit);
    }
}


// /////////////////////// Prototype ////////////////////////////
//
// void CityPopulation::allProcreate() {
//     std::vector<CitizenPrototype*> newCitizens;
//
//     for (CitizenPrototype* citizen : listOfCitizens) {
//         if (citizen) {                                      // Check for null
//             CitizenPrototype* newCitizen = citizen->procreate();
//             newCitizens.push_back(newCitizen);              // Store the new citizen
//         }
//     }
//
//     // Add new citizens to the population
//     listOfCitizens.insert(listOfCitizens.end(), newCitizens.begin(), newCitizens.end());
//     std::cout << "All citizens have procreated." << std::endl;
// }