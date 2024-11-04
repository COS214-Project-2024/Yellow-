/**
* @class CVisitor
* @brief A class that represents a concrete visitor.
* @ingroup Visitor
* @implements Visitor
*
* The Visitor class is a concrete visitor participant of the Visitor design pattern. It is used to visit the citizens and buildings of the city.
*/
#include "CVisitor.h"

void CVisitor::visitCitizens(Citizen* ele) {
	cout << "Citizen Have been vistesd" << endl;
}

// void CVisitor::visitTransport(Vehicle* ele) {
// 	// TODO - implement CVisitor::visitTransport
// 	throw "Not yet implemented";
// }

void CVisitor::visitBuilding(Section* ele) {
	cout << "Building Have been vistesd" << endl;
}
